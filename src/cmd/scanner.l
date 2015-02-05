%{

#include "scanner.hpp"


typedef order::Parser::token token;
typedef order::Parser::token_type token_type;

#define yyterminate() return token::END

%}


%option c++
%option debug
%option stack
%option batch
%option prefix="Welly"
%option outfile="scanner.cpp"
%option yywrap nounput

/* track locations in yylex */
%{
#define YY_USER_ACTION yylloc->columns( yyleng );
%}

WS      [ \t\r\n]+ 
PERIOD	.
WORD	[a-zA-Z]+
INTEGER	[0-9]+
DOUBLE	[0-9]+"."[0-9]+	

%%

%{
	yylloc->step();
%}

INTEGER {
	yylloc->step();
	yylval->integerVal = atoi( yytext );
	return token::INTEGER;
}

DOUBLE {
	yylloc->step();
	yylval->doubleVal = atof( yytext );
	return token::DOUBLE;
}

WORD {
	yylloc->step();
	yylval->wordVal = new std::string( yytext, yyleng );
	return token::WORD;
}

WS {
	yylloc->step();
}

PERIOD {
	yylloc->step();
	yylval->wordVal = new std::string( yytext, yyleng );
	return token::PERIOD;
}

%%

namespace order
{

Scanner::Scanner( std::istream* in, std::ostream* out )
	: WellyFlexLexer( in, out )
{}

Scanner::~Scanner()
{}

void Scanner::set_debug( bool flag )
{
	yy_flex_debug = flag;
}

}
#ifdef yylex
#undef yylex
#endif

int WellyFlexLexer::yylex()
{
	return 0;
}

int WellyFlexLexer::yywrap()
{
	return 1;
}


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

WS      [ \t\n]+ 

%%

%{
	yylloc->step();
%}

MOVE {
	yylloc->step();
	yylval->stringVal = new std::string( yytext, yyleng );
	return token::MOVE;
}

NW {
	yylloc->step();
	yylval->stringVal = new std::string( yytext, yyleng );
	return token::NW;
}

SW {
	yylloc->step();
	yylval->stringVal = new std::string( yytext, yyleng );
	return token::SW;
}

NE {
	yylloc->step();
	yylval->stringVal = new std::string( yytext, yyleng );
	return token::NE;
}

SE {
	yylloc->step();
	yylval->stringVal = new std::string( yytext, yyleng );
	return token::SE;
}

WS {
	yylloc->step();
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


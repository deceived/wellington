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

%%

%{
	yylloc->step();
%}

[0-9]+ {
	yylval->integerVal = atoi( yytext );
	return token::INTEGER;
}

%%

namespace order
{

Scanner::Scanner( std::istream* in, std::ostream* out )
	: WellyFlexLexer( in, out )
{}

Scanner::~Scanner()
{}

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


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
%option yyclass="WellyFlexLexer"
%option outfile="scanner.cpp"
%option nounistd never-interactive noyywrap


%%


%%

Scanner::Scanner( std::istream* in, std::ostream* out )
	: WellyFlexLexer( in, out )
{}

Scanner::~Scanner()
{}

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


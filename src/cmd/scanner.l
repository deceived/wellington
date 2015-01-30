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

INTEGER	[0-9]+
WS      [ \t\r]+ 

MOVE	[MmOoVvEe]
TO		[TtOo]
THE		[TtHhEe]
N		WS[Nn]WS
S		WS[Ss]WS
E		WS[Ee]WS
W		WS[Ww]WS

%%

%{
	yylloc->step();
%}

MOVE {
	yylval->stringVal = new std::string( yytext, yyleng );
	return token::MOVE;
}

TO {
	yylval->stringVal = new std::string( yytext, yyleng );
	return token::TO;
}

THE {
	yylval->stringVal = new std::string( yytext, yyleng );
	return token::THE;
}

N {
	yylval->stringVal = new std::string( yytext, yyleng );
	return token::N;
}

S {
	yylval->stringVal = new std::string( yytext, yyleng );
	return token::S;
}

E {
	yylval->stringVal = new std::string( yytext, yyleng );
	return token::E;
}

W {
	yylval->stringVal = new std::string( yytext, yyleng );
	return token::W;
}

INTEGER {
	yylval->integerVal = atoi( yytext );
	return token::INTEGER;
}

WS {
	yylloc->step();
}

\r {
	yylloc->lines( yyleng );
	yylloc->step();
	return token::EOL;
}

. {
	return static_cast<token_type>( *yytext );
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


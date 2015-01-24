%{

/* build with

   flex flex.l
   gcc lex.yy.c -lfl
   ./a.out

   defaults to copy stdin to stdout - useful to test rules
*/

#include "scanner.h"

%}



%option c++

%option debug

%option stack

%option batch

%option yyclass="WellyFlexLexer"

%option outfile="scanner.cpp" header-file="scanner.hpp"

%option nounistd never-interactive reentrant noyywrap

%option bison-bridge 

PERIOD "."

WS              [ \t\n]+
 
%%

ws          ;

move            { return( MOVE ); }

to              { return( TO ); }
the             { return( THE ); }
towards         { return( TOWARDS ); }
n               { return( N ); }
s               { return( S ); }
w               { return( W ); }
e               { return( E ); }
nw              { return( NW ); }
sw              { return( SW ); }
ne              { return( NE ); }
se              { return( SE ); }
period			{ return( PERIOD ); }

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


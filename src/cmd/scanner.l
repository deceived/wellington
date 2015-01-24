%{

/* build with

   flex flex.l
   gcc lex.yy.c -lfl
   ./a.out

   defaults to copy stdin to stdout - useful to test rules
*/

#include "scan.h"

%}

%option noyywrap

ws              [ \t\n]+
period			[\.]
 
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

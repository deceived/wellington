%{

/* build with

   flex flex.l
   gcc lex.yy.c -lfl
   ./a.out

   defaults to copy stdin to stdout - useful to test rules
*/

#include "scan.h"

%}

word            [a-zA-Z]+
number          [0-9]+
unit            {number}[ \t]+{word}
ws              [ \t\n]+
 
%%

ws          ;

move            { return( MOVE ); }
attack          { return( ATTACK ); }
defend          { return( DEFEND ); }

at              { return( AT ); }
to              { return( TO ); }
the             { return( THE ); }
towards         { return( TOWARDS ); }
for             { return( FOR ); }
m               { return( M ); }
yd              { return( YD ); }
via             { return( VIA ); }
n               { return( N ); }
s               { return( S ); }
w               { return( W ); }
e               { return( E ); }
nw              { return( NW ); }
sw              { return( SW ); }
ne              { return( NE ); }
se              { return( SE ); }
if              { return( IF ); }
inferior        { return( INFERIOR ); }
force           { return( FORCE ); }
encountered     { return( ENCOUNTERED ); }
no              { return( NO ); }
alternative     { return( ALTERNATIVE ); }
attacked        { return( ATTACKED ); }
and             { return( RETURN ); }
retreat         { return( RETREAT ); }

{unit}        { return( UNIT_SPECIFICATION ); }
{word}        { return( WORD ); }


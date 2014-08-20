%{

/* build with

   flex flex.l
   gcc lex.yy.c -lfl
   ./a.out

   defaults to copy stdin to stdout - useful to test rules
*/

#include "scan.h"

%}

word [a-zA-Z]+
number [0-9]+
unit {number}[ \t]+{word}
 
%%

move       { return( MOVE ); }
attack     { return( ATTACK ); }
defend     { return( DEFEND ); }

at            { return( AT ); }
to            { return( TO ); }
towards       { return( TOWARDS ); }
for           { return( FOR ); }
{number}m     { return( M ); }
{number}yd    { return( YD ); }
to[ \t]+the   { return( TO_THE ); }
via           { return( VIA ); }
[ \t]+n[ \t]+   { return( N ); }
[ \t]+s[ \t]+   { return( S ); }
[ \t]+w[ \t]+   { return( W ); }
[ \t]+e[ \t]+   { return( E ); }
[ \t]+nw[ \t]+  { return( NW ); }
[ \t]+sw[ \t]+  { return( SW ); }
[ \t]+ne[ \t]+  { return( NE ); }
[ \t]+se[ \t]+  { return( SE ); }

if[ \t]+inferior[ \t]+force[ \t]+encountered  { return( IF_INFERIOR_FORCE_ENCOUNTERED ); }
if[ \t]+no[ \t]+alternative  { return( IF_NO_ALTERNATIVE ); }
if[ \t]+attacked { return( IF_ATTACKED ); }
and[ \t]+retreat { return( AND_RETREAT ); }

{unit}        { return( UNIT_SPECIFICATION ); }
{word}        { return( LOCATION ); }


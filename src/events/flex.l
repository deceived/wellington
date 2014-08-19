%{

/* build with

   flex flex.l
   gcc lex.yy.c -lfl
   ./a.out

   defaults to copy stdin to stdout - useful to test rules
*/

enum Tokens
{
   MOVE,
   ATTACK,
   TO,
   TO_THE,
   VIA,
   FOR,
   TOWARDS,
   THE,
   N,
   S,
   E,
   W,
   NW,
   NE,
   SW,
   SE,
   M,
   KM,
   IF_INFERIOR_FORCE_ENCOUNTERED,
   IF_NO_ALTERNATIVE,
   AT,
   AND,
   IF_ATTACKED,
   AND_RETREAT,
   DEFEND,
   POSITION,
   LOCATION,
   UNIT_SPECIFICATION
};

%}

WORD [a-zA-Z]+
NUMBER [0-9]+
UNIT {NUMBER}[ \t]+{WORD}
 
%x MOVE
%x ATTACK
%x DEFEND

%%

<INITIAL>move       { BEGIN( MOVE); return( MOVE ); }
<INITIAL>attack     { BEGIN( ATTACK ); return( ATTACK ); }
<INITIAL>defend     { BEGIN( DEFEND ); return( DEFEND ); }

<MOVE>to            { printf( "[move to]" ); return( TO ); }
<MOVE>towards       { printf( "[move towards]" ); return( TOWARDS ); }
<MOVE>for           { printf( "[move for]" ); return( FOR ); }
<MOVE>{NUMBER}km    { printf( "[km]" ); return( KM ); }
<MOVE>{NUMBER}m     { printf( "[m]" ); return( M ); }
<MOVE>to[ \t]+the   { printf( "[to the]" ); return( TO_THE ); }
<MOVE>via           { printf( "[via]" ); return( VIA ); }
<MOVE>{WORD}        { printf( "[location]" ); printf( "%s", yytext ); BEGIN( INITIAL ); return( LOCATION ); }
<MOVE>[ \t]+n[ \t]+   { printf( "[north]" ); return( N ); }
<MOVE>[ \t]+s[ \t]+   { printf( "[south]" ); return( S ); }
<MOVE>[ \t]+w[ \t]+   { printf( "[west]" ); return( W ); }
<MOVE>[ \t]+e[ \t]+   { printf( "[east]" ); return( E ); }
<MOVE>[ \t]+nw[ \t]+  { printf( "[north west]" ); return( NW ); }
<MOVE>[ \t]+sw[ \t]+  { printf( "[south west]" ); return( SW ); }
<MOVE>[ \t]+ne[ \t]+  { printf( "[north east]" ); return( NE ); }
<MOVE>[ \t]+se[ \t]+  { printf( "[south east]" ); return( SE ); }

<ATTACK>if[ \t]+inferior[ \t]+force[ \t]+encountered  { printf( "[inferior force encountered]" ); BEGIN( INITIAL ); return( IF_INFERIOR_FORCE_ENCOUNTERED ); }
<ATTACK>if[ \t]+no[ \t]+alternative  { printf( "[no alternative]" ); BEGIN( INITIAL ); return( IF_NO_ALTERNATIVE ); }
<ATTACK>{UNIT}        { printf( "[unit spec]" ); printf( "%s", yytext ); return( UNIT_SPECIFICATION ); }
<ATTACK>at            { printf( "[at]" ); return( AT ); }
<ATTACK>{WORD}        { printf( "[location]" ); printf( "%s", yytext ); BEGIN( INITIAL ); return( LOCATION ); }

<DEFEND>if[ \t]+attacked { printf( "[if attacked]" ); return( IF_ATTACKED ); }
<DEFEND>and[ \t]+retreat { printf( "[and retreat]" ); return( AND_RETREAT ); }
<DEFEND>at            { printf( "[at]" ); return( AT ); }
<DEFEND>to            { printf( "[to]" ); return( TO ); }
<DEFEND>{WORD}        { printf( "[location]" ); printf( "%s", yytext ); BEGIN( INITIAL ); return( LOCATION ); }


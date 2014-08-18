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
   IF,
   INFERIOR_FORCE_ENCOUNTERED,
   NO_ALTERNATIVE,
   AT,
   AND,
   IF_ATTACKED,
   AND_RETREAT,
   DEFEND,
   POSITION,
   LOCATION
};

%}

WORD [a-zA-Z]+
NUMBER [0-9]+

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
<MOVE>{WORD}        { printf( "[location]" ); printf( "%s", yytext ); return( LOCATION ); }
<MOVE>[ \t]+n[ \t]+   { printf( "[north]" ); return( N ); }
<MOVE>[ \t]+s[ \t]+   { printf( "[south]" ); return( S ); }
<MOVE>[ \t]+w[ \t]+   { printf( "[west]" ); return( W ); }
<MOVE>[ \t]+e[ \t]+   { printf( "[east]" ); return( E ); }
<MOVE>[ \t]+nw[ \t]+  { printf( "[north west]" ); return( NW ); }
<MOVE>[ \t]+sw[ \t]+  { printf( "[south west]" ); return( SW ); }
<MOVE>[ \t]+ne[ \t]+  { printf( "[north east]" ); return( NE ); }
<MOVE>[ \t]+se[ \t]+  { printf( "[south east]" ); return( SE ); }

   /*
<ATTACK>if          { return( IF ); }
<ATTACK>WORD        { return( WORD ); }

<DEFEND>at          { return( AT ); }
<DEFEND>if          { return( IF ); }

via         { return( VIA ); }
for         { return( FOR ); }
towards     { return( TOWARDS ); }
n           { return( N ); }
s           { return( S ); }
w           { return( W ); }
e           { return( E ); }
nw          { return( NW ); }
sw          { return( SW ); }
ne          { return( NE ); }
se          { return( SE ); }
m           { return( M ); }
km          { return( KM ); }
if          { return( IF ); }
at          { return( AT ); }
and         { return( AND ); }
attacked    { return( ATTACKED ); }
retreat     { return( RETREAT ); }
position    { return( POSITION ); }
the         { return( THE ); }
   */

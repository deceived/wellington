%{

enum Tokens
{
   MOVE,
   ATTACK,
   TO,
   VIA,
   FOR,
   TOWARDS,
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
   INFERIOR,
   FORCE,
   ENCOUNTERED,
   NO,
   ALTERNATIVE,
   AT,
   AND,
   ATTACKED,
   RETREAT,
   DEFEND,
   POSITION
};

%}

WORD [a-zA-Z]+
NUMBER [0-9]+

%%

move    { return( MOVE ); }
attack  { return( ATTACK ); }
to      { return( TO ); }
via     { return( VIA ); }
for     { return( FOR ); }
towards { return( TOWARDS ); }
n       { return( N ); }
s       { return( S ); }
w       { return( W ); }
e       { return( E ); }
nw      { return( NW ); }
sw      { return( SW ); }
ne      { return( NE ); }
se      { return( SE ); }
m       { return( M ); }
km      { return( KM ); }
if      { return( IF ); }
inferior    { return( INFERIOR ); }
force       { return( FORCE ); }
encountered { return( ENCOUNTERED ); }
no          { return( NO ); }
alternative { return( ALTERNATIVE ); }
at          { return( AT ); }
and         { return( AND ); }
attacked    { return( ATTACKED ); }
retreat     { return( RETREAT ); }
defend      { return( DEFEND ); }
position    { return( POSITION ); }


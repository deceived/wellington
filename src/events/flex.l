%{

enum Tokens
{
   MOVE,
   ATTACK,
   TO,
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

%x MOVE
%x ATTACK
%x DEFEND

%%

<INITIAL>move       { BEGIN( MOVE); return( MOVE ); }
<INITIAL>attack     { BEGIN( ATTACK ); return( ATTACK ); }
<INITIAL>defend     { BEGIN( DEFEND ); return( DEFEND ); }

<MOVE>to            { return( TO ); }
<MOVE>towards       { return( TOWARDS ); }
<MOVE>for           { return( FOR ); }

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
inferior    { return( INFERIOR ); }
force       { return( FORCE ); }
encountered { return( ENCOUNTERED ); }
no          { return( NO ); }
alternative { return( ALTERNATIVE ); }
at          { return( AT ); }
and         { return( AND ); }
attacked    { return( ATTACKED ); }
retreat     { return( RETREAT ); }
position    { return( POSITION ); }
the         { return( THE ); }


%{

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


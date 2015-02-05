
%option c++
%option debug
%option stack
%option batch
%option prefix="Welly"
%option outfile="scanner.cpp"
%option yywrap nounput

WS      [ \t\r\n]+ 
PERIOD	.
WORD	[a-zA-Z]+
INTEGER	[0-9]+
DOUBLE	[0-9]+"."[0-9]+	

%%

INTEGER  ;

DOUBLE  ;

WORD  ;

PERIOD  ;

WS  ;

%%
/***
namespace order
{

Scanner::Scanner( std::istream* in, std::ostream* out )
	: WellyFlexLexer( in, out )
{}

Scanner::~Scanner()
{}

void Scanner::set_debug( bool flag )
{
	yy_flex_debug = flag;
}

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
***/

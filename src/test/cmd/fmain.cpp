#include <iostream>
#include <FlexLexer.h>

int main(int arc, char** argv)
{
	yyFlexLexer* scanner = new yyFlexLexer;

	while( scanner->yylex() != 0 )
		;

	return 0;
}

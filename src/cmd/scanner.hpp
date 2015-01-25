#ifndef SCANNER_HPP
#define SCANNER_HPP

#ifndef YY_DECL

#define	YY_DECL									\
    	order::Parser::token_type				\
    	order::Scanner::lex(					\
		order::Parser::semantic_type* yylval,	\
		order::Parser::location_type* yylloc	\
    )

#endif

#ifndef __FLEX_LEXER_H
#define yyFlexLexer WellyFlexLexer
#include "FlexLexer.h"
#undef yyFlexLexer
#endif

#include "parser.hpp"

namespace order {

class Scanner : public WellyFlexLexer
{

public:

	Scanner(std::istream* arg_yyin = 0,
	    	std::ostream* arg_yyout = 0);

	virtual ~Scanner();

	virtual Parser::token_type lex(
			Parser::semantic_type* yylval,
			Parser::location_type* yylloc
			);

};

}

#endif


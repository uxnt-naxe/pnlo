/*
#ifndef SOURCE_SHARE_H_
#define SOURCE_SHARE_H_

#define ERR -2 // error
#define EPS -1 // non-string
#define SNULL 0
#define DATAMAXLEN 10

enum STokenType {
	EOL,     // end of the line
	NUM,     // number
	//KEYWORD,
	WORD,
	SYMA,    // symbol of add and sub
	SYMM,    // symbol of mul and division
	//SYMBL,  // symbol of left bracket
	//SYMBR, // symbol of right bracket
	//SYMAS, // symbol of assignment
	//SPLIT, // other
	STTCUR   // SToken of type's count.
};

enum SNonTerm {
	S = STTCUR, // begin symbol
	AE,         // add and sub's exp
	AEE,        // AE'
	ME,         // mul and div's exp
	MEE,        // ME'
	E,          // exp
	SACUR       // SToken of type's count and SNonTerm of type's count.
};

#endif // SOURCE_SHARE_H_
*/
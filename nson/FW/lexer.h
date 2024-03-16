#include<string.h>
#include <iostream>
#include "Utf8.h"
using namespace std;
void lexer(i18nString code);


enum K_TokenType {
	EOL,
	STRING,
	WORD,
	VALUE,
	STTCUR
};
 

struct K_Token {

	//int row;
	//int line;
	//int type;
	//char* value;

	K_TokenType* type;

	char* value;
	// Sstring* data;
};

struct K_TokenList
{
	K_Token tlist[1024];
	int cur;
};






//  type = value;




typedef struct
{
	int row;
	int line;
	int type;
	char* value;
}QToken;

typedef struct
{
	int row;
	int line;
	char* info;
}QLexerErr;

typedef struct
{
	QToken tlist[4096];
	int cur;
}QTokenList;
enum
{
	TT_NUM = 1,
	TT_KEYWORD,
	TT_WORD,
	TT_SYMBOL,
	TT_SPLIT
};

//char* tlist_keyword[4] = { "","","","" };

QLexerErr* QLexerMake(char* codes, QTokenList* re);
// Tiny-C-Plus, lexer.cpp
// 2023-10-20 <20:50>
// 豆焰 <beanflame>
#include <iostream>
#include "Utf8.h"

#include "Windows.h"
using namespace std;




/*
enum xPnloTokenType {

    token_identifier,
    token_string,

    token_integer,       // 整数
    token_float,         // 小数

    token_false,         // false 假
    token_true,          // true 真
    token_null,          // null 空白

    token_equal_sign,    // = 等号
    token_semicolon,     // ; 分号

    token_greater_than,  // >
    token_tilde,         // ~

    token_end

};
*/


template<class T>
int getLength(T& arr) { return sizeof(arr) / sizeof(arr[0]); }










typedef struct
{
    int type;
    char* value;
}Token;




typedef struct
{
    Token tlist[4096];
    int cur;
}TokenList;


enum tokenType
{
    T_NULL = 0,
    TT_NUM,
    TT_KEYWORD,
    TT_WORD,
    TT_SYMBOL,
    TT_SPLIT
};


// NULL -> x
// ASS  -> '='
// SPA  -> ' ' | '\t' | '\n'  -> skip
// 









i18nString keywordTable[] = {
    L"import",
    L"print",
    L"int",
    L"fun", L"main", L"ret",
    L"result"
};




// line(0), row(0)




int isKeyWord(i18nString token) {
    for (int i = 0; i < getLength(keywordTable); i++) {
        if (token == keywordTable[i]) {
            return true;
        }
    }
    return false;
}

bool isEnglish(i18nChar ch) {
    if ((ch >= L'a' && ch <= L'z') || (ch >= L'A' && ch <= L'Z')) { return true; }
    else { return false; }
}

bool isChinese(i18nChar ch) {
    if ((ch >= L'一' && ch <= L'龥')) { return true; }
    else { return false; }
}

bool isText(i18nChar ch) {
    if (isEnglish(ch) || isChinese(ch)) { return true; }
    else { return false; }
}

bool isNum(i18nChar ch)
{
    if (ch >= L'0' && ch <= L'9') { return true; }
    else { return false; }
}






// ch = Text[stlPos];
// wcout << ch;
// stlPos++;
// 词法分析器 Lexer Token


void lexer(i18nString code) {
    i18nString token = L"";
    int stlPos = 0;
    i18nChar ch;

    wcout << token << L" <数学>" << endl;

    while (stlPos < code.length()) {
        ch = code[stlPos];

        
        if (code[stlPos] == '\n') {

        }
       
        else if (ch == L'/') {
            stlPos++;
            ch = code[stlPos];
            if (ch == L'/') {
                stlPos++;
                ch = code[stlPos];
                while (ch != 0 && ch != L'\n') {
                    token += ch;
                    stlPos++;
                    ch = code[stlPos];
                }
                wcout << token << L" <注释>" << endl;
                token = L"";
            }
            }
        else if (ch == L'=') {
            token += ch;
            stlPos++;
            ch = code[stlPos];

            wcout << token << L" <数学>" << endl;
            token = L"";
        }


        else {
            // wcout << ch;
            stlPos++;
        }
    }



    // wprintf(L"代码行:%d\n", line);


    // "xxxxx" -> value
    // = 
    // 30、"Jkol、wopax、刃瑞" -> value
    // ; -> END


    // "inmo" = "oeqnx";
    // "lop qwex" = 30;
    // "loiax" = "忍段"

    
    //i18nString token = L"";
    //i18nChar ch;

    /*
    int pos, line, row;
    pos = 0, line = 1, row = 0;

    while (pos < code.length()) {

        wcout << code[pos] <<"["<< line << ", " << row << "]" << endl;

        if (code[pos] == '\n') { // is enter.
            line++; row = 1;
        }
        row++;
        pos++;
    }
    wprintf(L"代码行:%d\n",line);
    */
}



void EEElexer(i18nString Text) {
    i18nString token = L"";
    int stlPos = 0;
    i18nChar ch;

    while (stlPos < Text.length()) {
        ch = Text[stlPos];

        if (isText(ch)) {
            while (isText(ch)) {
                token += ch;
                stlPos++;
                ch = Text[stlPos];
            }
            if (isKeyWord(token)) {
                wcout << token << " <identifier>" << endl;
                token = L"";
            }
            else {
                wcout << token << " <name>" << endl;
                token = L"";
            }
        }

        else if (ch == L'=') {
            token += ch;
            stlPos++;
            ch = Text[stlPos];

            wcout << token << L" <数学>" << endl;
            token = L"";
        }

        else if (ch == L';') {
            token += ch;
            stlPos++;
            ch = Text[stlPos];
            
            wcout << token << L" <数学>" << endl;
            token = L"";
        }

        else if (ch == L'/') {
            stlPos++;
            ch = Text[stlPos];
            if (ch == L'/') {
                stlPos++;
                ch = Text[stlPos];
                while (ch != 0 && ch != L'\n') {
                    token += ch;
                    stlPos++;
                    ch = Text[stlPos];
                }
                // wcout << token << L" <注释>" << endl;
                token = L"";
            }
        }


        else if (ch == L'\"') {
            stlPos++;
            ch = Text[stlPos];
            while (ch != 0 && ch != L'\"') {
                token += ch;
                stlPos++;
                ch = Text[stlPos];
            }
            wcout << token << L" <字符串>" << endl;
            token = L"";
            stlPos++;
        }


        else if (isNum(ch)) {
            while (isNum(ch) || (ch == L'.')) {
                token += ch;
                stlPos++;
                ch = Text[stlPos];
            }
            wcout << token << L" <数学>" << endl;
            token = L"";
        }

        else if (ch == L'\'') {
            stlPos++;
            ch = Text[stlPos];
            while (ch != 0 && ch != L'\'') {
                token += ch;
                stlPos++;
                ch = Text[stlPos];
            }
            wcout << token << L" <字符>" << endl;
            token = L"";
            stlPos++;
        }
         



        else {
            // wcout << ch;
            stlPos++;
        }
        Sleep(100);
    }
}



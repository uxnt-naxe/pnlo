#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>




class Lexer
{
private:
    std::string input;
    int position;
public:

        // token_type
    enum TokenType {
            // EOF        
            value_identifier,    // 标识符 azAZ09_
            value_string,        // 字符串
            value_number,        // 数字
            value_true,          // true
            value_false,         // false
            value_null,          // null

            value_integer,
            value_float,


            name_ass, // "="   name_separator

            TOKEN_SEM, // ";"

            // TOKEN_WS,   // [ \t\n\r]+ -> skip

            begin_object,  // >
            end_object,  // ~

            TOKEN_END  // !
        };

    struct Token {
        TokenType type;
        std::string value;
        Token() {}
        Token(TokenType t, const std::string &v) : type(t), value(v) {}
    };

    std::vector<Token> tokenList;



    Lexer(const std::string &text) : input(text), position(0) {}

    char getNextChar();
    void Next();
    void skipWhitespace();

    std::string get_value_identifier();
    std::string get_value_string();
    std::string get_value_number();

    Token getNextToken();

};



// std::map<std::string, Token> varMap = paser(tokenList);
// varMap["这里是varName"] = > 这个就是value 的token，如果要知道它的值，只要加.data就可以输出std::string类型的了
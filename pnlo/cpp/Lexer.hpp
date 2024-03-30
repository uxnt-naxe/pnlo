#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

#include "token/token.hpp"

class Lexer
{
    private:
        std::string input;
        int position;
    public:
        // token_type
        // std::vector<Token> tokenList;

        Lexer(const std::string &text) : input(text), position(0) {}
        ~Lexer(){}
        
        char getNextChar();
        void Next();
        void skipWhitespace();

        std::string get_value_identifier();
        std::string get_value_string();
        std::string get_value_integer();
        std::string get_value_float();

        std::string get_value_number();

        Token getNextToken();

};



// std::map<std::string, Token> varMap = paser(tokenList);
// varMap["这里是varName"] = > 这个就是value 的token，如果要知道它的值，只要加.data就可以输出std::string类型的了
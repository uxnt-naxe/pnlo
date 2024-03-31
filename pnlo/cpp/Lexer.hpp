#ifndef Lexer_h
#define Lexer_h

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include "token/token.hpp"





class Lexer
{
    private:
        std::string m_str;
        int m_idx;
    public:
        Lexer(const std::string &str) : m_str(str), m_idx(0) {}
        ~Lexer(){}
        
        char next_ch();
        void next();
        void next_skipWhitespace();
        void next_comments();
        
        std::string scan_identifier();
        std::string scan_string();
        std::string scan_integer();
        std::string scan_float();
        std::string scan_bool();
        std::string scan_number();
        // std::string scan_string(std::string str);
        token next_token();
};

#endif

// std::map<std::string, Token> varMap = paser(tokenList);
// varMap["这里是varName"] = > 这个就是value 的token，如果要知道它的值，只要加.data就可以输出std::string类型的了
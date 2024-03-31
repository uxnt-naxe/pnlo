#ifndef Parser_h
#define Parser_h

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

#include "Token/token.hpp"

/*

    pnlo
        obj
        kay
        arr
        value

*/

class Parser
{
    public:
    Parser();
        // std::vector<Token> tokenList
        // std::vector<Token> tokenList;

        
        std::map<std::string, token> parser(std::vector<token> tokenList);
        // ~Parser(){}
};


// std::map<std::string, Token> paser(std::vector<Token> tokenList)

#endif




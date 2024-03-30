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

#ifndef Parser_H
#define Parser_H

class Parser
{
    
    public:
        // std::vector<Token> tokenList
        // std::vector<Token> tokenList;

        Parser();
        std::map<std::string, Token> parser(std::vector<Token> tokenList);
        // ~Parser(){}
};


// std::map<std::string, Token> paser(std::vector<Token> tokenList)

#endif
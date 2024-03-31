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

#ifndef Parser_h
#define Parser_h

class Parser
{
    
    public:
        // std::vector<Token> tokenList
        // std::vector<Token> tokenList;

        Parser();
        std::map<std::string, token> parser(std::vector<token> tokenList);
        // ~Parser(){}
};


// std::map<std::string, Token> paser(std::vector<Token> tokenList)

#endif
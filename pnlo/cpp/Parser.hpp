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
private:
    std::vector<token> TL;
    int ti = 0;

public:
    Parser();
    ~Parser();
        // std::vector<Token> tokenList
        // std::vector<Token> tokenList;

    std::map<std::string, token> parser(std::vector<token> TL); //tokenList
        
};


// std::map<std::string, Token> paser(std::vector<Token> tokenList)

#endif




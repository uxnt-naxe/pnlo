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
        // std::vector<Token> tokenList
        std::vector<Token> tokenList;

        Parser(std::vector<Token> tokenList){}
        std::map<std::string, Token> Rawxxx(std::vector<Token> tokenList) {}

        // ~Parser(){}
};


// std::map<std::string, Token> paser(std::vector<Token> tokenList)
// {
//     
// }


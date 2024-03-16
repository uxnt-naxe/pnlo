#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

#include "nson.hpp"
#include "NeonFile.hpp"


int main() {

    Neon::File ojb = Neon::File("text.pnlo");

    std::string input = ojb.Read();

    Lexer lexer = Lexer(input);

    Token token = lexer.getNextToken();

    while (token.type != TOKEN_END) {
        tokenList.push_back(token);
        // std::cout << "Token: " << token.value << ", Type: " << token.type << std::endl;
        token = lexer.getNextToken();
    }
    
    tokenList.push_back(token);
    std::map<std::string, Token> getValue = paser(tokenList);


    std::cout << "Object1:" << getValue["Object1"].value << std::endl;
    std::cout << "Object2:" << getValue["Object2"].value << std::endl;
    std::cout << "Object3:" << getValue["Object3"].value << std::endl;
    std::cout << "Object4:" << getValue["Object4"].value << std::endl;
    std::cout << "6exp6:" << getValue["6exp6"].value << std::endl;


    // std::cout << Nopt["hello"].value << std::endl;

    return 0;
}



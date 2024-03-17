#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

#include "NeonFile.hpp"

#include "pnlo.hpp"



int main() {

    // pnlo obj = parse("qwe");
    // pnlo obj = pnlo("text.pnlo");
    // printf("%s", obj["Hello"]["Eloa"]);

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
    std::map<std::string, Token> Her = paser(tokenList);


    std::cout << "Object1:" << Her["Object1"].value << std::endl;
    std::cout << "Object2:" << Her["Object2"].value << std::endl;
    std::cout << "Object3:" << Her["Object3"].value << std::endl;
    std::cout << "Object4:" << Her["Object4"].value << std::endl;
    std::cout << "6exp6:" << Her["6exp6"].value << std::endl;


    // std::cout << Nopt["hello"].value << std::endl;

    return 0;
}



#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

#include "NeonFile.hpp"
#include "pnlo.hpp"

int main()
{
    // pnlo obj = parse("qwe");
    // pnlo obj = pnlo("text.pnlo");
    // printf("%s", obj["Hello"]["Eloa"]);

    Neon::File ojb = Neon::File("text.otne");
    std::string input = ojb.Read();
    
    Lexer lexer = Lexer(input);

    token _token = lexer.next_token();

    std::vector<token> tokenList;

    while (_token.type != token_end)
    {
        // lexer.tokenList.push_back(token);
        tokenList.push_back(_token);
        // std::cout << "Token: " <<"\"" << token.value << "\"" << ", Type: " << token.type << std::endl;
        _token = lexer.next_token();
    }

    Parser rarser = Parser();
    std::map<std::string, token> obj = rarser.parser(tokenList);

        // Lexer > Parser > 

        // Pnlo laop = laop.parser(input);
        // std::cout << "Pnlo Pnlo:" << laop["Pnlo"] << std::endl;
        // std::cout << Nopt["hello"].value << std::endl;

    std::cout << "Pnlo:" << obj["Pnlo"].value << std::endl;
    std::cout << "version:" << obj["version"].value << std::endl;
    std::cout << "Object1:" << obj["Object1"].value << std::endl;
    std::cout << "Object2:" << obj["Object2"].value << std::endl;
    std::cout << "Object3:" << obj["Object3"].value << std::endl;
    std::cout << "Object4:" << obj["Object4"].value << std::endl;
    std::cout << "main_obj_:" << obj["main_obj_"].value << std::endl;
    std::cout << "Time:" << obj["Time"].value << std::endl;
    std::cout << "OFF:" << obj["OFF"].value << std::endl;
    std::cout << "ON:" << obj["ON"].value << std::endl;
    






    return 0;
}

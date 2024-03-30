// 空白
#include "Parser.hpp"
#include "Token/token.hpp"


Parser::Parser() {

}

std::map<std::string, Token> Parser::parser(std::vector<Token> tokenList) {

    std::map<std::string, Token> varMap;

    // for (int i = 0; i < tokenList.size(); i++) {
    int i = 0;
    while (true)
    {

        if (
            tokenList[i].type != token_string &&
            tokenList[i].type != token_identifier
         )
            break; // 识别并储存varName
        std::string varName = tokenList[i].value;

        i++; // 下一个token
        if (tokenList[i].type != token_equal && tokenList[i].type != token_colon)
            break; // 识别"="
        i++;       // 下一个token
        if (
            tokenList[i].type != token_string && 
            tokenList[i].type != token_identifier && 
            tokenList[i].type != token_false && 
            tokenList[i].type != token_true && 
            tokenList[i].type != token_null && 
            tokenList[i].type != token_integer
            )
            break; // 识别并将varName和它的值一起存到map里
        varMap[varName] = tokenList[i];
        i++;
        if (tokenList[i].type != token_semicolon)
            break; // 识别";"
        i++;
        if (tokenList[i].type == token_end)
            break;
        // i++;
    }
    return varMap;
}
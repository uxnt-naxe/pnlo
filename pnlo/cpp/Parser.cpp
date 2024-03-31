// 空白
#include "Parser.hpp"
#include "Token/token.hpp"


Parser::Parser() {}
Parser::~Parser() {}



std::map<std::string, token> Parser::parser(std::vector<token> TL) {

    std::map<std::string, token> varMap;

    // for (int i = 0; i < tokenList.size(); i++) {
    int i = 0 ;

    while (true) {
        if (
            TL[i].type != id_string &&
            TL[i].type != id_identifier
            )
            break; // 识别并储存varName
        std::string varName = TL[i].value;
        i++; // 下一个token
        if (TL[i].type != symbol_equal && TL[i].type != symbol_colon)
            break; // 识别"="
        i++;       // 下一个token
        if (
            TL[i].type != id_string && 
            TL[i].type != id_identifier && 
            TL[i].type != v_false && 
            TL[i].type != v_true && 
            TL[i].type != v_null && 
            TL[i].type != v_int
            )
            break; // 识别并将varName和它的值一起存到map里
        varMap[varName] = TL[i];
        i++;
        if (TL[i].type != symbol_semicolon)
            break; // 识别";"
        i++;
        if (TL[i].type == token_end)
            break;
        // i++;
    }
    return varMap;
}
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

class Parse
{
    
};

std::map<std::string, Token> paser(std::vector<Token> tokenList)
{
    std::map<std::string, Token> varMap;

    // for (int i = 0; i < tokenList.size(); i++) {
    int i = 0;
    while (true)
    {

        if (tokenList[i].type != TOKEN_STR && tokenList[i].type != TOKEN_IDN)
            break; // 识别并储存varName
        std::string varName = tokenList[i].value;

        i++; // 下一个token
        if (tokenList[i].type != TOKEN_ASS)
            break; // 识别"="
        i++;       // 下一个token
        if (tokenList[i].type != TOKEN_STR && tokenList[i].type != TOKEN_IDN && tokenList[i].type != TOKEN_NUM)
            break; // 识别并将varName和它的值一起存到map里
        varMap[varName] = tokenList[i];
        i++;
        if (tokenList[i].type != TOKEN_SEM)
            break; // 识别";"
        i++;
        if (tokenList[i].type == TOKEN_END)
            break;
        // i++;
    }
    return varMap;
}
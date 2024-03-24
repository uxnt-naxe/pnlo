#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

#include "Token.hpp"


bool isDigit(char str) {
    if (str >= '0' && str <= '9') { return true; }
    return false;
}
bool isAlpha(char str) {
    if ((str >= 'A' && str <= 'Z') || (str >= 'a' && str <= 'z')) { return true; }
    return false;
}
bool isLetter(char str) {
    if (isAlpha(str) || isDigit(str) || str == '_') { return true; }
    return false;
}

// -------------------------------------------------------------------------------------------
// string





std::vector<Token> tokenList;





class Lexer
{
private:
    std::string input;
    int position;
public:
    Lexer(const std::string &text) : input(text), position(0) {}

    char currentChar() {
        if (position >= input.length()) {
            return '\0';
        }
        return input[position];
    }

    void advance() {
        position++;
    }

    void skipWhitespace() {
        while (currentChar() != '\0' && isspace(currentChar())) {
            advance();
        }
    }

    std::string get_value_identifier() {
        std::string identifier = "";
        while (isLetter(currentChar())) {
            identifier += currentChar();
            advance();
        }
        return identifier;
    }

    std::string get_value_string() {
        // 解析双引号内的字符串
        std::string value_string = "";
        advance(); // 跳过第一个双引号
        while (currentChar() != '\0' && currentChar() != '\"') {
            value_string += currentChar();
            advance();
        }
        advance(); // 跳过最后一个双引号
        return value_string;
    }
    
    std::string get_value_number() {
        std::string result = "";
        bool hasDecimal = false;
        bool isNegative = false;
        bool hasExponent = false;
        bool hasExponentSign = false;

        if (currentChar() == '-') {
            isNegative = true;
            result += "-";
            advance();
        }
        else if (currentChar() == '+') {
            advance();
        }
        while (currentChar() != '\0' && (isDigit(currentChar()) || currentChar() == '.' || currentChar() == 'e' || currentChar() == 'E' || currentChar() == '+' || currentChar() == '-')) {
            if (currentChar() == '.') {
                if (hasDecimal) {
                    break;
                }
                hasDecimal = true;
            }
            else if (currentChar() == 'e' || currentChar() == 'E') {
                if (hasExponent) {
                    break;
                }
                hasExponent = true;
            }
            else if ((currentChar() == '+' || currentChar() == '-') && hasExponent && !hasExponentSign) {
                hasExponentSign = true;
            }
            else if (!isDigit(currentChar())) {
                break;
            }
            result += currentChar();
            advance();
        }
        // 检查结果是否是一个有效数字
        if (result.empty() || (hasDecimal && result.size() == 1) || (hasExponent && (result.size() == 1 || hasExponentSign || !isDigit(result.back())))) {
            std::cerr << "Invalid number!" << std::endl;
            exit(1);
        }
        return result;
    }

    Token getNextToken() {
        while (currentChar() != '\0') {
            if (isspace(currentChar())) {
                skipWhitespace();
                continue;
            }
            else if (isLetter(currentChar())) {
                return Token(value_identifier, get_value_identifier());
            }
            else if (currentChar() == '\"') {
                return Token(value_string, get_value_string());
            }

          


            else if (isDigit(currentChar()) || currentChar() == '.' || currentChar() == '+' || currentChar() == '-') {
                return Token(value_number, get_value_number());
            }
            else if (currentChar() == '/') {
                advance();
                if (currentChar() == '/') {
                    advance();
                    // 跳过双斜线注释内容
                    while (currentChar() != '\0' && currentChar() != '\n') {
                        advance();
                    }
                    continue; // 继续解析下一个Token
                }
                else {
                    std::cerr << "Error: Invalid Character" << std::endl;
                    exit(1);
                }
            }
            


            







            switch (currentChar()) {
                case '>':
                    advance();
                    return Token(begin_object, ">");
                case '~':
                    advance();
                    return Token(end_object, "~");
                case '=':
                    advance();
                    return Token(name_ass, "=");
                case ';':
                    advance();
                    return Token(TOKEN_SEM, ";");
                default:
                    std::cerr << "Error: Invalid Character" << std::endl;
                    exit(1);
            }
        }
        return Token(TOKEN_END, "");
    }
};

// std::map<std::string, Token> varMap = paser(tokenList);
// varMap["这里是varName"] = > 这个就是value 的token，如果要知道它的值，只要加.data就可以输出std::string类型的了
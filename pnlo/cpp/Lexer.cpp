#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

#include "Lexer.hpp"

bool isDigit(char str) {
    if (str >= '0' && str <= '9') { return true; }
    return false;
}
bool isAlpha(char str) {
    if ((str >= 'A' && str <= 'Z') || (str >= 'a' && str <= 'z')) { return true; }
    return false;
}


// bool isLetter(char str) {
//     if (isAlpha(str) || str == '_') { return true; }
//     // if (isAlpha(str) || isDigit(str) || str == '_') { return true; }
//     return false;
// }



// -------------------------------------------------------------------------------------------
// string

    // getNextChar
    char Lexer::getNextChar() {
        if (position >= input.length()) {
            return '\0';
        }
        return input[position];
    }


    // Next
    void Lexer::Next() {
        position++;
    }


    void Lexer::skipWhitespace() {
        while (getNextChar() != '\0' && isspace(getNextChar())) {
            Next();
        }
    }

    // get_value_identifier isLetter
    std::string Lexer::get_value_identifier() {
        std::string value_identifier = "";
        while (
            isAlpha(getNextChar()) || 
            getNextChar() == '_' || 
            isDigit(getNextChar()) 
            ) {
            value_identifier += getNextChar();
            Next();
        }
        return value_identifier;
    }

    // get_value_string
    std::string Lexer::get_value_string() {
        // 解析双引号内的字符串
        std::string value_string = "";
        Next(); // 跳过第一个双引号
        while (getNextChar() != '\0' && getNextChar() != '\"') {
            value_string += getNextChar();
            Next();
        }
        Next(); // 跳过最后一个双引号
        return value_string;
    }

    // get_value_integer
    std::string Lexer::get_value_integer() {
        std::string value_integer = "";
        while (isDigit(getNextChar())) {
            value_integer += getNextChar();
            Next();
        }
        return value_integer;
    }



    // get_value_number
    std::string Lexer::get_value_number() {
        std::string result = "";
        bool hasDecimal = false;
        bool isNegative = false;
        bool hasExponent = false;
        bool hasExponentSign = false;

        if (getNextChar() == '-') {
            isNegative = true;
            result += "-";
            Next();
        }
        else if (getNextChar() == '+') {
            Next();
        }

        while (
            getNextChar() != '\0' && 
            (isDigit(getNextChar()) || 
            getNextChar() == '.' || 
            getNextChar() == 'e' ||  getNextChar() == 'E' || 
            getNextChar() == '+' ||  getNextChar() == '-')
            ) {
            if (getNextChar() == '.') {
                if (hasDecimal) {
                    
                    break;
                }
                hasDecimal = true;
            }
            else if (getNextChar() == 'e' || getNextChar() == 'E') {
                if (hasExponent) {
                    break;
                }
                hasExponent = true;
            }
            else if ((getNextChar() == '+' || getNextChar() == '-') && hasExponent && !hasExponentSign) {
                hasExponentSign = true;
            }
            else if (!isDigit(getNextChar())) {
                break;
            }
            result += getNextChar();
            Next();
        }
        
        // 检查结果是否是一个有效数字
        if (result.empty() || (hasDecimal && result.size() == 1) || (hasExponent && (result.size() == 1 || hasExponentSign || !isDigit(result.back())))) {
            std::cerr << "Invalid number!" << std::endl;
            exit(1);
        }
        return result;
    }

    // Lexer::Token Lexer::getNextToken() {
    Token Lexer::getNextToken() {
        while (getNextChar() != '\0') {
            if (isspace(getNextChar())) {
                skipWhitespace();
                continue;
            }

            else if (isAlpha(getNextChar()) || getNextChar() == '_') {
                std::string v = get_value_identifier();
                if (v == "false") {
                    return Token(token_false, "false");
                } else if(v == "true"){
                    return Token(token_true, "true");
                } else if(v == "null"){
                    return Token(token_null, "null");
                }
                return Token(token_identifier, v);
            }
            else if (getNextChar() == '\"') {
                return Token(token_string, get_value_string());
            }


            else if (
                isDigit(getNextChar()) || 
                getNextChar() == '.'  || 
                getNextChar() == '+' || 
                getNextChar() == '-') {
                std::string v = get_value_number();
                return Token(token_integer, v);
            }



            else if (getNextChar() == '/') {
                Next();
                if (getNextChar() == '/') {
                    Next();
                    // 跳过双斜线注释内容
                    while (getNextChar() != '\0' && getNextChar() != '\n') {
                        Next();
                    }
                    continue; // 继续解析下一个Token
                }
                else {
                    std::cerr << "Error: Invalid Character" << std::endl;
                    exit(1);
                }
            } else {
                switch (getNextChar()) {

                    case '=':
                        Next();
                        return Token(token_equal, "=");
                    case ':':
                        Next();
                        return Token(token_colon, ":");    
                    case ';':
                        Next();
                        return Token(token_semicolon, ";");

                    case '<':
                        Next();
                        return Token(token_less_than, "<");
                    case '>':
                        Next();
                        return Token(token_greater_than, ">");
                    
                    case '[':
                        Next();
                        return Token(token_left_bracket, "[");
                    case ']':
                        Next();
                        return Token(token_right_bracket, "]");

                    case ',':
                        Next();
                        return Token(token_comma, ",");
                    case '~':
                        Next();
                        return Token(token_tilde, "~");

                    default:
                        std::cerr << "Error: Invalid Character" << std::endl;
                        exit(1);
                }

            }
            
            


            
        }
        return Token(token_end, "");
    }
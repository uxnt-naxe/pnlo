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


char Lexer::next_ch() {
    if (m_idx >= m_str.length()) {
        return '\0';
    }
    return m_str[m_idx];
}

void Lexer::next() { 
    m_idx++; 
}

void Lexer::next_skipWhitespace() {
    while (
        next_ch() != '\0' && 
        isspace(next_ch())
        ){
        next();
    }
}

std::string Lexer::scan_identifier() {
    std::string str = "";
    while (
        isAlpha(next_ch()) || 
        next_ch() == '_' || 
        isDigit(next_ch()) 
        ){
        str += next_ch();
        next();
    }
    return str;
}

std::string Lexer::scan_string() {
    std::string str = "";
    next();
    while (
        next_ch() != '\0' &&
        next_ch() != '\"'
        ){
        str += next_ch();
        next();
    }
    next();
    return str;
}

// std::string Lexer::scan_string(std::string str) {
//     // value_string += getNextChar();
//     // Next();
//     std::string str_ = "";
//     next();
//     char ch = next_ch();
//     while (ch != '\0' && ch != '\"') {
//         str_ += ch;
//         next();
//     }
//     next();
//     return str_;
// }   

std::string Lexer::scan_integer() {
    std::string str = "";
    while (isDigit(next_ch())) {
        str += next_ch();
        next();
    }
    return str;
}




    // get_value_number
    std::string Lexer::scan_number() {
        std::string str = "";
        bool hasDecimal = false;
        bool isNegative = false;
        bool hasExponent = false;
        bool hasExponentSign = false;

        if (next_ch() == '-') {
            isNegative = true;
            str += "-";
            next();
        }
        else if (next_ch() == '+') {
            next();
        }

        while (
            next_ch() != '\0' && 
            (isDigit(next_ch()) || 
            next_ch() == '.' || 
            next_ch() == 'e' ||  next_ch() == 'E' || 
            next_ch() == '+' ||  next_ch() == '-')
            ) {
            if (next_ch() == '.') {
                if (hasDecimal) {
                    
                    break;
                }
                hasDecimal = true;
            }
            else if (next_ch() == 'e' || next_ch() == 'E') {
                if (hasExponent) {
                    break;
                }
                hasExponent = true;
            }
            else if ((next_ch() == '+' || next_ch() == '-') && hasExponent && !hasExponentSign) {
                hasExponentSign = true;
            }
            else if (!isDigit(next_ch())) {
                break;
            }
            str += next_ch();
            next();
        }
        
        // 检查结果是否是一个有效数字
        if (
            str.empty() || 
            (hasDecimal && str.size() == 1) || 
            (
                hasExponent && (str.size() == 1 || 
                hasExponentSign || 
                !isDigit(str.back()))
                )
            ){
            std::cerr << "Invalid number!" << std::endl;
            exit(1);
        }
        return str;
    }

   


    token Lexer::next_token() {
        while (next_ch() != '\0') {
            if (
                isspace(next_ch())
                ){
                next_skipWhitespace();
                continue;
            } else if (
                isAlpha(next_ch()) || 
                next_ch() == '_'
                ){
                std::string str = scan_identifier();
                if( str == "true" ){ return token(v_true, str);
                } else if (
                    str == "false" ){ return token(v_false, str);
                } else if (
                    str == "null" ){ return token(v_null, str);
                }
                return token(id_identifier, str);
            } else if (
                next_ch() == '\"'
                ){
                return token(id_string, scan_string());
            } else if (
                isDigit(next_ch()) || 
                next_ch() == '.'  || 
                next_ch() == '+' || 
                next_ch() == '-'
                ){
                std::string vint = scan_number();
                return token(v_int, vint);
            } else if (
                next_ch() == '/'
                ){
                next();
                if (next_ch() == '/') {
                    next();
                    // 跳过双斜线注释内容
                    while (next_ch() != '\0' && next_ch() != '\n') {
                        next();
                    }
                    continue; // 继续解析下一个Token
                }
                else {
                    std::cerr << "Error: Invalid Character" << std::endl;
                    exit(1);
                }
            } else {
                switch (next_ch()) {
                    case '=':
                        next();
                        return token(token_equal, "=");
                    case ':':
                        next();
                        return token(token_colon, ":");    
                    case ';':
                        next();
                        return token(token_semicolon, ";");
                    case '<':
                        next();
                        return token(token_less_than, "<");
                    case '>':
                        next();
                        return token(token_greater_than, ">");
                    case '[':
                        next();
                        return token(token_left_bracket, "[");
                    case ']':
                        next();
                        return token(token_right_bracket, "]");
                    case ',':
                        next();
                        return token(token_comma, ",");
                    case '~':
                        next();
                        return token(token_tilde, "~");
                    default:
                        std::cerr << "Error: Invalid Character" << std::endl;
                        exit(1);
                }
            }
        }
        return token(token_end, "");
    }
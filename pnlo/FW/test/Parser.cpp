#include <string.h>
#include <stdexcept>
#include <cstdlib>
using namespace std;

#include "Parser.hpp"


Parser::Parser() : m_idx(0)
{
}

Parser::~Parser()
{
}

void Parser::load(const string & str)
{
    m_str = str;
    m_idx = 0;
}

void Parser::skip_white_space()
{
    while (m_str[m_idx] == ' ' || m_str[m_idx] == '\r' || m_str[m_idx] == '\n' || m_str[m_idx] == '\t')
        m_idx++;
}

char Parser::get_next_token()
{
    skip_white_space();
    if (m_idx == m_str.size())
        throw std::logic_error("unexpected end of input");
    return m_str[m_idx++];
}

Obj Parser::parse()
{
    char ch = get_next_token();
    // null true false
    if (ch == 'n') {

        // std::string str;


        m_idx--;
        return parse_null();
    } else if (ch == 't' || ch == 'f') {
        m_idx--;
        return parse_bool();
    } 





    else if (ch == '-' || ( ch >= '0' && ch <= '9' ) ) {
        m_idx--;
        return parse_number();
    } else if (ch == '\"') {
        return Obj(parse_string());
    } else if (ch == '[') {
        return parse_array();
    } else if (ch == '{') {
        return parse_object();
    } 

    throw std::logic_error("unexpected character in parse json");
}

Obj Parser::parse_null()
{
    if (m_str.compare(m_idx, 4, "null") == 0)
    {
        m_idx += 4;
        return Obj();
    }
    throw std::logic_error("parse null error");
}

Obj Parser::parse_bool()
{
    if (m_str.compare(m_idx, 4, "true") == 0)
    {
        m_idx += 4;
        return Obj(true);
    }
    if (m_str.compare(m_idx, 5, "false") == 0)
    {
        m_idx += 5;
        return Obj(false);
    }
    throw std::logic_error("parse bool error");
}

Obj Parser::parse_number()
{
    size_t pos = m_idx;

    if (m_str[m_idx] == '-')
        m_idx++;

    // integer part
    if (m_str[m_idx] == '0')
    {
        m_idx++;
    }
    else if (in_range(m_str[m_idx], '1', '9'))
    {
        m_idx++;
        while (in_range(m_str[m_idx], '0', '9'))
        {
            m_idx++;
        }
    }
    else
    {
        throw std::logic_error("invalid character in number");
    }

    if (m_str[m_idx] != '.')
    {
        return Obj(std::atoi(m_str.c_str() + pos));
    }

    // decimal part
    m_idx++;
    if (!in_range(m_str[m_idx], '0', '9'))
    {
        throw std::logic_error("at least one digit required in fractional part");
    }
    while (in_range(m_str[m_idx], '0', '9'))
    {
        m_idx++;
    }
    return Obj(std::atof(m_str.c_str() + pos));
}

string Parser::parse_string()
{
    int pos = m_idx;
    while (true)
    {
        if (m_idx == m_str.size())
        {
            throw std::logic_error("unexpected end of input in string");
        }

        char ch = m_str[m_idx++];
        if (ch == '"')
        {
            break;
        }

        // The usual case: non-escaped characters
        if (ch == '\\')
        {
            ch = m_str[m_idx++];
            switch (ch)
            {
                case 'b':
                case 't':
                case 'n':
                case 'f':
                case 'r':
                case '"':
                case '\\':
                    break;
                case 'u':
                    m_idx += 4;
                    break;
                default:
                    break;
            }
        }
    }
    return m_str.substr(pos, m_idx - pos - 1);
}

Obj Parser::parse_array()
{
    Obj arr(Obj::pnlo_array);
    char ch = get_next_token();
    if (ch == ']')
    {
        return arr;
    }
    m_idx--;
    while (true)
    {
        arr.append(parse());
        ch = get_next_token();
        if (ch == ']')
        {
            break;
        }
        if (ch != ',')
        {
            throw std::logic_error("expected ',' in array");
        }
    }
    return arr;
}

Obj Parser::parse_object()
{
    Obj obj(Obj::pnlo_object);
    char ch = get_next_token();
    if (ch == '}')
    {
        return obj;
    }
    m_idx--;
    while (true)
    {
        ch = get_next_token();
        if (ch != '"')
        {
            throw std::logic_error("expected '\"' in object");
        }
        string key = parse_string();
        ch = get_next_token();
        if (ch != ':')
        {
            throw std::logic_error("expected ':' in object");
        }
        obj[key] = parse();
        ch = get_next_token();
        if (ch == '}')
        {
            break;
        }
        if (ch != ',')
        {
            throw std::logic_error("expected ',' in object");
        }
    }
    return obj;
}
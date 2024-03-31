#pragma once

#include <string>
// using namespace std;

#include "Pnlo.hpp"


class Parser
{
public:
    Parser();
    ~Parser();

    void load(const std::string & str);
    Pnlo parse();

private:
    void skip_white_space();
    char get_next_token();

    Pnlo parse_null();
    Pnlo parse_bool();
    Pnlo parse_number();
    std::string parse_string();
    Pnlo parse_array();
    Pnlo parse_object();

    bool in_range(int x, int lower, int upper)
    {
        return (x >= lower && x <= upper);
    }

private:
    std::string m_str;
    size_t m_idx;
};


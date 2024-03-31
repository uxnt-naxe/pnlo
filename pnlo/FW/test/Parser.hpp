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
    Obj parse();

private:
    void skip_white_space();
    char get_next_token();

    Obj parse_null();
    Obj parse_bool();
    Obj parse_number();
    std::string parse_string();
    Obj parse_array();
    Obj parse_object();

    bool in_range(int x, int lower, int upper)
    {
        return (x >= lower && x <= upper);
    }

private:
    std::string m_str;
    size_t m_idx;
};


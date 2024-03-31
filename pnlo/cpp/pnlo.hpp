#include "Lexer.hpp"
#include "Parser.hpp"

#ifndef Pnlo_h
#define Pnlo_h

class Pnlo
{
public:
    enum Type
    {
        pnlo_null = 0,  // null value
        pnlo_bool,      // bool value
        pnlo_int,       // integer value
        pnlo_double,    // double value
        pnlo_string,    // string value
        pnlo_array,     // array value
        pnlo_object     // object value
    };
    Pnlo();

    
};

#endif
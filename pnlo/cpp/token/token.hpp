#ifndef token_h
#define token_h
#include <string>
#include <list>
#include <map>


enum token_type {

    token_null = 0,          // null  空白
    // ------------------------------
    token_identifier,    // 标识符 azAZ09_
    token_string,        // 字符串
    // ------------------------------
    token_integer,       // 整数
    token_float,         // 小数
    // ------------------------------
    token_false,         // false 假
    token_true,          // true  真
    
    // 符号
    // ------------------------------
    token_less_than,     // LT < 小于 
    token_greater_than,  // GT > 大于
    // ------------------------------
    token_left_bracket,   // [ 
    token_right_bracket,  // ] 
    // ------------------------------
    token_comma,          // ,
    token_equal,          // = 等号
    token_colon,          // : 冒号
    token_semicolon,      // ; 分号
    token_tilde,          // ~ 
    // ------------------------------
    token_end,            // !

};  // ok

struct token {
    token_type type;
    std::string value;

    token() {}
    token(token_type t, const std::string &v) : type(t), value(v) {}
};





#endif









/*


// Obj
// Value


Pnlo:

    key_value: 
      "xxxx" = bool/int/double/string/  array(obj)

    obj: 
        > key_value / obj ~



struct Value
{
    bool m_bool;
    int m_int;
    double m_double;
    std::string * m_string;

    std::list<Obj> * m_array;
    std::map<std::string, Obj> * m_object;
};

struct Obj {
    Type m_type;
    Value m_value;
};


*/
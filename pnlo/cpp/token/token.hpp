#ifndef token_h
#define token_h
#include <string>
#include <list>
#include <map>


enum token_type {

    v_null = 0,          // null  空白
    // ------------------------------
    id_identifier,    // 标识符 azAZ09_
    id_string,        // 字符串
    // ------------------------------
    v_int,       // 整数
    b_float,         // 小数
    // ------------------------------
    v_false,         // false 假
    v_true,          // true  真

    // v_obj,          //
    // v_key_value,    // 
    
    // symbol 符号
    // ------------------------------
    symbol_less_than,     // LT < 小于 
    symbol_greater_than,  // GT > 大于
    // ------------------------------
    symbol_left_bracket,   // [ 
    symbol_right_bracket,  // ] 
    // ------------------------------
    symbol_comma,          // ,
    symbol_equal,          // = 等号
    symbol_colon,          // : 冒号
    symbol_semicolon,      // ; 分号
    symbol_tilde,          // ~ 
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

    Cpp编程，帮我写数据结构
    key_value: 
      "xxxx" = bool/int/double/string/  array(obj)

    obj: 
        > key_value / obj ~


*/
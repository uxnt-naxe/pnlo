


enum TokenType {
    // key_identifier,
    // key_string,
    // key_value

    token_identifier,    // 标识符 azAZ09_
    token_string,        // 字符串

    token_integer,       // 整数
    token_float,         // 小数

    token_false,         // false 假
    token_true,          // true 真
    token_null,          // null 空白

    token_left_bracket,   // [ 
    token_right_bracket,  // ] 
    token_comma,          //,

    token_equal,    // = 等号
    token_colon,         // : 冒号
    token_semicolon,     // ; 分号

    token_less_than,     // LT < 小于 
    token_greater_than,  // GT > 大于
    token_tilde,         // ~ 

    
    token_end,            // !

};  // ok

struct Token {
    TokenType type;
    std::string value;
    Token() {}
    Token(TokenType t, const std::string &v) : type(t), value(v) {}
};
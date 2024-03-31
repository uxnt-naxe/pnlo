#ifndef Pnlo_h
#define Pnlo_h

#include "Lexer.hpp"
#include "Parser.hpp"


struct pValue {
    bool Bool;
    int Int;
    double Double;
    std::string String;
};  // ( bool / int / double / string )


struct pKeyValue:std::map<std::string, pValue> {
    // pKeyValue(const std::string& k, const pValue& v) : key(k), value(v) {}
};

struct pObject {
    pKeyValue keyValue;
    std::map<std::string, pObject> Object;
};

std::list<pObject> Array;











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
        // -----------------------------
        // pnlo_key_value,
        pnlo_array,     // array value
        pnlo_object     // object value
    };
    Pnlo();

    // (null, "null")

    Type m_type;
};



#endif









// std::vector<Value> KeyValue;
//  Value  / array(Value/obj)
// key_value: Value
// obj:  > key_value / obj ~
// std::vector<KeyValue>
#pragma once

#include <string>
// using std::string;

#include <list>
#include <map>


class Obj
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
        pnlo_value,
        pnlo_object     // object value
    };

    Obj();
    Obj(Type type);
    Obj(bool value);
    Obj(int value);
    Obj(double value);
    Obj(const char * value);
    Obj(const std::string & value);
    Obj(const Obj & other);
    ~Obj();

    Type type() const;

    bool isNull() const;
    bool isBool() const;
    bool isInt() const;
    bool isDouble() const;
    bool isString() const;
    bool isArray() const;
    bool isObject() const;

    bool asBool() const;
    int asInt() const;
    double asDouble() const;
    std::string asString() const;

    // number of values in array or object
    int size() const;

    // return true if empty array, empty object, or null, otherwise, false.
    bool empty() const;

    void clear();

    bool has(int index);
    bool has(const char * key);
    bool has(const std::string & key);

    void remove(int index);
    void remove(const char * key);
    void remove(const std::string & key);

    // append value to array at the end.
    void append(const Obj & value);

    Obj & operator = (const Obj & other);
    bool operator == (const Obj & other);
    bool operator != (const Obj & other);

    Obj & operator [] (int index);
    Obj & operator [] (const char * key);
    Obj & operator [] (const std::string & key);

    operator bool();
    operator int();
    operator double();
    operator std::string();

    void parse(const std::string & str);
    std::string str() const;

    typedef std::list<Obj>::iterator iterator;
    iterator begin()
    {
        return (m_value.m_array)->begin();
    }
    iterator end()
    {
        return (m_value.m_array)->end();
    }

private:
    void copy(const Obj & other);

private:
    union Value
    {
        bool m_bool;
        int m_int;
        double m_double;
        std::string * m_string;
        std::list<Obj> * m_array;
        std::map<std::string, Obj> * m_object;
    };

    std::map<std::string, Value> * m_key_value;

    Type m_type;
    Value m_value;
};




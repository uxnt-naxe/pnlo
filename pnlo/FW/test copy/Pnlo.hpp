#pragma once

#include <string>
// using std::string;

#include <list>
#include <map>


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
    Pnlo(Type type);
    Pnlo(bool value);
    Pnlo(int value);
    Pnlo(double value);
    Pnlo(const char * value);
    Pnlo(const std::string & value);
    Pnlo(const Pnlo & other);
    ~Pnlo();

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
    void append(const Pnlo & value);

    Pnlo & operator = (const Pnlo & other);
    bool operator == (const Pnlo & other);
    bool operator != (const Pnlo & other);

    Pnlo & operator [] (int index);
    Pnlo & operator [] (const char * key);
    Pnlo & operator [] (const std::string & key);

    operator bool();
    operator int();
    operator double();
    operator std::string();

    void parse(const std::string & str);
    std::string str() const;

    typedef std::list<Pnlo>::iterator iterator;
    iterator begin()
    {
        return (m_value.m_array)->begin();
    }
    iterator end()
    {
        return (m_value.m_array)->end();
    }

private:
    void copy(const Pnlo & other);

private:
    union Value
    {
        bool m_bool;
        int m_int;
        double m_double;
        std::string * m_string;
        std::list<Pnlo> * m_array;
        std::map<std::string, Pnlo> * m_object;
    };

    Type m_type;
    Value m_value;
};


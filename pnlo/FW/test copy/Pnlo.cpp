#include <sstream>
using std::stringstream;

#include <stdexcept>

#include "Pnlo.hpp"
#include "Parser.hpp"


Pnlo::Pnlo() : m_type(pnlo_null)
{
}

Pnlo::Pnlo(Type type) : m_type(type)
{
    switch (m_type)
    {
        case pnlo_null:
            break;
        case pnlo_bool:
            m_value.m_bool = false;
            break;
        case pnlo_int:
            m_value.m_int = 0;
            break;
        case pnlo_double:
            m_value.m_double = 0.0;
            break;
        case pnlo_string:
            m_value.m_string = new std::string("");
            break;
        case pnlo_array:
            m_value.m_array = new std::list<Pnlo>();
            break;
        case pnlo_object:
            m_value.m_object = new std::map<std::string, Pnlo>();
        default:
            break;
    }
}

Pnlo::Pnlo(bool value) : m_type(pnlo_bool)
{
    m_value.m_bool = value;
}

Pnlo::Pnlo(int value) : m_type(pnlo_int)
{
    m_value.m_int = value;
}

Pnlo::Pnlo(double value) : m_type(pnlo_double)
{
    m_value.m_double = value;
}

Pnlo::Pnlo(const char * value) : m_type(pnlo_string)
{
    m_value.m_string = new std::string(value);
}

Pnlo::Pnlo(const std::string & value) : m_type(pnlo_string)
{
    m_value.m_string = new std::string(value);
}


Pnlo::Pnlo(const Pnlo & other) : m_type(pnlo_null) { copy(other); }
Pnlo::~Pnlo() { }

Pnlo::Type Pnlo::type() const { return m_type; }
bool Pnlo::isNull() const { return m_type == pnlo_null; }
bool Pnlo::isBool() const { return m_type == pnlo_bool; }
bool Pnlo::isInt() const { return m_type == pnlo_int; }
bool Pnlo::isDouble() const { return m_type == pnlo_double; }
bool Pnlo::isString() const { return m_type == pnlo_string; }
bool Pnlo::isArray() const { return m_type == pnlo_array; }
bool Pnlo::isObject() const { return m_type == pnlo_object; }


bool Pnlo::asBool() const
{
    if (m_type == pnlo_bool)
    {
        return m_value.m_bool;
    }
    throw std::logic_error("function Json::asBool value type error");
}

int Pnlo::asInt() const
{
    if (m_type == pnlo_int)
    {
        return m_value.m_int;
    }
    throw std::logic_error("function Json::asInt value type error");
}

double Pnlo::asDouble() const
{
    if (m_type == pnlo_double)
    {
        return m_value.m_double;
    }
    throw std::logic_error("function Json::asDouble value type error");
}

std::string Pnlo::asString() const
{
    if (m_type == pnlo_string)
    {
        return *(m_value.m_string);
    }
    throw std::logic_error("function Json::asString value type error");
}

void Pnlo::copy(const Pnlo & other)
{
    m_type = other.m_type;
    m_value = other.m_value;
}

int Pnlo::size() const
{
    switch (m_type)
    {
        case pnlo_array:
            return (m_value.m_array)->size();
        case pnlo_object:
            return (m_value.m_object)->size();
        default:
            break;
    }
    throw std::logic_error("function Json::size value type error");
}

bool Pnlo::empty() const
{
    switch (m_type)
    {
        case pnlo_null:
            return true;
        case pnlo_array:
            return (m_value.m_array)->empty();
        case pnlo_object:
            return (m_value.m_object)->empty();
        default:
            break;
    }
    return false;
}

void Pnlo::clear()
{
    switch (m_type)
    {
        case pnlo_null:
        case pnlo_bool:
        case pnlo_int:
        case pnlo_double:
            break;
        case pnlo_string:
            {
                delete m_value.m_string;
            }
            break;
        case pnlo_array:
            {
                for (auto it = (m_value.m_array)->begin(); it != (m_value.m_array)->end(); it++)
                {
                    it->clear();
                }
                delete m_value.m_array;
            }
            break;
        case pnlo_object:
            {
                for (auto it = (m_value.m_object)->begin(); it != (m_value.m_object)->end(); it++)
                {
                    it->second.clear();
                }
                delete m_value.m_object;
            }
            break;
        default:
            break;
    }
    m_type = pnlo_null;
}

bool Pnlo::has(int index)
{
    if (m_type != pnlo_array)
    {
        return false;
    }
    int size = (m_value.m_array)->size();
    return (index >= 0) && (index < size);
}

bool Pnlo::has(const char * key)
{
    std::string name(key);
    return has(name);
}

bool Pnlo::has(const std::string & key)
{
    if (m_type != pnlo_object)
    {
        return false;
    }
    return (m_value.m_object)->find(key) != (m_value.m_object)->end();
}

void Pnlo::remove(int index)
{
    if (m_type != pnlo_array)
    {
        return;
    }
    int size = (m_value.m_array)->size();
    if (index < 0 || index >= size)
    {
        return;
    }
    auto it = (m_value.m_array)->begin();
    for (int i = 0; i < index; i++)
    {
        it++;
    }
    it->clear();
    (m_value.m_array)->erase(it);
}

void Pnlo::remove(const char * key)
{
    std::string name = key;
    remove(name);
}

void Pnlo::remove(const std::string & key)
{
    if (m_type != pnlo_object)
    {
        return;
    }
    auto it = (m_value.m_object)->find(key);
    if (it != (m_value.m_object)->end())
    {
        it->second.clear();
        (m_value.m_object)->erase(key);
    }
}

void Pnlo::append(const Pnlo & value)
{
    if (m_type != pnlo_array)
    {
        clear();
        m_type = pnlo_array;
        m_value.m_array = new std::list<Pnlo>();
    }
    (m_value.m_array)->push_back(value);
}

// Pnlo &Pnlo::operator=(const Pnlo &other)


Pnlo & Pnlo::operator = (const Pnlo & other)
{
    clear();
    copy(other);
    return *this;
}

bool Pnlo::operator == (const Pnlo & other)
{
    if (m_type != other.type())
    {
        return false;
    }
    switch (m_type)
    {
        case pnlo_null:
            return true;
        case pnlo_bool:
            return (m_value.m_bool == other.m_value.m_bool);
        case pnlo_int:
            return (m_value.m_int == other.m_value.m_int);
        case pnlo_double:
            return (m_value.m_double == other.m_value.m_double);
        case pnlo_string:
            return *(m_value.m_string) == *(other.m_value.m_string);
        case pnlo_array:
            return m_value.m_array == other.m_value.m_array;
        case pnlo_object:
            return m_value.m_object == other.m_value.m_object;
        default:
            break;
    }
    return false;
}

bool Pnlo::operator != (const Pnlo & other)
{
    return !(*this == other);
}

Pnlo & Pnlo::operator [] (int index)
{
    if (index < 0)
    {
        throw std::logic_error("function Json::operator [int] index less than 0");
    }
    if (m_type != pnlo_array)
    {
        clear();
        m_type = pnlo_array;
        m_value.m_array = new std::list<Pnlo>();
    }
    int size = (m_value.m_array)->size();
    if (index >= 0 && index < size)
    {
        auto it = (m_value.m_array)->begin();
        for (int i = 0; i < index; i++)
        {
            it++;
        }
        return *it;
    }
    if (index >= size)
    {
        for (int i = size; i <= index; i++)
        {
            (m_value.m_array)->push_back(Pnlo());
        }
    }
    return (m_value.m_array)->back();
}

Pnlo & Pnlo::operator [] (const char * key)
{
    std::string name = key;
    return (*this)[name];
}

Pnlo & Pnlo::operator [] (const std::string & key)
{
    if (m_type != pnlo_object)
    {
        clear();
        m_type = pnlo_object;
        m_value.m_object = new std::map<std::string, Pnlo>();
    }
    return (*(m_value.m_object))[key];
}

Pnlo::operator bool()
{
    if (m_type != pnlo_bool)
    {
        throw std::logic_error("function Json::operator (bool) requires bool value");
    }
    return m_value.m_bool;
}

Pnlo::operator int()
{
    if (m_type != pnlo_int)
    {
        throw std::logic_error("function Json::operator (int) requires int value");
    }
    return m_value.m_int;
}

Pnlo::operator double()
{
    if (m_type != pnlo_double)
    {
        throw std::logic_error("function Json::operator (double) requires double value");
    }
    return m_value.m_double;
}

Pnlo::operator std::string()
{
    if (m_type != pnlo_string)
    {
        throw std::logic_error("function Json::operator (string) requires string value");
    }
    return *(m_value.m_string);
}

void Pnlo::parse(const std::string & str)
{
    Parser parser;
    parser.load(str);
    *this = parser.parse();
}

std::string Pnlo::str() const
{
    stringstream ss;
    switch (m_type)
    {
        case pnlo_null:
            ss << "null";
            break;
        case pnlo_bool:
            if (m_value.m_bool)
            {
                ss << "true";
            }
            else
            {
                ss << "false";
            }
            break;
        case pnlo_int:
            ss << m_value.m_int;
            break;
        case pnlo_double:
            ss << m_value.m_double;
            break;
        case pnlo_string:
            ss << "\"" << *(m_value.m_string) << "\"";
            break;
        case pnlo_array:
            {
                ss << "[";
                for (auto it = (m_value.m_array)->begin(); it != (m_value.m_array)->end(); it++)
                {
                    if (it != (m_value.m_array)->begin())
                    {
                        ss << ",";
                    }
                    ss << (*it).str();
                }
                ss << "]";
            }
            break;
        case pnlo_object:
            {
                ss << "{";
                for (auto it = (m_value.m_object)->begin(); it != (m_value.m_object)->end(); it++)
                {
                    if (it != (m_value.m_object)->begin())
                    {
                        ss << ",";
                    }
                    ss << "\"" << it->first << "\":" << it->second.str();
                }
                ss << "}";
            }
            break;
        default:
            break;
    }
    return ss.str();
}
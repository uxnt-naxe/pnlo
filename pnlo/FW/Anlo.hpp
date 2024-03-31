#ifndef Anlo_h
#define Anlo_h

#include <string>
#include <list>
#include <map>



// Anlp
class Anlo {
    public:
        enum Type {
            // ----------------
            anlo_null = 0,  
            anlo_bool,      
            anlo_int,       
            anlo_double,    
            anlo_string,  
            // ----------------
            anlo_key_value,
            anlo_array,     
            anlo_object     
            // ----------------
        };

        std::string asString() const { return m_key_value.m_value.m_string; }

        Anlo & operator = (const Anlo & other)
        {
            // clear();
            // copy(other);
            return *this;
        }

        Anlo & operator = (const char * other)
        {
            // clear();
            // copy(other);
            // (*this)
            m_key_value.m_value.m_string = other;
            return *this;
        }

        Anlo & operator [] (const char * key);

        Anlo & operator [] (const char * key)
        {
            m_key_value.m_string = key;
            std::string name = key;
            return (*this);
        }

      

       
     

        Anlo & operator [] (const std::string & key)
        {
           // if (m_type != pnlo_object)
           // {
           //     clear();
           //     m_type = pnlo_object;
           //     m_value.m_object = new std::map<std::string, Pnlo>();
           // }
            return (*this)[key];
        }


        operator std::string()
        {
            // if (m_type != pnlo_string)
            // {
            //     throw std::logic_error("function Json::operator (string) requires string value");
            // }
            return m_key_value.m_value.m_string;
        }



    private:
        
        struct Value {
            bool m_bool;
            int m_int;
            double m_double;
            std::string m_string;
        };

        struct KeyValue {
            
            std::string m_string;
            Value m_value;

            // std::list<Anlo> * m_array;

            // std::map<std::string, Value> * m_varMap;
        };

        Type m_type;
        KeyValue m_key_value;
        // Anlo m_object;
        
        // std::map<std::string, Anlo> m_object;



        // std::map<std::string, Anlo> * m_object;

        // struct Obj {
        //     KeyValue m_key_value;
        //     std::map<std::string, Anlo> * m_object;
        //     // std::map<std::string, Obj> * m_object;
        // };
                
};

    






#endif  // Anlo_h
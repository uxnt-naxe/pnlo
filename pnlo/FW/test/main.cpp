
#include <iostream>
#include <string>


#include "NeonFile.hpp"
#include "pnlo.hpp"



int main() {
    Neon::File ojb = Neon::File("text.otne");
    std::string input = ojb.Read();

    // std::cout << input << std::endl;

    



    // { "qwe":{ "a":1 } }


    // we[0]["wx"] = "Haloe";
    // we[1]["wx"] = "Haloe";
    
    // std::cout << we["Hae"].type() << std::endl;
    // std::cout << we[0]["wx"].type() << std::endl;


    Obj Hapr = Obj();

    Hapr["Hello"] = "2";

    std::cout << Hapr.str() << std::endl;



    // pnlo_value,


    return 0;
}
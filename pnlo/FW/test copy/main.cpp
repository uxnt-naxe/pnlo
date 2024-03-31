
#include <iostream>
#include <string>


#include "NeonFile.hpp"
#include "pnlo.hpp"



int main() {
    Neon::File ojb = Neon::File("text.otne");
    std::string input = ojb.Read();

    // std::cout << input << std::endl;
    Pnlo we = Pnlo();

    we["kat"] = "";
    
    std::cout << we["kat"].type() << std::endl;

    std::cout << we["kat"].str() << std::endl;

    return 0;
}
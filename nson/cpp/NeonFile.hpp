#include <string>

// Neon ReadFile
// string NeonFile(string path);

namespace Neon
{

    class File
    {
    private:
        std::string path;
        /* data */
    public: 
        // std::string path 
        File(/* args */);
        ~File();
        
        File(std::string path);
        std::string Read(std::string path);
        std::string Read();
        void Write(std::string path, std::string buffer);
        void Write(std::string buffer);

    };

}

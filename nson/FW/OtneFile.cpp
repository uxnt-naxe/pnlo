#include <iostream>
#include "OtneFile.h"

#include "Utf8.h"
using namespace std;


/*
bool readFile(const char* filename, wstring &content) {
    wchar_t linex[4096];

    FILE* file;
    file = fopen(filename, "rt+,ccs=UTF-8");
    if (file == NULL) {
        wprintf(L"File Open Error!");
        return false;
    }
    while(fgetws(linex, 4096, file))
    {
        content += wstring(linex);
    }
    fclose(file);
    return true;
}
*/



i18nString ReadFile(string filename)
{
    i18nChar text[4096];
    i18nString content;
    FILE* file;
    file = fopen(filename.c_str(), "rt+,ccs=UTF-8");
    if (file == NULL)
    {
        return L"File Open Error!";
    }
    while (fgetws(text, 4096, file))
    {
        content += wstring(text);
    }
    fclose(file);
    return content;
}
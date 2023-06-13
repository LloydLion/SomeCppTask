#include <iostream>
#include "cstring.hpp"
#include "stringbuilder.hpp"

using namespace std;

mstring readUtilDelimeter(const char* delimeters, stringbuilder* buffer = nullptr)
{
    if (buffer == nullptr)
        buffer = new stringbuilder();

    bool skipNewline = strcontains('\n', delimeters) == false;

    while (true)
    {
        char newChar;
        cin >> newChar;
        
        if (skipNewline && newChar == '\n')
            continue;

        bool isDelimeter = strcontains(newChar, delimeters);

        if (isDelimeter)
        {
            break;
        }
        else buffer->push(newChar);
    }

    return buffer->finalize();
}

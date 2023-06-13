#include <iostream>
#include "cstring.hpp"

using namespace std;

int readUtilDelimeter(const char* delimeters, char* buffer)
{
    char* bufferPointer = buffer;

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
            *bufferPointer = '\0';
            break;
        }
        else *bufferPointer = newChar;

        bufferPointer++;
    }

    return bufferPointer - buffer;
}
/// @brief Calculates length of string
/// @param data Input string
/// @return Length of input string
int strlen(const char* data)
{
    int result = 0;
    while (*(data + result))
    {
        result++;
    }

    return result;
}

/// @brief Check if string contains character
/// @param sym Character to check
/// @param target Input string
/// @return If string contains character
bool strcontains(char sym, const char* target)
{
    while (true)
    {
        char a = *(target);
        if (a == '\0')
            return false;
        if (a == sym)
            return true;

        target++;
    }
}

/// @brief Count character entries in string
/// @param sym Character to be counted
/// @param target Input string
/// @return Count of entries of character
int countch(char sym, const char* target)
{
    int result = 0;
    while (true)
    {
        char a = *(target);
        if (a == '\0')
            break;
        if (a == sym)
            result++;

        target++;
    }

    return result;
}

/// @brief Result of string split operation
struct splitResult
{
    /// @brief Creates new result
    /// @param count Count of split segments
    /// @param pointers Array of pointers, each ponter is string segment
    splitResult(int count, char** pointers)
    {
        this->count = count;
        this->pointers = pointers;
    }


    /// @brief Count of split segments
    int count;
    /// @brief Array of pointers, each ponter is string segment
    char** pointers;
};

/// @brief Slits string by specified character (WARNING: original string will be CHANGED, if it critical use strsplitim)
/// @param buffer Original string
/// @param seporator Character to split by
/// @return Pointers array, each pointer is string to original string segment
splitResult strsplit(char* buffer, char seporator)
{
    char** output = new char*[countch(seporator, buffer)];

    *(output) = buffer;
    int usedPointers = 1;

    while (true)
    {
        char a = *(buffer);
        if (a == '\0')
            break;

        if (a == seporator)
        {
            *(buffer) = '\0';
            *(output + usedPointers) = buffer + 1;
            usedPointers++;
        }

        buffer++;
    }

    //Output structure
    //Input: Some string that I wanna split by words\0
    //Modified input: Some\0string\0that\0I\0wanna\0split\0by\0words\0
    //Pointers:       ^     ^       ^     ^  ^      ^      ^   ^

    return splitResult(usedPointers, output);
}

/// @brief Slits string by specified character (NOTE: original string will be CLONED)
/// @param buffer Original string
/// @param seporator Character to split by
/// @return Pointers array, each pointer is string to original string segment
splitResult strsplitim(const char* buffer, char seporator)
{
    int len = strlen(buffer);
    char* buffercpy = new char[len];
    memcpy(buffercpy, buffer, len);
    return strsplit(buffercpy, seporator);
}
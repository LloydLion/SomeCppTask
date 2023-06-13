int strlen(const char* data)
{
    int result = 0;
    while (*(data + result))
    {
        result++;
    }

    return result;
}

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

int strsplit(char* buffer, char seporator, char** output)
{
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

    return usedPointers;
}
#include <iostream>

struct mstring
{
    mstring(int length, char* pointer)
    {
        this->length = length;
        this->pointer = pointer;
    }


    void dispose()
    {
        delete[] pointer;
    }


    int length;
    char* pointer;
};


class stringbuilder
{
private:
    char** _bufferCell;
    int* _lenCell;

    char* _internalBuffer;
    int _charPointer;
    int _lenLimit;


public:
    stringbuilder()
    {
        _lenLimit = 20;
        _internalBuffer = new char[_lenLimit];
        _charPointer = 0;
        _bufferCell = nullptr;
        _lenCell = nullptr;
    }
    
    stringbuilder(char** externalBuffer, int* bufferSize)
    {
        _lenLimit = *bufferSize;
        _internalBuffer = *externalBuffer;
        _bufferCell = externalBuffer;
        _charPointer = 0;
    }


    void push(const char* newContent, int count = 1)
    {
        count -= 1; //Cut \0 char

        if (_charPointer + count >= _lenLimit)
            ensure(__max(_lenLimit * 2, _charPointer + count));
        memcpy(_internalBuffer, newContent, count);
        _charPointer += count;
    }

    void push(char newChar)
    {
        if (_charPointer + 1 >= _lenLimit)
            ensure(_lenLimit * 2);
        *(_internalBuffer + _charPointer) = newChar;
        _charPointer++;
    }

    mstring finalize()
    {
        push('\0');
        return mstring(_charPointer, _internalBuffer);
    }

private:
    void ensure(int targetSize)
    {
        char* newBuffer = new char[targetSize];
        memcpy(newBuffer, _internalBuffer, _charPointer);
        delete[] _internalBuffer;
        _internalBuffer = newBuffer;
        if (_bufferCell != nullptr)
        {
            *_bufferCell = _internalBuffer;
            *_lenCell = targetSize;
        }
    }
};
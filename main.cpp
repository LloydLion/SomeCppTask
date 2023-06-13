#include "consolehelp.hpp"

int main()
{
    const char delimeters[] = "\n";
    const char wordSeporator = ' ';
    const char insertWord[] = "WORD";

    cin.unsetf(ios_base::skipws); //Read ALL characters (include [space], \t, \n, \r)

    int inputBufferSize = 20;
    char* inputBuffer = new char[inputBufferSize];

    int minEnterWordLen = ~(1 << 31); //Int max value

    while (true)    
    {
        mstring input = readUtilDelimeter(delimeters, new stringbuilder(&inputBuffer, &inputBufferSize));

        splitResult sr = strsplit(input.pointer, wordSeporator);
        int wordCount = sr.count;
        char** words = sr.pointers;

        bool needProcess = false;
        int* wordLens = new int[wordCount];

        for (int i = 0; i < wordCount - 1; i++)
        {
            wordLens[i] = words[i + 1] - words[i] - 1; //Distance between pointers equals word len + 1 (1 - seporator aka \0)
            needProcess |= wordLens[i] % 2 == 0;
        }
        //This magic doesn't work for last word
        wordLens[wordCount - 1] = strlen(words[wordCount - 1]);
        needProcess |= wordLens[wordCount - 1] % 2 == 0;       

        if (needProcess)
        {
            int pwords = 0; //NEED ONLY FOR CORRECT SEPORATORS PRINT
            for (int i = 0; i < wordCount; i++)
            {
                if (i != 0) //Skip first word
                {
                    if (pwords != 0)
                        cout << wordSeporator;
                    cout << words[i];
                    pwords++;
                }

                if (wordLens[i] % 2 == 0) //Insert word
                {
                    if (pwords != 0)
                        cout << wordSeporator;
                    cout << insertWord;
                    pwords++;
                }
            }
        }
        else
        {
            //Print raw input
            cout << words[0];
            for (int i = 1; i < wordCount; i++)
            {
                cout << wordSeporator;
                cout << words[i];
            }
        }

        cout << endl;

        if (wordCount == minEnterWordLen)
            break;
        if (wordCount < minEnterWordLen)
            minEnterWordLen = wordCount;
    }

    return 0;
}

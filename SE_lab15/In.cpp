#include "In.h"
#include "Error.h"
#include"stdafx.h"

using namespace std;

namespace In
{
    IN getin(wchar_t* infile)
    {
        IN inner_text;

        ifstream file;
        file.open(infile);

        if (!file)
            throw ERROR_THROW(110);

        unsigned char tempChar;
        int position = 0;
        inner_text.size = 0;
        inner_text.lines = 1;
        inner_text.ignore = 0;
        inner_text.text = new unsigned char[IN_MAX_LEN_TEXT];
        bool flagEmptyFile = true;

        while ((tempChar = file.get()) && !file.eof())
        {
            flagEmptyFile = false;

            switch (inner_text.code[tempChar])
            {
            case IN::T:
            {
                //if (tempChar == IN_CODE_ENDL)
                //{
                //    inner_text.text[inner_text.size] = '|';
                //    inner_text.size++;
                //    inner_text.lines++;
                //    position = 0;
                //    break;
                //}
                inner_text.text[inner_text.size++] = tempChar;
                position++;
                break;
            }

            case IN::I:
            {
                inner_text.ignore++;
                position++;
                break;
            }

            case IN::F:
            {
                throw ERROR_THROW_IN(111, inner_text.lines, position + 1);
                break;
            }
            default:
            {
                inner_text.text[inner_text.size++] = inner_text.code[tempChar];
                position++;
                break;
            }
            }
        }

        if (flagEmptyFile)
            throw ERROR_THROW(113);

        if (inner_text.size == 0)
            inner_text.lines = 0;

        inner_text.text[inner_text.size] = '\0';
        file.close();
        return inner_text;
    }
}

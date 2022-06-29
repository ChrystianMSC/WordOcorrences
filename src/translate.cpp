#include "translate.h"


char translateChar(char _char, string ordem)
{
    string normal = NORMAL;
    int i = 0;
    for (; i < 26; ++i)
    {
        if (_char == ordem[i])
        {
            break;
        }
    }

    if (i == 26 && normal[i] == '\0')
    {
        return _char;
    }

    return normal[i];
}

char undoTranslate(char _char, string ordem)
{
    string normal = NORMAL;
    int i = 0;
    for (; i < 26; ++i)
    {
        if (_char == normal[i])
        {
            break;
        }
    }

    if (i == 26 && ordem[i] == '\0')
    {
        return _char;
    }

    return ordem[i];
}
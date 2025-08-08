#include "Input.h"

STATE_INPUT checkInputBuffer()
{
    try {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.seekg(0);
    }
    catch (...) { return INPUT_BAD_VALUE; }
    return INPUT_GOOD_VALUE;
}

STATE_INPUT checkInt(const std::string& inp)
{
    if (inp.empty()) return INPUT_BAD_VALUE; // empty string is invalid

    for (size_t i = 0; i < inp.size(); i++)
    {
        if (i == 0 && inp[i] == '-') // allow negative sign at start
            continue;

        if (!(inp[i] >= '0' && inp[i] <= '9')) // must be digit
            return INPUT_BAD_VALUE;
    }
    return INPUT_GOOD_VALUE;
}

STATE_INPUT checkHex(const std::string& inp)
{
    if (inp.empty())
        return STATE_INPUT::INPUT_BAD_VALUE;

    std::string hexPart = inp;

    // Handle prefixes
    if (hexPart.size() > 2 && (hexPart[0] == '0') && (hexPart[1] == 'x' || hexPart[1] == 'X'))
    {
        hexPart = hexPart.substr(2);
    }
    else if (hexPart.size() > 1 && hexPart[0] == '#')
    {
        hexPart = hexPart.substr(1);
    }

    // Must have at least one digit after prefix
    if (hexPart.empty())
        return STATE_INPUT::INPUT_BAD_VALUE;

    // Validate each character
    for (char c : hexPart)
    {
        if (!((c >= '0' && c <= '9') ||
            (c >= 'A' && c <= 'F') ||
            (c >= 'a' && c <= 'f')))
        {
            return STATE_INPUT::INPUT_BAD_VALUE;
        }
    }

    return STATE_INPUT::INPUT_GOOD_VALUE;
}


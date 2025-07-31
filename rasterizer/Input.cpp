#include "Input.h"

STATE_INPUT checkInputBuffer()
{
    if (std::cin.bad() || std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.seekg(0);
        return INPUT_BAD_VALUE;
    }

    return INPUT_GOOD_VALUE;
}

STATE_INPUT checkInt(const std::string& inp)
{
    for (size_t i = 0; i < inp.size(); i++)
    {
        if (!((inp[i] >= 48 || inp[i] <= 57) || (i == 0 && inp[0] == '-'))) { return INPUT_BAD_VALUE; }
    }
    return INPUT_GOOD_VALUE;
}

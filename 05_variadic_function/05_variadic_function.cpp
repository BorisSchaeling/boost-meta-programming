#include <cstdarg>
#include <cassert>

int find(int val, int count, ...)
{
    va_list args;
    va_start(args, count);
    for (int i{}; i < count; ++i)
    {
        int j = va_arg(args, int);
        if (j == val)
            return i;
    }
    va_end(args);
    return -1;
}

int main()
{
    assert(find(3, 5, 5, 2, 3, 1, 4) == 2);
    assert(find(6, 3, 5, 2, 3) == -1);
}

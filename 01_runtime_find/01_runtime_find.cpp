#include <array>
#include <cassert>

int find(const std::array<int, 5> &a, int val)
{
    for (int i{}; i < a.size(); ++i)
    {
        if (a[i] == val)
            return i;
    }
    return -1;
}

int main()
{
    std::array<int, 5> a{ 5, 2, 3, 1, 4 };
    assert(find(a, 3) == 2);
    assert(find(a, 6) == -1);
}

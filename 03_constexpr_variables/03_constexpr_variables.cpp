#include <array>

constexpr int find(const std::array<int, 5> &a, int val)
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
    constexpr std::array<int, 5> a{ 5, 2, 3, 1, 4 };
    constexpr int r1{ find(a, 3) };
    static_assert(r1 == 2);

    constexpr int r2{ find(a, 6) };
    static_assert(r2 == -1);
}

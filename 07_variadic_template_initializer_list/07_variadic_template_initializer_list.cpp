#include <initializer_list>

template <int Val, int... Args>
constexpr int find()
{
    int index{};
    for (int i : { Args... })
    {
        if (Val == i)
            return index;
        ++index;
    }
    return -1;
}

int main()
{
    constexpr int r1{ find<3, 5, 2, 3, 1, 4>() };
    static_assert(r1 == 2);

    constexpr int r2{ find<6, 5, 2, 3>() };
    static_assert(r2 == -1);
}

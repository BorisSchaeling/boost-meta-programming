template <int Val, int Index>
constexpr int find_impl()
{
    return -1;
}

template <int Val, int Index, int Next, int... Args>
constexpr int find_impl()
{
    return Val == Next ? Index : find_impl<Val, Index + 1, Args...>();
}

template <int Val, int... Args>
constexpr int find()
{
    return find_impl<Val, 0, Args...>();
}

int main()
{
    constexpr int r1{ find<3, 5, 2, 3, 1, 4>() };
    static_assert(r1 == 2);

    constexpr int r2{ find<6, 5, 2, 3>() };
    static_assert(r2 == -1);
}

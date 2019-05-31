template <int Val>
constexpr int find()
{
    return -1;
}

template <int Val, int Arg0>
constexpr int find()
{
    return Val == Arg0 ? 0 : find<Val>();
}

template <int Val, int Arg0, int Arg1>
constexpr int find()
{
    return Val == Arg1 ? 1 : find<Val, Arg0>();
}

template <int Val, int Arg0, int Arg1, int Arg2>
constexpr int find()
{
    return Val == Arg2 ? 2 : find<Val, Arg0, Arg1>();
}

template <int Val, int Arg0, int Arg1, int Arg2, int Arg3>
constexpr int find()
{
    return Val == Arg3 ? 3 : find<Val, Arg0, Arg1, Arg2>();
}

template <int Val, int Arg0, int Arg1, int Arg2, int Arg3, int Arg4>
constexpr int find()
{
    return Val == Arg4 ? 4 : find<Val, Arg0, Arg1, Arg2, Arg3>();
}

int main()
{
    constexpr int r1{ find<3, 5, 2, 3, 1, 4>() };
    static_assert(r1 == 2);

    constexpr int r2{ find<6, 5, 2, 3>() };
    static_assert(r2 == -1);
}

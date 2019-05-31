#include <array>
#include <algorithm>
#include <iterator>

int main()
{
    constexpr std::array<int, 5> a{ 5, 2, 3, 1, 4 };
    constexpr auto it1{ std::find(std::begin(a), std::end(a), 3) };
    constexpr int r1{ it1 != std::end(a) ? std::distance(std::begin(a), it1) : -1 };
    static_assert(r1 == 2);

    constexpr auto it2{ std::find(std::begin(a), std::end(a), 6) };
    constexpr int r2{ it2 != std::end(a) ? std::distance(std::begin(a), it2) : -1 };
    static_assert(r2 == -1);
}

#include <boost/hana.hpp>

int main()
{
    constexpr auto t{ boost::hana::make_tuple(5, 2, 3, 1, 4) };
    constexpr bool r1{ boost::hana::any_of(t, boost::hana::equal.to(3)) };
    static_assert(r1);

    constexpr int a[5]{ 5, 2, 3 };
    constexpr bool r2{ boost::hana::any_of(a, boost::hana::equal.to(6)) };
    static_assert(!r2);
}

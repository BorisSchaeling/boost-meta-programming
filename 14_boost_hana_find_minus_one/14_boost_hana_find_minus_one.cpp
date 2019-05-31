#include <boost/hana.hpp>

int main()
{
    constexpr auto t1{ boost::hana::make_tuple(boost::hana::int_c<5>, boost::hana::int_c<2>, boost::hana::int_c<3>, boost::hana::int_c<1>, boost::hana::int_c<4>) };
    constexpr auto r1{ boost::hana::find(t1, boost::hana::int_c<3>) };
    static_assert(r1.value() == 3);

    constexpr auto t2{ boost::hana::tuple_c<int, 5, 2, 3> };
    constexpr auto r2{ boost::hana::find(t2, boost::hana::int_c<6>) };
    static_assert(r2.value_or(-1) == -1);
}

#include <boost/hana.hpp>
#include <string>
#include <iostream>

int main()
{
    constexpr boost::hana::tuple<int*, double, const char*> t{ nullptr, 3.14, "Hello" };
    boost::hana::for_each(t, [](auto t){ std::cout << t << '\n'; });

    struct _ {
        BOOST_HANA_DEFINE_STRUCT(_,
            (int*, i),
            (double, d),
            (std::string, s)
        );
    } s{ nullptr, 3.14, "Hello" };
    boost::hana::for_each(s, [](auto pair){ std::cout << boost::hana::second(pair) << '\n'; });
}

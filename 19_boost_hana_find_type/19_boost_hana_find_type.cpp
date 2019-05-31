#include <boost/hana.hpp>
#include <string>
#include <type_traits>

int main()
{
    constexpr auto t1 = boost::hana::make_tuple(boost::hana::type_c<int*>, boost::hana::type_c<double>, boost::hana::type_c<std::string>);
    constexpr auto r1{ boost::hana::find(t1, boost::hana::type_c<std::string>) };
    static_assert(boost::hana::is_just(r1));

    boost::hana::tuple<int*, double, std::string> t2;
    auto r2 { boost::hana::find_if(t2, [](auto t){ return boost::hana::bool_c<std::is_same<decltype(t), std::string>::value>; }) };
    static_assert(boost::hana::is_just(r2));
}

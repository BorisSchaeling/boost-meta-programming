#include <boost/mp11/mpl.hpp>
#include <string>
#include <tuple>
#include <type_traits>

template <int I>
using int_ = std::integral_constant<int, I>;

int main()
{
    using v1 = boost::mp11::mp_list<int*, double, std::string>;
    using r1_index = boost::mp11::mp_find<v1, std::string>;
    using v1_size = boost::mp11::mp_size<v1>;
    using in_v1 = boost::mp11::mp_less<r1_index, v1_size>;
    constexpr int r1{ boost::mp11::mp_if<in_v1, r1_index, int_<-1>>::value };
    static_assert(r1 == 2);

    using v2 = std::tuple<int*, double, bool>;
    using r2_index = boost::mp11::mp_find<v2, std::string>;
    using v2_size = boost::mp11::mp_size<v2>;
    using in_v2 = boost::mp11::mp_less<r2_index, v2_size>;
    constexpr int r2{ boost::mp11::mp_if<in_v2, r2_index, int_<-1>>::value };
    static_assert(r2 == -1);
}

#include <boost/mp11/mpl.hpp>
#include <tuple>
#include <type_traits>

template <int I>
using int_ = std::integral_constant<int, I>;

int main()
{
    using v1 = boost::mp11::mp_list_c<int, 5, 2, 3, 1, 4>;
    using index1 = boost::mp11::mp_find<v1, int_<3>>;
    using size1 = boost::mp11::mp_size<v1>;
    using in_v1 = boost::mp11::mp_less<index1, size1>;
    constexpr int r1{ boost::mp11::mp_if<in_v1, index1, int_<-1>>::value };
    static_assert(r1 == 2);

    using v2 = std::tuple<int_<5>, int_<2>, int_<3>>;
    using index2 = boost::mp11::mp_find<v2, int_<6>>;
    using size2 = boost::mp11::mp_size<v2>;
    using in_v2 = boost::mp11::mp_less<index2, size2>;
    constexpr int r2{ boost::mp11::mp_if<in_v2, index2, int_<-1>>::value };
    static_assert(r2 == -1);
}

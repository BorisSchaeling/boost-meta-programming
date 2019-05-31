#include <boost/mpl/vector.hpp>
#include <boost/mpl/vector_c.hpp>
#include <boost/mpl/integral_c.hpp>
#include <boost/mpl/find.hpp>

int main()
{
    using v1 = boost::mpl::vector<boost::mpl::integral_c<int, 5>, boost::mpl::integral_c<int, 2>, boost::mpl::integral_c<int, 3>, boost::mpl::integral_c<int, 1>, boost::mpl::integral_c<int, 4>>;
    using it1 = boost::mpl::find<v1, boost::mpl::integral_c<int, 3>>::type;
    using pos1 = it1::pos;
    constexpr int r1{ pos1::value };
    static_assert(r1 == 2);

    using v2 = boost::mpl::vector_c<int, 5, 2, 3>;
    using it2 = boost::mpl::find<v2, boost::mpl::integral_c<int, 6>>::type;
    using pos2 = it2::pos;
    constexpr int r2{ pos2::value };
    static_assert(r2 == 3);
}

#include <boost/mpl/vector_c.hpp>
#include <boost/mpl/integral_c.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/find.hpp>
#include <boost/mpl/size.hpp>
#include <boost/mpl/less.hpp>
#include <boost/mpl/if.hpp>

int main()
{
    using v1 = boost::mpl::vector_c<int, 5, 2, 3, 1, 4>;
    using it1 = boost::mpl::find<v1, boost::mpl::integral_c<int, 3>>::type;
    using index1 = it1::pos;
    using size1 = boost::mpl::size<v1>::type;
    using in_v1 = boost::mpl::less<index1, size1>::type;
    constexpr int r1{ boost::mpl::if_<in_v1, index1, boost::mpl::int_<-1>>::type::value };
    static_assert(r1 == 2);

    using v2 = boost::mpl::vector_c<int, 5, 2, 3>;
    using it2 = boost::mpl::find<v2, boost::mpl::integral_c<int, 6>>::type;
    using index2 = it2::pos;
    using size2 = boost::mpl::size<v2>::type;
    using in_v2 = boost::mpl::less<index2, size2>::type;
    constexpr int r2{ boost::mpl::if_<in_v2, index2, boost::mpl::int_<-1>>::type::value };
    static_assert(r2 == -1);
}

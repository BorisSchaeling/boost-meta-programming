#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/punctuation/comma.hpp>
#include <boost/preprocessor/punctuation/comma_if.hpp>
#include <boost/preprocessor/arithmetic/inc.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>

template <int Val>
constexpr int find()
{
    return -1;
}

#define FIND_TEMPLATE_PARAMETERS(z, n, text) BOOST_PP_COMMA_IF(n) BOOST_PP_CAT(text, n)

#define FIND_TEMPLATE_ARGUMENTS(z, n, text) BOOST_PP_COMMA() BOOST_PP_CAT(text, n)

#define FIND_TEMPLATE(z, n, _) \
    template <int Val, BOOST_PP_REPEAT_ ## z(BOOST_PP_INC(n), FIND_TEMPLATE_PARAMETERS, int Arg)> \
    constexpr int find() \
    { \
        return Val == BOOST_PP_CAT(Arg, n) ? n : find<Val BOOST_PP_REPEAT_ ## z(n, FIND_TEMPLATE_ARGUMENTS, Arg)>(); \
    }

BOOST_PP_REPEAT(5, FIND_TEMPLATE, nil)

int main()
{
    constexpr int r1{ find<3, 5, 2, 3, 1, 4>() };
    static_assert(r1 == 2);

    constexpr int r2{ find<6, 5, 2, 3>() };
    static_assert(r2 == -1);
}

#include <boost/hana.hpp>
#include <string>
#include <type_traits>
#include <iostream>

struct person {
    BOOST_HANA_DEFINE_STRUCT(person,
        (std::string, name),
        (int, age)
    );
};

struct foldable_tag
{};

struct not_foldable_tag
{};

template <class T>
void serialize_impl(T t, not_foldable_tag) { std::cout << t << '\n'; }

template <class T>
void serialize_impl(T t, foldable_tag) { boost::hana::for_each(t, [](auto pair){ std::cout << boost::hana::second(pair) << '\n'; }); }

template <class T>
void serialize(T t) {
    using tag = std::conditional_t<boost::hana::Foldable<T>::value, foldable_tag, not_foldable_tag>;
    serialize_impl(t, tag{});
}

int main()
{
    person tom{ "Tom", 35 };
    serialize(tom);

    std::string s{"String"};
    serialize(s);

    int i{1};
    serialize(i);
}

#include <boost/hana.hpp>
#include <string>
#include <utility>
#include <iostream>

struct person {
    std::string name;
    int age;

    void serialize(std::ostream &os) const
    {
        os << name << '\n' << age << '\n';
    }
};

auto has_serialize = boost::hana::is_valid([](auto &&obj) -> decltype(obj.serialize(std::declval<std::ostream&>())) {});

template <class T>
void serialize(const T &t)
{
    if constexpr (has_serialize(t))
        t.serialize(std::cout);
    else
        std::cout << t << '\n';
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

#include <boost/hana.hpp>
#include <string>
#include <iostream>

struct person {
    std::string name;
    int age;

    void serialize(std::ostream &os) const
    {
        os << name << '\n' << age << '\n';
    }
};

template <class T>
auto serialize(const T &t) -> decltype(std::cout << t)
{ std::cout << t << '\n'; }

template <class T>
auto serialize(const T &t) -> decltype(t.serialize(std::cout))
{ t.serialize(std::cout); }

int main()
{
    person tom{ "Tom", 35 };
    serialize(tom);

    std::string s{"String"};
    serialize(s);

    int i{1};
    serialize(i);
}

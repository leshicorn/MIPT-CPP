#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Person
{
public:
    // Конструктор по умолчанию (без аргументов)
    Person() : surname(""), name(""), middleName("") {}

    // Конструктор, принимающий фамилию, имя и отчество
    Person(std::string surname, std::string name, std::string middleName)
        : surname(surname), name(name), middleName(middleName) {}

    // Оператор ввода для класса Person
    friend std::istream& operator>>(std::istream& in, Person& person)
    {
        in >> person.surname >> person.name >> person.middleName;
        return in;
    }

    // Оператор вывода для класса Person
    friend std::ostream& operator<<(std::ostream& out, const Person& person)
    {
        out << person.surname << " " << person.name << " " << person.middleName;
        return out;
    }

    // Оператор сравнения для класса Person
    bool operator<(const Person& other) const
    {
        if (surname != other.surname)
            return surname < other.surname;
        if (name != other.name)
            return name < other.name;
        return middleName < other.middleName;
    }

private:
    std::string surname;
    std::string name;
    std::string middleName;
};

int main()
{
    std::cout << "Testing I/O" << std::endl;
    Person p;
    std::cin >> p;
    std::cout << p << std::endl;

    std::cout << "Testing sorting" << std::endl;
    std::vector<Person> people;
    people.push_back(Person("Ivanov", "Ivan", "Ivanovich"));
    people.push_back(Person("Petrov", "Petr", "Petrovich"));
    people.push_back(Person("Ivanov", "Ivan", "Petrovich"));
    people.push_back(Person("Ivanov", "Petr", "Ivanovich"));

    // Сортировка вектора людей
    std::sort(people.begin(), people.end());

    for (const Person& person : people)
    {
        std::cout << person << std::endl;
    }

    return 0;
}

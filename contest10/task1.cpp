#include <iostream>
#include <string>

class Student
{
public:
    // Задать имя студента
    void setName(std::string name)
    {
        this->name = name;
    }

    // Указать количество баллов за контрольную
    void setScore(unsigned int score)
    {
        this->score = score;
    }

    // Получить имя студента
    std::string getName() const
    {
        return name;
    }

    // Получить количество баллов студента
    unsigned int getScore() const
    {
        return score;
    }

    // Перегрузка оператора ввода >>
    friend std::istream& operator>>(std::istream& is, Student& student)
    {
        // Считываем имя студента (возможно, с пробелами)
        std::getline(is, student.name);

        // Устанавливаем баллы в 0
        student.score = 0;

        return is;
    }

    // Перегрузка оператора вывода <<
    friend std::ostream& operator<<(std::ostream& os, const Student& student)
    {
        os << "'" << student.name << "': " << student.score;
        return os;
    }

private:
    std::string name;
    unsigned int score;
};

int main()
{
    Student s;
    std::cin >> s;
    s.setScore(10);
    std::cout << s;

    return 0;
}

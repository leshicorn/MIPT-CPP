#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct Student {
    std::string lastName;
    std::string firstName;
    std::string patronymic;
    int birthYear;
    int course;
    std::string groupNumber;
    std::vector<int> grades;

    Student(const std::string& ln, const std::string& fn, const std::string& patr, int year, int c, const std::string& group, const std::vector<int>& gr)
        : lastName(ln), firstName(fn), patronymic(patr), birthYear(year), course(c), groupNumber(group), grades(gr) {}
};

struct Node {
    Student data;
    Node* next;
};

Node* head = nullptr;

// Функция для создания списка из 10 звеньев с введенными значениями
void createList() {
    for (int i = 0; i < 10; ++i) {
        std::string lastName, firstName, patronymic, group;
        int year, course;
        std::vector<int> grades;

        std::cout << "Введите данные для студента " << i + 1 << ":\n";
        std::cout << "Фамилия: ";
        std::cin >> lastName;
        std::cout << "Имя: ";
        std::cin >> firstName;
        std::cout << "Отчество: ";
        std::cin >> patronymic;
        std::cout << "Год рождения: ";
        std::cin >> year;
        std::cout << "Курс: ";
        std::cin >> course;
        std::cout << "Номер группы: ";
        std::cin >> group;

        std::cout << "Оценки по 5 предметам: ";
        for (int j = 0; j < 5; ++j) {
            int grade;
            std::cin >> grade;
            grades.push_back(grade);
        }

        Student student(lastName, firstName, patronymic, year, course, group, grades);

        Node* newNode = new Node{student, head};
        head = newNode;
    }
}

// Функция для добавления первого звена
void addFirstNode() {
    std::string lastName, firstName, patronymic, group;
    int year, course;
    std::vector<int> grades;

    std::cout << "Введите данные для студента:\n";
    std::cout << "Фамилия: ";
    std::cin >> lastName;
    std::cout << "Имя: ";
    std::cin >> firstName;
    std::cout << "Отчество: ";
    std::cin >> patronymic;
    std::cout << "Год рождения: ";
    std::cin >> year;
    std::cout << "Курс: ";
    std::cin >> course;
    std::cout << "Номер группы: ";
    std::cin >> group;

    std::cout << "Оценки по 5 предметам: ";
    for (int i = 0; i < 5; ++i) {
        int grade;
        std::cin >> grade;
        grades.push_back(grade);
    }

    Student student(lastName, firstName, patronymic, year, course, group, grades);

    Node* newNode = new Node{student, head};
    head = newNode;
}

// Функция для добавления последнего звена
void addLastNode() {
    Node* newNode = head;
    while (newNode->next != nullptr) {
        newNode = newNode->next;
    }

    std::string lastName, firstName, patronymic, group;
    int year, course;
    std::vector<int> grades;

    std::cout << "Введите данные для студента:\n";
    std::cout << "Фамилия: ";
    std::cin >> lastName;
    std::cout << "Имя: ";
    std::cin >> firstName;
    std::cout << "Отчество: ";
    std::cin >> patronymic;
    std::cout << "Год рождения: ";
    std::cin >> year;
    std::cout << "Курс: ";
    std::cin >> course;
    std::cout << "Номер группы: ";
    std::cin >> group;

    std::cout << "Оценки по 5 предметам: ";
    for (int i = 0; i < 5; ++i) {
        int grade;
        std::cin >> grade;
        grades.push_back(grade);
    }

    Student student(lastName, firstName, patronymic, year, course, group, grades);
    newNode->next = new Node{student, nullptr};
}

// Функция для добавления звена до или после звена с заданным элементом
void addNodeBeforeOrAfterElement(const std::string& lastNameToFind, bool before) {
    Node* current = head;
    Node* previous = nullptr;

    std::string lastName, firstName, patronymic, group;
    int year, course;
    std::vector<int> grades;

    std::cout << "Введите данные для нового студента:\n";
    std::cout << "Фамилия: ";
    std::cin >> lastName;
    std::cout << "Имя: ";
    std::cin >> firstName;
    std::cout << "Отчество: ";
    std::cin >> patronymic;
    std::cout << "Год рождения: ";
    std::cin >> year;
    std::cout << "Курс: ";
    std::cin >> course;
    std::cout << "Номер группы: ";
    std::cin >> group;

    std::cout << "Оценки по 5 предметам: ";
    for (int i = 0; i < 5; ++i) {
        int grade;
        std::cin >> grade;
        grades.push_back(grade);
    }

    Student student(lastName, firstName, patronymic, year, course, group, grades);

    while (current != nullptr && current->data.lastName != lastNameToFind) {
        previous = current;
        current = current->next;
    }

    if (current != nullptr) {
        Node* newNode = new Node{student, nullptr};
        if (before) {
            newNode->next = current;
            if (previous != nullptr) {
                previous->next = newNode;
            } else {
                head = newNode;
            }
        } else {
            newNode->next = current->next;
            current->next = newNode;
        }
    } else {
        std::cout << "Элемент с фамилией '" << lastNameToFind << "' не найден.\n";
    }
}

// Функция для удаления первого звена
void deleteFirstNode() {
    if (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    } else {
        std::cout << "Список пуст, невозможно удалить первое звено.\n";
    }
}

// Функция для удаления последнего звена
void deleteLastNode() {
    if (head == nullptr) {
        std::cout << "Список пуст, невозможно удалить последнее звено.\n";
        return;
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
    } else {
        Node* current = head;
        Node* previous = nullptr;

        while (current->next != nullptr) {
            previous = current;
            current = current->next;
        }

        previous->next = nullptr;
        delete current;
    }
}

// Функция для удаления звена с заданным элементом
void deleteNodeWithElement(const std::string& lastNameToDelete) {
    if (head == nullptr) {
        std::cout << "Список пуст, невозможно удалить элемент.\n";
        return;
    }

    Node* current = head;
    Node* previous = nullptr;

    while (current != nullptr && current->data.lastName != lastNameToDelete) {
        previous = current;
        current = current->next;
    }

    if (current != nullptr) {
        if (previous != nullptr) {
            previous->next = current->next;
        } else {
            head = current->next;
        }
        delete current;
    } else {
        std::cout << "Элемент с фамилией '" << lastNameToDelete << "' не найден.\n";
    }
}

// Функция для записи списка в файл
void writeListToFile(const std::string& filename) {
    std::ofstream file(filename);
    Node* current = head;

    while (current != nullptr) {
        file << current->data.lastName << " " << current->data.firstName << " " << current->data.patronymic << " " <<
            current->data.birthYear << " " << current->data.course << " " << current->data.groupNumber << " ";
        for (int grade : current->data.grades) {
            file << grade << " ";
        }
        file << "\n";
        current = current->next;
    }

    file.close();
}

// Функция для печати списка
void printList() {
    Node* current = head;

    while (current != nullptr) {
        std::cout << "Фамилия: " << current->data.lastName << "\n";
        std::cout << "Имя: " << current->data.firstName << "\n";
        std::cout << "Отчество: " << current->data.patronymic << "\n";
        std::cout << "Год рождения: " << current->data.birthYear << "\n";
        std::cout << "Курс: " << current->data.course << "\n";
        std::cout << "Номер группы: " << current->data.groupNumber << "\n";
        std::cout << "Оценки по 5 предметам: ";
        for (int grade : current->data.grades) {
            std::cout << grade << " ";
        }
        std::cout << "\n\n";
        current = current->next;
    }
}

// Функция для удаления всего списка
void deleteList() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// Функция для выполнения задачи 11
void duplicateElements() {
    Node* current = head;
    while (current != nullptr) {
        Node* newNode = new Node{current->data, current->next};
        current->next = newNode;
        current = newNode->next;
    }
}

int main() {
    std::string lastNameToFind; // Переменная объявлена здесь

    int choice;
    while (true) {
        std::cout << "Выберите действие:\n";
        std::cout << "1. Создать список из 10 звеньев\n";
        std::cout << "2. Добавить первое звено\n";
        std::cout << "3. Добавить последнее звено\n";
        std::cout << "4. Добавить звено до элемента\n";
        std::cout << "5. Удалить первое звено\n";
        std::cout << "6. Удалить последнее звено\n";
        std::cout << "7. Удалить звено с элементом\n";
        std::cout << "8. Записать список в файл\n";
        std::cout << "9. Печать списка\n";
        std::cout << "10. Удаление всего списка\n";
        std::cout << "11. Дублировать элементы списка\n";
        std::cout << "0. Выход\n";
        std::cin >> choice;

        switch (choice) {
            case 1:
                createList();
                break;
            case 2:
                addFirstNode();
                break;
            case 3:
                addLastNode();
                break;
            case 4:
                std::cout << "Введите фамилию элемента, перед которым хотите добавить новое звено: ";
                std::cin >> lastNameToFind;
                std::cout << "Добавить перед (0) или после (1) элемента? ";
                int beforeOrAfter;
                std::cin >> beforeOrAfter;
                addNodeBeforeOrAfterElement(lastNameToFind, beforeOrAfter == 0);
                break;
            case 5:
                deleteFirstNode();
                break;
            case 6:
                deleteLastNode();
                break;
            case 7:
                std::cout << "Введите фамилию элемента, который хотите удалить: ";
                std::cin >> lastNameToFind;
                deleteNodeWithElement(lastNameToFind);
                break;
            case 8:
                writeListToFile("student_list.txt");
                break;
            case 9:
                printList();
                break;
            case 10:
                deleteList();
                break;
            case 11:
                duplicateElements();
                break;
            case 0:
                deleteList();
                return 0;
            default:
                std::cout << "Неверный выбор. Попробуйте еще раз.\n";
                break;
        }
}

    return 0;
}

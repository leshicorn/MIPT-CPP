/*
Этот код представляет собой пример использования полиморфизма и наследования в языке программирования C++. Он решает задачу создания и использования различных обработчиков (handlers), которые могут выполнять различные операции в зависимости от своего типа.

Формат ввода:

    Вводится имя пользователя (username).
    Затем вводится количество обработчиков (handlerCount).
    Для каждого обработчика вводится его имя (handlerName).

Формат вывода:

    Для каждого обработчика выводится сообщение о запуске (Running handler) и имя пользователя.
    Вызывается метод preProcess для каждого обработчика.
    Проверяется доступ пользователя к обработчику с помощью метода accessAllowed.
    Если доступ разрешен, вызывается метод run, иначе выводится сообщение "Access denied".
    Вызывается метод postProcess для каждого обработчика.
    Объекты обработчиков освобождаются с помощью оператора delete.  

Пример ввода:
    admin
    3
    HandlerOne
    HandlerTwo
    HandlerThree
Пример вывода:
    Running handler HandlerOne for user admin
    SmartHandler preprocess
    SmartHandler runs
    SmartHandler postprocess
    Running handler HandlerTwo for user admin
    SmartHandler preprocess
    SmartHandler runs
    SmartHandler postprocess
    Running handler HandlerThree for user admin
    HeavyHandler runs

*/

#include <iostream>
#include <string>

class Handler {
public:
    virtual void preProcess() {
        // Реализация по умолчанию ничего не делает
    }

    virtual void postProcess() {
        // Реализация по умолчанию ничего не делает
    }

    virtual bool accessAllowed(std::string username) {
        // Реализация по умолчанию всегда разрешает доступ
        if (username == "14") return true;
        return true;
    }

    virtual void run() = 0;

    virtual ~Handler() {
        // Виртуальный деструктор
    }
};

class BadHandler : public Handler {
    // Не предоставляем реализацию метода run, что некорректно
};

/**
 * @brief Класс, который реализует фиктивный обработчик.
 * 
 * Этот класс наследуется от класса Handler и переопределяет его метод run() для вывода сообщения на консоль.
 */
class DummyHandler : public Handler {
public:
    /**
     * @brief Запускает фиктивный обработчик.
     * 
     * Этот метод просто выводит сообщение на консоль.
     */
    void run() override {
        std::cout << "DummyHandler runs" << std::endl;
    }
};

/**
 * @brief Класс, который реализует интерфейс обработчика и предоставляет дополнительные функциональные возможности.
 */
class SmartHandler : public Handler {
public:
    /**
     * @brief Запускается перед основным процессом и выводит сообщение на консоль.
     */
    void preProcess() override {
        std::cout << "SmartHandler preprocess" << std::endl;
    }

    /**
     * @brief Запускается после основного процесса и выводит сообщение на консоль.
     */
    void postProcess() override {
        std::cout << "SmartHandler postprocess" << std::endl;
    }

    /**
     * @brief Проверяет, есть ли у пользователя доступ к процессу.
     * @param username Имя пользователя.
     * @return Истинно, если пользователь является администратором, ложно в противном случае.
     */
    bool accessAllowed(std::string username) override {
        return username == "admin";
    }

    /**
     * @brief Запускает основной процесс и выводит сообщение в консоль.
     */
    void run() override {
        std::cout << "SmartHandler runs" << std::endl;
    }
};

/**
 * @brief Класс, который наследуется от Handler и выделяет массив из 1000 целых чисел в конструкторе.
 * 
 */
class HeavyHandler : public Handler {
protected:
    int* data;

public:
    /**
     * @brief Создайте новый объект HeavyHandler и выделите массив из 1000 целых чисел.
     * 
     */
    HeavyHandler() {
        data = new int[1000];
    }

    /**
     * @brief Уничтожьте объект HeavyHandler и освободите массив целых чисел.
     * 
     */
    ~HeavyHandler() {
        delete[] data;
    }

    /**
     * @brief Runs the HeavyHandler object.
     * 
     */
    void run() override {
        std::cout << "HeavyHandler runs" << std::endl;
    }
};

int main() {
    std::string username;
    std::cin >> username;

    int handlerCount;
    std::cin >> handlerCount;

    for (int i = 0; i < handlerCount; ++i) {
        std::string handlerName;
        std::cin >> handlerName;

        Handler* h = nullptr;

        if (handlerName == "HandlerOne") {
            h = new DummyHandler();
        } else if (handlerName == "HandlerTwo") {
            h = new SmartHandler();
        } else if (handlerName == "HandlerThree") {
            h = new HeavyHandler();
        }

        if (h) {
            std::cout << "Running handler " << handlerName << " for user " << username << std::endl;
            h->preProcess();
            if (h->accessAllowed(username)) {
                h->run();
            } else {
                std::cout << "Access denied" << std::endl;
            }
            h->postProcess();
            delete h;
        } else {
            std::cout << "Invalid handler name: " << handlerName << std::endl;
        }
    }

    return 0;
}

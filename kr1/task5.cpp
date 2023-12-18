/*
Этот код предоставляет простую систему регистрации и выполнения модулей. Программа начинается с ввода количества модулей (moduleCount) и затем регистрирует каждый модуль с именем "moduleOne" или "moduleTwo". Затем программа запрашивает количество выполнений модулей (runCount) и выполняет соответствующий модуль по его имени.

Формат ввода:

    Вводится количество модулей (moduleCount).
    Затем для каждого модуля вводится его имя ("moduleOne" или "moduleTwo").
    Затем вводится количество выполнений модулей (runCount).
    Затем для каждого выполнения вводится имя модуля, который нужно выполнить.

Формат вывода:
Программа выводит информацию о регистрации модулей и о выполнении каждого модуля. Если модуль не найден при выполнении, программа сообщит об этом.

Пример:

Input:
    2
    moduleOne
    moduleTwo
    3
    moduleOne
    moduleTwo
    moduleC

Output:
    Registering module: moduleOne
    Registering module: moduleTwo
    Running module: moduleOne
    moduleOne runs
    Running module: moduleTwo
    moduleTwo runs
    Module not found: moduleC

*/

#include <iostream>
#include <string>
#include <unordered_map>

class Module {
public:
    virtual std::string getName() const = 0;
    virtual void run() = 0;
};

class moduleOne : public Module {
public:
    std::string getName() const override {
        return "moduleOne";
    }
    void run() override {
        std::cout << "moduleOne runs" << std::endl;
    }
};

class moduleTwo : public Module {
public:
    std::string getName() const override {
        return "moduleTwo";
    }
    void run() override {
        std::cout << "moduleTwo runs" << std::endl;
    }
};

class Dispatcher {
public:
    void registerModule(Module* m) {
        if (m) {
            modules[m->getName()] = m;
            // std::cout << "Registering module: " << m->getName() << std::endl;
        }
    }

    void runModule(const std::string moduleName) const {
    if (modules.count(moduleName) > 0) {
        // std::cout << "Running module: " << moduleName << std::endl;
        modules.at(moduleName)->run();
    } else {
        // std::cout << "Module not found: " << moduleName << std::endl;
    }
}


private:
    std::unordered_map<std::string, Module*> modules;
};

int main() {
    int moduleCount;
    std::cin >> moduleCount;
    std::cin.ignore(); // Сбросим символ новой строки

    Dispatcher dispatcher;

    for (int i = 0; i < moduleCount; ++i) {
        std::string moduleName;
        std::getline(std::cin, moduleName);
        if (moduleName.empty()) continue;

        if (moduleName == "moduleOne") {
            dispatcher.registerModule(new moduleOne());
        } else if (moduleName == "moduleTwo") {
            dispatcher.registerModule(new moduleTwo());
        }
    }

    int runCount;
    std::cin >> runCount;
    std::cin.ignore(); // Сбросим символ новой строки

    for (int i = 0; i < runCount; ++i) {
        std::string moduleName;
        std::getline(std::cin, moduleName);
        if (moduleName.empty()) continue;

        dispatcher.runModule(moduleName);
    }

    return 0;
}

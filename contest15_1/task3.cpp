#include <iostream>
#include <string>
#include <set>
#include <map>

class ResultsHolder {
private:
    std::map<std::string, unsigned> results;

public:
    void update(const std::string& full_name, unsigned mark) {
        results[full_name] = mark;
    }

    void print_students() const {
        for (const auto& entry : results) {
            std::cout << entry.first << " " << entry.second << std::endl;
        }
    }

    void print_standings() const {
        std::multiset<std::pair<unsigned, std::string>, std::greater<>> standings;

        for (const auto& entry : results) {
            standings.emplace(entry.second, entry.first);
        }

        for (const auto& entry : standings) {
            std::cout << entry.second << " " << entry.first << std::endl;
        }
    }

    std::set<std::string> process_military_request(const std::set<std::string>& names) {
        std::set<std::string> eligible_for_military;

        for (const auto& name : names) {
            auto it = results.find(name);
            if (it != results.end() && it->second < 3) {
                eligible_for_military.insert(name);
                results.erase(it);
            }
        }

        return eligible_for_military;
    }
};

int main() {
    ResultsHolder rh;

    rh.update("Alex", 6);
    rh.update("Anny", 5);
    rh.update("Ivan", 10);
    rh.update("Anastasia", 9);
    rh.update("Johnny", 1);
    rh.update("Alex", 7);
    rh.update("Nikita", 8);

    std::cout << "Exam results:" << std::endl;
    rh.print_standings();

    std::set<std::string> to_military_service = rh.process_military_request({"Ivan", "Johnny"});

    std::cout << "MoD request:" << std::endl;
    for (const auto& s : to_military_service) {
        std::cout << s << std::endl;
    }

    std::cout << "Next year group:" << std::endl;
    rh.print_students();

    return 0;
}

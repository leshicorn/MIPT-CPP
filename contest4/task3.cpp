#include <iostream>
#include <vector>
#include <string>

using namespace std;

const vector<int> days_in_month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    int Q;
    cin >> Q;
    
    vector<vector<string>> monthly_schedule(31); // Вектор списков дел на каждый день месяца
    int current_day = 0; // Текущий день
    int current_month = 0; // Текущий месяц
    
    for (int i = 0; i < Q; i++) {
        string command;
        cin >> command;
        
        if (command == "ADD") {
            int day;
            string task;
            cin >> day >> task;
            monthly_schedule[day - 1].push_back(task); // Добавляем дело в список на указанный день
        } else if (command == "DUMP") {
            int day;
            cin >> day;
            cout << monthly_schedule[day - 1].size() << " ";
            for (const string& task : monthly_schedule[day - 1]) {
                cout << task << " ";
            }
            cout << endl;
        } else if (command == "NEXT") {
            int next_month = (current_month + 1) % 12; // Переходим к следующему месяцу
            int days_in_current_month = days_in_month[current_month];
            int days_in_next_month = days_in_month[next_month];
            
            // Переносим дела с "лишних" дней текущего месяца
            if (days_in_next_month < days_in_current_month) {
                for (int day = days_in_next_month; day < days_in_current_month; day++) {
                    monthly_schedule[days_in_next_month - 1].insert(
                        monthly_schedule[days_in_next_month - 1].end(),
                        monthly_schedule[day].begin(),
                        monthly_schedule[day].end()
                    );
                }
            }
            
            monthly_schedule.resize(days_in_next_month); // Устанавливаем размер для нового месяца
            current_month = next_month;
            current_day = min(current_day, days_in_next_month - 1);
        }
    }
    
    return 0;
}

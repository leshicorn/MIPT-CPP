#include <vector>
#include <algorithm>
#include <iostream>

class ResultsTable
{
public:
    void addResult(unsigned int score)
    {
        results.push_back(score);
    }

    unsigned int getMinScore() const
    {
        if (results.empty())
        {
            // Если нет результатов, возвращаем 0 или другое значение по умолчанию.
            // В данной реализации, возвращаем 0.
            return 0;
        }

        // Используем алгоритм std::min_element для нахождения минимального значения.
        return *std::min_element(results.begin(), results.end());
    }

    unsigned int getScoreForPosition(unsigned int positionNumber) const
    {
        if (positionNumber > results.size() || positionNumber == 0)
        {
            // Если запрошена позиция, которой нет, возвращаем 0 или другое значение по умолчанию.
            // В данной реализации, возвращаем 0.
            return 0;
        }

        // Сначала сортируем результаты в убывающем порядке.
        std::vector<unsigned int> sortedResults = results;
        std::sort(sortedResults.rbegin(), sortedResults.rend());

        // Затем возвращаем результат по запрошенной позиции (месту).
        return sortedResults[positionNumber - 1];
    }

private:
    std::vector<unsigned int> results;
};

int main()
{
    ResultsTable t;
    t.addResult(30);
    t.addResult(85);
    t.addResult(12);
    t.addResult(31);

    std::cout << "1st place score: " << t.getScoreForPosition(1) << std::endl;
    std::cout << "2nd place score: " << t.getScoreForPosition(2) << std::endl;
    std::cout << "3rd place score: " << t.getScoreForPosition(3) << std::endl;
    std::cout << "Min score during the tournament: " << t.getMinScore() << std::endl;

    return 0;
}

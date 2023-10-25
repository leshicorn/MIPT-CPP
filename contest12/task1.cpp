#include <vector>
#include <iostream>

class Task
{
protected:
    int cpuNum;
    int size;

public:
    Task(int cpuNum, int size)
    {
        this->cpuNum = cpuNum;
        this->size = size;
    }

    int getCPU() const
    {
        return cpuNum;
    }

    int getSize() const
    {
        return size;
    }
};

class Analyzer
{
private:
    int numCores;
    std::vector<int> coreLoads;

public:
    Analyzer(int numCores) : numCores(numCores), coreLoads(numCores, 0)
    {
    }

    void analyze(const std::vector<Task> &tasks)
    {
        // Сначала сбросим нагрузку на каждом ядре
        for (int i = 0; i < numCores; i++)
        {
            coreLoads[i] = 0;
        }

        // Затем пересчитаем нагрузку на каждом ядре на основе задач
        for (const Task &task : tasks)
        {
            int cpuNum = task.getCPU();
            int taskSize = task.getSize();
            coreLoads[cpuNum] += taskSize;
        }
    }

    int getLoadForCPU(int cpuNum)
    {
        if (cpuNum >= 0 && cpuNum < numCores)
        {
            return coreLoads[cpuNum];
        }
        return 0; // Если указан недопустимый номер ядра
    }
};

int main()
{
    int numberOfCores = 4;
    std::vector<Task> data = {{0, 1}, {1, 10}, {0, 6}, {2, 12}, {3, 5}};
    Analyzer a(numberOfCores);
    a.analyze(data);

    for (int i = 0; i < numberOfCores; i++)
    {
        std::cout << a.getLoadForCPU(i) << std::endl;
    }

    return 0;
}

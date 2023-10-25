#include <iostream>
#include <string>
#include <unordered_map>
#include <limits>

class TelemetryController
{
public:
    void handleEvent(const std::string& device, long value)
    {
        // Проверяем, существует ли устройство в нашей хэш-таблице
        if (data.find(device) == data.end())
        {
            data[device] = TelemetryData(); // Если нет, создаем новую запись
        }

        // Обновляем статистику для устройства
        data[device].count++;
        data[device].minValue = std::min(data[device].minValue, value);
        data[device].maxValue = std::max(data[device].maxValue, value);
    }

    unsigned int getEventsCount(const std::string& device) const
    {
        if (data.find(device) != data.end())
        {
            return data.at(device).count;
        }
        return 0;
    }

    long getMinValue(const std::string& device) const
    {
        if (data.find(device) != data.end())
        {
            return data.at(device).minValue;
        }
        return std::numeric_limits<long>::max(); // Возвращаем максимальное значение, если устройство не найдено
    }

    long getMaxValue(const std::string& device) const
    {
        if (data.find(device) != data.end())
        {
            return data.at(device).maxValue;
        }
        return std::numeric_limits<long>::min(); // Возвращаем минимальное значение, если устройство не найдено
    }

private:
    struct TelemetryData
    {
        unsigned int count = 0;
        long minValue = std::numeric_limits<long>::max();
        long maxValue = std::numeric_limits<long>::min();
    };

    std::unordered_map<std::string, TelemetryData> data;
};

int main()
{
    TelemetryController tc;
    tc.handleEvent("d1", 42);
    tc.handleEvent("d1", -42);
    tc.handleEvent("d2", 100);
    std::cout << "Events count for d1: " << tc.getEventsCount("d1") << std::endl;
    std::cout << "Min value for d1: " << tc.getMinValue("d1") << std::endl;
    std::cout << "Max value for d1: " << tc.getMaxValue("d1") << std::endl;

    return 0;
}

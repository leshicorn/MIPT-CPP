#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Connection
{
public:
    Connection(std::string source, unsigned short int port, unsigned long long timestamp) : source(source), port(port), timestamp(timestamp) {}

    std::string getSource() const { return source; }
    unsigned short int getPort() const { return port; }
    unsigned long long getTimestamp() const { return timestamp; }

private:
    std::string source;
    unsigned short int port;
    unsigned long long timestamp;
};

class IntrusionDetector
{
public:
    void setTimeThreshold(unsigned short int timeThreshold) { this->timeThreshold = timeThreshold; }
    void setPortLimit(unsigned short int portLimit) { this->portLimit = portLimit; }

    void handleConnection(const Connection& c)
    {
        // Обновляем хранилище сетевых подключений
        connections.push_back(c);

        // Проверяем, является ли это подключение потенциальным нарушителем
        if (isPotentialIntruder(c.getSource()))
        {
            intruders.insert(c.getSource());
        }
    }

    bool isIntruder(const std::string& source) const
    {
        return intruders.find(source) != intruders.end();
    }

private:
    unsigned short int timeThreshold = 5; // По умолчанию
    unsigned short int portLimit = 3;     // По умолчанию

    std::vector<Connection> connections;
    std::unordered_set<std::string> intruders;

    bool isPotentialIntruder(const std::string& source) const
    {
        int count = 0;
        unsigned long long lastTimestamp = 0;

        for (const Connection& conn : connections)
        {
            if (conn.getSource() == source)
            {
                if (count == 0 || (conn.getTimestamp() - lastTimestamp) <= timeThreshold)
                {
                    count++;
                }
                lastTimestamp = conn.getTimestamp();
            }

            if (count >= portLimit)
            {
                return true;
            }
        }

        return false;
    }
};

int main()
{
    IntrusionDetector id;
    id.setTimeThreshold(5);
    id.setPortLimit(3);
    id.handleConnection({"evil.com", 21, 100504});
    id.handleConnection({"evil.com", 22, 100501});
    id.handleConnection({"evil.com", 23, 100502});
    id.handleConnection({"evil.com", 24, 100503});
    id.handleConnection({"evil.com", 25, 100500});
    std::cout << "Checking if evil.com is intruder: " << id.isIntruder("evil.com") << std::endl;

    id.handleConnection({"load.com", 80, 100504});
    id.handleConnection({"load.com", 80, 100501});
    id.handleConnection({"load.com", 80, 100502});
    id.handleConnection({"load.com", 80, 100503});
    id.handleConnection({"load.com", 80, 100500});
    std::cout << "Checking if load.com is intruder: " << id.isIntruder("load.com") << std::endl;

    return 0;
}

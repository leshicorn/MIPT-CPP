#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <forward_list>

using namespace std;

struct Plate {
    unsigned int id;
    string serialNumber;
    enum Type {
        TITANIUM,
        CARBON_SILICATE_LACE
    };
    Type type;
    unsigned int cyclesSinceService;
    vector <unsigned char> sensorData;
    vector <bool> autorepairLog;

};

forward_list<Plate> processDamaged(vector<Plate> &plating) {
    forward_list<Plate> res;
    for (size_t j = 0; j < plating.size(); j++) {
        bool isDamaged = false;
        for (size_t i = 0; i < plating[j].autorepairLog.size(); i++) {
            if (!isDamaged && ((plating[j].sensorData.size() < plating[j].cyclesSinceService) ||
                (plating[j].autorepairLog[i] == false) ||
                (plating[j].cyclesSinceService > 3467 && plating[j].type == Plate::TITANIUM) ||
                (plating[j].cyclesSinceService > 10000 && plating[j].type == Plate::CARBON_SILICATE_LACE))) {
                res.push_front(plating[j]);
                isDamaged = true;
            }
        }
    }
    return res;
}

int main() {
    std::vector <Plate> plating = {
        {
            4354,
            "AFS465EF468",
            Plate::TITANIUM,
            38,
            std::vector <unsigned char> (38),
            std::vector <bool> (38, true)
        },
        {
            5343,
            "FDHGK765CDK",
            Plate::CARBON_SILICATE_LACE,
            2345,
            std::vector <unsigned
            char> (2345),
            std::vector <bool> (2345, true)
        },
        {
            4365,
            "ASDV345OKJJ",
            Plate::TITANIUM,
            100,
            std::vector <unsigned char> (100),
            std::vector <bool> (100, true)
        },
        {
            8724,
            "456JYHF567G",
            Plate::CARBON_SILICATE_LACE,
            100001,
            std::vector <unsigned
            char> (100001),
            std::vector <bool> (100001, true)
        },
        {
            7435,
            "KUYTD8654KF",
            Plate::TITANIUM,
            32,
            std::vector <unsigned char> (32),
            std::vector <bool> (32, true)
        },
        {
            8486,
            "JHTJJYTDJYT",
            Plate::CARBON_SILICATE_LACE,
            46,
            std::vector <unsigned
            char> (46),
            std::vector <bool> (46, true)
        },
        {
            8646,
            "356CJYT8854",
            Plate::TITANIUM,
            51,
            std::vector <unsigned char> (51),
            std::vector <bool> (51, false)
        },
        {
            5476,
            "JHTD6KY65KJ",
            Plate::CARBON_SILICATE_LACE,
            132,
            std::vector <unsigned
            char> (132),
            std::vector <bool> (132, true)
        },
        {
            6874,
            "VV457VTY487",
            Plate::TITANIUM,
            346,
            std::vector <unsigned char> (346),
            std::vector <bool> (346, true)
        },
        {
            1387,
            "JHGFRD648GH",
            Plate::CARBON_SILICATE_LACE,
            12,
            std::vector <unsigned
            char> (11),
            std::vector <bool> (12, true)
        }
    };
    auto damaged = processDamaged(plating);
    for (auto d: damaged) {
        std::cout << d.serialNumber << std::endl;
    }
    return 0;
}
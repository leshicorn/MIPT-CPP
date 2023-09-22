#include <iostream>
#include <algorithm>
#include <vector>

#define R 8.31

class GasHolder {
public:
    float volume; //const
    float temperature;
    float pressure;
    GasHolder(float v) {
        volume = v;
        temperature = 273;
        pressure = 0;
    }
    //  PV = (m/M)RT

    void heat(float dT) {
        float t_prev = temperature;
        float p_prev = pressure;
        temperature += dT;
        pressure = p_prev * temperature / t_prev;
    }

    void cool(float dT) {
        float t_prev = temperature;
        float p_prev = pressure;
        temperature -= dT; 
        if (temperature < 0) {
            temperature = 0;
        }
        pressure = p_prev * temperature / t_prev;
    }

    void inject(float m, float M) {
        pressure += ((m / M) * R * temperature) / volume;
    }

    float getPressure() {
        return pressure;
    }

    ~GasHolder() {
        std::cout << "GasHolder deleted" << std::endl;
    }

};

int main() {

    GasHolder h(1.0);
    h.inject(29, 29);
    std::cout << "Pressure after operation: " << h.getPressure() << " Pa" << "\n";
    h.inject(29, 29);
    std::cout << "Pressure after operation: " << h.getPressure() << " Pa" << "\n";
    h.heat(273);
    std::cout << "Pressure after operation: " << h.getPressure() << " Pa" << "\n";
    h.cool(373);
    std::cout << "Pressure after operation: " << h.getPressure() << " Pa" << "\n";
    h.cool(373);
    std::cout << "Pressure after operation: " << h.getPressure() << " Pa" << "\n";

    return 0;
}
#include <iostream>

class Material {
public:
    virtual float getStress(float strain) = 0;
};

class ElasticMaterial : public Material {
private:
    float elasticModulus;

public:
    ElasticMaterial(float elasticModulus) : elasticModulus(elasticModulus) {}

    float getStress(float strain) override {
        return elasticModulus * strain;
    }
};

class PlasticMaterial : public Material {
private:
    float elasticModulus;
    float strainLimit;

public:
    PlasticMaterial(float elasticModulus, float strainLimit)
        : elasticModulus(elasticModulus), strainLimit(strainLimit) {}

    float getStress(float strain) override {
        if (strain <= strainLimit) {
            return elasticModulus * strain;
        } else {
            return elasticModulus * strainLimit; // Материал начинает течь, напряжение остается постоянным
        }
    }
};

int main() {
    Material* m;
    m = new ElasticMaterial(100);
    std::cout << "Material stress is: " << m->getStress(0.1) << std::endl;
    delete m;

    m = new PlasticMaterial(100, 0.01);
    std::cout << "Material stress is: " << m->getStress(0.1) << std::endl;
    delete m;

    return 0;
}

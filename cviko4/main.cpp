#include <iostream>
using namespace std;

class ElectricCar{
private:
    float m_maxAh;
    float m_avaliableAh;
    float m_maxCurrent;

public:
    ElectricCar(float maxAh, float avaliableAh, float maxCurrent){
        m_maxAh = maxAh;
        m_avaliableAh = avaliableAh;
        m_maxCurrent = maxCurrent;
    }

    float getMaxCurrent(){
        return m_maxCurrent;
    }

    void charge(float maxAhFromPowerStation){
        if((m_avaliableAh + maxAhFromPowerStation) <= m_maxAh){
            m_avaliableAh += maxAhFromPowerStation;
        } else {
            m_avaliableAh = m_maxAh;
        }
    }

    void prfloatInfo(){
        cout << "Max: " << m_maxAh << endl;
        cout << "Current: " << m_avaliableAh << endl;
    }
};

class PowerStation{
private:
    float m_maxCurrent;
    float m_hourChargeAh;

public:
    PowerStation(float maxCurrent, float hourChargeAh){
        m_maxCurrent = maxCurrent;
        m_hourChargeAh = hourChargeAh;
    }

    void chargeForHour(ElectricCar* car){
        car -> charge((car -> getMaxCurrent() / m_maxCurrent) * m_hourChargeAh);
    }
};

int main() {
    PowerStation* ps1 = new PowerStation(4,4);
    ElectricCar* skoda = new ElectricCar(20, 10, 3);
    ps1 -> chargeForHour(skoda);
    skoda -> prfloatInfo();

    delete ps1;
    delete skoda;
    return 0;
}

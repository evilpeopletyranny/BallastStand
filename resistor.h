#ifndef RESISTOR_H
#define RESISTOR_H


class Resistor
{
private:
    double consumption;
    double percent;
    bool active;

public:
    explicit Resistor(double consumption, double percent, bool active = false);
    double getConsumption() const;
    void setConsumption(double newConsumption);
    bool getActive() const;
    void setActive(bool newActive);
    bool isActive();

    void activate();
    void deactivate();
};

#endif // RESISTOR_H

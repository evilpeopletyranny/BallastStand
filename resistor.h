#ifndef RESISTOR_H
#define RESISTOR_H


class Resistor
{
private:
    double consumption;
    bool active;

public:
    explicit Resistor(double consumption, bool active = false);
    double getConsumption() const;
    void setConsumption(double newConsumption);
    bool getActive() const;
    void setActive(bool newActive);
    bool isActive();

    void activate();
    void deactivate();
};

#endif // RESISTOR_H

#ifndef RESISTOR_H
#define RESISTOR_H


class Resistor
{
private:
    double power;
    double percent;
    bool active;

public:
    explicit Resistor(double consumption, double percent, bool active = false);
    double getPower() const;
    void setPower(double newConsumption);
    bool getActive() const;
    void setActive(bool newActive);
    bool isActive();

    void activate();
    void deactivate();
    double getPercent() const;
};

#endif // RESISTOR_H

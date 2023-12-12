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
    Resistor(const Resistor &otherResistor);

    double getPower() const;
    double getPercent() const;

    bool isActive() const;
};
#endif // RESISTOR_H

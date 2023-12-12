#include "resistor.h"

double Resistor::getPower() const
{
    return power;
}

bool Resistor::isActive() const
{
    return active;
}

double Resistor::getPercent() const
{
    return percent;
}

Resistor::Resistor(double consumption, double percent, bool active)
{
    this->power = consumption;
    this->percent = percent;
    this->active = active;
}

Resistor::Resistor(const Resistor &otherResistor)
{
    this->power = otherResistor.power;
    this->percent = otherResistor.percent;
    this->active = otherResistor.active;
}

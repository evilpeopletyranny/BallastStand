#include "resistor.h"

double Resistor::getPower() const
{
    return power;
}

void Resistor::setPower(double newConsumption)
{
    power = newConsumption;
}

bool Resistor::getActive() const
{
    return active;
}

void Resistor::setActive(bool newActive)
{
    active = newActive;
}

bool Resistor::isActive()
{
    return active;
}

void Resistor::activate()
{
    active = true;
}

void Resistor::deactivate()
{
    active = false;
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

#include "resistor.h"

double Resistor::getConsumption() const
{
    return consumption;
}

void Resistor::setConsumption(double newConsumption)
{
    consumption = newConsumption;
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

Resistor::Resistor(double consumption, double percent, bool active)
{
    this->consumption = consumption;
    this->percent = percent;
    this->active = active;
}

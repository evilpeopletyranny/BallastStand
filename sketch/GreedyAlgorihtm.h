#ifndef GreedyAlgorihtm_h
#define GreedyAlgorihtm_h

#include "Resistor.h"         //класс "Резистор"

#define number_of_lamps 5

//Функция, реализующая алгоритм включения/выключения элементов баллластной нагрузки
void greedyAlgorihtm(double load, Resistor (&list) [number_of_lamps])
{
  if (number_of_lamps == 0) return; //если массив реле пустой, то ничего не рассчитываем

  double smallestConsumption = list[number_of_lamps - 1].get_consumption(); //вычисляем наименьшую мощность из балластной нагрузки

  for (int i = 0; i < number_of_lamps; i++) //проходим по массиву реле
  {
    if (list[i].get_consumption() <= load || abs(load - list[i].get_consumption()) <= smallestConsumption / 2.0)  //условие активации
    {
      list[i].activate(); //активация реле
      load -= list[i].get_consumption();  //уменьшение компенсируемой мощности на то значение, которое мы включили
    }
    else
    {
      list[i].deactivate(); //деактивация реле
    }
  }
}

#endif

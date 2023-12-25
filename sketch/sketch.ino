#include "GreedyAlgorihtm.h"  //функция включения/отключен резисторов

#define start_pin 2 //пин, с которого начинается подключение реле и кнопок

#define GENERAL 1000  //максимальная полезная нагрузка
#define CURRENT 700   //начальное значение текущей полезной нагрузки

double general_load = GENERAL, current_load = CURRENT, tmp_load;
int lamps = number_of_lamps;  //количество реле

Resistor list[number_of_lamps]; //список элементов класса Resistor

unsigned int i = 0;

void setup() {
  Serial.begin(9600);

  //Предполагается, что цифровые пины сначала присваиваются кнопкам, потом реле
  unsigned int pin_counter_lamps = start_pin;

  /*
     Таким образом:
     start_pin - number_of_lamps - пины, отвечающие за переключатели
     number_of_lamps+1 - number_of_lamps*2 - пины, отвечающие за реле
  */

  for (i; i <= number_of_lamps; i++)
  {
    pinMode(pin_counter_lamps, OUTPUT);
    digitalWrite(pin_counter_lamps, LOW);
    pin_counter_lamps++;
  }

  list[0].set_consumption(general_load / 2);

  //Заполнение сопротивлений балластных нагрузок
  for (i = 1; i < lamps - 1; i++)
  {
    list[i].set_consumption(list[i - 1].get_consumption() / 2);
  }
  list[lamps - 1].set_consumption(list[lamps - 2].get_consumption());

}

void loop()
{
  if (Serial.available()>0) //проверка того, что последовательный порт доступен
  {
    tmp_load = Serial.parseFloat(SKIP_WHITESPACE);  //считывает значение полезной нагрузки из последовательного порта
    Serial.println(tmp_load,4);
    if ((tmp_load > 0) && (tmp_load <= GENERAL))  //проверяем введенное значение на корректность
    {
      current_load = tmp_load;
      greedyAlgorihtm((general_load - current_load), list); //вызов алгоритма
      
      for (i = 0; i < number_of_lamps; i++) //переключение реле и вывод результата в монитор порта
      {
        if (list[i].get_activate_status())
        {
          digitalWrite(i + start_pin, HIGH);  //включение реле
          list[i].activate();
          Serial.print(i);
          Serial.println("   ON");
          
        }
        else
        {
          digitalWrite(i + start_pin, LOW); //выключение реле
          list[i].deactivate(); 
          Serial.print(i);
          Serial.println("   OFF");
        }
      }
    }
  }
}

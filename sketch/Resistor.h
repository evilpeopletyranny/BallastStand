#ifndef Resistor_h
#define Resistor_h

using namespace std;

class Resistor  //класс, реализующий элемент балластной нагрузки
{
private:
  float consumption;  //мощность элемента балластной нагрузки
  bool active;        //статус элемента нагрузки

public:
  //конструктор по умолчанию
  Resistor() 
  {
    consumption = 0;
    active = false;
  }

  //конструктор с параметром
  //создаем экземпляр класса с заданной мощностью
  Resistor(float user_consumption) 
  {
    consumption = user_consumption;
    active = false;
  }

  //перегруженные операторы сравнения для дальнейшей модификации алгоритма
  friend bool operator<(const Resistor res1, const Resistor res2);
  friend bool operator>(const Resistor res1, const Resistor res2);

  //метод активации элемента
  void activate() 
  {
    active = true;
  }

  //метод деактивации элемента
  void deactivate() 
  {
    active = false;
  }

  //метод для задания значения мощности элемента
  bool set_consumption(float user_consumption) 
  {
    if ((user_consumption >= 0)) 
    {
      consumption = user_consumption;
      return true;
    } else
      return false;
  }

  //метод получения значения мощности элемента
  float get_consumption() 
  {
    return consumption;
  }

  //метод получения статуса активации элемента
  bool get_activate_status() 
  {
    return active;
  }
};

//перегруженные операторы сравнения для дальнейшей модификации алгоритма
bool operator<(const Resistor res1, const Resistor res2) 
{
  return (res1.consumption < res2.consumption);
}

bool operator>(const Resistor res1, const Resistor res2) 
{
  return (res1.consumption > res2.consumption);
}

#endif

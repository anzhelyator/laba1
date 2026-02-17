#include <iostream>
#include <bitset>
//Состояния костюма (битовые флаги).
enum Condition_of_suit {
    Invisibility=0,
    Silence=1,
    Infrared_waves=2,
    Radio_waves=3,
    Energy_mode=4
};
//Функция 1: меняет состояние на противоположное.
std::bitset<5> Toggle(std::bitset<5> suit, int state_num) {
    suit.flip(state_num - 1);
    return suit;
}
//Функция 2: проверяет, активно ли выбранное состояние.
bool Active(std::bitset<5> suit, int state_num) {
    return suit.test(state_num - 1);
}
//Функция 3: считает кол-во активных состояний.
int Count_active(std::bitset<5> suit) {
    return suit.count(); 
}
//Функция 4: проверка обнаружения.
bool Detect(std::bitset<5> suit) {
    //Включены невидимость или беззвучие.
    bool cond1 = suit.test(Invisibility) || suit.test(Silence);
    //Включены радио или ИК.
    bool cond2 = suit.test(Radio_waves) || suit.test(Infrared_waves);
    return cond1 && cond2;
}
int main() {
    //Стартовое состояние: невидимость + энергосбережение.
    std::bitset<5> suit;
    suit.set(Invisibility); //включаем невидимость.
    suit.set(Energy_mode); //включаем энергосберегательный режим.

    auto toggled = Toggle(suit, 2); //переключить беззвучие.
    bool active = Active(suit, 1); //проверить невидимость.
    int count = Count_active(suit); //посчитать состояния.
    bool detected = Detect(suit); //проверить обнаружение.
   return 0;
}
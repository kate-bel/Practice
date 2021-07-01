/**
* @file practice.cpp
* @author Ѕ≥лецька  .¬. 515-¬
* @brief ѕрактична робота
*
* ѕереведенн€ ц≥лого числа в текст
*/
// п≥дключеннн€ заголовочних файл≥в стандартних б≥бл≥отек
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<locale.h>

using namespace std;

int main()
{
    //локал≥зац≥€
    setlocale(LC_ALL, "Ukrainian");
    //оголошенн€ зм≥нних
    const char* one[] = { "один", "два", "три", "чотири", "п'€ть", "шiсть", "сiм", "вiсiм", "дев'€ть" };
    const char* teen[] = { "одинадц€ть", "дванадц€ть", "тринадц€ть", "чотирнадц€ть", "п'€тнадц€ть", "шiстнадц€ть", "сiмнадц€ть", "вiсiмнадц€ть", "дев'€тнадц€ть" };
    const char* des[] = { "двадц€ть", "тридц€ть", "сорок", "п'€тдес€т", "шiстдес€т", "сiмдес€т", "вiсiмдес€т", "дев'€носто" };
    const char* hundr[] = { "сто", "двiстi", "триста", "чотириста", "п'€тсот", "шiстсот", "сiмсот", "вiсiмсот", "дев'€тсот" };
    const char* thousand[] = { "одна тис€ча", "двi тис€чi", "три тис€чi", "чотири тис€чi", "п'€ть тис€ч", "шiсть тис€ч", "сiм тис€ч", "вiсiм тис€ч", "д'ев€ть тис€ч" };
    const char* million[] = { "один мiльйон", "два мiльйони", "три мiльйони", "чотири мiльйони", "п'€ть мiльйонiв", "шiсть мiльйонiв", "ciм мiльйонiв", "вiсiм мiльйонiв", "дев'€ть мiльйонiв" };
    const char* miliard[] = { "один мiль€рд", "два мiль€рдa", "три мiль€рдa", "чотири мiль€рдa", "п'€ть мiль€рдiв", "шiсть мiль€рдiв", "ciм мiль€рдiв", "вiсiм мiль€рдiв", "дев'€ть мiль€рдiв" };

    double number; //зм≥нна дл€ введенн€ числа
    int natur; //зм≥нна дл€ роботи з ц≥лим числом
    int a, b, c, d, e, f, g, h, i, j; //тимчасов≥ зм≥нн≥ дл€ ц≥лого числа
    const char* first = "", * second = "", * third = "", * fourth = "", * fifth = "", * sixth = "", * seventh = "", * eighth = "", * nineth = "", * tenth = "", * eleventh = ""; //зм≥нн≥ дл€ виведенн€ ц≥лого
    const char* neg = ""; //зм≥нна дл€ м≥нуса

    //введенн€ числа
    printf("¬ведiть число: ");
    scanf_s("%lg", &number);

    //перев≥рка числа на вх≥д у д≥апазон
    if (number > 2147483647 || number < -2147483647)
    {
        printf("¬ведено неправильне число");
        return 0;
    }
    //перев≥рка на в≥д'Їмн≥сть
    if (number < 0)
    {
        neg = "мiнус";
        number *= -1;
    }
    else
    {
        printf("");
    }

    natur = (int)number;
    //розбиваЇмо число на составн≥ цифри
    a = natur % 10; //число одиниць                
    b = (natur % 100) / 10; //число дес€тка
    c = (natur % 1000) / 100; //число сотень
    d = (natur % 10000) / 1000; //число тис€ч
    e = (natur % 100000) / 10000; //число дес€тк≥в тис€ч
    f = (natur % 1000000) / 100000; //число сотень тис€ч
    g = (natur % 10000000) / 1000000; //число м≥льйон≥в
    h = (natur % 100000000) / 10000000; // число дес€тк≥в мiльйонiв
    i = (natur % 1000000000) / 100000000; //число сотень м≥льйон≥в
    j = (natur % 10000000000) / 1000000000; //число м≥ль€рд≥в

    //0-10
    if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0 && g == 0 && h == 0 && i == 0 && j == 0)
    {
        printf("нуль");
    }
    if (a != 0 && b != 1)
    {
        first = one[a - 1];
    }
    else if (a == 0 && b == 1)
    {
        printf("дес€ть");
    }
    else if (a == 0 && b == 0)
    {
        first = "";
    }

    //11-99
    if (b == 0)
    {
        second = "";
    }
    else if (b == 1 && a != 0)
    {
        second = teen[a - 1];
    }
    else if (b != 1)
    {
        second = des[b - 2];
    }

    //100-999
    if (c != 0)
    {
        third = hundr[c - 1];
    }

    //1000-19999
    if (d != 0 && e != 1)
    {
        fourth = thousand[d - 1];
    }
    else if (d == 0 && e == 1)
    {
        printf("дес€ть тис€ч");
    }
    else if (d != 0 && e == 1 && e != 0)
    {
        fifth = strcat(_strdup(teen[d - 1]), " тис€ч");
    }

    // 20 000-99 999
    if (e != 0 && e != 1 && d == 0)
    {
        fifth = strcat(_strdup(des[e - 2]), " тис€ч");
    }
    else if (e != 0 && e != 1 && d != 0)
    {
        fifth = des[e - 2];
    }

    // 100 000-999 999
    if (f != 0 && d == 0 && e == 0)
    {
        sixth = strcat(_strdup(hundr[f - 1]), " тис€ч");
    }
    else if (f != 0)
    {
        sixth = hundr[f - 1];
    }

    // 1 000 000-9 999 999
    if (g != 0 && h == 0)
    {
        seventh = million[g - 1];
    }

    // 10 000 000-99 999 999
    if (h == 1 && g == 0)
    {
        printf("дес€ть мiльйонiв");
    }
    else if (h == 1 && h != 0 && g != 0)
    {
        seventh = strcat(_strdup(teen[g - 1]), " мiльйонiв");
    }
    else if (h != 0 && h != 1 && g == 0)
    {
        seventh = strcat(_strdup(des[h - 2]), " мiльйонiв");
    }
    else if (h != 0 && h != 1 && g != 0)
    {
        eighth = des[h - 2];
    }

    // 100 000 000- 999 999 999
    if (i == 1 && h == 0 && g == 0)
    {
        printf("сто мiльйонiв");
    }
    else if (i != 0 && h == 0 && g == 0)
    {
        nineth = strcat(_strdup(hundr[i - 1]), " мiльйонiв");
    }
    else if (i != 0)
    {
        tenth = hundr[i - 1];
    }

    // 1 000 000 000-2 147 483 647
    if (j != 0)
    {
        eleventh = miliard[j - 1];
    }

    //виведенн€ числа словами
    printf("%s", neg);
    printf("%s %s %s ", eleventh, tenth, nineth);
    printf("%s %s %s %s ", eighth, seventh, sixth, fifth);
    printf("%s %s %s %s", fourth, third, second, first);
}
/**
* @file practice.cpp
* @author Білецька К.В. 515-В
* @brief Практична робота
*
* Переведення цілого числа в текст
*/
// підключенння заголовочних файлів стандартних бібліотек
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<locale.h>

using namespace std;

int main()
{
    //локалізація
    setlocale(LC_ALL, "Ukrainian");
    //оголошення змінних
    const char* one[] = { "один", "два", "три", "чотири", "п'ять", "шiсть", "сiм", "вiсiм", "дев'ять" };
    const char* teen[] = { "одинадцять", "дванадцять", "тринадцять", "чотирнадцять", "п'ятнадцять", "шiстнадцять", "сiмнадцять", "вiсiмнадцять", "дев'ятнадцять" };
    const char* des[] = { "двадцять", "тридцять", "сорок", "п'ятдесят", "шiстдесят", "сiмдесят", "вiсiмдесят", "дев'яносто" };
    const char* hundr[] = { "сто", "двiстi", "триста", "чотириста", "п'ятсот", "шiстсот", "сiмсот", "вiсiмсот", "дев'ятсот" };
    const char* thousand[] = { "одна тисяча", "двi тисячi", "три тисячi", "чотири тисячi", "п'ять тисяч", "шiсть тисяч", "сiм тисяч", "вiсiм тисяч", "д'евять тисяч" };
    const char* million[] = { "один мiльйон", "два мiльйони", "три мiльйони", "чотири мiльйони", "п'ять мiльйонiв", "шiсть мiльйонiв", "ciм мiльйонiв", "вiсiм мiльйонiв", "дев'ять мiльйонiв" };
    const char* miliard[] = { "один мiльярд", "два мiльярдa", "три мiльярдa", "чотири мiльярдa", "п'ять мiльярдiв", "шiсть мiльярдiв", "ciм мiльярдiв", "вiсiм мiльярдiв", "дев'ять мiльярдiв" };

    double number; //змінна для введення числа
    int natur; //змінна для роботи з цілим числом
    int a, b, c, d, e, f, g, h, i, j; //тимчасові змінні для цілого числа
    const char* first = "", * second = "", * third = "", * fourth = "", * fifth = "", * sixth = "", * seventh = "", * eighth = "", * nineth = "", * tenth = "", * eleventh = ""; //змінні для виведення цілого
    const char* neg = ""; //змінна для мінуса

    //введення числа
    printf("Введiть число: ");
    scanf_s("%lg", &number);

    //перевірка числа на вхід у діапазон
    if (number > 2147483647 || number < -2147483647)
    {
        printf("Введено неправильне число");
        return 0;
    }
    //перевірка на від'ємність
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
    //розбиваємо число на составні цифри
    a = natur % 10; //число одиниць                
    b = (natur % 100) / 10; //число десятка
    c = (natur % 1000) / 100; //число сотень
    d = (natur % 10000) / 1000; //число тисяч
    e = (natur % 100000) / 10000; //число десятків тисяч
    f = (natur % 1000000) / 100000; //число сотень тисяч
    g = (natur % 10000000) / 1000000; //число мільйонів
    h = (natur % 100000000) / 10000000; // число десятків мiльйонiв
    i = (natur % 1000000000) / 100000000; //число сотень мільйонів
    j = (natur % 10000000000) / 1000000000; //число мільярдів

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
        printf("десять");
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
        printf("десять тисяч");
    }
    else if (d != 0 && e == 1 && e != 0)
    {
        fifth = strcat(_strdup(teen[d - 1]), " тисяч");
    }

    // 20 000-99 999
    if (e != 0 && e != 1 && d == 0)
    {
        fifth = strcat(_strdup(des[e - 2]), " тисяч");
    }
    else if (e != 0 && e != 1 && d != 0)
    {
        fifth = des[e - 2];
    }

    // 100 000-999 999
    if (f != 0 && d == 0 && e == 0)
    {
        sixth = strcat(_strdup(hundr[f - 1]), " тисяч");
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
        printf("десять мiльйонiв");
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

    //виведення числа словами
    printf("%s", neg);
    printf("%s %s %s ", eleventh, tenth, nineth);
    printf("%s %s %s %s ", eighth, seventh, sixth, fifth);
    printf("%s %s %s %s", fourth, third, second, first);
}

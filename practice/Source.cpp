/**
* @file practice.cpp
* @author �������� �.�. 515-�
* @brief ��������� ������
*
* ����������� ������ ����� � �����
*/
// ����������� ������������ ����� ����������� �������
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<locale.h>

using namespace std;

int main()
{
    //����������
    setlocale(LC_ALL, "Ukrainian");
    //���������� ������
    const char* one[] = { "����", "���", "���", "������", "�'���", "�i���", "�i�", "�i�i�", "���'���" };
    const char* teen[] = { "����������", "����������", "����������", "������������", "�'���������", "�i���������", "�i��������", "�i�i��������", "���'���������" };
    const char* des[] = { "��������", "��������", "�����", "�'�������", "�i�������", "�i������", "�i�i������", "���'������" };
    const char* hundr[] = { "���", "��i��i", "������", "���������", "�'�����", "�i�����", "�i����", "�i�i����", "���'�����" };
    const char* thousand[] = { "���� ������", "��i �����i", "��� �����i", "������ �����i", "�'��� �����", "�i��� �����", "�i� �����", "�i�i� �����", "�'����� �����" };
    const char* million[] = { "���� �i�����", "��� �i������", "��� �i������", "������ �i������", "�'��� �i�����i�", "�i��� �i�����i�", "ci� �i�����i�", "�i�i� �i�����i�", "���'��� �i�����i�" };
    const char* miliard[] = { "���� �i�����", "��� �i�����a", "��� �i�����a", "������ �i�����a", "�'��� �i�����i�", "�i��� �i�����i�", "ci� �i�����i�", "�i�i� �i�����i�", "���'��� �i�����i�" };

    double number; //����� ��� �������� �����
    int natur; //����� ��� ������ � ����� ������
    int a, b, c, d, e, f, g, h, i, j; //�������� ���� ��� ������ �����
    const char* first = "", * second = "", * third = "", * fourth = "", * fifth = "", * sixth = "", * seventh = "", * eighth = "", * nineth = "", * tenth = "", * eleventh = ""; //���� ��� ��������� ������
    const char* neg = ""; //����� ��� �����

    //�������� �����
    printf("����i�� �����: ");
    scanf_s("%lg", &number);

    //�������� ����� �� ���� � �������
    if (number > 2147483647 || number < -2147483647)
    {
        printf("������� ����������� �����");
        return 0;
    }
    //�������� �� ��'������
    if (number < 0)
    {
        neg = "�i���";
        number *= -1;
    }
    else
    {
        printf("");
    }

    natur = (int)number;
    //��������� ����� �� ������� �����
    a = natur % 10; //����� �������                
    b = (natur % 100) / 10; //����� �������
    c = (natur % 1000) / 100; //����� ������
    d = (natur % 10000) / 1000; //����� �����
    e = (natur % 100000) / 10000; //����� ������� �����
    f = (natur % 1000000) / 100000; //����� ������ �����
    g = (natur % 10000000) / 1000000; //����� �������
    h = (natur % 100000000) / 10000000; // ����� ������� �i�����i�
    i = (natur % 1000000000) / 100000000; //����� ������ �������
    j = (natur % 10000000000) / 1000000000; //����� �������

    //0-10
    if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0 && g == 0 && h == 0 && i == 0 && j == 0)
    {
        printf("����");
    }
    if (a != 0 && b != 1)
    {
        first = one[a - 1];
    }
    else if (a == 0 && b == 1)
    {
        printf("������");
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
        printf("������ �����");
    }
    else if (d != 0 && e == 1 && e != 0)
    {
        fifth = strcat(_strdup(teen[d - 1]), " �����");
    }

    // 20 000-99 999
    if (e != 0 && e != 1 && d == 0)
    {
        fifth = strcat(_strdup(des[e - 2]), " �����");
    }
    else if (e != 0 && e != 1 && d != 0)
    {
        fifth = des[e - 2];
    }

    // 100 000-999 999
    if (f != 0 && d == 0 && e == 0)
    {
        sixth = strcat(_strdup(hundr[f - 1]), " �����");
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
        printf("������ �i�����i�");
    }
    else if (h == 1 && h != 0 && g != 0)
    {
        seventh = strcat(_strdup(teen[g - 1]), " �i�����i�");
    }
    else if (h != 0 && h != 1 && g == 0)
    {
        seventh = strcat(_strdup(des[h - 2]), " �i�����i�");
    }
    else if (h != 0 && h != 1 && g != 0)
    {
        eighth = des[h - 2];
    }

    // 100 000 000- 999 999 999
    if (i == 1 && h == 0 && g == 0)
    {
        printf("��� �i�����i�");
    }
    else if (i != 0 && h == 0 && g == 0)
    {
        nineth = strcat(_strdup(hundr[i - 1]), " �i�����i�");
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

    //��������� ����� �������
    printf("%s", neg);
    printf("%s %s %s ", eleventh, tenth, nineth);
    printf("%s %s %s %s ", eighth, seventh, sixth, fifth);
    printf("%s %s %s %s", fourth, third, second, first);
}
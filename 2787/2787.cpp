/*
* ���������ҵĴ��룬���ȫ�����Լ������ж�����Ȼ���������������е���ϡ� 
* ����Ŀǰ����д�������������ʱ�������� 
*/
#include <iostream>
#include <cmath>
using namespace std;
const int NUM = 4;
const int TARGET = 24;
const double ZERO = 1e-6;
bool flag = false;
double number[NUM];
bool Deal(int);
int main()
{
    while(cin >> number[0])
    {
        if(fabs(number[0] - 0.0) < ZERO)
            break;
        for(int i = 1; i < NUM; ++i)
            cin >> number[i];
        flag = false;
        Deal(NUM);
        if(flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
bool Deal(int step)
{
    if(step == 1)
    {
        if(fabs(number[0] - TARGET) < ZERO)
        {
            flag = true;
            return true;
        }
        else
            return false;
    }
    for(int i = 0; i < step; ++i)
    {
        for(int j = i + 1; j < step; ++j)
        {
            double tmp_a = number[i], tmp_b = number[j];
            number[j] = number[step - 1];
            number[i] = tmp_a + tmp_b;
            Deal(step - 1);
            number[i] = tmp_a - tmp_b;
            Deal(step - 1);
            number[i] = tmp_b - tmp_a;
            Deal(step - 1);
            number[i] = tmp_a * tmp_b;
            Deal(step - 1);
            if(fabs(tmp_b - 0.0) > ZERO)
            {
                number[i] = tmp_a / tmp_b;
                Deal(step - 1);
            }
            if(fabs(tmp_a - 0.0) > ZERO)
            {
                number[i] = tmp_b / tmp_a;
                Deal(step - 1);
            }
            number[i] = tmp_a;
            number[j] = tmp_b;
        }
    }
    return true;
}


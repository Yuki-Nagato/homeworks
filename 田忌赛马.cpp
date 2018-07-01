#include<iostream>  
#include<algorithm>  

using namespace std;
#define MAX 106  
struct speed
{
    int data;
    int state;
};

int cmp(speed a, speed b)
{
    if (a.data<b.data) return 1;
    else return 0;
}
int main()
{
    int n;
    speed num1[MAX], num2[MAX];
    cin >> n;
    while (n)
    {
        for (int i = 0; i<n; i++)
        {
            cin >> num1[i].data;
            num1[i].state = 0;
        }
        for (int i = 0; i<n; i++)
        {
            cin >> num2[i].data;
            num2[i].state = 0;
        }
        sort(num1, num1 + n, cmp);
        sort(num2, num2 + n, cmp);
        signed int sum1 = 0, sum2 = 0;
        for (int i = 0; i<n; i++)  //这边的目的是求出赢的场数
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (num1[i].data>num2[j].data)
                {
                    if (num1[i].state == 0 && num2[j].state == 0)
                    {
                        sum1++;
                        num1[i].state = 1;
                        num2[j].state = 1;
                        break;
                    }
                }
            }
        }
        for (int i = 0; i<n; i++)  //这边的目的是求出平局的场数
        {
            for (int j = 0; j<n; j++)
            {
                if (num1[i].data == num2[j].data)
                {
                    if (num1[i].state == 0 && num2[j].state == 0)
                    {
                        sum2++;
                        num1[i].state = 1;
                        num2[j].state = 1;
                        break;
                    }
                }
            }
        }
        cout << 2 * sum1 - n + sum2 << endl;
        cin >> n;
    }
    return 0;
}

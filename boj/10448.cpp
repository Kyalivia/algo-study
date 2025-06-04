#include <bits/stdc++.h>

using namespace std;

// Tn의 최대 값: 1000이라고 가정
// n의 범위: 1~45

vector<int> t_list;
int check_sum(int num)
{
    int sum = 0;
    for (int p = 0; p < 45; p++)
    {
        sum = 0;
        for (int q = 0; q < 45; q++)
        {
            for (int r = 0; r < 45; r++)
            {
                sum = t_list[p] + t_list[q] + t_list[r];
                if (sum == num)
                    return 1;
            }
        }
    }
    return 0;
}

int main(void)
{
    int T = 0;
    int num = 0;

    cin >> T;

    for (int i = 0; i < 45; i++)
    {
        num = (i + 1) * (i + 2) / 2;
        t_list.push_back(num);
    }

    while (T--)
    {
        cin >> num;
        if (check_sum(num))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef struct {
    int money;
    int cnt;
} person;

int main(void)
{
    int money = 0;
    int price = 0;
    int j_total = 0;
    int s_total = 0;
    vector<int> days;

    cin >> money;
    person joon;
    person sung;
    joon.money = money;
    joon.cnt = 0;
    sung.money = money;
    sung.cnt = 0;
    for (int i = 0; i < 14; i++)
    {
        cin >> price;
        days.push_back(price);
    }

    // joon
    for (int i = 0; i < 14; i++)
    {
        
        if (joon.money > 0 && joon.money / days[i])
        {
            joon.cnt += joon.money / days[i];
            joon.money -= (joon.cnt * days[i]);
        }
    }
    j_total = joon.money + (days[13] * joon.cnt);
    
    // sung
    for (int i = 3; i < 14; i++)
    {
        // 3일 연속 가격 상승 - 매도
        if (days[i - 3] < days[i - 2] && days[i - 2] < days[i - 1] && days[i - 1] < days[i])
        {
            if (sung.cnt)
            {
                sung.money += sung.cnt * days[i];
                sung.cnt = 0;
            }
        }
        // 3일 연속 가격 하강 - 매수
        if (days[i - 3] > days[i - 2] && days[i - 2] > days[i - 1] && days[i - 1] > days[i])
        {
            if (sung.money > 0 && sung.money / days[i])
            {
                sung.cnt += sung.money / days[i];
                sung.money -= (sung.cnt * days[i]);
            }
        }
    }
    s_total = sung.money + (days[13] * sung.cnt);

    if (j_total > s_total)
    {
        cout << "BNP" << endl;
    }
    else if (j_total == s_total)
    {
        cout << "SAMESAME" << endl;
    }
    else
    {
        cout << "TIMING" << endl;
    }
    return 0;
}
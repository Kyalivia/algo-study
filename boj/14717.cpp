#include <bits/stdc++.h>

using namespace std;

int checker[10][10];

int main(void)
{
    int num = 0;
    int a = 0;
    int b = 0;
    int all = 0; // 전체 경우의 수
    int cnt = 0; // 지거나 비기는 경우
    double result = 0;

    // 우선순위 저장: 큰 수 -> 우선순위 높다.
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (i + 1 == j + 1) 
            {
                // 같은 수
                checker[i][j] = (i + 1) + 10;
            }
            else 
            {
                // 다른 수
                num = (i + 1) + (j + 1);
                checker[i][j] = (num % 10);
            }
        }
    }

    cin >> a >> b;
    // 이길 수 없는 경우: 상대방의 우선순위가 높거나, 같은 경우
    for (int p = 0; p < 10; p++)
    {
        for (int q = 0; q < 10; q++)
        {
            if (p == q)
            {
                if (p != a - 1 && p != b -1)
                {
                    if (checker[p][q] > checker[a - 1][b - 1])
                        cnt++;
                }
            }
            else
            {
                if (checker[p][q] >= checker[a - 1][b - 1])
                {
                    if ((p == a - 1 && q == b - 1) || (p == b - 1 && q == a - 1))
                    {
                        // 2개: 같은 경우 - (1, 2), (2, 1)
                        cnt += 1;
                    }
                    else if (p == a - 1 || q == a - 1 || p == b - 1  || q == b - 1)
                    {
                        // 1개: 같은 경우 - (1, 9), (1, 8), ...
                        cnt += 1;
                    }
                    else 
                    {
                        // 0개: 같은 경우 - (3, 7)
                        cnt += 2;
                    }
                }
            }
        }
    }
    // 자기 자신이 뽑힌 경우 제외: (a, b)
    if (a != b)
    {
        cnt -= 1;
    }
    // 확률 계산
    all = (18 * 17) / 2;
    result = (all - cnt) / (double)all;
    cout << fixed;
    cout.precision(3);
    cout << result << endl;

    return 0;
}
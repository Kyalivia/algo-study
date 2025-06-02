#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int N;

    cin >> N;

    int res = 0;
    int sum = 0;
    int cpy = 0;
    for(int i = 0; i <= N; i++)
    {
        sum = 0;
        cpy = i;
        // 분해합
        while (cpy != 0)
        {
            sum += (cpy % 10);
            cpy /= 10;
        }
        sum += i;
        // 확인
        if (sum == N)
        {
            res = i;
            break;
        }
    }

    cout << res << endl;
    return 0;
}
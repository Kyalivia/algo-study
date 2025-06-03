#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    vector<int> inputs;
    int n = 0;
    int sum = 0;
    int c_sum = 0;

    for (int i = 0; i < 9; i++)
    {
        cin >> n;
        inputs.push_back(n);
        sum += n;
    }
    // 정렬
    c_sum = sum;
    sort(inputs.begin(), inputs.end());
    // 2개씩 뽑아 제외해서 합을 구해보기
    for (int a = 0; a < 8; a++)
    {
        sum = c_sum;
        sum -= inputs[a];
        for (int b = a + 1; b < 9; b++)
        {
            sum -= inputs[b];
            if (sum == 100)
            {
                for (int j = 0; j < 9; j++)
                {
                    if (j == a || j == b)
                        continue;
                    cout << inputs[j] << endl;
                }
                return 0;
            }
            sum += inputs[b];
        }
    }

    return 0;
}
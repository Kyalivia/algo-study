
#include <bits/stdc++.h>

using namespace std;

// cups[번호] = 위치;

int main(void)
{
    int M = 0;
    int a = 0;
    int b = 0;
    int temp = 0;

    // 위치 초기화
    vector<int> cups(3);
    cups[0] = 0;
    cups[1] = 1;
    cups[2] = 2;

    cin >> M;
    while (M--)
    {
        cin >> a >> b;
        // swap
        temp = cups[a - 1];
        cups[a - 1] = cups[b - 1];
        cups[b - 1] = temp;
    }

    // 0인 위치를 갖는 공의 번호 출력하기
    for (int i = 0; i < 3; i++)
    {
        if (cups[i] == 0)
            cout << (i + 1) << endl;
    }
    return 0;
}
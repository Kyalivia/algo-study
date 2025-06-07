#include <bits/stdc++.h>

using namespace std;

// 한 숫자를 기준으로(완탐)
// 확인1) 같은 행에 같은 숫자O, 같은 열에 같은 숫자O
// 확인2) 길이 같아
// 확인3) 나머지 좌표 확인
// 넓이 갱신

int main(void)
{
    int N, M;
    string str;
    int max = 0;
    int area = 0;
    int base = 0;
    int diff = 0;

    cin >> N >> M;
    vector<vector<int>> board(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++)
    {
        cin >> str;
        for (int j = 0; j < M; j++)
        {
            board[i][j] = str[j] - '0';
        }
    }

    // 탐색 - 넓이 찾기
    for(int p = 0; p < N - 1; p++)
    {
        for (int q = 0; q < M - 1; q++)
        {
            base = board[p][q];
            // 같은 행
            for(int c = q + 1; c < M; c++)
            {
                if (board[p][c] == base)
                {
                    diff = c - q;
                    // 같은 열 확인
                    if (p + diff < N)
                    {
                        if (board[p + diff][q] == base)
                        {
                            // 마지막 좌표
                            if (board[p + diff][q + diff] == base)
                            {
                                area = (diff + 1) * (diff + 1);
                                if (max < area)
                                    max = area;
                            }
                        }
                    }
                }
            }
        }
    }

    if (max)
        cout << max << endl;
    else
        cout << 1 << endl;
    return 0;
}
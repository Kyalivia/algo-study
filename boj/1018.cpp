#include <bits/stdc++.h>

using namespace std;

// 8x8 체스판을 만들고
// 영역별 비교해서 확인하기
int main(void)
{
    int N, M;
    char color[2] = {'W', 'B'};
    char pat1[8][8]; // WB
    char pat2[8][8]; // BW
    string line;
    int min = 0;
    int cnt1 = 0;
    int cnt2 = 0;

    // 패턴 채우기
    for(int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            pat1[i][j] = color[(i + j) % 2]; 
        }
    }
    for(int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            pat2[i][j] = color[(i + j + 1) % 2]; 
        }
    }
    

    cin >> N >> M;
    vector<vector<char>> board(N);
    for (int i = 0; i < N; i++)
    {
        cin >> line;
        for (int j = 0; j < M; j++)
        {
            board[i].push_back(line[j]);
        }
    }
    
    // 탐색
    min = N * M;
    for(int p = 0; p < N - 7; p++)
    {
        for (int q = 0; q < M - 7; q++)
        {
            cnt1 = 0;
            cnt2 = 0;
            // pat1 확인, pat2 확인
            for (int r = p; r < p + 8; r++)
            {
                for (int c = q; c < q + 8; c++)
                {
                    if (board[r][c] != pat1[r - p][c - q])
                        cnt1++;
                    if (board[r][c] != pat2[r - p][c - q])
                        cnt2++;
                }
            }
            if (min > cnt1)
                min = cnt1;
            if (min > cnt2)
                min = cnt2;
        }
    }

    cout << min << endl;
    return 0;
}
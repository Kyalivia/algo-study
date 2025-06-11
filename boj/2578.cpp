
#include <bits/stdc++.h>

using namespace std;

typedef struct _val
{
    int row;
    int col;
} val;

int check_bingo(int checker[][5])
{
    int bingo_cnt = 0;
    int val_cnt;

    // 같은 행
    for (int i = 0; i < 5; i++)
    {
        val_cnt = 0;
        for (int j = 0; j < 5; j++)
        {
            if (checker[i][j])
                val_cnt += 1;
        }
        if (val_cnt == 5)
            bingo_cnt += 1;
    }

    // 같은 열
    for (int i = 0; i < 5; i++)
    {
        val_cnt = 0;
        for (int j = 0; j < 5; j++)
        {
            if (checker[j][i])
                val_cnt += 1;
        }
        if (val_cnt == 5)
            bingo_cnt += 1;
    }

    // 대각선
    val_cnt = 0;
    for (int i = 0; i < 5; i++)
    {
        if (checker[i][i])
            val_cnt++;
    }
    if (val_cnt == 5)
        bingo_cnt += 1;
    val_cnt = 0;
    for (int i = 0; i < 5; i++)
    {
        if (checker[4 - i][i])
            val_cnt++;
    }
    if (val_cnt == 5)
        bingo_cnt += 1;

    return bingo_cnt;
}

int main(void)
{
    val board[30];
    int checker[5][5];
    int num = 0;
    int cnt = 0;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> num;
            board[num].row = i;
            board[num].col = j;
            checker[i][j] = 0;
        }
    }

    for (int k = 0; k < 5; k++)
    {
        for (int p = 0; p < 5; p++)
        {
            cin >> num;
            checker[board[num].row][board[num].col] = 1;
            cnt++;
            if (check_bingo(checker) >= 3)
            {
                cout << cnt << endl;
                return 0;
            }
        }
    }

    return 0;
}
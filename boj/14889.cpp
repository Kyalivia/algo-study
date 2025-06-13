#include <bits/stdc++.h>

using namespace std;

int calc_score(vector<int>& team, const vector<vector<int>>& board) {
    int score = 0;
    for (int i = 0; i < team.size(); i++) {
        for (int j = i + 1; j < team.size(); j++) {
            score += board[team[i]][team[j]];
            score += board[team[j]][team[i]];
        }
    }
    return score;
}

int main(void)
{
    int N = 0;

    cin >> N;
    vector<vector<int>> board(N, vector<int>(N, 0));
    for (int i = 0 ; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }

    // 조합
    int answer = INT_MAX;
    vector<int> comb;
    for (int i = 0; i < N; i++) {
        comb.push_back(i < N / 2 ? 0 : 1);  // N/2명만 선택
    }

    do {
        vector<int> team_start, team_link;
        for (int i = 0; i < N; i++) {
            if (comb[i] == 0) team_start.push_back(i);
            else team_link.push_back(i);
        }

        int score_start = calc_score(team_start, board);
        int score_link = calc_score(team_link, board);
        answer = min(answer, abs(score_start - score_link));

    } while (next_permutation(comb.begin(), comb.end()));

    cout << answer << endl;

    return 0;
}
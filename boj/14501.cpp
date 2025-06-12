#include <bits/stdc++.h>

using namespace std;
int main() {
    int N = 0;
    int t = 0;
    int p = 0;
    int max = 0;
    int sum = 0;
    
    cin >> N;
    vector<pair<int, int>> days;
    while(N--)
    {
        cin >> t >> p;   
        days.push_back({t, p});
    }

    for (int i = 0; i < days.size(); i++)
    {
        sum = 0;
        for (int k = i; k < days.size(); k++)
        {
            if (k == days.size() - 1 && days[k].first != 1)
                break;
            sum += days[k].second;
            k += days[k].first - 1;
            if (k > days.size() - 1)
                break;
        }
        if (sum > max)
            max = sum;
    }
    cout << max << endl;
    return 0;
}
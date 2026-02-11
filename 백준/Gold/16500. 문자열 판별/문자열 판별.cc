#include <iostream>
#include <string>
#include <sstream>
#include <deque>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <climits>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;
    
vector<int> dp;
vector<string> words;
string str;
int DP(int i)
{
    int length = str.size();

    if (i == length) return 1;

    int& ret = dp[i];
    if (ret != -1) return ret;

    ret = 0;

    for (const string& word : words)
    {
        int len = word.size();
        if (i + len > length)   continue;

        bool ok = true;
        for (int l = 0; l < len; l++)
        {
            if (str[i + l] != word[l]) {
                ok = false;
                break;
            }
        }
        if (!ok) 
            continue;

        if (DP(i + len))
        {
            ret = 1;
            break;
        }
    }

    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> str;
    int n;
    cin >> n;
    words.resize(n);
    for (int i = 0; i < n; i++)
        cin >> words[i];
    
    dp.assign(str.size() + 1, -1);

    int answer = DP(0);

    cout << answer << "\n";

    return 0;
}
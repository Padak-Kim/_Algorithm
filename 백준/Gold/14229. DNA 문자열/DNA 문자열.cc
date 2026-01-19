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
using namespace std;

const char DNA[4] = { 'A','C','G','T' };

bool dfs(int depth, int k, string& cur, unordered_set<string>& seen, string& answer) 
{
    if (depth == k) 
    {
        if (seen.find(cur) == seen.end()) 
        {
            answer = cur;
            return true;
        }
        return false;
    }

    for (int i = 0; i < 4; i++) 
    {
        cur.push_back(DNA[i]);
        if (dfs(depth + 1, k, cur, seen, answer))
            return true;
        cur.pop_back();
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    cin >> S;
    int n = S.size();

    for (int k = 1; k <= 6; k++) {
        unordered_set<string> seen;
        seen.reserve(n);

        // 부분문자열 저장
        for (int i = 0; i + k <= n; i++) 
        {
            seen.insert(S.substr(i, k));
        }

        string cur, answer;
        if (dfs(0, k, cur, seen, answer)) 
        {
            cout << answer << "\n";
            return 0;
        }
    }
}
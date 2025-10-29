#include <deque>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, r;
vector<char> picked;
vector<char> candidate;
void dfs(int start, int depth)
{
    if (r == depth)
    {
        int vowelCnt = 1, consonantCnt = 2;
        bool ok = false;
        for (int i = 0; i < picked.size(); i++)
        {
            // 조건. 사전순으로 정렬된 알파벳
            if (i < picked.size() - 1 && picked[i] > picked[i + 1])
                return;

            // 조건. 최소 한 개의 모음(a, e, i, o, u)과 최소 두 개의 자음
            if (picked[i] == 'a' || picked[i] == 'e' || picked[i] == 'i' ||
                picked[i] == 'o' || picked[i] == 'u')
                vowelCnt--;
            else
                consonantCnt--;

            if (vowelCnt <= 0 && consonantCnt <= 0)
            {
                ok = true;
                break;
            }
        }
        if (!ok) return; // 실패
        
        for (char c : picked)
            cout << c;
        cout << "\n";
    }
    for (int i = start; i < n; i++)
    {
        picked.push_back(candidate[i]);
        dfs(i + 1, depth + 1);
        picked.pop_back();
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int L, C;
    cin >> L >> C;

    n = C;
    r = L;
    candidate.assign(C, ' ');
    for (int i = 0; i < C; i++)
    {
        cin >> candidate[i];
    }
    
    sort(candidate.begin(), candidate.end());
    dfs(0, 0);
    return 0;
}

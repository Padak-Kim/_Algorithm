#include <string>
#include <vector>
#include <stack>
using namespace std;

string solution(int n, int k, vector<string> cmd) {
    string answer(n, 'O');
    vector<int> prev(n);
    vector<int> next(n);
    
    vector<bool> removed(n, false);
    
    for(int i = 0; i < n; i++)
    {
        prev[i] = i - 1;
        next[i] = (i == n - 1) ? -1 : i + 1;
    }
    
    stack<pair<int, pair<int, int>>> st; // idx, {prev, next}
    int cur = k; // 현재 커서 위치 인덱스
    
    for (string &s : cmd)
    {
        char c = s[0];
        if (c == 'D')
        {
            int num = stoi(s.substr(2)); // 커서 이동할 숫자
            while (num--)   cur = next[cur];
        }
        else if (c == 'U')
        {
            int num = stoi(s.substr(2)); // 커서 이동할 숫자
            while (num--)   cur = prev[cur];
        }
        else if (c == 'C')
        {
            removed[cur] = true;
            st.push({cur, {prev[cur], next[cur]}});
            
            // 끊어진 노드 연결
            if (prev[cur] != -1) next[prev[cur]] = next[cur];
            if (next[cur] != -1) prev[next[cur]] = prev[cur];
            
            // 삭제된 행이 가장 마지막 행인 경우 바로 윗 행 선택, 아니면 아래 행 선택
            cur = (next[cur] != -1) ? next[cur] : prev[cur];
        }
        else    // Z
        {
            auto [idx, pn] = st.top();  st.pop();
            auto [p, n2] = pn;
            removed[idx] = false;
            
            if (p != -1) next[p] = idx;
            if (n2 != -1) prev[n2] = idx;
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        if (removed[i] == true) answer[i] = 'X';
    }
    
    return answer;
}
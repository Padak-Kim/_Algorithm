#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> q;
    priority_queue<int> pq;
    
    for(int i = 0; i < priorities.size(); i++)
    {
        q.push({priorities[i], i});
        pq.push(priorities[i]);
    }
    
    int cnt = 0;
    while(!q.empty())
    {
        auto [pri, idx] = q.front(); q.pop();
        
        if (pq.top() == pri)
        {
            pq.pop();
            answer++;
            if (idx == location) break;
        }
        else
        {
            q.push({pri, idx});
        }
            
    }
    return answer;
}
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<int> q;
    vector<int> sortVec;
    for (int i = 0; i < priorities.size(); i++)
    {
        q.push(i);
    }
    
    while(!q.empty())
    {
        int now_index = q.front();
        q.pop();
        if (priorities[now_index] == *max_element(priorities.begin(), priorities.end()))
        {
            sortVec.push_back(now_index);
            priorities[now_index] = 0;
        }
        else
        {
            q.push(now_index);
        }
    }
    
    for (int i = 0; i < sortVec.size(); i++)
    {
        if (sortVec[i] == location) return i+1;
    }
    return answer;
}
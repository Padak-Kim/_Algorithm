#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

bool compare(const vector<int>& a, const vector<int>& b)
{
    if (a[1] == b[1])   
        return a[0] < b[0];
    return  a[1] < b[1];  
}

int solution(vector<vector<int>> targets) {
    int answer = 0;
    
    sort(targets.begin(), targets.end(), compare);
    
    queue<int> q;
    q.push(targets[0][1]);
    answer++;
    for(int i = 0; i < targets.size(); i++)
    {
        int time = q.front();
        
        if (targets[i][0] >= time)
        {
            q.push(targets[i][1]);
            q.pop();
            answer++;
        }
    }
    
    return answer;
}
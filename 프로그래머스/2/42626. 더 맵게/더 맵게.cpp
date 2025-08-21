#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i = 0; i < scoville.size(); i++)
        pq.push(scoville[i]);
    
    while (pq.size() >= 2)
    {
        int food = pq.top(); pq.pop();
        
        if (food >= K)
            break;
        
        int newFood = food + pq.top() * 2;
        pq.pop();
        pq.push(newFood);
        answer++;
    }
    
    if (!pq.empty() && pq.top() < K)
        return -1;
    
    return answer;
}
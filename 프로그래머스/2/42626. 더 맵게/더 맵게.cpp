#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int count = 0;
    bool flag = true;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    for(int i = 0; i < scoville.size(); i++)
    {
        minHeap.push(scoville[i]);
        
        if (K > scoville[i])
        {
            flag = false;
        }
    }
    
    if (flag)
    {
        return count; // 0
    }
    
    while(minHeap.size() > 1)
    {
        int min1 = minHeap.top();
        minHeap.pop();
        int min2 = minHeap.top();
        minHeap.pop();
        
        int mix = min1 + (min2 * 2);
        minHeap.push(mix);
        count++;
        
        if (minHeap.top() >= K)
        {
            return count;
        }       
    }
    
    return -1;
}
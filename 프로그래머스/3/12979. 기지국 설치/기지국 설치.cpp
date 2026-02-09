#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int range = 2 * w + 1;
    
    int cur = 1;
    
    for(int s : stations)
    {
        int left = s - w;
        int right = s + w;
        
        if (cur < left)
        {
            int l = left - cur; // 빈 구간 길이
            answer += (l + range - 1) / range;
        }
        
        cur = max(cur, right + 1);
        
        if (cur > n) break;
    }
    
    if (cur <= n)
    {
        int len = n - cur + 1;
        
        answer += (len + range - 1) / range;
    }
    
    return answer;
}
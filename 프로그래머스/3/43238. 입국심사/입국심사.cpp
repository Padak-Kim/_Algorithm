#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool CanProcess(int n, vector<int> times, long long mid)
{
    long long cnt = 0;
    for (auto t : times)
    {
        cnt += mid / t;
        
        if (cnt >= n)
            return true;
    }
    return false;
}
long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    long long hi = *max_element(times.begin(), times.end()) * 1LL * n;
    long long lo = 0;
    
    while(hi >= lo)
    {
        long long mid = lo + (hi - lo) / 2;
        
        if (CanProcess(n, times, mid))
        {
            answer = mid;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }
    
    
    return answer;
}
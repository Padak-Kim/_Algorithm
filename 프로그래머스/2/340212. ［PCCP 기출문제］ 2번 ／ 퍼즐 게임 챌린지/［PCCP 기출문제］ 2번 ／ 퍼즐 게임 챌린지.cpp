#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    
    int hi = *max_element(diffs.begin(), diffs.end());
    int lo = 1;
    
    while (lo <= hi)
    {
        // 숙련도
        int mid = lo + (hi - lo) / 2;
        
        long long res = 0;
        for(int i = 0; i < diffs.size(); i++)
        {
            if (diffs[i] <= mid)
            {
                res += times[i];
            }
            else if (diffs[i] > mid)
            {
                int lose = diffs[i] - mid; // 4 - 2
                
                res += (times[i] + times[i - 1]) * lose + times[i];
            }
        }
        // 가능
        if (res <= limit)
        {
            cout << mid << endl;
            hi = mid - 1;
            answer = mid;
        }
        else
        {
            lo = mid + 1;
        }
        
    }
    
    return answer;
}
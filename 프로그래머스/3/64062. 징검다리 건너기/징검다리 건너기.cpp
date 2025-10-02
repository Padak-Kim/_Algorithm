#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool can(vector<int>& stones, int k, int mid)
{
    int run = 0;
    
    for(int& n : stones)
    {
        if (n < mid)
        {
            if (++run >= k)  return false;
        }
        else
            run = 0;
    }
    
    return true;
}
int solution(vector<int> stones, int k) {
    int answer = 0;
    int lo = 1; int hi = *max_element(stones.begin(), stones.end());
    
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (can(stones, k, mid))
        {
            answer = mid;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }
    return answer;
}
#include <string>
#include <vector>
#include <iostream>
#include <climits>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    
    int n = (int)sequence.size();
    long long sum = 0;
    int l = 0;
    int bestLen = INT_MAX, bestL = 0, bestR = 0;
    
    for (int r = 0; r < n; r++)
    {
        sum += sequence[r];
        while (l <= r && sum >= k)
        {
            if (sum == k)
            {
                int len = r - l + 1;
                if (len < bestLen || (len == bestLen && l < bestL))
                {
                    bestLen = len;
                    bestL = l;
                    bestR = r;
                }
            }
            sum -= sequence[l++];
        }
    }
        
    return {bestL, bestR};
}
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n, vector<int> losts, vector<int> reserves) {
    int answer = n - losts.size();
    sort(losts.begin(), losts.end());
    sort(reserves.begin(), reserves.end());
    for (int i = 0; i < losts.size();)
    {
        auto it = find(reserves.begin(), reserves.end(), losts[i]);
        if (it != reserves.end())
        {
            // 같은 값이 있음
            answer++;
            reserves.erase(it);
            losts.erase(losts.begin() + i);
        }
        else
        {
            i++;
        }
    }
    for (int i = 0; i < losts.size(); i++)
    {
        int lost = losts[i];
        
        auto it = find(reserves.begin(), reserves.end(), lost - 1);
        if (it != reserves.end())
        {
            // -1 존재
            answer++;
            reserves.erase(it);
            continue;
        }
        it = find(reserves.begin(), reserves.end(), lost + 1);
        
        if (it != reserves.end())
        {
            // +1 존재
            answer++;
            reserves.erase(it);
        }
         
    }
    
    return answer;
}
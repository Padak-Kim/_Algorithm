#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int n = nums.size();
    int r = nums.size() / 2;
    
    set<int> s;
    
    for(auto& num : nums)
        s.insert(num);
    
    for (auto it = s.begin(); it != s.end();)
    {
        answer++;
        it = s.upper_bound(*it);
        
        if (answer == r)
            break;
    }
    
    return answer;
}
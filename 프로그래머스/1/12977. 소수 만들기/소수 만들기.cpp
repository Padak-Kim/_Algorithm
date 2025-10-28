#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

bool isPrime(int n)
{
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    
    for(int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int N,r;
vector<int> picked;
vector<int> res;
void dfs(vector<int>& nums, int start, int depth)
{
    if (depth == r)
    {
        int sum = 0;
        for(int x : picked)
        {
            sum += x;
        }
        if (isPrime(sum))
            res.push_back(sum);
        return;
    }
    
    for(int i = start; i < N; i++)
    {
        picked.push_back(nums[i]);
        dfs(nums, i + 1, depth + 1);
        picked.pop_back();
    }
}
int solution(vector<int> nums) {
    int answer = -1;
    N = nums.size();
    r = 3;

    dfs(nums, 0, 0);
    answer = res.size();
    return answer;
}
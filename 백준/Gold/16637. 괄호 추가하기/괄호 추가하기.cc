#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>
using namespace std;

int n;
vector<int> nums;
vector<char> ops;
long long ans;
int opsCnt;

long long ApplyOp(int a, char op, int b)
{
    if (op == '+')  return (long long)(a + b);
    if (op == '-')  return (long long)(a - b);
    return (long long)(a * b);
}
void dfs(int idx, long long cur)
{
    // 더 이상 계산할 연산자 없음
    if (idx >= opsCnt)
    {
        ans = max(ans, cur);
        return;
    }

    // 괄호 사용 x
    long long val1 = ApplyOp(cur, ops[idx], nums[idx + 1]);
    dfs(idx + 1, val1);

    // 괄호 사용 o
    // 계산할 연산자 없어서 연산 못함
    if (idx + 1 >= opsCnt) return;

    // 뒤에 괄호 연산
    long long val2 = ApplyOp(nums[idx + 1], ops[idx + 1], nums[idx + 2]);
    long long val3 = ApplyOp(cur, ops[idx], val2);
    dfs(idx + 2, val3);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ans = INT_MIN;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        
        if (c >= '0' && c <= '9')
        {
            // 숫자
            nums.push_back(c - '0');
        }
        else
        {
            // 수식
            ops.push_back(c);
        }
    }
    opsCnt = ops.size();
    dfs(0, nums[0]);
    
    cout << ans;
    return 0;
}

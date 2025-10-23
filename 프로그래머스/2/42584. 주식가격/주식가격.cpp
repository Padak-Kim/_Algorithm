#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    
    stack<int> s;
    s.push(0);
    
    for(int i = 1; i < prices.size(); i++)
    {
        int idx = s.top();
        int oldPrice = prices[idx];
        int newPrice = prices[i];
        if (oldPrice <= newPrice) // 가격이 떨어지지않음
        {
            s.push(i);
        }
        else // 가격이 떨어짐
        {
            answer[idx]++;
            s.pop();
            while(!s.empty())
            {
                idx = s.top();
                oldPrice = prices[idx];
                if (oldPrice <= newPrice)
                    break;
                else
                {
                    answer[idx] = i - idx;         
                    s.pop();
                }
            }            
            s.push(i);
        }
    }
    
    int n = prices.size() - 1; // 마지막 idx
    while (!s.empty())
    {
        int idx = s.top();
        s.pop();
        answer[idx] = n - idx;
    }
    
    return answer;
}
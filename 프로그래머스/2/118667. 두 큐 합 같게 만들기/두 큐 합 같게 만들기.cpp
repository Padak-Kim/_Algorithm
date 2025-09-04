#include <string>
#include <vector>
#include <queue>
#include <numeric>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    queue<int> q1;
    queue<int> q2;
    
    // 두 큐에 담긴 모든 원소의 합
    long long sum = 0, s1 = 0, s2 = 0;
    int maxNum = -1;
    for(int i = 0; i < queue1.size(); i++)
    {
        q1.push(queue1[i]);
        sum += queue1[i];
        s1 += queue1[i];
        q2.push(queue2[i]);
        sum += queue2[i];
        s2 += queue2[i];
        maxNum = max(maxNum, queue1[i]);
        maxNum = max(maxNum, queue2[i]);
    }
    
    // 두 수의 합이 홀수거나 가장 높은 값이 절반 이상이면 불가
    if (sum % 2 == 1 || maxNum > sum / 2)
        return -1;
    
    long long limit = 3LL * queue1.size() * 2;
    while (answer <= limit)
    {
        if (s1 == sum / 2)
            return answer;
        
        if (s1 < sum / 2)
        {
            //if (q1.empty()) return -1;
            int n = q2.front(); q2.pop();
            q1.push(n);
            s2 -= n;
            s1 += n;
        }
        else
        {
            //if (q2.empty()) return -1;
            int n = q1.front(); q1.pop();
            q2.push(n);
            s1 -= n;
            s2 += n;
        }
        answer++;
    }
    
    return -1;
}
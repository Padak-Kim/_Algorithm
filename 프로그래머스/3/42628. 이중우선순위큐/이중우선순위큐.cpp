#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

multiset<int, greater<int>> max_ms; // 내림차순
multiset<int> min_ms;   // 오름차순

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    for (int i = 0; i < operations.size(); i++)
    {
        if (operations[i] == "D 1")
        {
            if (!max_ms.empty())
            {
                auto it = max_ms.begin();
                
                max_ms.erase(*it);
                min_ms.erase(*it);
            }
        }
        else if (operations[i] == "D -1")
        {
            if (!max_ms.empty())
            {
                auto it = min_ms.begin();
                
                max_ms.erase(*it);
                min_ms.erase(*it);
            }
        }
        else
        {
            
            int num = stoi(operations[i].substr(2));
            //cout << num << endl;
            
            max_ms.insert(num);
            min_ms.insert(num);
        }
    }
    
    if (max_ms.empty())
    {
        answer = {0, 0};
    }
    else
    {
        answer = {*max_ms.begin(), *min_ms.begin()};
    }
    return answer;
    
}
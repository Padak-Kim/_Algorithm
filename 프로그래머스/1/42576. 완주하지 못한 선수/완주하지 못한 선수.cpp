#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    multiset<string> ms;
    
    for (auto& s : participant)
    {
        ms.insert(s);
    }
    for (auto& s : completion)
    {
        auto it = ms.find(s);
        if (it != ms.end())
            ms.erase(it);
    }
    
    for(auto iter = ms.begin(); iter != ms.end(); ++iter)
    {
        cout << *iter << endl;
        answer = *iter;
    }
    return answer;
}
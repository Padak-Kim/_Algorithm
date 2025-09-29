#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    unordered_map<char, int> um;
    
    for(int i = 0; i < s.size(); i++)
    {
        if (!um.count(s[i]))
        {
            um.insert({s[i], i}); // (char, index)
            answer.push_back(-1);
        }
        else
        {
            int prev_idx = um[s[i]];
            um[s[i]] = i;
            answer.push_back(i - prev_idx);
        }
    }
    return answer;
}
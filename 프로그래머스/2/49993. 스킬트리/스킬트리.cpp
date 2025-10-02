#include <string>
#include <vector>
#include <set>
#include <queue>
#include <unordered_map>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    for (string& skill_tree : skill_trees)
    {
        int idx = 0;
        bool check = true;
        for(char& sk : skill_tree)
        {
            auto pos = skill.find(sk);
            if (pos == string::npos)
                continue;
            if (pos == idx)
                idx++;
            else{
                check = false;
                break;
            }
        }
        if (check)  answer++;
    }
    
    return answer;
}
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

bool MatchId(string user, string banId)
{
    if (user.size() != banId.size()) return false;
    
    for (int i = 0; i < banId.size(); i++)
    {
        if (banId[i] == '*')        continue;
        if (banId[i] != user[i])    return false;
    }
    cout << banId << " : " << user << endl;
    return true;
}
unordered_map<int, vector<int>> um;
unordered_set<int> seenMasks;
int answer = 0;
void DFS(vector<string>& user_id, vector<string>& banned_id, int start, int depth, int usedMask)
{
    if (depth == banned_id.size())
    {
        if (seenMasks.insert(usedMask).second) {
            answer++;
        }
        return;
    }
    
    int i = depth;
    
    for (int id : um[i])
    {
        if (usedMask & (1 << id)) continue;

        DFS(user_id, banned_id, i + 1, depth + 1, usedMask | (1 << id));
    }
}
int solution(vector<string> user_id, vector<string> banned_id) {
    answer = 0;
    for(int i = 0; i < user_id.size(); i++)
    {
        for (int j = 0; j < banned_id.size(); j++)
        {
            if (MatchId(user_id[i], banned_id[j]))
            {
                // 벤 후보군
                um[j].push_back(i);
            }
        }
    }
    DFS(user_id, banned_id, 0, 0, 0);
    return answer;
}
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool found = false;
vector<string> final_path;

void Dfs(string curr, vector<vector<string>>& tickets, vector<bool>& used, vector<string>& path)
{
    path.push_back(curr);
    
    if (path.size() == tickets.size() + 1)
    {
        final_path = path;
        found = true;
        return;
    }
    
    for (int i = 0; i < tickets.size(); i++){
        if (!used[i] && tickets[i][0] == curr){
            used[i] = true;
            Dfs(tickets[i][1], tickets, used, path);
            used[i] = false;
            
            if (found) return;
        }
    }
    path.pop_back();
}
vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    sort(tickets.begin(), tickets.end(), [](const vector<string>& a, const vector<string>& b)
         {
            return a[1] < b[1]; 
         });
    
    vector<bool> used(tickets.size(), false);
    vector<string> path;
    
    Dfs("ICN", tickets, used, path);
    
    return final_path;
}
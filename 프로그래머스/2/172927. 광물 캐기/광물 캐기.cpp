#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Group
{
    int dia = 0;
    int iron = 0;
    int stone = 0;
    
    int score = 0;
};
int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    
    int totalPicks = picks[0] + picks[1] + picks[2];
    int maxMine = min((int)minerals.size(), totalPicks * 5);
    
    vector<Group> groups;
    for (int i = 0; i < maxMine; i += 5)
    {
        Group g;
        for (int j = i; j < i + 5 && j < maxMine; j++)
        {
            if (minerals[j] == "diamond") g.dia++;
            else if (minerals[j] == "iron") g.iron++;
            else g.stone++;
        }
        g.score = g.dia * 25 + g.iron * 5 + g.stone;
        groups.push_back(g);
    }
    
    sort(groups.begin(), groups.end(), [](const Group& a, const Group& b){
       return a.score > b.score; 
    });
    
    for (auto &g : groups)
    {
        int pickType = -1;
        if (picks[0] > 0) {
            pickType = 0; picks[0]--;
        }
        else if (picks[1] > 0) {
            pickType = 1; picks[1]--;
        }
        else if (picks[2] > 0)
        {
            pickType = 2; picks[2]--;
        }
        else
            break;
    
        if (pickType == 0)
        {
            answer += g.dia + g.iron + g.stone;
        }
        else if (pickType == 1)
        {
            answer += g.dia * 5 + g.iron + g.stone;
        }
        else
        {
            answer += g.dia * 25 + g.iron * 5 + g.stone;
        }
    }
    return answer;
}
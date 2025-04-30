#include <string>
#include <vector>
#include <set>

using namespace std;

multiset<string> ms;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    for(int i = 0; i < participant.size(); i++)
    {
        ms.insert(participant[i]);
    }
    
    for (int j = 0; j < completion.size(); j++)
    {
        ms.erase(ms.find(completion[j]));
    }
    
    answer = *ms.begin();
    
    return answer;
}
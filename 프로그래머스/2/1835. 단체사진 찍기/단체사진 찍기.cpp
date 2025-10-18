#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool Valid(vector<char>& v, vector<string>& data)
{
    int pos[256];
    
    for (int idx = 0; idx < v.size(); idx++)
        pos[v[idx]] = idx;
    
    for(string& d : data)
    {
        char a = d[0];
        char b = d[2];
        char op = d[3];
        int gap = d[4] - '0';
        int dist = abs(pos[a] - pos[b]) - 1;
        if (op == '=' && dist != gap) return false;
        if (op == '<' && dist >= gap) return false;
        if (op == '>' && dist <= gap) return false;
    }
    return true;
}
int solution(int n, vector<string> data) {
    int answer = 0;
    
    vector<char> v = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
    sort(v.begin(), v.end());
    
    do
    {
        if(Valid(v, data))
            answer++;
    } while(next_permutation(v.begin(), v.end()));
        
    return answer;
}
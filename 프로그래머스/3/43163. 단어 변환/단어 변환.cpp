#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> visited;
int min_answer = 999;

void Dfs(string begin, string target, vector<string> words, int cnt)
{
    if (begin == target)
    {
        min_answer = min(min_answer, cnt);
        return;
    }
    
    for (int i = 0; i < words.size(); i++)
    {
        if (visited[i] == true) continue;
        
        // 단어 하나씩 비교
        string word = words[i];
        bool isConvertible = false;
        int count = 0;
        for(int j = 0; j < word.size(); j++)
        {
            if (word[j] == begin[j])
                count++;
        }
        if (count == word.size() - 1)
            isConvertible = true;
        
        // 바꿀 수 있음
        if (isConvertible)
        {
            visited[i] = true;
            Dfs(word, target, words, cnt + 1);
            visited[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    visited = vector<bool>(words.size(), false);
    Dfs(begin, target, words, 0);
    
    if (min_answer == 999) return 0;
    return min_answer;
}
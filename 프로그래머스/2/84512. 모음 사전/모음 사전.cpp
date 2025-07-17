#include <string>
#include <vector>

using namespace std;

int answer = 0;
int count = 0;
bool found = false;
vector<char> letters = {'A', 'E', 'I', 'O', 'U'};

void dfs(string current, const string& target) {
    if (found) return;

    if (current == target) {
        answer = count;
        found = true;
        return;
    }

    if (current.length() >= 5) return;

    for (char c : letters) {
        count++;
        dfs(current + c, target);
        if (found) return;
    }
}

int solution(string word) {
    answer = 0;
    count = 0;
    found = false;
    dfs("", word);
    return answer;
}

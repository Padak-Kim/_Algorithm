#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<bool> visited(26, false);
int K = 0;
int maxCnt = 0;
void DFS(vector<string>& words, int start, int depth)
{
    if (depth == K)
    {
        int cnt = 0;
        for (string& word : words)
        {
            bool ok = true;
            for (char c : word)
            {
                if (!visited[c - 'a']) {
                    ok = false;
					break;
                }
            }
            if (ok)
                cnt++;
        }
		maxCnt = max(maxCnt, cnt);
    }

    for (int i = start; i < 26; i++)
    {
        if (visited[i])
			continue;
		visited[i] = true;
        DFS(words, i + 1, depth + 1);
		visited[i] = false;
    }
}
int main() {
    int n, k;
    cin >> n >> k;
    vector<string> words(n);
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        words[i] = str.substr(4, str.size() - 8);
    }

    if (k < 5)
    {
        cout << 0;
        return 0;
    }
	vector<char> essential = { 'a', 'n', 't', 'i', 'c' };

    for (char c : essential)
        visited[c - 'a'] = true;

    K = k - 5;
    DFS(words, 0, 0);
	cout << maxCnt;
    return 0;
}
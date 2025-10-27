#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int map[26][26];
bool visited[26][26];
int home[1000];
int n;
int cnt = 0;
int xPos[4] = { 0, 0, -1, 1 }; // up, down, left, right
int yPos[4] = { 1, -1, 0, 0 }; // up, down, left, right
void Dfs(int x, int y) {
    visited[x][y] = true;
    ++home[cnt];

    for (int i = 0; i < 4; i++) {
        int new_xPos = x + xPos[i];
        int new_yPos = y + yPos[i];
        if (new_xPos >= 0 && new_xPos < n && new_yPos >= 0 && new_yPos < n && !visited[new_xPos][new_yPos]) {
            if (map[new_xPos][new_yPos] == 1) {
                Dfs(new_xPos, new_yPos);
            }
            else {
                continue;
            }
        }
    }
}

void DfsAll() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j] == false && map[i][j] == 1) {
                ++cnt;
                Dfs(i, j);
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(map, -1, sizeof(map));
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < s.length(); j++) {
            int num = s[j] - '0';
            map[i][j] = num;
        }
    }

    DfsAll();
    sort(home + 1, home + cnt + 1);
    cout << cnt << "\n";
    for (int i = 1; i <= cnt; i++) {
        cout << home[i] << "\n";
    }
    return 0;
}
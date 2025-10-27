#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int N;
char map[101][101];
char c_map[101][101];
bool visited[101][101];
bool c_visited[101][101];

int res1 = 0, res2 = 0;

int xpos[4] = { 0,0,-1,1 }; // up, down, left, right
int ypos[4] = { 1,-1,0,0 }; // up, down, left, right

void DFS(int y, int x)
{
    char here = map[y][x];
    visited[y][x] = true;

    for (int i = 0; i < 4; i++) {
        int new_xpos = x + xpos[i];
        int new_ypos = y + ypos[i];

        if (new_xpos < 0 || new_xpos >= N || new_ypos < 0 || new_ypos >= N)
            continue;

        if (visited[new_ypos][new_xpos] == true)
            continue;

        if (map[new_ypos][new_xpos] == here) // 이전과 색이 같을 때
        {
            DFS(new_ypos, new_xpos);
        }
    }
}

void c_DFS(int y, int x)
{
    char here = c_map[y][x];
    c_visited[y][x] = true;

    for (int i = 0; i < 4; i++) {
        int new_xpos = x + xpos[i];
        int new_ypos = y + ypos[i];

        if (new_xpos < 0 || new_xpos >= N || new_ypos < 0 || new_ypos >= N)
            continue;

        if (c_visited[new_ypos][new_xpos] == true)
            continue;

        if (c_map[new_ypos][new_xpos] == here) // 이전과 색이 같을 때
        {
            c_DFS(new_ypos, new_xpos);
        }
    }
}

void DFSAll()
{
    char prev_color = 'X';

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            char color = map[i][j];
            if (visited[i][j] == false)
            {
                res1++;
                DFS(i, j);             
            }
            if (c_visited[i][j] == false)
            {
                res2++;
                c_DFS(i, j);
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    memset(map, 'X', sizeof(map));
    memset(c_map, 'X', sizeof(c_map));
    memset(visited, false, sizeof(visited));
    memset(c_visited, false, sizeof(c_visited));

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];

            if (map[i][j] == 'R')
                c_map[i][j] = 'G';
            else
                c_map[i][j] = map[i][j];
        }
    }

    DFSAll();

    cout << res1 << " " << res2;

    return 0;
}

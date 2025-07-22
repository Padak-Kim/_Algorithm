#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Pos
{
    int x;
    int y;

    Pos(int xp, int yp) : x(xp), y(yp) {}
};
// UP, DOWN, LEFT, RIGHT
int xPos[4] = {0, 0, -1, 1};
int yPos[4] = { -1, 1, 0, 0 };

int answer = 0;
queue<Pos> q;
vector<vector<int>> distances;

void Bfs(vector<vector<int>> maps, int x, int y)
{
    distances[y][x] = 1;
    q.push(Pos(x, y));

    while (!q.empty())
    {
        Pos p = q.front(); q.pop();

        for (int i = 0; i < 4; i++)
        {
            int new_xPos = p.x + xPos[i];
            int new_yPos = p.y + yPos[i];

            if (new_xPos < 0 || new_xPos >= maps[0].size() ||
                new_yPos < 0 || new_yPos >= maps.size())
                continue;

            if (maps[new_yPos][new_xPos] == 1)
            {
                if (distances[new_yPos][new_xPos] != -1) continue;

                distances[new_yPos][new_xPos] = distances[p.y][p.x] + 1;
                q.push(Pos(new_xPos, new_yPos));
            }
        }
    }
}
int solution(vector<vector<int>> maps) 
{
    int n = maps.size();   // 행
    int m = maps[0].size(); // 열
    distances = vector<vector<int>>(n, vector<int>(m, -1));

    Bfs(maps, 0, 0);
    answer = distances[n - 1][m - 1];
    return answer;
}
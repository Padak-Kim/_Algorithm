#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <climits>
using namespace std;

vector<vector<char>> board;
int width, height;
int sx, sy;
int lx, ly;
int ex, ey;
int dx[4] = {-1, 1, 0, 0}; // left, right, up, down
int dy[4] = {0, 0, -1, 1}; // left, right, up, down
void BFS(vector<string>& maps, vector<vector<int>>& dist, int start_x, int start_y)
{
    queue<pair<int,int>> q;
    q.push({start_x, start_y});
    dist[start_y][start_x] = 0;
    
    while(!q.empty())
    {
        auto [cx, cy] = q.front(); q.pop();
        
        for(int dir = 0; dir < 4; dir++)
        {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            
            if (nx < 0 || nx >= width || ny < 0 || ny >= height)    continue;
            if (maps[ny][nx] == 'X')    continue;
            if (dist[ny][nx] > dist[cy][cx] + 1)
            {
                dist[ny][nx] = dist[cy][cx] + 1;
                q.push({nx, ny});
            }
        }            
        
    }
}
int solution(vector<string> maps) {
    height = maps.size();
    width = maps[0].size();
    sx, sy = 0;
    lx, ly = 0;
    ex, ey = 0;
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            if(maps[i][j] == 'S')
            {
                sx = j;
                sy = i;
            }
            else if (maps[i][j] == 'L')
            {
                lx = j;
                ly = i;
            }
            else if (maps[i][j] == 'E')
            {
                ex = j;
                ey = i;
            }
        }
    }
    int answer = 0;
    vector<vector<int>> distL(height, vector<int>(width, INT_MAX));
    BFS(maps, distL, sx, sy);
    if (distL[ly][lx] == INT_MAX)
        return -1;
    answer += distL[ly][lx];
    vector<vector<int>> distE(height, vector<int>(width, INT_MAX));
    BFS(maps, distE, lx, ly);
    if (distL[ey][ex] == INT_MAX)
        return -1;
    answer += distE[ey][ex];
    return answer;
}
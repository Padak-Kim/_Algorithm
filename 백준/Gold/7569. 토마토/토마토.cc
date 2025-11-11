#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int m, n, h;
int cnt = 0;

int new_xPos;
int new_yPos;
int new_zPos;
int xPos[6] = { 0,  0,  -1  ,1  ,0  ,0 }; // up, down, left, right, front, back
int yPos[6] = { 0,  0,  0,  0,  1,  -1 }; // up, down, left, right, front, back
int zPos[6] = { 1,  -1, 0,  0,  0,  0 }; // up, down, left, right, front, back
int map[101][101][101];
int days[101][101][101];
int max_day = 0;
struct Pos
{
    int X;
    int Y;
    int Z;
    Pos(int x, int y, int z)
    {
        X = x;
        Y = y;
        Z = z;
    }
};
queue<Pos> q;

void Bfs()
{

    while (!q.empty())
    {
        int x = q.front().X;
        int y = q.front().Y;
        int z = q.front().Z;
        q.pop();

        for (int i = 0; i < 6; i++)
        {
            new_xPos = xPos[i] + x;
            new_yPos = yPos[i] + y;
            new_zPos = zPos[i] + z;
            if (new_xPos < 0 || new_xPos >= m || new_yPos < 0 || new_yPos >= n || new_zPos < 0 || new_zPos >= h)
                continue;

            if (map[new_yPos][new_xPos][new_zPos] == -1 || map[new_yPos][new_xPos][new_zPos] == 1)
                continue;

            if (map[new_yPos][new_xPos][new_zPos] == 0)
            {
                map[new_yPos][new_xPos][new_zPos] = 1;
                days[new_yPos][new_xPos][new_zPos] = days[y][x][z] + 1;
                max_day = max(days[new_yPos][new_xPos][new_zPos], max_day);
                Pos pos(new_xPos, new_yPos, new_zPos);
                q.push(pos);
            }
        }
    }
}

bool Check()
{
    for (int z = 0; z < h; z++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (map[i][j][z] == 0)
                {
                    return false;
                }
            }
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> m >> n >> h;
    memset(map, -1, sizeof(map));
    memset(days, 0, sizeof(days));
    for (int z = 0; z < h; z++) 
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int num;

                cin >> num;
                map[i][j][z] = num; // y x z
                if (num == 1)
                {
                    Pos pos(j, i, z);
                    q.push(pos);
                }
            }
        }
    }
    Bfs();
    if (!Check())
        cout << -1;
    else
        cout << max_day;

    return 0;
}
#include <vector>
#include <queue>
using namespace std;

struct Pos
{
    Pos(int Pos_y, int Pos_x) : y(Pos_y), x(Pos_x)
    {

    }
    int y = 0;
    int x = 0;
};
int n, m;


vector<vector<int>> distances;
vector<vector<bool>> visited;

bool CanGo(Pos pos)
{
    if (pos.x < 0 || pos.x >= m)
        return false;
    if (pos.y < 0 || pos.y >= n)
        return false;
    return true;
}
int Bfs(vector<vector<int>> maps, int start_y, int start_x)
{
    n = maps.size();
    m = maps[0].size();

    distances = vector<vector<int>>(n, vector<int>(m, -1));
    visited = vector<vector<bool>>(n, vector<bool>(m, false));
    queue<Pos> q;

    q.push(Pos(start_y, start_x));
    distances[start_y][start_x] = 1;
    visited[start_y][start_x] = true;

    Pos front[4] =
    {
        Pos {-1, 0}, // Up
        Pos {0, -1}, // Left
        Pos {1, 0},  // Down
        Pos {0, 1}   // Right
    };
    while (!q.empty())
    {
        Pos pos = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int newPos_y = pos.y + front[i].y;
            int newPos_x = pos.x + front[i].x;

            if (!CanGo(Pos(newPos_y, newPos_x)))
                continue;
            if (maps[newPos_y][newPos_x] == 0)
                continue;
            if (visited[newPos_y][newPos_x] == true)
                continue;

            q.push(Pos(newPos_y, newPos_x));
            visited[newPos_y][newPos_x] = true;

            distances[newPos_y][newPos_x] = distances[pos.y][pos.x] + 1;
        }
    }

    if (visited[n - 1][m - 1] == false)
        return -1;
    return distances[n - 1][m - 1];
}
int solution(vector<vector<int>> maps)
{
    int answer = 0;
    
    answer = Bfs(maps, 0, 0);

    return answer;
}
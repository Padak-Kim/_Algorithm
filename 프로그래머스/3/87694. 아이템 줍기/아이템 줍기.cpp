#include <string>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;
const int MAX = 101;
int board[MAX][MAX];
int dist[MAX][MAX];

// 상하좌우
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    memset(board, 0, sizeof(board));
    memset(dist, -1, sizeof(dist));
    
    for (auto& rect : rectangle)
    {
        int x1 = rect[0] * 2;
        int y1 = rect[1] * 2;
        int x2 = rect[2] * 2;
        int y2 = rect[3] * 2;
        
        for (int y = y1; y <= y2; y++)
        {
            for (int x = x1; x <= x2; x++)
            {
                board[y][x] = 1;
            }
        }
        
    }
    
    for (auto& rect : rectangle)
    {
        int x1 = rect[0] * 2 + 1;
        int y1 = rect[1] * 2 + 1;
        int x2 = rect[2] * 2 - 1;
        int y2 = rect[3] * 2 - 1;
        
        for (int y = y1; y <= y2; y++)
        {
            for (int x = x1; x <= x2; x++)
            {
                board[y][x] = 0;
            }
        }
 
    }
    
    int sx = characterX * 2;
    int sy = characterY * 2;
    int ex = itemX * 2;
    int ey = itemY * 2;
    
    queue<pair<int,int>> q;
    q.push({sy, sx});
    dist[sy][sx] = 0;
    
    while(!q.empty())
    {
        auto [y, x] = q.front(); q.pop();
        
        for (int dir = 0; dir < 4; dir++)
        {
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            
            if (nx < 0 || nx >= MAX || ny < 0 || ny >= MAX) continue;
            if (board[ny][nx] == 0) continue;
            if (dist[ny][nx] != -1) continue;
            
            dist[ny][nx] = dist[y][x] + 1;
            q.push({ny, nx});
        }
    }
    
    return dist[ey][ex] / 2;
}
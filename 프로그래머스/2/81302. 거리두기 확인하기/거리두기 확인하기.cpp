#include <string>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = {0, 0, -1, 1}; // up, down, left, right
int dy[4] = {-1, 1, 0, 0}; // up, down, left, right
bool BFS(const vector<string>& place, int sy, int sx)
{
    queue<pair<int,int>> q;
    q.push({sy, sx});
    vector<vector<int>> dist(5, vector<int>(5, -1));
    dist[sy][sx] = 0;
    while(!q.empty())
    {
        auto [y, x] = q.front(); q.pop();
        
        for(int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if (ny < 0 || ny >= 5 || nx < 0 || nx >= 5) continue;
            
            // 이미 방문한 곳
            if (dist[ny][nx] != -1) continue;
            
            int d = dist[y][x] + 1;
            
            // 거리가 2 초과면 넘김
            if (d > 2) continue;
            
            // 파티션이면 넘김
            if (place[ny][nx] == 'X') continue;
            
            // 거리 2이내에 p를 만나면 넘김
            if (place[ny][nx] == 'P') return false;
            
            dist[ny][nx] = d;
            q.push({ny, nx});
        }
    }
    return true;
}
vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(vector<string>& place : places)
    {
        bool ok = true;
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (place[i][j] == 'P')
                {
                    if(BFS(place, i, j) == false)
                    {
                        ok = false;
                        break;
                    }
                }
            }
            if (!ok) break;
        }
        answer.push_back(ok ? 1 : 0);
    }
    return answer;
}
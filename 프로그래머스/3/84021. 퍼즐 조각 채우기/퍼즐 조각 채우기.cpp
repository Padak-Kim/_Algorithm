#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 상하좌우
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int n;

vector<pair<int,int>> normalize(vector<pair<int, int>> shape)
{
    sort(shape.begin(), shape.end());
    int y0 = shape[0].first;
    int x0 = shape[0].second;
    for (auto& [y, x] : shape)
    {
        y -= y0;
        x -= x0;
    }
    return shape;
}

vector<pair<int,int>> Rotate(vector<pair<int,int>> shape)
{
    vector<pair<int, int>> result;
    for (auto [y, x] : shape)
    {
        result.push_back({x, -y});
    }
    return normalize(result);
}
vector<vector<pair<int,int>>> Extract_Shapes(vector<vector<int>>& board, int value)
{
    vector<vector<pair<int,int>>> shapes;
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    
    for(int y = 0; y < n; y++)
    {
        for(int x = 0; x < n; x++)
        {
            if (!visited[y][x] && board[y][x] == value)
            {
                vector<pair<int,int>> shape;
                queue<pair<int,int>> q;
                q.push({y, x});
                visited[y][x] = true;
                int base_y = y, base_x = x;
                
                while(!q.empty())
                {
                    auto [cy, cx] = q.front(); q.pop();
                    shape.push_back({cy - base_y, cx - base_x});
                    for (int dir = 0; dir < 4; dir++)
                    {
                        int ny = cy + dy[dir];
                        int nx = cx + dx[dir];
                        
                        if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
                        if (!visited[ny][nx] && board[ny][nx] == value)
                        {                           
                            q.push({ny, nx});
                            visited[ny][nx] = true;
                        }
                    }
                }
                shapes.push_back(normalize(shape));
            }
        }
    }
    
    return shapes;
}


int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    n = game_board.size();
    auto empty_spaces = Extract_Shapes(game_board, 0);
    auto puzzle_blocks = Extract_Shapes(table, 1);
    vector<bool> used(puzzle_blocks.size(), false);
    int answer = 0;
    
    for (auto& space : empty_spaces)
    {
        bool found = false;
        for (int i = 0; i < puzzle_blocks.size(); i++)
        {
            if (used[i]) continue;
            auto shape = puzzle_blocks[i];
            for (int r = 0; r < 4; r++)
            {
                if (space == shape)
                {
                    used[i] = true;
                    answer += shape.size();
                    found = true;
                    break;
                }
                shape = Rotate(shape);
            }
            if (found) break;
        }
    }
    return answer;
}
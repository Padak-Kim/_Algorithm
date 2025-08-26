#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    while (true)
    {
        bool flag = false;
        set<pair<int, int>> mark;
        // 지울 칸 표시
        for (int i = 0; i < m - 1; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
                char c = board[i][j];
                if (c == '.')   continue;
                
                if (board[i][j+1] == c && board[i+1][j] == c && board[i+1][j+1] == c)
                {
                    mark.insert({i, j});
                    mark.insert({i+1, j});
                    mark.insert({i, j+1});
                    mark.insert({i+1, j+1});
                    flag = true;
                }
            }
        }
        
        // 지울게 없으면 종료
        if (!flag)  break;
        
        // 지우고 카운트
        for (auto [y, x] : mark)
        {
            board[y][x] = '.';
            answer++;
        }
        
        // 중력 처리
        for (int x = 0; x < n; ++x) 
        {
            int write = m - 1;              // 아래에서부터 채울 위치
            for (int y = m - 1; y >= 0; --y) 
            {
                if (board[y][x] != '.') {
                    board[write][x] = board[y][x];
                    if (write != y) board[y][x] = '.';
                    --write;
                }
            }
        }
    }
    return answer;
}
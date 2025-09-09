#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    
    int dy[4] = {-1, 1, 0, 0}; // up, down, left, right
    int dx[4] = {0, 0, -1, 1}; // up, down, left, right
    
    string color = board[h][w];
    
    for (int dir = 0; dir < 4; dir++)
    {
        if (h + dy[dir] < 0 || h + dy[dir] >= board.size() || w + dx[dir] < 0 || w + dx[dir] >= board.size())
            continue;
        if (color == board[h + dy[dir]][w + dx[dir]])
            answer++;
    }
    
    return answer;
}
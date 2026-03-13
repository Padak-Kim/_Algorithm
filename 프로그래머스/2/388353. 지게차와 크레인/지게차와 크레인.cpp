#include <string>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void markOutside(vector<string>& board, vector<vector<bool>>& outside) {
    int n = board.size();
    int m = board[0].size();

    outside.assign(n, vector<bool>(m, false));
    queue<pair<int,int>> q;

    q.push({0, 0});
    outside[0][0] = true;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (outside[nx][ny]) continue;

            // 빈칸(.)만 통해서 외부가 퍼져나감
            if (board[nx][ny] == '.') {
                outside[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

int solution(vector<string> storage, vector<string> requests) {
    int h = storage.size();
    int w = storage[0].size();

    // 바깥 한 겹 패딩 추가
    vector<string> board(h + 2, string(w + 2, '.'));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            board[i + 1][j + 1] = storage[i][j];
        }
    }

    vector<vector<bool>> outside;

    for (string req : requests) {
        char target = req[0];

        // 현재 시점 기준 외부 연결 빈칸 표시
        markOutside(board, outside);

        vector<pair<int,int>> removeList;

        if (req.size() == 1) {
            // 지게차: 현재 시점에 외부와 닿아 있는 target만 제거
            for (int i = 1; i <= h; i++) {
                for (int j = 1; j <= w; j++) {
                    if (board[i][j] != target) continue;

                    bool accessible = false;
                    for (int dir = 0; dir < 4; dir++) {
                        int ni = i + dx[dir];
                        int nj = j + dy[dir];
                        if (outside[ni][nj]) {
                            accessible = true;
                            break;
                        }
                    }

                    if (accessible) removeList.push_back({i, j});
                }
            }
        } else {
            // 크레인: target 전부 제거
            for (int i = 1; i <= h; i++) {
                for (int j = 1; j <= w; j++) {
                    if (board[i][j] == target) {
                        removeList.push_back({i, j});
                    }
                }
            }
        }

        // 한 요청에서 제거될 것들 한꺼번에 제거
        for (auto [x, y] : removeList) {
            board[x][y] = '.';
        }
    }

    int answer = 0;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (board[i][j] != '.') answer++;
        }
    }
    return answer;
}
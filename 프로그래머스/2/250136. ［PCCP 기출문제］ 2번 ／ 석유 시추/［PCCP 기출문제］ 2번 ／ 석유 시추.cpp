#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void DfsLabel(const vector<vector<int>>& land,
              vector<vector<int>>& comp,
              int y, int x, int id, int& sizeCnt)
{
    int h = land.size();
    int w = land[0].size();

    comp[y][x] = id;
    sizeCnt++;

    for (int dir = 0; dir < 4; dir++) {
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
        if (land[ny][nx] == 0) continue;
        if (comp[ny][nx] != -1) continue;

        DfsLabel(land, comp, ny, nx, id, sizeCnt);
    }
}

int solution(vector<vector<int>> land) {
    int h = land.size();
    int w = land[0].size();

    // 1) 컴포넌트 라벨링
    vector<vector<int>> comp(h, vector<int>(w, -1));
    vector<int> compSize;
    int id = 0;

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (land[y][x] == 1 && comp[y][x] == -1) {
                int cnt = 0;
                DfsLabel(land, comp, y, x, id, cnt);
                compSize.push_back(cnt);
                id++;
            }
        }
    }

    // 2) 열별로 고유한 컴포넌트 id들의 크기를 합산
    int answer = 0;
    vector<int> lastSeen(id, -1); // 열마다 중복 합산 방지용

    for (int col = 0; col < w; col++) {
        int sum = 0;
        for (int row = 0; row < h; row++) {
            int cid = comp[row][col];
            if (cid == -1) continue;
            if (lastSeen[cid] == col) continue; // 이미 더한 컴포넌트
            lastSeen[cid] = col;
            sum += compSize[cid];
        }
        answer = max(answer, sum);
    }

    return answer;
}

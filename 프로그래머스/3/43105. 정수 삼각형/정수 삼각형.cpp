#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int N = triangle.size();

    // triangle을 그대로 dp로 활용
    for (int y = N - 2; y >= 0; --y) {
        for (int x = 0; x <= y; ++x) {
            triangle[y][x] += max(triangle[y + 1][x], triangle[y + 1][x + 1]);
        }
    }

    return triangle[0][0];  // 최종 최대 경로 합
}

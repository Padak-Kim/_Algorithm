#include <iostream>
#include <deque>
#include <vector>
#include <unordered_map>
#include <queue>
#include <climits>
#include <cmath>
#include <algorithm>
using namespace std;

int toDate(int m, int d)
{
    return m * 100 + d;
}

// 시작 날짜 오름차순
// 시작이 같다면 끝 날짜 내림차순
bool compare(const vector<int>& a, const vector<int>& b)
{
    int aStart = toDate(a[0], a[1]);
    int bStart = toDate(b[0], b[1]);

    if (aStart != bStart)
        return aStart < bStart;

    int aEnd = toDate(a[2], a[3]);
    int bEnd = toDate(b[2], b[3]);

    return aEnd > bEnd;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> v(n, vector<int>(4));
    for (int i = 0; i < n; i++)
    {
        int startM, startD, endM, endD;

        cin >> startM >> startD >> endM >> endD;
        v[i][0] = startM;
        v[i][1] = startD;
        v[i][2] = endM;
        v[i][3] = endD;
    }

    int answer = 0;

    sort(v.begin(), v.end(), compare);

    int cur = toDate(3, 1);
    int target = toDate(11, 30);

    int idx = 0;
    while (cur <= target)
    {
        int bestEnd = cur;
        // 피는 날이 cur보다 낮은 꽃 중 가장 오래 피는 꽃

        while (idx < n)
        {
            int start = toDate(v[idx][0], v[idx][1]);
            int end = toDate(v[idx][2], v[idx][3]);

            if (start > cur)
                break;

            bestEnd = max(bestEnd, end);
            idx++;
        }

        if (bestEnd == cur)
        {
            answer = 0;
            break;
        }

        answer++;
        cur = bestEnd;
    }

    cout << answer;

    return 0;
}

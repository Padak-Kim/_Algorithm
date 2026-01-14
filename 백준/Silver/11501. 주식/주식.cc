#include <iostream>
#include <deque>
#include <vector>
#include <unordered_map>
#include <queue>
#include <climits>
#include <cmath>
#include <algorithm>
using namespace std;

// 오늘 가격이 앞으로 나올 어떤 날의 가격보다 싸다
// -> 사는 게 이득
// 오늘 가격이 앞으로의 최고가보다 비싸거나 같다면
// -> 사는 게 손해

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        int d;
        cin >> d;

        long long answer = 0;

        vector<int> v(d);
        for (int i = 0; i < d; i++)
        {
            cin >> v[i];
        }

        int maxNum = 0; // 최고가
        for (int j = d - 1; j >= 0; j--)
        {
            if (maxNum <= v[j])
            {
                maxNum = v[j];
            }
            else
            {
                answer += maxNum - v[j];
            }

        }

        cout << answer << endl;
    }

    
    return 0;
}

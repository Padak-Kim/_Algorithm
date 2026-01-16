#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, C;
    cin >> N >> C;

    vector<long long> x(N);
    for (int i = 0; i < N; i++) cin >> x[i];
    sort(x.begin(), x.end());

    auto canPlace = [&](long long d) -> bool {
        int cnt = 1;                 // 첫 집에 설치
        long long last = x[0];

        for (int i = 1; i < N; i++) {
            if (x[i] - last >= d) {
                cnt++;
                last = x[i];
                if (cnt >= C) return true;
            }
        }
        return cnt >= C;
    };

    long long lo = 1;
    long long hi = x.back() - x.front();
    long long ans = 0;

    while (lo <= hi) {
        long long mid = lo + (hi - lo) / 2;

        if (canPlace(mid)) {     // mid 거리로 C개 가능 -> 더 늘려보기
            ans = mid;
            lo = mid + 1;
        } else {                 // 불가능 -> 거리 줄이기
            hi = mid - 1;
        }
    }

    cout << ans << "\n";
    return 0;
}

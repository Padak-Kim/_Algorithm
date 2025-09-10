#include <bits/stdc++.h>
using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    for (long long x = 1; x <= r2; x++) {
        // 바깥 원에서 가능한 최대 y
        long long y_max = floor(sqrt(1LL * r2 * r2 - x * x));
        // 안쪽 원에서 가능한 최소 y
        long long y_min = ceil(sqrt(max(0LL, 1LL * r1 * r1 - x * x)));

        answer += (y_max - y_min + 1);
    }
    return answer * 4; // 1사분면 계산 후 대칭
}

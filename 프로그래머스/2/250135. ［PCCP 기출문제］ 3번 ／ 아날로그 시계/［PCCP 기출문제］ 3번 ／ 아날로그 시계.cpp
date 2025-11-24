#include <bits/stdc++.h>
using namespace std;

long long solution(int h1, int m1, int s1,
                   int h2, int m2, int s2)
{
    const int FULL = 43200;  // 360도 * 120배 스케일

    long long start = 1LL * h1 * 3600 + 1LL * m1 * 60 + s1;
    long long end   = 1LL * h2 * 3600 + 1LL * m2 * 60 + s2;

    long long ans = 0;

    // 시작 시각이 0시 또는 12시라면 이미 세 바늘이 겹쳐 있음
    if (start == 0 || start == 12 * 3600)
        ans++;

    auto normCur = [&](long long x) {
        return x % FULL;          // 현재는 0도 그대로
    };
    auto normNext = [&](long long x) {
        x %= FULL;
        if (x == 0) x = FULL;     // 다음은 0을 FULL로 바꿔 단조 증가처럼
        return x;
    };

    for (long long t = start; t < end; ++t) {
        long long curH = normCur(t);          // 시침: 1단위/초
        long long curM = normCur(t * 12);     // 분침: 12단위/초
        long long curS = normCur(t * 720);    // 초침: 720단위/초

        long long nextH = normNext(t + 1);
        long long nextM = normNext((t + 1) * 12);
        long long nextS = normNext((t + 1) * 720);

        bool hit = false;

        if (curS < curH && nextS >= nextH) {  // 초침-시침 cross
            ans++;
            hit = true;
        }
        if (curS < curM && nextS >= nextM) {  // 초침-분침 cross
            ans++;
            hit = true;
        }

        // 세 바늘 동시에 겹쳤다면(2번 센 것 중 1번 빼기)
        if (hit && nextS == nextH && nextH == nextM)
            ans--;
    }

    return ans;
}

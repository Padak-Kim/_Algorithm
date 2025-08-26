#include <string>
#include <vector>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;

    long long y = d - (d % k);
    const long long D2 = 1LL * d * d;          // ← 오버플로우 방지: long long

    for (long long x = 0; x <= d; x += k) {
        while (y >= 0 && (x*x) + (y*y) > D2) { // ← d*d 대신 D2 사용
            y -= k;
        }
        answer += y / k + 1;                   // y<0이면 0 더해짐(OK)
    }
    return answer;
}
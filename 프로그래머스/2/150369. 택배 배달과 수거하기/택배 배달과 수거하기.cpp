#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;

    // 뒤에서부터 남은 배달/수거량을 누적해서 관리
    long long needD = 0; // i번 집까지(0..i) 처리하기 위해 남아있는 배달 총량
    long long needP = 0; // i번 집까지 처리하기 위해 남아있는 수거 총량

    for (int i = n - 1; i >= 0; --i) {
        needD += deliveries[i];
        needP += pickups[i];

        if (needD == 0 && needP == 0) continue;

        // i까지 오기 위해 필요한 왕복 횟수(배달/수거 둘 중 큰 쪽을 커버해야 함)
        long long trips = max(
            (needD + cap - 1) / cap,
            (needP + cap - 1) / cap
        );

        // 거리: (i+1)까지 왕복이므로 *2
        answer += (long long)(i + 1) * 2 * trips;

        needD -= trips * cap;
        needP -= trips * cap;
    }

    return answer;
}
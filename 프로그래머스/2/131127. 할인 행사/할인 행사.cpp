#include <bits/stdc++.h>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    const int K = 10;
    if ((int)discount.size() < K) return 0;

    unordered_map<string,int> need, cur;
    for (int i = 0; i < (int)want.size(); ++i) need[want[i]] = number[i];

    auto ok = [&](){
        // want에 있는 품목만 검사 (최대 10개라 매번 검사해도 빠름)
        for (int i = 0; i < (int)want.size(); ++i) {
            if (cur[want[i]] < number[i]) return false;
        }
        return true;
    };

    // 초기 윈도우 [0, K)
    for (int i = 0; i < K; ++i) {
        if (need.count(discount[i])) cur[discount[i]]++;
    }

    int answer = 0;
    if (ok()) answer++;

    // 한 칸씩 슬라이드
    for (int i = K; i < (int)discount.size(); ++i) {
        const string& out = discount[i - K];
        const string& in  = discount[i];

        if (need.count(out)) cur[out]--;   // 나가는 것 반영
        if (need.count(in))  cur[in]++;    // 들어오는 것 반영

        if (ok()) answer++;
    }
    return answer;
}

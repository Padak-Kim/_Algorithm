#include <vector>
#include <numeric> 
using namespace std;


bool isYellow(const vector<int>& s, long long t) {
    int G = s[0], Y = s[1], R = s[2];
    int P = G + Y + R;

    int x = (t - 1) % P;
    return (G <= x && x < G + Y);
}

int solution(vector<vector<int>> signals) {
    long long L = 1;

    for (const auto& s : signals) {
        int P = s[0] + s[1] + s[2];
        L = L / gcd(L, P) * P;
    }

    // 1초부터 LCM초까지 탐색
    for (long long t = 1; t <= L; t++) {
        bool ok = true;
        for (const auto& s : signals) {
            if (!isYellow(s, t)) {
                ok = false;
                break;
            }
        }
        if (ok) return (int)t;
    }

    return -1;
}
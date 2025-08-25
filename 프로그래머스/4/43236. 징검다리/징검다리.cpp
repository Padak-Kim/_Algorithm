#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool CanProcess(int distance, const vector<int>& rocks, int n, long long mid)
{
    int remove = 0; // 제거한 바위 수
    int prev = 0; // 이전지점 (처음은 0)
    for(auto& r : rocks)
    {
        // mid보다 값이 작음 -> 거리의 최소값보다 작아서 바위를 제거서 거리를 늘려야함
        if (r - prev < mid)
        {
            remove++;
        }
        else // 거리의 최소값보다 크거나 같음 -> 조건 만족 -> 바위로 점프
        {
            prev = r;
        }
        
        if (remove > n) return false; // 제거해야하는 개수보다 더 많으면 실패
    }
    
    if (distance - prev < mid)  remove++; // 도착지와 마지막 바위와 비교
    
    return remove <= n;
}
    
int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    
    long long lo = 0;
    long long hi = distance;
    
    sort(rocks.begin(), rocks.end());
    
    while(hi >= lo)
    {
        long long mid = lo + (hi - lo) / 2;
        
        if (CanProcess(distance, rocks, n, mid))
        {
            lo = mid + 1;
            answer = mid;
        }
        else
        {
            hi = mid - 1;
        }
    }
    
    return answer;
}
#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    
    // 부분 문자열의 길이
    int k = p.size();
    // 전체 문자열의 길이
    int n = t.size();
    
    // 합쳐진 문자열
    string sum;
    for(int r = 0; r < n; r++)
    {
        sum += t[r];
        // 문자열 길이가 같아지고 sum이 
        if (sum.size() == k)
        {
            if (sum <= p)
            {
                answer++;   
            }
            sum.erase(0,1);
        }
    }
    
    return answer;
}
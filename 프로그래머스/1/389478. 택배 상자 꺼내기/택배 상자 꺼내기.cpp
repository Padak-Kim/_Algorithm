#include <string>
#include <vector>

using namespace std;

int solution(int n, int w, int num) {
    int answer = 0;
    
    int level = ((num - 1) / w) + 1; // num의 층수
    int pos = ((num - 1) % w) + 1; // 같은 층 기준점에서부터 몇 칸 떨어진지 (1 ~ w)
    
    while (true)
    {
        int value = w * (level - 1) + pos;
        
        if (n >= value) answer++;
        if (n < value)  break;
        
        level++;
        pos = w - (pos - 1);
    }
    
    return answer;
}
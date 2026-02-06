#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = 0;
    int n = s.size();
    
    int bestlength = n;
    // 문자열길이의 반까지 잘라가면서 모두 검사
    for(int l = 1; l <= n / 2; l++)
    {     
        string prev = s.substr(0, l);
        int count = 1;  
        string word = "";
        
        // l크기만큼 자르기
        for(int i = l; i < n; i += l)
        {
            string cur = s.substr(i, min(l, n - i));
            
            if (cur == prev)
            {
                count++;
            }
            else
            {
                if (count > 1)
                    word += to_string(count);
                word += prev;
                
                prev = cur;
                count = 1;
            }
        }
        
        if (count > 1)
            word += to_string(count);
        word += prev;
        
        bestlength = min(bestlength, (int)word.size());
    }
    
    answer = bestlength;
    return answer;
}
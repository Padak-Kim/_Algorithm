#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    unordered_map<string, int> um1; // 부분문자, count
    unordered_map<string, int> um2; // 부분문자, count
    // 대문자로 통일
    transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
    transform(str2.begin(), str2.end(), str2.begin(), ::toupper);
    
    int um1Cnt = 0;    
    int um2Cnt = 0;
    bool Check = false;
    // 부분집합 생성
    for(int i = 0; i < str1.size() - 1; i++)
    {
        if (str1[i] >= 'A' && str1[i] <= 'Z' && str1[i + 1] >= 'A' && str1[i + 1] <= 'Z')
        {           
            um1[{ str1[i], str1[i + 1]}]++;
            um1Cnt++;
        }
    }
    for(int i = 0; i < str2.size() - 1; i++)
    {
        if (str2[i] >= 'A' && str2[i] <= 'Z' && str2[i + 1] >= 'A' && str2[i + 1] <= 'Z')
        {
            um2[{ str2[i], str2[i + 1]}]++;
            um2Cnt++;
            
            if (!Check)
            {
                // um1에 없는 문자
                if (um1.find({ str2[i], str2[i + 1]}) == um1.end())
                    Check = true;          
            }
        }
    }
    
    // 둘 다 부분문자열 없음
    if (um1.empty() && um2.empty())
        return 65536;
    
    int num1 = 0; // 교집합
    int num2 = 0; // 합집합
    
    for(auto& [s, c] : um1)
    {
        // 같은 부분문자열 있음
        if (um2.find(s) != um2.end())
        {
            // 교집합 추가
            int minCnt = min(c, um2[s]);
            num1 += minCnt;
        }
    }
    
    // 합집합
    num2 = um1Cnt + um2Cnt - num1;
    // (교집합 / 합집합) * 65536
    double res = (double)num1 / (double)num2 * 65536;
    answer = (int)res; 
    
    return answer;
}
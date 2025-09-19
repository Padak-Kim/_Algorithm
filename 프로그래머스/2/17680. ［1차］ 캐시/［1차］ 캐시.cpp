#include <string>
#include <vector>
#include <unordered_map>
#include <list>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    list<string> li;
    unordered_map<string, list<string>::iterator> um;
    
    if (cacheSize == 0) return cities.size() * 5;
    
    for(int i = 0; i < cities.size(); i++)
    {
        string key = cities[i];
        transform(key.begin(), key.end(), key.begin(), ::tolower);
        if (um.find(key) == um.end())   // 새 원소
        {
            if (li.size() == cacheSize)
            {
                // 꽉 차서 가장 마지막에 추가된 것 삭제
                string last = li.back(); li.pop_back();
                um.erase(last);
            }
            answer += 5;
        }
        else // 이미 있음
        {
            li.erase(um[key]);
            answer++;
        }
        li.push_front(key);
        um[key] = li.begin();
    }
    
    return answer;
}
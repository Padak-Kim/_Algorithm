#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <list>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    list<string> li;
	unordered_map<string, list<string>::iterator> um;
    
    if (cacheSize == 0) return cities.size() * 5;
    for(int i = 0 ; i < cities.size(); i++)
    {
        string city = cities[i];
        transform(city.begin(), city.end(), city.begin(), ::tolower);
        auto it = um.find(city);
        if (it != um.end()) // 캐시에 있음
        {
            // 삭제 후 뒤로 보내기
            li.erase(it->second);
            um.erase(city);
            answer += 1;
        }
        else
        {
            // 캐시에 없음
            // 꽉 찼으면 가장 오래된거 제거
            if (li.size() >= cacheSize)
            {
                um.erase(*li.begin());
                li.pop_front();   
            }
            answer += 5;    
        }
        
        // 새로 삽입
        li.push_back(city);
        um[city] = prev(li.end());
    }
    return answer;
}
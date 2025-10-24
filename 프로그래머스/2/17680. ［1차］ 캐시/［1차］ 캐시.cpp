#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    if (cacheSize == 0)
        return cities.size() * 5;
    
    unordered_map<string, list<string>::iterator> um; // cityName, whereInList
    list<string> cacheList;
    int cnt = 0;
    for(auto& city : cities)
    {
        transform(city.begin(), city.end(), city.begin(), ::tolower);
        // 첫 도시
        
        auto it = um.find(city);
        // 새로운 도시 들어왔을 때
        if (it == um.end())
        {
            if (cacheList.size() == cacheSize)
            {
                // 제일 오래된 것 삭제
                string oldCity = cacheList.back();
                um.erase(oldCity);
                cacheList.pop_back();
            }

            // 새로운 도시 유입
            cacheList.push_front(city);
            um.insert({city, cacheList.begin()});
            answer += 5;
        }
        else // 캐시안에 있는 것 들어왔을 때
        {
            // 캐시안에 있는 것 삭제하고 다시 생성
            cacheList.erase(it->second);
            cacheList.push_front(city);

            um[city] = cacheList.begin();
            answer++;


            //cout << city << " 캐시가 반환됐습니다. " << answer << endl;
        }
    }
    return answer;
}
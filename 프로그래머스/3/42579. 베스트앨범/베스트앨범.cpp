#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, vector<pair<int,int>>> um; // [장르, [고유 번호, 재생 수]]
    unordered_map<string, int> um2; // [장르, 총 재생 수]
    for(int i = 0; i < plays.size(); i++)
    {
        um[genres[i]].push_back({i, plays[i]});
        um2[genres[i]] += plays[i];
    }
    multimap<int, string, greater<int>> mm;
    
    // 장르별 총 재생 수 별로 정렬
    for(auto& p : um2)
    {
        mm.insert({p.second, p.first});
    }
    
    // [총 재생 수, 장르]
    for (auto& p : mm)
    {
        string genre = p.second;
        cout << genre << endl;
        // [재생 수, 고유 번호]
        multimap<int, int, greater<int>> mm2;
        for (auto& p2 : um)
        {
            if (p2.first == genre)
            {
                for (auto & v : p2.second)
                {
                    mm2.insert({v.second, v.first});        
                }
            }
        }
        
        int cnt = 0;
        for (auto& p2 : mm2)
        {
            answer.push_back(p2.second);
            
            cnt++;
            if (cnt == 2)
                break;
        }
    }
    return answer;
}
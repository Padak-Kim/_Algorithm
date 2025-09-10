#include <bits/stdc++.h>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    unordered_map<string, int> pos; 
    pos.reserve(players.size() * 2);

    for (int i = 0; i < (int)players.size(); ++i)
        pos[players[i]] = i;

    for (const string& name : callings) {
        int i = pos[name];
        if (i == 0) continue;               // 이미 1등이면 스킵 (문제 조건상 거의 없음)

        string& cur = players[i];
        string& front = players[i - 1];
        
        
        // 위치 갱신
        pos[cur] = i - 1;       // cur는 한 칸 앞
        pos[front] = i;         // front는 한 칸 뒤
        
        // 자리 바꾸기
        swap(cur, front);
    
    }
    return players;
}

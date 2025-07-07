#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string name) {
    int answer = 0;
    
    for (char c : name) 
    {
        int up = c - 'A';
        int down = 'Z' - c + 1;
        answer += min(up, down);
    }
    
    int move = name.size() - 1;

    for (int i = 0; i < name.size(); i++) {
        int next = i + 1;
        while (next < name.size() && name[next] == 'A')
            next++;
        
        int b = name.size() - next;
        int numMin = min(i, b);
        
        int goBack = i + name.size() - next + numMin;
        move = min(move, goBack);
    }

    answer += move;
    
    return answer;
}
#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    int n = 0; // 증설돼 있는 서버 개수
    queue<int> q;
    int time = 0;
    for(int i = 0; i < k; i++)
        q.push(0);
    for(int& p : players)
    {
        int front = q.front();
        q.pop();
        n -= front;
        
        cout << "[" << time <<"H] " << p << " / " << m << " < " << n << endl;
        // 서버 증설 필요
        if (p / m > n)
        {
            int server = (p / m) - n;
            
            cout << server << endl;
            answer += server;
            q.push(server);
            n += server;
        }
        else
            q.push(0);          
        
        time++;
    }
    
    return answer;
}
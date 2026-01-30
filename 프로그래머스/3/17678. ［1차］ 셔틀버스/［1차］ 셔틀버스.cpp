#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int ToMin(const string& s)
{
    int h = stoi(s.substr(0,2));
    int m = stoi(s.substr(3,2));
    
    return h * 60 + m;
}

string ToHHMM(int x)
{
    int h = x / 60;
    int m = x % 60;
    
    string hh = (h < 10 ? "0" : "") + to_string(h);
    string mm = (m < 10 ? "0" : "") + to_string(m);

    return hh + ":" + mm;
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    
    vector<int> crew;
    crew.reserve(timetable.size());
    
    for(int i = 0; i < timetable.size(); i++)
    {
        crew.push_back(ToMin(timetable[i]));
    }
    sort(crew.begin(), crew.end());
    
    // 마지막 셔틀 시간
    int lastBusTime = 540 + t * (n - 1);
    
    // 아직 탑승 못한 크루 idx
    int idx = 0;
    
    // 막차에 탄 인원
    int lastCnt = 0;
    // 막차에 마지막으로 탄 인원의 탑승시간
    int lastVisitor = 0;
    for(int i = 0; i < n; i++)
    {
        int busTime = 540 + i * t; // 현재 버스 시간
        int cnt = 0; // 현재 버스 인원
        while (idx < crew.size() && crew[idx] <= busTime && cnt < m)
        {
            // 탑승
            lastVisitor = crew[idx];
            idx++;
            cnt++;
            
        }
        
        if (i == n - 1)
            lastCnt = cnt;
    }
    
    // 마지막 셔틀에 자리가 남은 경우
    if (lastCnt < m)
        return ToHHMM(lastBusTime);
    // 마지막 셔틀이 꽉찬 경우
    // 마지막 사람보다 1분 빨리 도착해야함
    else
        return ToHHMM(lastVisitor - 1);
}
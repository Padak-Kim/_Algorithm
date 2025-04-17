#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = schedules.size();
    for (int j = 0; j < schedules.size(); j++)
    {
        int worktime = schedules[j] + 10;        // 출근 인정 시간 (+10)
        vector<int> timelog = timelogs[j];  // 출근 로그
        bool flag = true;
        
        if (worktime % 100 >= 60)
        {
            worktime += 40;     // 10분 추가 했을 때 60분넘으면 다음 시간으로 넘어감
        }
        
        for (int i = 0; i < 7; i++)
        {
            if (!flag) break;
            
            int startday_cnt = startday - 1 + i;
            if ((startday_cnt) % 7 >= 5)
            {
                continue;
            }
            //cout << timelog[i] << " " << worktime << endl;
            if (timelog[i] > worktime)
            {
                answer--;
                flag = false;
            }
        }
    }
    return answer;
}
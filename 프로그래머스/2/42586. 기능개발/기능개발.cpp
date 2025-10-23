#include <string>
#include <vector>
#include <iostream>
using namespace std;

int CalculationDate(int progress, int speed)
{
    int day = (100 - progress) / speed;
    if ((100 - progress) % speed != 0) // 나머지가 나오면 +1
        day++;
    
    return day;
}
vector<int> solution(vector<int> progresses, vector<int> speeds) 
{
    vector<int> answer;
    
    int proceeding = 0;
    int cnt = 0;
    for(int i = 0; i < progresses.size(); i++)
    {
        int day = CalculationDate(progresses[i], speeds[i]);
        if (proceeding == 0)
        {
            proceeding = day;
            cnt++;
        }
        else
        {
            if (proceeding >= day)
            {
                cnt++;
            }
            else
            {
                answer.push_back(cnt);
                proceeding = day;
                cnt = 1;
            }
        }
    }
    
    answer.push_back(cnt);
    return answer;
}
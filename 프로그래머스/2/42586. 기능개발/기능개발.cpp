#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    for (int i = 0; i < progresses.size(); i++)
    {
        int count = 1; // 배포 개수
        
        
        int day = (100 - progresses[i]) / speeds[i]; // 배포 일 수
        
        if ((100 - progresses[i]) % speeds[i] != 0) // 작업이 남았으면 +1
            day++;
        
        while(i + 1 < progresses.size())
        {
            int nextDay = (100 - progresses[i + 1]) / speeds[i + 1];
            
            if ((100 - progresses[i + 1]) % speeds[i + 1] != 0) // 작업이 남았으면 +1
                nextDay++;
            
            if (day >= nextDay)
            {
                count++;
                i++;
            }
            else
            {
                break;
            }
        }
        
        answer.push_back(count);
    }
    
    return answer;
}
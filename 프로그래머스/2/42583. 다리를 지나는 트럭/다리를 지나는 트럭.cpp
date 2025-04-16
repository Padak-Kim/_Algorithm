#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    vector<int> finish_truck;
    queue<int> ing_truck;
    
    int sum = 0; // weight 합산
    int now_index = 0;
    while(finish_truck.size() != truck_weights.size())
    {
        answer++; // 시간 초 증가
        
        if (ing_truck.size() == bridge_length)
        {
            // 다리 지남
            sum -= ing_truck.front();
            if (ing_truck.front() != 0)
            {
                finish_truck.push_back(ing_truck.front());
            }
            ing_truck.pop();
        }
        if (weight >= sum + truck_weights[now_index])
        {
            // 다리 진입
            sum += truck_weights[now_index];
            ing_truck.push(truck_weights[now_index]); 
            now_index++;
        }
        else
        {
            // 아무도 진입하지 못함
            ing_truck.push(0);
        }
        
    }
    
    return answer;
}
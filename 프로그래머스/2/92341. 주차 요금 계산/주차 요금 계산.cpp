#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <unordered_map>
#include <map>
#include <unordered_set>
using namespace std;

int CalculationParkTime(const string& enterTime, const string& exitTime)
{
    int parkTime = (stoi(exitTime.substr(0,2)) * 60 + stoi(exitTime.substr(3,5))) - 
            (stoi(enterTime.substr(0,2)) * 60 + stoi(enterTime.substr(3,5)));
    
    return parkTime;
}
vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    unordered_map<int, string> enterTimeDB; // carNumber, time
    map<int, int> parkTimeDB; // carNumber, parkTime
    for(string& record : records)
    {
        stringstream ss(record);
        string time, carNumber, op;
        ss >> time >> carNumber >> op;
        
        int num = stoi(carNumber);
        if (op == "IN")
        {
            enterTimeDB.insert({num, time});
        } 
        else // OUT
        {
            // 시간 계산
            // 입차 시간
            string enterTime = enterTimeDB[num];
            
            int parkTime = CalculationParkTime(enterTime, time);
            
            enterTimeDB.erase(num);
            
            auto it = parkTimeDB.find(num);
            if (it == parkTimeDB.end())
                parkTimeDB.insert({num, parkTime});
            else
                parkTimeDB[num] += parkTime;
            
            //cout << num << " : "<< parkTimeDB[num] << "분"<< endl;
        }
    }
    // 출차기록이 없는 차량들
    for (auto iter = enterTimeDB.begin(); iter != enterTimeDB.end(); ++iter)
    {
        int num = iter->first;
        string enterTime = iter->second;
        string exitTime = "23:59";
        int parkTime = CalculationParkTime(enterTime, exitTime);
        
        auto it = parkTimeDB.find(num);
        if (it == parkTimeDB.end())
            parkTimeDB.insert({num, parkTime});
        else
            parkTimeDB[num] += parkTime;
        
        cout << num << " : "<< parkTimeDB[num] << "분"<< endl;
    }
    // 주차 요금 계산
    for(auto iter = parkTimeDB.begin(); iter != parkTimeDB.end(); ++iter)
    {   
        int basicTime = fees[0];
        int basicFee = fees[1];
        int unitTime = fees[2];
        int unitFee = fees[3];
        int totalPrice = basicFee; // 기본 요금
        int parkTime = iter->second;
        
        if (parkTime <= basicTime) // 기본 시간보다 낮거나 같음
            answer.push_back(totalPrice);
        else // 추가 요금
        {
            int unit = (parkTime - basicTime) / unitTime;
            if ((parkTime - basicTime) % unitTime != 0) // 올림 처리
                unit++;
            totalPrice += unitFee * unit;
            
            answer.push_back(totalPrice);
        }
    }
    return answer;
}
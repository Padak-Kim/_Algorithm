#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    
    int castingTime = bandage[0]; // 시전 시간
    int recoverySec = bandage[1]; // 초당 회복량
    int addRecovery = bandage[2]; // 추가 회복량
    int time = 0;                 // 게임 시간
    int maxHealth = health;       // 최대 체력
    
    for (auto attack : attacks)
    {
        int atkTime = attack[0];    // 공격 시간
        int damage = attack[1];     // 피해량
        
        int successTime = 0;        // 연속 성공시간
        
        cout << "atkTime : "<< atkTime << endl;
        cout << "damage : "<< damage << endl;
        while (true)
        {
            time++;
            if (time == atkTime)
            {
                health -= damage;   // 데미지 입음
                
                cout << "Time : "<< time << endl;
                cout << "Health : "<< health << endl;
                break;
            }
            
            if (maxHealth == health)
            {
                continue;
            }
            health += recoverySec; // 초당 회복
            successTime++;
            
            if (castingTime == successTime) // 시전시간 다 채웠으면
            {
                health += addRecovery;
            
                successTime = 0;
            }
            
            if (health > maxHealth)
            {
                health = maxHealth;
            }
        }  
        
        if (health <= 0)
            return -1;      
    }
    
    return health;
}
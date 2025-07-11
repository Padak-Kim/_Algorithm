#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    int i = 0;
    while(k > 0 && i < number.size())
    {
        if (answer.empty())
        {
            answer.push_back(number[i]);
        }
        else
        {
            if (answer.back() < number[i])
            {
                answer.pop_back();     
                k--;
                i--;
            }
            else
            {
                answer.push_back(number[i]);
            }
        }
        i++;     
    }
    
    while (i < number.size())
    {
        answer.push_back(number[i]);
        i++;
    }
    
    while (k > 0)
    {
        answer.pop_back();
        k--;
    }
    return answer;
}
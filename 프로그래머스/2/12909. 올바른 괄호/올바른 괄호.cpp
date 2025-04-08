#include <string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string str)
{
    stack<int> s;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ')')
        {
            if (s.empty())
            {
                return false;
            }
            
            s.pop();
        }
        
        if (str[i] == '(')
        {
            s.push(1);
        }  
    }
    
    if (s.empty())
    {
        return true;
    }
    
    return false;
}
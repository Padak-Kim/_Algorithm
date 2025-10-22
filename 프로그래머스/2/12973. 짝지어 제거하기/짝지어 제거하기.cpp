#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string str)
{
    stack<char> s;
    for(int i = 0; i < str.size(); i++)
    {
        char c = str[i];
        if (s.empty() || s.top() != c)
            s.push(c);
        else
            s.pop();
    }
    
    if (!s.empty())
    {
        while(!s.empty())
        {
            char c = s.top(); s.pop();
            
            if (c != s.top())
                return 0; 
        }
        
        return 0;
    }
    else
        return 1;

}
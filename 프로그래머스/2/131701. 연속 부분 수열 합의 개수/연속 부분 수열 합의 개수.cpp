#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    set<int> s;
    int n = elements.size();
    for(int len = 1; len <= n; len++)
    {
        if (len == 1){
            for (int i = 0; i < n; i++)
                s.insert(elements[i]);
            continue;
        }  
        int l = 0;
        
        while (l < n)
        {
            int sum = 0;
            for (int r = l; r < len + l; r++)
            {
                sum += elements[r % n];
            } 
            s.insert(sum);
            l++;
        }
    }
    answer = s.size();
    return answer;
}
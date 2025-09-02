#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    
    set<string> s;
    
    for (auto& phone : phone_book)
    {
        s.insert(phone);
    }
    
    for (auto it = s.begin(); it != s.end(); ++it)
    {
        auto it1 = s.upper_bound(*it);
        auto it2 = s.lower_bound(*it + "\x7f");
        
        if (it1 != it2)
            return false;
        else
            continue;
    }
    return true;
}
#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(int N, int number) {
    if (N == number)    return 1;
    
    vector<set<int>> cache(9);
    
    // 5, 55, 555, 5555, ...
    for(int i = 1; i <= 8; i++)
    {
        int num = 0;
        for (int j = 0; j < i; j++)
        {
            num = num * 10 + N;
        }
        cache[i].insert(num);
        
        for (int j = 1; j < i; j++)
        {
            for (int a : cache[j])
            {
                for (int b : cache[i - j])
                {
                    cache[i].insert(a + b);
                    cache[i].insert(a - b);
                    cache[i].insert(a * b);
                    if (b != 0)
                        cache[i].insert(a / b);
                }
            }
        }
        if (cache[i].count(number)) return i;
    }
    
    return -1;
}
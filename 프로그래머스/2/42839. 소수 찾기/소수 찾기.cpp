#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool isPrime(int n)
{
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0) return false;
    return true;
}

int solution(string numbers) {
    int answer = 0;
    set<int> nums;
    
    sort(numbers.begin(), numbers.end());
    
    do {
        string tmp = "";
        for(int i = 0; i < numbers.size(); i++)
        {
            tmp += numbers[i];
            int n = stoi(tmp);
            if (isPrime(n))
                nums.insert(n);
        }
    } while (next_permutation(numbers.begin(), numbers.end()));
    
    answer = nums.size();
    return answer;
}
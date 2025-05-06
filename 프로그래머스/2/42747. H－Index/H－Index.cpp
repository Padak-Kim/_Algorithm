#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end(), greater<>());
    
    int h = 0;
    for (int i = 0; i < citations.size(); ++i) {
        if (citations[i] >= i + 1) h++;
        else break;
    }
    
    answer = h;
    return answer;
}
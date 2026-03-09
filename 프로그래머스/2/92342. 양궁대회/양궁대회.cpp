#include <string>
#include <vector>

using namespace std;

int bestResult = -1;
vector<int> best(11, 0);

// 가장 낮은 점수를 더 많이 맞힌 경우인지 확인
bool compare(const vector<int>& a, const vector<int>& b)
{
    for (int i = 10; i >= 0; i--)
    {
        if (a[i] != b[i]) return a[i] > b[i];
    }
    return false;
}
void DFS(int idx, int remain, vector<int>& peach, vector<int>& lion)
{
    if (idx >= 11)
    {
        if (remain > 0) 
            lion[10] += remain;
        
        int result = 0;
        
        int lionScore = 0;
        int peachScore = 0;
        
        for (int i = 0; i < 11; i++)
        {
            int score = 10 - i;
            
            if (lion[i] == 0 && peach[i] == 0)
                continue;
            
            if (lion[i] > peach[i]) 
                lionScore += score;
            else 
                peachScore += score;
        }
        
        if (lionScore <= peachScore)
            result = -1;
        else
            result = lionScore - peachScore;
        
        if (result > bestResult)
        {
            bestResult = result;
            best = lion;
        }
        else if (result == bestResult && result != -1)
        {
            if(compare(lion, best)) 
                best = lion;
        }
        
        if (remain > 0) lion[10] -= remain;
        return;
    }
    
    int num = peach[idx] + 1;
    if (remain >= num)
    {
        lion[idx] = num;
        DFS(idx + 1, remain - num, peach, lion);
        lion[idx] = 0;
    }
    
    DFS(idx + 1, remain, peach, lion);
}
vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    vector<int> lion(11, 0);
    
    DFS(0, n, info, lion);
    
    if (bestResult == -1) return {-1};
    return best;
}
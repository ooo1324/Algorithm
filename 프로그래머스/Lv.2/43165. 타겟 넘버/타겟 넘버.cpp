#include <string>
#include <vector>
using namespace std;

int answer = 0;
int targetNum =0;
void dfs(vector<int> vec, int i, int num, int sum)
{   
    sum += vec[i] * num;
    
    if(vec.size() - 1 == i++)
    {
        if(sum == targetNum)
            answer++;   
        return;
    }
    
    dfs(vec, i, -1, sum);
    dfs(vec, i, 1, sum);
}

int solution(vector<int> numbers, int target) {
    
    targetNum = target;
    
    dfs(numbers, 0, -1, 0);
    dfs(numbers, 0, 1, 0);
    
    return answer;
}
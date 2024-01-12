#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> score(3);
    vector<int> vec1 = {1,2,3,4,5};
    vector<int> vec2 = {2,1,2,3,2,4,2,5};
    vector<int> vec3 = {3,3,1,1,2,2,4,4,5,5};
    
    for(int i =0; i< answers.size(); i++)
    {
        if(answers[i] == vec1[i%vec1.size()]) score[0]++;
        if(answers[i] == vec2[i%vec2.size()]) score[1]++;
        if(answers[i] == vec3[i%vec3.size()]) score[2]++;
    }
    
    int maxVal = max(max(score[0], score[1]),score[2]);
    
    for(int i =0;i<score.size(); i++)
    {
        if(maxVal == score[i])
            answer.push_back(i+1);        
    }
    return answer;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int n = 0, count = 0, num = 0;
    cin >> n;
    string str="666";
    
    while(true)
    {
      if(count == n) break;
     
      num++;
  
      if(to_string(num).find(str) != std::string::npos)
        count++;      
    }
    
    cout << num;
    
    return 0;
}
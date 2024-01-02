#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;

    cin >> str;

    string numStr = "";
    char mode = 'n';
    int curNum = 0;
    int sum = 0;

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] != '+' && str[i] != '-')
        {
            numStr += str[i];
        }
        else
        {
            curNum = stoi(numStr);
            numStr = "";

            if (mode == 'n')
            {
                mode = str[i];
                sum = curNum;
                continue;
            }

            if (mode == '-')
                sum -= curNum;
            else if (mode == '+')
                sum += curNum;

            if (mode != '-')
                mode = str[i];
        }
    }

    if (mode == '-')
        sum -= stoi(numStr);
    else
        sum += stoi(numStr);
  
    cout << sum;

    return 0;
}
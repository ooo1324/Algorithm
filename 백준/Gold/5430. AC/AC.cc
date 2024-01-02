#include <iostream>
#include <algorithm>
#include <deque>
#include <string>
using namespace std;
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;

	int i = 0;
	while(true)
	{
		if (t <= i)
			break;

		int n;
		string p, str;
		bool check = true; 
		cin >> p >> n >> str;

		deque<int> dq;
		int start = 1;
		bool reverse = false;
		for (int j = 0; j < str.size(); j++)
		{
			if (str[j] == ',' || str[j] == ']')
			{
				if (str.size() > 2)
				{
					dq.push_back(stoi(str.substr(start, j - start)));
					start = j + 1;
				}
			}
		}

		for (int j = 0; j < p.size(); j++)
		{
			if (check)
			{
				if (p[j] == 'R')
				{
					reverse = !reverse;
				}
				else if (p[j] == 'D')
				{
					if (dq.empty())
						check = false;
					else
					{
						if (reverse)
							dq.pop_back();
						else
							dq.pop_front();
					}	
				}
			}
		}

		if (check)
		{
			cout << '[';
			int start = 0, end = 0, value = 0;
			if (reverse)
			{
				start = dq.size() - 1;
				end = -1;
				value = -1;		
			}
			else
			{
				start = 0;
				end = dq.size();
				value = 1;
			}

			while (true)
			{
				if (start == end)
					break;

				cout << dq[start];
				if (start + value != end )
					cout << ",";

				start += value;
			}
			cout << "]\n";
		}
		else
			cout << "error" << '\n';

		i++;
	}

	return 0;
}
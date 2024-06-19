#include <iostream>
using namespace std;
#define MAX 201
int mazeArr[MAX][MAX];
string str;
int n, k;
int moveValue = 0;
void moveMaze(int i, int j)
{
	int node_x = i;
	int node_y = j;

	for(int v = 0; v < k; v++)
	{
		int tmp_x = node_x;
		int tmp_y = node_y;
		 char ch = str[v];
			if(ch == 'U')
				node_x -= 1;
			else if(ch == 'L')
				node_y -= 1;
			else if(ch == 'R')
				node_y += 1;
			else if(ch == 'D')
				node_x += 1;
		
			if(node_x < 0 || node_x >= n || node_y < 0 || node_y >= n)
			{
					node_x = tmp_x;
	 				node_y = tmp_y;
					continue;
			}
	

			if(mazeArr[node_x][node_y] == 2)
			{
					moveValue++;
					cout << "SUCCESS " << moveValue;
					return;
			}
		
			if(mazeArr[node_x][node_y] != 3)
			{
					moveValue++;
			}
			else
			{
				 	node_x = tmp_x;
	 				node_y = tmp_y;
			}
	}
	
	cout<< "FAIL";
	return;
}
int main() {
	char input[100];

  cin.tie(NULL);
  ios::sync_with_stdio(false);

	cin >> n >> k >> str;
	
	pair<int, int> startNode;
	pair<int, int> endNode;
	int a;
	
	for(int i = 0; i < n; i++)
	{
			for(int j = 0; j < n; j++)
			{
					cin >> a;
					if(a == 1)
						startNode = {i, j};
					else if(a == 2)
						endNode = {i, j};
					mazeArr[i][j] = a;
			}
	}
	
	moveMaze(startNode.first, startNode.second);
	
	return 0;
}
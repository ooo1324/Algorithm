#include <iostream>
#include <vector>
using namespace std;
int value = 0;
int n, k;
int move_x[4] = {0, 0, 1, -1};
int move_y[4] = {-1, 1, 0, 0};
void boom(int i, int j)
{
	value++;
	for(int v =0; v < 4; v++)
	{
		 int x = i + move_x[v];
		 int y = j + move_y[v];
		
		 if(x < 0 || x >= n || y <0 || y >= n)
			 continue;
		
		value++;
	}
	
}
int main() {
	
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n >> k;
	int x,y;
	for(int i =0; i < k ; i++)
	{
		  cin >> x >> y;
			boom(x-1, y-1); 
	}

	cout << value;
	return 0;
}
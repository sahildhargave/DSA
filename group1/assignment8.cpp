#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int V;
	cout << "Enter no of vertex" << endl;
	cin >> V;
	int G[V][V];
	cout << "Enter value of adj matrix" << endl;
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			cin >> G[i][j];
		}
	}

	int edge;
	int visit[V];

	for (int i = 0; i < V; i++)
	{
		visit[i] = false;
	}
	edge = 0;
	visit[0] = true;

	int x;
	int y;

	while (edge < V - 1)
	{

		int min = INT_MAX;
		x = 0;
		y = 0;

		for (int i = 0; i < V; i++)
		{
			if (visit[i])
			{
				for (int j = 0; j < V; j++)
				{
					if (!visit[j] && G[i][j])
					{
						if (min > G[i][j])
						{
							min = G[i][j];
							x = i;
							y = j;
						}
					}
				}
			}
		}
		cout << x << " ---> " << y << " :  " << G[x][y];
		cout << endl;
		visit[y] = true;
		edge++;
	}

	return 0;
}

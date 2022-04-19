#include <iostream>
using namespace std;

int cost[100][100], n, src;

int mindistnode(int mindist[], bool visited[]) {

	int node = 0;
	int min = INT_MAX;

	for (int i = 0; i < n; i++) {
		if (!visited[i] && mindist[i] < min) {
			min = mindist[i];
			node = i;
		}

	}
	return node;
}


void display(int mindist[], int par[]){
	cout << "Node:\t\t\tCost:\t\t\tPath:";

	for (int i = 0; i < n; i++) {

		cout << i << "\t\t\t" << mindist[i] << "\t\t\t" << " ";
		cout << i << " ";
		int parnode = par[i];

		while (parnode != -1) {
			cout << " <- " << parnode << " ";
			parnode = par[parnode];
		}

		cout << endl;
	}

}

void dijkstra(int src) {

	int mindist[100], par[100];
	bool visited[100] = { 0 };

	fill(mindist, mindist + n, INT_MAX);

	mindist[src] = 0;
	par[src] = -1;

	for (int i = 0; i < n; i++) {

		int u = mindistnode(mindist, visited);

		visited[u] = true;

		for (int v = 0; v < n; v++) {
			if (!visited[v] && cost[u][v] != 999 &&
				(mindist[u] + cost[u][v]) < mindist[v])
			{
				par[v] = u;
				mindist[v] = mindist[u] + cost[u][v];
			}
		}
	}

	display(mindist, par);
}


int main() {

	cout << "Enter number of vertex, n: ";
	cin >> n;

	cout << "Enter cost matrix: \n";

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> cost[i][j];
		}
	}

	cout << "Enter source node: ";
	cin >> src;
	dijkstra(src);


}
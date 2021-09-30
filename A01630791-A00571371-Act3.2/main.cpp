#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>
using namespace std;


void dijkstra(vector<vector<int>>& g) {
  int n = g.size();
  // inicializar arreglo de visitados y de distancias
  int d[n];
  bool s[n];
  for (int i = 0; i < n; i++) {
    s[i] = false;
    d[i] = INT_MAX;
  }

  priority_queue<int, vector<int>, greater<int>> q;


}

void relax(int u, int v, int w, int* d) {
  if (d[v] > d[u] + w) {
    d[v] = d[u] + w;
  }
}

int main() {
  int n;
  cin >> n;

  vector<vector<int>> g(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> g[i][j];
    }
  }

  return 0;
}

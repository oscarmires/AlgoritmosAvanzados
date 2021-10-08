/**
 * Actividad 3.2
 *
 * Oscar Miranda Escalante
 * A01630791
 * Jose Rodrigo Saucedo Cruz
 * A00571371
 *
 * Pruebas
 * test1: prueba de canvas
 * test2: lista doblemente enlazada
 * test3: círculo
 * test4: grafo grande
 */

#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>
using namespace std;

struct Vertex {
  int d;
  int id;
  bool visited;
  Vertex(int node) {
    this->d = INT_MAX;
    this->id = node;
    this->visited = false;
  }
  Vertex(int node, int distance) {
    this->d = distance;
    this->id = node;

  }
  Vertex() {
    this->visited = false;
  }
  bool operator>(const Vertex& v) const {
    return this->d > v.d;
  }
};


/**
 * Dijkstra
 *
 * Complejidad: O(n + n^2) Esto por la inicializacion de la distancia y la impresion de los valores, mas la complejidad de dijkstra que es O(n^2)
 * */
void dijkstra(vector<vector<int>>& g, int start) {
  int n = g.size();
  vector<Vertex> nodes(n);
  for (int i = 0; i < n; i++) {
    nodes[i].d = INT_MAX;
  }
  priority_queue<Vertex, vector<Vertex>, greater<Vertex>> q;

  nodes[start].d = 0;
  nodes[start].id = start;
  q.push(nodes[start]);

  while (!q.empty()) {
    Vertex tmp = q.top();
    nodes[tmp.id].visited = true;
    for (int i = 0; i < n; i++) {
      if (!nodes[i].visited && g[tmp.id][i] > 0) {
        q.push(Vertex(i, tmp.d + g[tmp.id][i]));

        // relax
        if (nodes[i].d > tmp.d + g[tmp.id][i]) {
          nodes[i].d = tmp.d + g[tmp.id][i];
        }

      }
    }
    q.pop();
  }

  for (int i = 0; i < n; i++) {
    if (i != start)
      cout << "node " << start + 1 << " to node " << i + 1 << " : " << nodes[i].d << endl;
  }
}

int update(int a, int b1, int b2) {
  if (b1 == -1) {
    return a;
  } else if (b2 == -1) {
    return a;
  } else if (a == -1) {
    return b1 + b2;
  } else {
    return a < b1 + b2 ? a : b1 + b2;
  }
}


/**
 * Dijkstra
 *
 * Complejidad: O(n^3 + n^2) Esto por la complejidad de de Floyd que es O(n^3), mas la complejidad de la impresion de la matriz que es O(n^2)
 * */
void floyd(vector<vector<int>> g) {
  int n = g[0].size();
  vector<vector<int>> d = g;

  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        d[i][j] = update(d[i][j], d[i][k], d[k][j]);
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << d[i][j] << ' ';
    }
    cout << endl;
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
  cout << "Dijkstra : " << endl;
  for (int i = 0; i < n; i++) {
    dijkstra(g, i);
    cout << endl;
  }

  cout << "Floyd :" << endl;
  floyd(g);
  return 0;
}


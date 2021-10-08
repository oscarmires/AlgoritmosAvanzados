/**
 * Actividad 3.3
 *
 * Oscar Miranda Escalante
 * A01630791
 * Jose Rodrigo Saucedo Cruz
 * A00571371
 *
 * Pruebas
 * test1: ejemplo de Canvas
 * test2: ejemplo de presentación
 * test3: caso extremo
 * test4: descendente y ascendente
 */

#include <iostream>
#include <vector>
using namespace std;

struct item {
  int w, v;
  item() {
    this->w = 0;
    this->v = 0;
  }
};

/**
 * Algoritmo 0-1 Knapsack con programación dinámica
 *
 * Complejidad: O(n*W)
 *    Donde n = número de elementos y W = peso límite
 *
 * */
int knapsackDP(vector<item> items, int W) {

  int n = items.size();

  vector<vector<int>> T(n, vector<int>(W + 1));
  int wi, bi;
  for (int i = 0; i < W + 1; i++) {
    T[0][i] = 0;
  }
  for (int i = 0; i < n; i++) {
    T[i][0] = 0;
    if (i > 0) {
      for (int j = 1; j < W + 1; j++) {
        wi = items[i].w;
        bi = items[i].v;
        if (wi <= j) {
          if ((bi + T[i - 1][j - wi]) > T[i - 1][j]) {
            T[i][j] = bi + T[i - 1][j - wi];
          } else {
            T[i][j] = T[i - 1][j];
          }
        } else {
          T[i][j] = T[i - 1][j];
        }
      }

    }
  }

  return T[n - 1][W];
}

int main() {

  int n, w, v;
  cin >> n;
  vector<item> items(n + 1);
  items[0].w = 0;
  items[0].v = 0;
  for (int i = 1; i <= n; i++) {
    cin >> v;
    items[i].v = v;
  }
  for (int i = 1; i <= n; i++) {
    cin >> w;
    items[i].w = w;
  }
  cin >> w;

  cout << knapsackDP(items, w) << endl;

  return 0;
}

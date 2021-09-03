/**
 * Actividad 1.2
 *
 * Oscar Miranda Escalante
 * A01630791
 * Jose Rodrigo Saucedo Cruz
 * A00571371
 *
 * Pruebas
 * test1: prueba cuando el precio es 0
 * test2: prueba con caso promedio
 * test3: prueba con muchas
 * test4: prueba con resultado diferente para cada algoritmo
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// n -> número de denominaciones
// p -> precio de producto
// q -> billete/moneda con que se paga
// arr -> denominaciones

void printVerticalArr(int arr[], int start, int end) {
  for (int i = start; i < end; i++) {
    cout << arr[i] << endl;
  }
}


/**
 * greedyAlgorithm
 *
 * complejidad computacional: O(n) para todos los casos
 */
int* greedyAlgorithm(int n, int arr[], int p, int q) {
  int* change = new int[n];
  int remainder = q - p;

  for (int i = 0; i < n; i++) {
    change[i] = remainder / arr[i];
    remainder = remainder % arr[i];
  }

  return change;
}

/**
 * dynamicProgramming
 *
 * complejidad computacional:
 *    O(n*(m^2)) donde n es el cambio y m es el numero de monedas para el peor y caso promedio
 *    O(n*m) es el mejor caso, cuando la mejor solución se encontró en un inicio
 *
 */

void dynamicProgramming(int n, int arr[], int p, int q) {
  int suma = 0;
  int nuevaSolucion = 0;
  int change = q - p;
  if (change == 0) {
    for (int i = 0; i < n; i++) {
      cout << 0 << endl;
    }
    return;
  }

  vector<vector<int>> values(n + 1, vector<int>(change + 1, 0));
  // primer valor son filas, segundos valor son columnas
  for (int i = 0; i < change + 1; i++) {
    values[0][i] = change + 1;
  }

  values[0][0] = 0;

  for (int i = 1; i <= change; i++) {
    for (int j = 0; j < n; j++) {
      if (arr[j] <= i) {
        nuevaSolucion = values[0][i - arr[j]] + 1; //monedas para arr[j]
        if (nuevaSolucion < values[0][i]) {
          values[0][i] = nuevaSolucion;
          if (nuevaSolucion == 0) {
            values[j + 1][i]++;
          }
          else {
            for (int k = 1; k < n + 1; k++) {
              values[k][i] = values[k][i - arr[j]];
            }
            values[j + 1][i]++;
          }
        }
      }
    }
  }
  if (values[0][change] > change) {
    cout << "Error, no se pudo computar correctamente, revise entrada que sea valida" << endl;
    return;
  }
  for (int i = 1; i < n + 1; i++) {
    cout << values[i][change] << endl;
    suma += (values[i][change] * arr[i - 1]);
  }
  if ((suma - change) > 0) {
    cout << "Le puedo deber " << suma - change << "pesos?" << endl;
  }
}



int main() {
  int n, p, q;
  cin >> n;

  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  sort(arr, arr + n, greater<int>());

  cin >> p;
  cin >> q;

  cout << "Avaro: " << endl;
  printVerticalArr(greedyAlgorithm(n, arr, p, q), 0, n);
  cout << "Dynamic programming: " << endl;
  dynamicProgramming(n, arr, p, q);

  return 0;
}

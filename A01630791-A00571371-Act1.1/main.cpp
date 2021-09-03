/**
 * Actividad 1.1
 *
 * Oscar Miranda Escalante
 * A01630791
 * Jose Rodrigo Saucedo Cruz
 * A00571371
 *
 */

#include <iostream>
using namespace std;

void printArr(double arr[], int start, int end) {
  for (int i = start; i < end; i++) {
    cout << arr[i] << ' ';
  }
  cout << endl;
}


/**
 * merge
 *
 * complejidad comptacional: O(n)
 */
void merge(double* arr, int start, int half, int end) {
  int i = start,
    j = half;

  double sortedArr[end - start];

  int k = 0;
  while (i < half && j < end) {
    if (arr[i] < arr[j]) {
      sortedArr[k] = arr[i];
      i++;
    }
    else {
      sortedArr[k] = arr[j];
      j++;
    }
    k++;
  }

  while (i < half) {
    sortedArr[k] = arr[i];
    i++;
    k++;
  }

  while (j < end) {
    sortedArr[k] = arr[j];
    j++;
    k++;
  }

  for (int i = start; i < end; i++) {
    arr[i] = sortedArr[i - start];
  }
}


/**
 * mergeSort
 *
 * Compeljidad computacional: O(n*log(n))
 */
void mergeSort(double arr[], int start, int end) {

  if (start < end - 1) {
    int half = (start + end) / 2;
    mergeSort(arr, start, half);
    mergeSort(arr, half, end);
    merge(arr, start, half, end);
  }
}

int main() {
  int n = 0;
  cin >> n;

  double arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  mergeSort(arr, 0, n);
  printArr(arr, 0, n);

  return 0;
}


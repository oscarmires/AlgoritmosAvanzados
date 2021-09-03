/**
 * Actividad 1.3
 *
 * Oscar Miranda Escalante
 * A01630791
 * Jose Rodrigo Saucedo Cruz
 * A00571371
 *
 * Pruebas
 * test1: ejemplo de canvas
 * test2: matriz 1x1
 * test3: matriz con 2 soluciones
 * test4: matriz 2 puntos muertos
 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Point {
  int i;
  int j;
  Point() {
    this->i = 0;
    this->j = 0;
  };
  Point(int i, int j) {
    this->i = i;
    this->j = j;
  }
  Point right() {
    return Point(this->i, this->j + 1);
  }
  Point down() {
    return Point(this->i + 1, this->j);
  }
  Point left() {
    return Point(this->i, this->j - 1);
  }
  Point up() {
    return Point(this->i - 1, this->j);
  }
};

class Maze {
private:
  int m;
  int n;
  vector<vector<int>> maze;
  vector<vector<int>> result;
  vector<vector<bool>> visited;

  bool isPointValid(Point p) {
    return
      p.i >= 0
      && p.i < this->m
      && p.j >= 0
      && p.j < this->n
      && this->maze[p.i][p.j] == 1;
  }

  bool isVisited(Point p) {
    return this->visited[p.i][p.j];
  }

  /**
   * backtracking
   * Complejidad:
   *  O(k) matriz 1x1
   *  O(m * n) promedio
   */
  bool backtracking(Point currentPos) {
    if (currentPos.i == m - 1 && currentPos.j == n - 1) {
      return true;
    }
    Point nextPoint = currentPos.right();
    if (isPointValid(nextPoint) && !isVisited(nextPoint)) {
      this->visited[nextPoint.i][nextPoint.j] = 1;
      if (backtracking(nextPoint)) {
        this->result[nextPoint.i][nextPoint.j] = 1;
        return true;
      }
    }
    nextPoint = currentPos.down();
    if (isPointValid(nextPoint) && !isVisited(nextPoint)) {
      this->visited[nextPoint.i][nextPoint.j] = 1;
      if (backtracking(nextPoint)) {
        this->result[nextPoint.i][nextPoint.j] = 1;
        return true;
      }
    }
    nextPoint = currentPos.left();
    if (isPointValid(nextPoint) && !isVisited(nextPoint)) {
      this->visited[nextPoint.i][nextPoint.j] = 1;
      if (backtracking(nextPoint)) {
        this->result[nextPoint.i][nextPoint.j] = 1;
        return true;
      }
    }
    nextPoint = currentPos.up();
    if (isPointValid(nextPoint) && !isVisited(nextPoint)) {
      this->visited[nextPoint.i][nextPoint.j] = 1;
      if (backtracking(nextPoint)) {
        this->result[nextPoint.i][nextPoint.j] = 1;
        return true;
      }
    }
    return false;
  }

public:
  /*
    Maze() {
      this->m = 4;
      this->n = 4;
      this->result = vector<vector<int>>(m, vector<int>(n, 0));
      this->result[0][0] = 1;
      this->result[m - 1][n - 1] = 1;
      this->visited = vector<vector<bool>>(m, vector<bool>(n, 0));
      this->path.push(Point(0, 0));

      this->maze = { {1, 0, 0, 0},
                     {1, 1, 0, 1},
                     {0, 1, 0, 0},
                     {1, 1, 1, 1} };
    }
  */
  Maze(int m, int n) {
    this->m = m;
    this->n = n;
    this->result = vector<vector<int>>(m, vector<int>(n, 0));
    this->result[0][0] = 1;
    this->result[m - 1][n - 1] = 1;
    this->visited = vector<vector<bool>>(m, vector<bool>(n, 0));
  }


  void readInput() {
    int val;
    for (int i = 0; i < m; i++) {
      vector<int> line;
      for (int j = 0; j < n; j++) {
        cin >> val;
        line.push_back(val);
      }
      this->maze.push_back(line);
    }
  }

  void print() {
    for (auto line : this->maze) {
      for (auto i : line) {
        cout << i << " ";
      }
      cout << endl;
    }
  }

  void printSolution() {
    for (auto line : this->result) {
      for (auto i : line) {
        cout << i << " ";
      }
      cout << endl;
    }
  }

  void backtracking() {
    this->backtracking(Point(0, 0));
  }

  void branchAndBound() {

  }
};


int main() {
  int m, n;

  cin >> m;
  if (m <= 0) {
    cout << "Entrada no valida" << endl;
    return 1;
  }
  cin >> n;
  if (n <= 0) {
    cout << "Entrada no valida" << endl;
    return 1;
  }

  Maze laberinto(m, n);
  laberinto.readInput();
  laberinto.backtracking();
  laberinto.printSolution();

  return 0;
}

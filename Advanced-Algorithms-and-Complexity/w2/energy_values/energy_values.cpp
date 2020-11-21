#include <cmath>
#include <iostream>
#include <vector>

const double EPS = 1e-6;
const int PRECISION = 20;
int prow = -1, pcol = -1;

typedef std::vector<double> Column;
typedef std::vector<double> Row;
typedef std::vector<Row> Matrix;

#define debug(x) std::cout << '>' << #x << ':' << x << std::endl;
struct Equation {
    Equation(const Matrix &a, const Column &b):
        a(a),
        b(b)
    {}

    Matrix a;
    Column b;
};

struct Position {
    Position(int column, int row):
        column(column),
        row(row)
    {}

    int column;
    int row;
};

Equation ReadEquation() {
    int size;
    std::cin >> size;
    Matrix a(size, std::vector <double> (size, 0.0));
    Column b(size, 0.0);
    for (int row = 0; row < size; ++row) {
        for (int column = 0; column < size; ++column)
            std::cin >> a[row][column];
        std::cin >> b[row];
    }
    return Equation(a, b);
}

Position SelectPivotElement(
  const Matrix &a,
  std::vector <bool> &used_rows,
  std::vector <bool> &used_columns) {
    int size = a.size();
    // This algorithm selects the first free element.
    // You'll need to improve it to pass the problem.
     Position pivot_element(0, 0);
    // while (used_rows[pivot_element.row])
    //     ++pivot_element.row;
    // while (used_columns[pivot_element.column])
    //     ++pivot_element.column;
    // return pivot_element;
    int y;
      for(y = prow+1;y<size;y++){
        if(a[y][pcol+1]){
          pivot_element.row = y;
          pivot_element.column = pcol+1;
        }
      }

      prow++;
      pcol++;

      return pivot_element;

}

void SwapLines(Matrix &a, Column &b, std::vector <bool> &used_rows, Position &pivot_element) {
    std::swap(a[pivot_element.column], a[pivot_element.row]);
    std::swap(b[pivot_element.column], b[pivot_element.row]);
    std::swap(used_rows[pivot_element.column], used_rows[pivot_element.row]);
    pivot_element.row = pivot_element.column;
}

void ProcessPivotElement(Matrix &a, Column &b, const Position &pivot_element) {
      int size = a.size();
      // debug(size);
      // debug(a[pivot_element.row][pivot_element.column]);
      double pvt = a[pivot_element.row][pivot_element.column];
      for(int i = 0;i<size;i++){
    //    debug(a[pivot_element.row][i]);
        a[pivot_element.row][i] = a[pivot_element.row][i] / pvt;
      }
      b[pivot_element.row] /= pvt;
    //  debug(b[pivot_element.row]);

      for(int i = 0;i<size;i++){
        if(i==pivot_element.row){
          continue;
        }

        if(a[i][pivot_element.column]){
          double factr = a[i][pivot_element.column];
          for(int j = 0;j<size;j++){
            a[i][j] = a[i][j] - factr * a[pivot_element.row][j];
          }

          b[i] = b[i] - factr * b[pivot_element.row];
        }
      }

}

void MarkPivotElementUsed(const Position &pivot_element, std::vector <bool> &used_rows, std::vector <bool> &used_columns) {
    used_rows[pivot_element.row] = true;
    used_columns[pivot_element.column] = true;
}

Column SolveEquation(Equation equation) {
    Matrix &a = equation.a;
    Column &b = equation.b;
    int size = a.size();

    std::vector <bool> used_columns(size, false);
    std::vector <bool> used_rows(size, false);
    for (int step = 0; step < size; ++step) {
        Position pivot_element = SelectPivotElement(a, used_rows, used_columns);
        SwapLines(a, b, used_rows, pivot_element);
        ProcessPivotElement(a, b, pivot_element);
        MarkPivotElementUsed(pivot_element, used_rows, used_columns);
    }

    return b;
}

void PrintColumn(const Column &column) {
    int size = column.size();
    std::cout.precision(PRECISION);
    for (int row = 0; row < size; ++row)
        std::cout << column[row] << std::endl;
}

int main() {
    Equation equation = ReadEquation();
    Column solution = SolveEquation(equation);
    PrintColumn(solution);
    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> creer_triangle_numerote(int N) {
  vector<vector<int>>myvektor(N);
  int c  =1;
  for(int i = 0; i<myvektor.size(); ++i) {
    myvektor[i].resize(i);
    for(int j = 0; j<i ; ++j) {
      myvektor[i][j] =c++;
    }
  }
  return myvektor;
}

void print_2d_vector(const vector<vector<int>>& v) {
  for (const auto& ligne : v) {
    cout << "[";
    for (size_t i = 0; i < ligne.size(); ++i) {
      cout << ligne[i] << (i == ligne.size() - 1 ? "" : ", ");
    }
    cout << "]" << endl;
  }
}

int main() {
  auto triangle = creer_triangle_numerote(5);
  print_2d_vector(triangle);
}
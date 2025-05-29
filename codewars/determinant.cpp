#include<iostream>
#include<vector>

using namespace std;

long long determinant(vector<vector<long long>> m){
  if (m.size() == 1) return m[0][0];
  if (m.size() == 2) return m[0][0] * m[1][1] - m[0][1] * m[1][0];
  long long det = 0;

  for (int i = 0; i < m.size(); i++){
    vector<vector<long long>> submatrix;
    for (int j = 1; j < m.size(); j++){
      vector<long long> row;
      for (int k = 0; k < m.size(); k++){
        if (k != i) row.push_back(m[j][k]);
      }
      submatrix.push_back(row);
    }
    det += (i % 2 == 0 ? 1 : -1) * m[0][i] * determinant(submatrix);
  }
  return det;
}

int main (){
  int n;
  cin >> n;
  vector<vector<long long>> m(n, vector<long long>(n));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      cin >> m[i][j];
    }
  }
  cout << determinant(m) << endl;
}

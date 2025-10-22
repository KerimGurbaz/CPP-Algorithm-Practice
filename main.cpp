#include <iostream>
#include <vector>
using namespace std;

// TODO: int somme_voisins(const vector<vector<int>>& m, int r, int c);
int somme_voisins(const vector<vector<int>>& m, int r, int c) {
    if(m.empty() || m[0].empty()) {
        return 0;
    }
    int num_rows = m.size();
    int num_cols = m[0].size();
    int sum = 0;

    for(int dr =-1; dr<=1; ++dr) {
        for(int dc = -1; dc<=1; ++dc) {
            if(dr == 0 && dc ==0) {
                continue;
            }
            int nr = r + dr;
            int nc = c + dc;

            bool isvalidRow = nr>=0 && nr<num_rows;
            bool isvalidCol= nc>=0 && nc<num_cols;

            if(isvalidCol && isvalidRow) {
                sum += m[nr][nc];
            }
        }
    }

    return sum;
}


int main() {
    vector<vector<int>> m{
            {1,2,3,4},
            {5,6,7,8},
            {9,1,2,3}
    };
    cout << somme_voisins(m, 1, 2) << '\n'; // beklenen değer söylemiyorum :)
}

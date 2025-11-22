#include <iostream>
#include <array>
#include <vector>
#include <sstream>
using namespace std;

/*
* void display(const vector<int> &v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i];
        if (i < v.size() - 1) {
            cout << ", ";
        }
    }
}

void rotateRight(vector<int> &v) {
    vector<int>temp(v.size());

    for (int i = 0; i < v.size(); ++i) {
       temp[(i-1 +v.size())% v.size()] = v[i];
    }
    v = temp;
}

int main() {
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};

    rotateRight(v);
    display(v);
}
void supprimer_centre(vector<int>& v) {
    int m = v.size()/2;
    if(v.size()<3) {
        v.erase(v.begin(), v.end());
    }else if(v.size()%2) {
        v.erase(v.begin()+m, v.begin()+m+1);
    }else {
        v.erase(v.begin()+m-1,v.begin()+m+1 );
    }
}
int main() {
    for (vector<int> v: {vector<int>{},
                         {1},
                         {1, 2},
                         {1, 2, 3},
                         {1, 2, 3, 4},
                         {1, 2, 3, 4, 5},
                         {1, 2, 3, 4, 5, 6}}) {
        cout << to_string(v) << " -> ";
        supprimer_centre(v);
        cout << to_string(v) << endl;
                         }
}

void supprimer_valeur(vector<int>& v , const int& n) {
    int slow = 0;
    for(size_t fast = 0; fast<v.size(); ++fast) {
        if(v[fast] != n) {
            v[slow]= v[fast];
            ++slow;
        }
    }
    while(v.size() > slow) {
        v.pop_back();
    }

}

int main() {
    for (vector<int> v: {vector<int>{},
                         {2},
                         {1, 2, 2, 2, 3, 1, 2, 4},
                         {2, 3, 4, 3, 2, 1},
                         {2, 2, 2},
                         {5, 4, 3, 2, 1, 2}}) {
        cout << to_string(v) << " -> ";
        supprimer_valeur(v,2);
        cout << to_string(v) << endl;
                         }
}

 */

string to_string(const vector<int>& v) {
    ostringstream os;
    os<<"[";
    for(size_t i = 0; i<v.size(); ++i) {
        os<<v[i];
        if(i<v.size()-1) {
            os<<", ";
        }
    }
    os<<"]";
    return  os.str();
}

void rendre_unique(vector<int>& v) {
    int slow =0;
    for(size_t fast =1; fast<v.size(); ++fast) {
        if(v[fast] != v[slow]) {
            v[++slow]= v[fast];
        }
    }
    v.resize(slow +1);
}


int main() {
    for (vector<int> v: {vector<int>{},
                         {2},
                         {1, 2, 2, 2, 3, 1, 2, 4},
                         {2, 3, 3, 2, 2, 1},
                         {2, 2, 2},
                         {5, 4, 4, 3, 2, 2, 2, 3}}) {
        cout << to_string(v) << " -> ";
        rendre_unique(v);
        cout << to_string(v) << endl;
                         }
}
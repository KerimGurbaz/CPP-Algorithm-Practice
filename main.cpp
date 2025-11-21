/*
* #include <iostream>
#include <vector>
#include <string>
#include <cstdint>
using namespace std;

struct Personne {
    string nom;
    uint16_t annee;
};
string trouver_doyen(const vector<Personne>& p ) {
  if(!p.empty()) {
      Personne doyen = p[0];
      for(size_t i = 0; i<p.size(); ++i) {
          if(p[i].annee < doyen.annee ) {
              doyen = p[i];
          }
      }
      return doyen.nom;
  }else {
      return "inconnu";
  }
}

int main() {
    // İsim, Doğum Yılı
    vector<Personne> groupe = {
        {"Alice", 1990},
        {"Bob", 1985},
        {"Charlie", 1992},
        {"David", 1985} // Eşit yaşta, ilk geleni veya fark etmez
    };

    // Vektör boş değilse en yaşlıyı (yılı en küçük olanı) bul
    string doyen = trouver_doyen(groupe);

    cout << "Le doyen est: " << doyen << endl;
    // Beklenen: Bob (veya David, mantığına göre)

    vector<Personne> vide;
    cout << "Vide: " << trouver_doyen(vide) << endl;
    // Beklenen: Inconnu
}

#include <iostream>
#include <cmath> // abs için
using namespace std;

struct Point {
    int a = 0;
    int b = 0;
};

struct Rectangle {
    Point p1;
    Point p2;
};

int calculer_surface(const Rectangle &r) {
    int largeur = abs(r.p2.a - r.p1.a);
    int longeur = abs(r.p2.b - r.p1.b);
    return (largeur * longeur);
}

int main() {
    Rectangle r = {{0, 10}, {20, 0}};

    int area = calculer_surface(r);

    cout << "Surface: " << area << endl;
}

 */

#include <iostream>
using namespace std;

struct Coord {
   double x;
    double y;
};

const Coord& plus_proche(const Coord& p1, const Coord& p2) {
    double dist1 = (p1.x *p1.x) + (p1.y * p1.y);
    double dist2 = (p2.x *p2.x) + (p2.y * p2.y);

    if(dist1 < dist2) {
        return p1;
    }else {
        return p2;
    }
}


int main() {
    Coord p1 = {3.0, 4.0};   // Orijine uzaklık: 5 (3-4-5 üçgeni)
    Coord p2 = {10.0, 10.0}; // Orijine uzaklık: ~14.1

    // Dikkat: Fonksiyon, p1 veya p2'nin KENDİSİNİ (referansını) döndürmeli
    const Coord& proche = plus_proche(p1, p2);

    cout << "Plus proche: " << proche.x << ", " << proche.y << endl;
    // Beklenen: 3, 4
}
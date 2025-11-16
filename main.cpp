#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum class Categorie { ALIMENTATION, ELECTRONIQUE, VETEMENT };

struct Produit {
    string nom;
    Categorie cat;
    int quantite;
    double prix;
};

void ajouter_stock( vector<Produit>&stock,const string nom,const Categorie cat, const int quantite,const double prix) {
    for(auto & produit : stock) {
        if(produit.nom == nom) {
            produit.quantite += quantite;
            return;
        }
    }

    stock.push_back({nom, cat, quantite, prix});


}

// YARDIMCI
void afficher_stock(const vector<Produit>& stock) {
    for (const auto& p : stock) {
        cout << p.nom << ": " << p.quantite << endl;
    }
}

int main() {
    vector<Produit> magasin;

    // 1. Yeni ürün ekle
    ajouter_stock(magasin, "Pomme", Categorie::ALIMENTATION, 50, 0.5);

    // 2. Yeni ürün ekle
    ajouter_stock(magasin, "Laptop", Categorie::ELECTRONIQUE, 10, 999.9);

    // 3. MEVCUT ürünü güncelle (Sadece miktar artmalı, yeni satır eklenmemeli)
    ajouter_stock(magasin, "Pomme", Categorie::ALIMENTATION, 20, 0.5);

    afficher_stock(magasin);
    // Beklenen:
    // Pomme: 70
    // Laptop: 10
}
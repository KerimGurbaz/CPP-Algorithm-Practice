#include <iostream>
#include <limits>

// Bu fonksiyon yukarıda düzelttiğimiz haliyle doğru.
long long factorielle(int n) {
    if (n < 0) return 0; // Hata durumu
    if (n == 0) return 1;
    long long resultat = 1;
    for (int i = 1; i <= n; ++i) {
        resultat *= i;
    }
    return resultat;
}

// VERİMLİ OLAN YÖNTEM
int plus_petit_n_pour_factorielle_de_n_plus_grande_que(int m) {
    int n = 1;
    long long fact = 1;
    while (fact <= m) {
        n++;
        fact *= n; // Faktöriyeli sıfırdan hesaplamak yerine bir önceki adımı kullanıyoruz
    }
    return n;
}

int main() {
    const int m = 100'000'000;
    int n = plus_petit_n_pour_factorielle_de_n_plus_grande_que(m);

    // main fonksiyonu artık doğru n değerini alacağı için doğru çalışacak.
    // n = 12 olarak bulunacak.
    std::cout << n - 1 << "! = " << factorielle(n - 1) << " <= " << m
              << " < " << factorielle(n) << " = " << n << "!" << std::endl;

    return 0;
}
#include <iostream>
using namespace std;


// template<typename T>
// // T&min( T & a, T & b, T & c ) {
// //     return a<b ? ( a<c?a:c ) :b<c?b:c;
// // }
//
// T&min(T&a, T& b, T&c) {
//     T *m = &a;
//     if(b< *m)m = &b;
//     if(c< *m) m =&c;
//
//     return *m;
// }
//
// int main() {
//     // --- Test 1: Integer ---
//     int a = 5;
//     int b = 2;
//     int c = 9;
//
//     cout << "En kucuk (baslangic): " << min(a, b, c) << endl; // Çıktı: 2
//
//     min(a, b, c) = 1;
//
//     cout << "Atamadan sonra b: " << b << endl; // Çıktı: 1
//
//     // Referans tutmak
//     int& min_abc = min(a, b, c); // min_abc artık b'nin takma adıdır.
//     min_abc = 10; // b = 10 olur.
//     cout << "Referans degisimi sonrasi b: " << b << endl; // Çıktı: 10
//
//     cout << "-----------------" << endl;
//
//     // --- Test 2: Double ---
//     double d = 5.0;
//     double e = 2.0;
//     double f = 9.0;
//
//     cout << "En kucuk (double): " << min(d, e, f) << endl; // 2.0
//     min(d, e, f) = 1.0; // e = 1.0 olur.
//
//     cout << "Atamadan sonra e: " << e << endl; // 1.0
//
//     return 0;
// }
#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cout << "Hany szot fogsz megadni? ";
    cin >> n;

    if (n <= 0) return 0;

    string aktualisSzo, leghosszabb, legrovidebb;

    cout << "Add meg az 1. szot: ";
    cin >> aktualisSzo;
    leghosszabb = aktualisSzo;
    legrovidebb = aktualisSzo;

    for (int i = 1; i < n; i++) {
        cout << "Add meg a(z) " << i + 1 << ". szot: ";
        cin >> aktualisSzo;

        if (aktualisSzo.length() > leghosszabb.length()) {
            leghosszabb = aktualisSzo;
        }
        if (aktualisSzo.length() < legrovidebb.length()) {
            legrovidebb = aktualisSzo;
        }
    }

    cout << "A leghosszabb szo: " << leghosszabb << endl;
    cout << "A legrovidebb szo: " << legrovidebb << endl;

    return 0;
}
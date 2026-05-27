//1. Feladat
//Írjon függvényt, amelynek két integer paramétere van, a visszatérési értéke pedig a két szám közötti prímszámok darabszáma.

//2. Feladat
//Írjon függvényt, amelynek paramétere egy 4x4-es, egész számokat tartalmazó kétdimenziós tömb. A függvény visszatérési értéke egy 4 elemű (egydimenziós) tömb legyen, amely minden egyes oszlopnak a mediánját tárolja.

//3. Feladat
//Valósítson meg egy muvelet nevű, void visszatérési értékű függvényt, amely három paramétert vár:
    //Egy egész számot (az eredmény tárolására), amelyet referencia szerint vesz át.
    //Egy karaktert, amely a műveletet jelöli (+, -, *).
    //Egy egész számot, amely a művelet operandusa. A függvény módosítsa az első paraméterként kapott változó értékét a megadott művelettel és operandussal. (Példa: ha a változó értéke 10, a karakter *, a szám 3, akkor a változó új értéke 30 legyen).

//4. Feladat
//Kérjen be a felhasználótól a konzolról pontosan 8 darab egész számot. A beolvasást követően döntse el, hogy a megadott számok között szerepel-e fibonacci szám. Az eredményt (van/nincs ilyen szám) írja ki a képernyőre.

//5. Feladat
//Olvassa be a szamok.txt állományt, amely egy 5x5-ös mátrixot tartalmaz (egész számok).
    //Határozza meg a mellékátló elemeinek mediánját.
    //Válogassa ki azokat az elemeket a mátrixból, amelyek értéke nagyobb, mint ez a medián, és írja ki őket a nagyobbak.txt állományba.

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

//1. Feladat
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int countPrimesBetween(int a, int b) {
    int count = 0;
    int start = min(a, b);
    int end = max(a, b);
    for (int i = start + 1; i < end; i++) {
        if (isPrime(i)) count++;
    }
    return count;
}

//2. Feladat
vector<int> getColumnMedians(int matrix[4][4]) {
    vector<int> medians(4);
    for (int col = 0; col < 4; col++) {
        vector<int> current_col(4);
        for (int row = 0; row < 4; row++) {
            current_col[row] = matrix[row][col];
        }
        sort(current_col.begin(), current_col.end());
        medians[col] = (current_col[1] + current_col[2]) / 2;
    }
    return medians;
}

//3. Feladat
void muvelet(int& eredmeny, char op, int operandus) {
    if (op == '+') eredmeny += operandus;
    else if (op == '-') eredmeny -= operandus;
    else if (op == '*') eredmeny *= operandus;
}


//4. Feladat
bool isFibonacci(int n) {
    if (n < 0) return false;
    int a = 0, b = 1;
    if (n == a || n == b) return true;
    int c = a + b;
    while (c <= n) {
        if (c == n) return true;
        a = b;
        b = c;
        c = a + b;
    }
    return false;
}

int main() {
    //1. Feladat
    cout << "1. feladat (10 es 20 kozotti primek szama): " << countPrimesBetween(10, 20) << "\n\n";
    
    //2. Feladat
    int m[4][4] = {
        {1, 5, 9, 13},
        {2, 6, 10, 14},
        {3, 7, 11, 15},
        {4, 8, 12, 16}
    };
    vector<int> medians = getColumnMedians(m);
    cout << "2. feladat (oszlopok medianjai): ";
    for(int val : medians) {
        cout << val << " ";
    }
    cout << "\n\n";

    //3. Feladat
    int eredmeny = 10;
    muvelet(eredmeny, '*', 3);
    cout << "3. feladat (10 * 3 muvelet utan az eredmeny): " << eredmeny << "\n\n";

    //4. Feladat
    cout << "4. feladat:\nKerlek adj meg 8 szamot: ";
    int number;
    bool found = false;
    for (int i = 0; i < 8; i++) {
        cin >> number;
        if (isFibonacci(number)) {
            found = true;
        }
    }
    if (found) {
        cout << "van ilyen szam\n\n";
    } else {
        cout << "nincs ilyen szam\n\n";
    }

    //5. Feladat
    int matrix5[5][5];
    ifstream infile("szamok.txt");
    if (infile.is_open()) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                infile >> matrix5[i][j];
            }
        }
        infile.close();

        vector<int> sec_diag(5);
        for (int i = 0; i < 5; i++) {
            sec_diag[i] = matrix5[i][4 - i];
        }

        sort(sec_diag.begin(), sec_diag.end());
        int median = sec_diag[2];

        ofstream outfile("nagyobbak.txt");
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (matrix5[i][j] > median) {
                    outfile << matrix5[i][j] << " ";
                }
            }
        }
        outfile.close();
        cout << "5. feladat kesz (nagyobbak.txt letrehozva)\n";
    } else {
        cout << "5. feladat hiba: a szamok.txt nem talalhato.\n";
    }

    return 0;
}
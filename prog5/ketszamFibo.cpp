#include <iostream>
#include <algorithm>

using namespace std;

int legnagyobbFiboKozott(int a, int b) {
    int alsoHatar = min(a, b);
    int felsoHatar = max(a, b);
    
    int f1 = 0, f2 = 1, f_kovetkezo = 1;
    int legnagyobb = -1;

    while (f1 <= felsoHatar) {
        if (f1 >= alsoHatar) {
            legnagyobb = f1; 
        }
        
        f_kovetkezo = f1 + f2;
        f1 = f2;
        f2 = f_kovetkezo;
    }
    
    return legnagyobb;
}

int main() {
    cout << "Legnagyobb Fibo 10 es 50 kozott: " << legnagyobbFiboKozott(10, 50) << endl;
    return 0;
}
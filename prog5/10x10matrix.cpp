#include <iostream>

using namespace std;

void sorAtlagokKiszamit(int matrix[10][10], double atlagok[10]) {
    for (int i = 0; i < 10; i++) {
        double sorOsszeg = 0;
        for (int j = 0; j < 10; j++) {
            sorOsszeg += matrix[i][j];
        }
        atlagok[i] = sorOsszeg / 10.0; 
    }
}

int main() {
    int tesztMatrix[10][10] = {0};
    tesztMatrix[0][0] = 5;    
    tesztMatrix[0][1] = 10;
    
    double eredmenyAtlagok[10];
    
    sorAtlagokKiszamit(tesztMatrix, eredmenyAtlagok);
    
    cout << "Az 1. sor atlaga: " << eredmenyAtlagok[0] << endl;
    return 0;
}
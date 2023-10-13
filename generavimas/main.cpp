#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));

    int n;
    cout << "kiek studentu?";
    cin >> n;

    ofstream failas("studentai.txt");
    if (!failas.is_open()) {
        cerr << "Nepavyko atidaryti failo" << endl;
        return 1;
    }

    for (int i = 1; i <= n; ++i) {
        failas << "Vardas" << i << "\tPavarde" << i;
        for (int j = 0; j < 15; ++j) {
            failas << "\t" << rand() % 10 + 1;
        }
        failas << endl;
    }

    failas.close();

    return 0;
}

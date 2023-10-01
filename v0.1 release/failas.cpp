#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iomanip>
#include <algorithm>
#include "failas.h"

using namespace std;

void isFailo(int a) {
    ifstream failas("C:\\Users\\Administrator\\Desktop\\studentai10000.txt");
    if (!failas.is_open()) {
        throw runtime_error("Nepavyko atidaryti failo");
    }

    string line;
    while (getline(failas, line)) {
        istringstream iss(line);
        string vardas, pavarde;
        iss >> vardas >> pavarde;

        vector<int> balai;
        int j;
        while (iss >> j) {
            balai.push_back(j);
        }

        double suma = 0;
        for(int j : balai) {
            suma += j;
        }

        sort(balai.begin(), balai.end());
        double mediana;
        if ((balai.size()) % 2 == 0)
            mediana = (balai[balai.size()/2 - 1] + balai[balai.size()/2]) / 2.0;
        else
            mediana = balai[balai.size()/2];

        if (a == 1) {
            cout << setw(15) << left << vardas << setw(15) << left << pavarde << setw(15) << left << fixed << setprecision(2) << suma/balai.size();
        } else if (a == 2) {
            cout << setw(15) << left << vardas << setw(15)<< left << pavarde << setw(15) << left << mediana;
        } else {
            throw runtime_error("Neteisingas pasirinkimas a");
        }
        cout << endl;
    }
    failas.close();
}

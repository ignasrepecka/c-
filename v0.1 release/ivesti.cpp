#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
#include <iomanip>
#include <stdexcept>
#include "ivesti.h"

using namespace std;

void ivestiStudentus(int n, int a) {
    for(int i = 0; i < n; ++i) {
        string vardas, pavarde;
        vector<int> balai;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Vardas:" ;
        getline(cin, vardas);

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Pavardė:" ;
        getline(cin, pavarde);

        cout << "Rezultatai (įveskite ne sveikąjį skaičių, kad sustabdytumėte): ";
        while(true) {
            int j;
            if(!(cin >> j)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
            balai.push_back(j);
        }

        int egz;
        cout << "Egzamino rezultatas: ";
        cin >> egz;
        balai.push_back(egz);
        cout << endl;

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
            cout << endl;
        } else {
            throw runtime_error("Neteisingas pasirinkimas a");
        }
    }
}

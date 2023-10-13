#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <stdexcept>

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

    int a;
    cout << "Ką pasirinksite?: 1 - Vidurkis, 2 - Mediana: ";
    cin >> a;

    string vardas, pavarde;

    try {
        ifstream failas("C:\\Users\\Administrator\\Desktop\\cc++++\\v0.2\\studentai.txt");
        ofstream failas1("protingi.txt"), failas2("durni.txt");
        if (!failas.is_open()) {
            throw runtime_error("Nepavyko atidaryti failo");
        }

        string line;
        while (getline(failas, line)) {
            istringstream iss(line);
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
                double vidurkis = suma/balai.size();
                if (vidurkis < 5)
                    failas2 << setw(15) << left << vardas << setw(15) << left << pavarde << setw(15) << left << fixed << setprecision(2) << vidurkis << endl;
                else
                    failas1 << setw(15) << left << vardas << setw(15) << left << pavarde << setw(15) << left << fixed << setprecision(2) << vidurkis << endl;
            } else if (a == 2) {
                if (mediana < 5)
                    failas2 << setw(15) << left << vardas << setw(15)<< left << pavarde << setw(15) << left << mediana << endl;
                else
                    failas1 << setw(15) << left << vardas << setw(15)<< left << pavarde << setw(15) << left << mediana << endl;
            } else {
                throw runtime_error("Neteisingas pasirinkimas a");
            }
        }
        failas.close();
        failas1.close();
        failas2.close();

    }
    catch (const exception& e) {
        cerr << "Klaida: " << e.what() << endl;
    }
    return 0;
}

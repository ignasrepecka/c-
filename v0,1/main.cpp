#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include <cstring>


using namespace std;

int main() {
    srand(time(0));
    int n;
    cout << "Kiek studentų?: ";
    cin >> n;

    int b;
    cout << "Ką pasirinksite?: 1 - Įvesti ranka, 2 - Generuoti atsitiktinai, 3 - Skaityti iš failo:";
    cin >> b;

    int a;
    cout << "Ką pasirinksite?: 1 - Vidurkis, 2 - Mediana: ";
    cin >> a;

    string vardas, pavarde;

    try {
        if (b == 1) {
            for(int i = 0; i < n; ++i) {
                string vardas, pavarde;
                vector<int> balai;

                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Vardas:" ;
                getline(cin, vardas);

                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Pavardė:" ;
                getline(cin, pavarde);

                cout <<"Rezultatai (įveskite ne sveikąjį skaičių, kad sustabdytumėte): ";
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
        else if (b == 2) {
            for(int i = 0; i < n; ++i) {
                string vardas, pavarde;
                vector<int> balai;

                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Vardas:" ;
                getline(cin, vardas);

                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Pavardė:" ;
                getline(cin, pavarde);

                int num_results = rand() % 10 + 1;
                for(int j = 0; j < num_results; ++j) {
                    balai.push_back(rand() % 10 + 1);
                }

                int egz = rand() % 10 + 1;
                balai.push_back(egz);

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
        else if (b == 3) {
            ifstream failas("C:\\Users\\Administrator\\Desktop\\studentai10000.txt");
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
        else {
            throw runtime_error("Neteisingas pasirinkimas");
        }
    }
    catch (const exception& e) {
        cerr << "Klaida: " << e.what() << endl;
    }
    return 0;
}

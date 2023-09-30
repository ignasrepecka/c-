#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;



int main()
{
    srand(time(0));
    int n;
    std::cout << "Kiek studentų?: ";
    std::cin >> n;

    int b;
    cout << "Ką pasirinksite?: 1 - Įvesti ranka, 2 - Generuoti atsitiktinai: ";
    cin >> b;

    int a;
    cout << "Ką pasirinksite?: 1 - Vidurkis, 2 - Mediana: ";
    cin >> a;

    for(int i = 0; i < n; ++i) {
        string vardas, pavarde;
        std::vector<int> balai;

        if (b == 1) {
            std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
            std::cout << "Vardas:" ;
            std::getline(std::cin, vardas);

            std::cin.ignore(numeric_limits<streamsize>::max(), '\n');

            std::cout << "Pavardė:" ;
            std::getline(std::cin, pavarde);
            std::cout <<"Rezultatai (įveskite ne sveikąjį skaičių, kad sustabdytumėte): ";
            while(true) {
                int j;
                if(!(std::cin >> j)) {
                    std::cin.clear();
                    std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
                balai.push_back(j);
            }
            int egz;
            std::cout << "Egzamino rezultatas: ";
            std::cin >> egz;
            balai.push_back(egz);
            std::cout << std::endl;

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
                cout << "Blogas pasirinkimas";
            }
        }
        else if (b == 2) {
            std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
            std::cout << "Vardas:" ;
            std::getline(std::cin, vardas);

            std::cin.ignore(numeric_limits<streamsize>::max(), '\n');

            std::cout << "Pavardė:" ;
            std::getline(std::cin, pavarde);


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
                cout << "Blogas pasirinkimas";
            }
        }
    }
}

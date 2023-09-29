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
    std::cout << "keik namu darbu buvo: ";
    std::cin >> n;

    int b;
    cout << "ką pasirinksite?: 1 - Įvesti ranka, 2 - Generuoti atsitiktinai, 3 - Skaityti iš failo: ";
    cin >> b;

    string vardas, pavarde;

    int a;
    cout << "ką pasirinksite?: 1 - Vidurkis, 2 - Mediana: ";
    cin >> a;

    if (b == 1) {
        std::vector<int> balai;
        std::cout <<"rezultatai: ";
        for(int i = 0; i < n; ++i) {
            int j;
            std::cin >> j;
            balai.push_back(j);
        }
        int egz;
        std::cout << "Egzamino balas: ";
        std::cin >> egz;
        balai.push_back(egz);
        std::cout << std::endl;

        double suma = 0;
        for(int j : balai) {
            suma += j;
        }

        sort(balai.begin(), balai.end());
        double mediana;
        if ((n+1) % 2 == 0)
            mediana = (balai[(n+1)/2 - 1] + balai[(n+1)/2]) / 2.0;
        else
            mediana = balai[(n+1)/2];

        std::cin.ignore(numeric_limits<streamsize>::max(), '\n');

        std::cout << "vardas:" ;
        std::getline(std::cin, vardas);

        std::cin.ignore(numeric_limits<streamsize>::max(), '\n');

        std::cout << "pavarde:" ;
        std::getline(std::cin, pavarde);
        cout << setw(10) << left << "vardas" << setw(10) << left << "pavarde" << setw(10) << left << "vidurkis/mediana";
        cout << endl;

        if (a == 1) {
            cout << setw(10) << left << vardas << setw(10) << left << pavarde << setw(10) << left << fixed << setprecision(2) << suma/(n+1);
        } else if (a == 2) {
            cout << setw(10) << left << vardas << setw(10)<< left << pavarde << setw(10) << left << mediana;
        } else {
            cout << "blogas pasirinkimas";
        }
    } else if (b == 2) {
         std::vector<int> balai;
         std::cout <<"rezultatai: ";
         for(int i = 0; i < n; ++i) {
             int j = rand() % 10 + 1;
             balai.push_back(j);
             std::cout << j << " ";
         }
         int egz = rand() % 10 + 1;
         balai.push_back(egz);
         std::cout << egz;
         std::cout << std::endl;

          double suma = 0;
          for(int j : balai) {
              suma += j;
          }

          sort(balai.begin(), balai.end());
          double mediana;
          if ((n+1) % 2 == 0)
              mediana = (balai[(n+1)/2 - 1] + balai[(n+1)/2]) / 2.0;
          else
              mediana = balai[(n+1)/2];

          std::cin.ignore(numeric_limits<streamsize>::max(), '\n');

          std::cout << "vardas:" ;
          std::getline(std::cin, vardas);

          std::cin.ignore(numeric_limits<streamsize>::max(), '\n');

          std::cout << "pavarde:" ;
          std::getline(std::cin, pavarde);
          cout << setw(10) << left << "vardas" << setw(10) << left << "pavarde" << setw(10) << left << "vidurkis/mediana";
          cout << endl;

           if (a == 1) {
               cout << setw(10) << left << vardas << setw(10) << left << pavarde << setw(10) << left << fixed << setprecision(2) << suma/(n+1);
           } else if (a == 2) {
               cout << setw(10) << left << vardas << setw(10)<< left << pavarde << setw(10) << left << mediana;
           } else {
               cout << "blogas pasirinkimas";
           }
    } else if (b == 3) {
        cout << setw(10) << left << "vardas" << setw(10) << left << "pavarde" << setw(10) << left << "vidurkis/mediana";
        cout << endl;
        ifstream failas("C:\\Users\\Administrator\\Desktop\\studentai10000.txt");
        while(failas >> vardas >> pavarde){
            std::vector<int> balai;
            for(int i=0; i<n; i++) {
                int j;
                failas >> j;
                balai.push_back(j);
            }
            int egz;
            failas >> egz;
            balai.push_back(egz);

            double suma = 0;
            for(int j : balai) {
                suma += j;
            }

            sort(balai.begin(), balai.end());
            double mediana;
            if ((n+1) % 2 == 0)
                mediana = (balai[(n+1)/2 - 1] + balai[(n+1)/2]) / 2.0;
            else
                mediana = balai[(n+1)/2];



            if (a == 1) {
                cout << setw(10) << left << vardas << setw(10) << left << pavarde << setw(10) << left << fixed << setprecision(2) << suma/(n+1);
            } else if (a == 2) {
                cout << setw(10) << left << vardas << setw(10)<< left << pavarde << setw(10) << left << mediana;
            } else {
                cout << "blogas pasirinkimas";
            }
            cout << endl;
        }
        failas.close();
    } else {
        cout << "blogas pasirinkimas";
    }

    return 0;
}


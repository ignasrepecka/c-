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

    if (b == 1) {
        std::vector<int> balai;
        std::cout <<"rezultatai: ";
        for(int i = 0; i < n; ++i) {
            int j;
            std::cin >> j;
            balai.push_back(j);
        }
        std::cout << std::endl;

        double suma = 0;
        for(int j : balai) {
            suma += j;
        }

        sort(balai.begin(), balai.end());
        double mediana;
        if (n % 2 == 0)
            mediana = (balai[n/2 - 1] + balai[n/2]) / 2.0;
        else
            mediana = balai[n/2];

        std::cin.ignore(numeric_limits<streamsize>::max(), '\n');

        std::cout << "vardas:" ;
        std::getline(std::cin, vardas);

        std::cin.ignore(numeric_limits<streamsize>::max(), '\n');

        std::cout << "pavarde:" ;
        std::getline(std::cin, pavarde);

        int a;
        cout << "ką pasirinksite?: 1 - Vidurkis, 2 - Mediana: ";
        cin >> a;

        cout << "vardas      " << "pavarde       ";

        if (a == 1) {
            cout << "vidurkis";
            cout << endl;
            cout << "------------------------------------------";
            cout << endl;
            cout << vardas << "     " << pavarde << "       " << fixed << setprecision(2) << suma/n;
        } else if (a == 2) {
            cout << "mediana";
            cout << endl;
            cout << "------------------------------------------";
            cout << endl;
            cout << vardas << "     " << pavarde << "       " << mediana;
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
        std::cout << std::endl;

         double suma = 0;
         for(int j : balai) {
             suma += j;
         }

         sort(balai.begin(), balai.end());
         double mediana;
         if (n % 2 == 0)
             mediana = (balai[n/2 - 1] + balai[n/2]) / 2.0;
         else
             mediana = balai[n/2];

         std::cin.ignore(numeric_limits<streamsize>::max(), '\n');

         std::cout << "vardas:" ;
         std::getline(std::cin, vardas);

         std::cin.ignore(numeric_limits<streamsize>::max(), '\n');

         std::cout << "pavarde:" ;
         std::getline(std::cin, pavarde);

         int a;
         cout << "ką pasirinksite?: 1 - Vidurkis, 2 - Mediana: ";
         cin >> a;

         cout << "vardas      " << "pavarde       ";

          if (a == 1) {
              cout << "vidurkis";
              cout << endl;
              cout << "------------------------------------------";
              cout << endl;
              cout << vardas << "     " << pavarde << "       " << fixed << setprecision(2) << suma/n;
          } else if (a == 2) {
              cout << "mediana";
              cout << endl;
              cout << "------------------------------------------";
              cout << endl;
              cout << vardas << "     " << pavarde << "       " << mediana;
          } else {
              cout << "blogas pasirinkimas";
          }
    } else if (b == 3) {
        cout << "vardas      " << "pavarde       " << "vidurkis";
        cout << endl;
        ifstream failas("C:\\Users\\Administrator\\Desktop\\studentai10000.txt");
        while(failas >> vardas >> pavarde){
            std::vector<int> balai;
            for(int i=0; i<n; i++) {
                int j;
                failas >> j;
                balai.push_back(j);
            }

            double suma = 0;
            for(int j : balai) {
                suma += j;
            }

            sort(balai.begin(), balai.end());
            double mediana;
            if (n % 2 == 0)
                mediana = (balai[n/2 - 1] + balai[n/2]) / 2.0;
            else
                mediana = balai[n/2];
            cout << vardas << "     " << pavarde << "       " << fixed << setprecision(2) << suma/n;
            cout << endl;
        }
        failas.close();
    } else {
        cout << "blogas pasirinkimas";
    }

    return 0;
}


#include <iostream>
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
    std::vector<int> balai;
    int n;
    double suma = 0;
    std::cout << "keik namu darbu buvo: ";
    std::cin >> n;

    int b;
    cout << "ką pasirinksite?: 1 - Įvesti ranka, 2 - Generuoti atsitiktinai: ";
    cin >> b;

    if (b == 1) {
        std::cout <<"rezultatai: ";
        for(int i = 0; i < n; ++i) {
            int j;
            std::cin >> j;
            balai.push_back(j);
        }
        std::cout << std::endl;
    } else if (b == 2) {
        std::cout <<"rezultatai: ";
        for(int i = 0; i < n; ++i) {
            int j = rand() % 10 + 1;
            balai.push_back(j);
            std::cout << j << " ";
        }
        std::cout << std::endl;
    } else {
        cout << "blogas pasirinkimas";
        return 0;
    }

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

    string vardas;
    std::cout << "vardas:" ;
    std::getline(std::cin, vardas);

    std::cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string pavarde;
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

    return 0;
}

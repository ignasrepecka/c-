#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

int main()
{
    std::vector<int> balai;
    int n;
    int suma = 0;
    std::cout << "keik namu darbu buvo: ";
    std::cin >> n;

    std::cout <<"rezultatai: ";
    for(int i = 0; i < n; ++i) {
        int j;
        std::cin >> j;
        balai.push_back(j);
    }
    std::cout << std::endl;

    for(int j : balai) {
    suma += j;
    }

    std::cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string vardas;
    std::cout << "vardas:" ;
    std::getline(std::cin, vardas);


    std::cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string pavarde;
    std::cout << "pavarde:" ;
    std::getline(std::cin, pavarde);

    cout << "vardas " << "pavarde " << "vidurkis";
    cout << endl;
    cout << "------------------------------------------";
    cout << endl;
    cout << vardas << " " << pavarde << " " << suma/n;

    return 0;
}

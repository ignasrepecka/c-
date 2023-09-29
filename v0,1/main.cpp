#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    int n;
    std::cout << "kiek nd: ";
    std::cin >> n;
    std::cout << "ivedei: " << n << std::endl;

    ifstream failas("C:\\Users\\Administrator\\Desktop\\studentai10000.txt");

    string vardas;
    string pavarde;
    vector<double> ND(n);
    double egz;



    while(failas >> vardas >> pavarde){
        for(int i=0; i<n; i++) {
            failas >> ND[i];
        }
        failas >> egz;
        cout << vardas << " " << pavarde << " ";
        for(int i = 0; i < n; i++) {
            cout << ND[i] << " ";
        }
        cout << " " << egz;
        cout << endl;
    }

    return 0;
}

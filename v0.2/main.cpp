#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <stdexcept>

using namespace std;

struct Student {
    string vardas;
    string pavarde;
    double score;
};

bool compare(const Student &a, const Student &b) {
    return a.score < b.score;
}

int main() {
    srand(time(0));

    int a;
    cout << "Ką pasirinksite?: 1 - Vidurkis, 2 - Mediana: ";
    cin >> a;

    try {
        ifstream failas("C:\\Users\\Administrator\\Desktop\\cc++++\\v0.2\\studentai.txt");
        ofstream failas1("protingi.txt"), failas2("durni.txt");
        if (!failas.is_open()) {
            throw runtime_error("Nepavyko atidaryti failo");
        }

        vector<Student> students;
        string line;
        while (getline(failas, line)) {
            istringstream iss(line);
            Student student;
            iss >> student.vardas >> student.pavarde;

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
                student.score = suma/balai.size();
            } else if (a == 2) {
                student.score = mediana;
            } else {
                throw runtime_error("Neteisingas pasirinkimas a");
            }
            
            students.push_back(student);
        }
        
        sort(students.begin(), students.end(), compare);

        for (const auto &student : students) {
            if (student.score < 5)
                failas2 << setw(15) << left << student.vardas << setw(15) << left << student.pavarde << setw(15) << left << fixed << setprecision(2) << student.score << endl;
            else
                failas1 << setw(15) << left << student.vardas << setw(15) << left << student.pavarde << setw(15) << left << fixed << setprecision(2) << student.score << endl;
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

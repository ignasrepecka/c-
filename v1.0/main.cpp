#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <stdexcept>
#include <chrono>

using namespace std;
using namespace std::chrono;

struct Student {
    string vardas;
    string pavarde;
    double score;
};

bool compareScore(const Student &a, const Student &b) {
    return a.score < b.score;
}

bool compareName(const Student &a, const Student &b) {
    return a.vardas < b.vardas;
}

bool compareSurname(const Student &a, const Student &b) {
    return a.pavarde < b.pavarde;
}

bool isDurni(const Student &s) {
    return s.score < 5;
}

int main() {
    srand(time(0));

    int a, b;
    cout << "Ka pasirinksite?: 1 - Vidurkis, 2 - Mediana: ";
    cin >> a;
    cout << "Kaip rusiuoti?: 1 - Pagal varda, 2 - Pagal pavarde, 3 - Pagal vidurki/mediana: ";
    cin >> b;

    try {
        ifstream failas("C:\\Users\\Administrator\\Desktop\\studentai100000.txt");

        ofstream failas1("protingi.txt"), failas2("durni.txt");
        if (!failas.is_open()) {
            throw runtime_error("Nepavyko atidaryti failo");
        }

        list<Student> students;
        string line;
        auto start = high_resolution_clock::now();
        while (getline(failas, line)) {
            istringstream iss(line);
            Student student;
            iss >> student.vardas >> student.pavarde;

            list<int> balai;
            int j;
            while (iss >> j) {
                balai.push_back(j);
            }

            double suma = 0;
            for(int j : balai) {
                suma += j;
            }

            balai.sort();
            double mediana;
            auto it = balai.begin();
            advance(it, balai.size()/2);
            if ((balai.size()) % 2 == 0)
                mediana = (*prev(it) + *it) / 2.0;
            else
                mediana = *it;

            if (a == 1) {
                student.score = suma/balai.size();
            } else if (a == 2) {
                student.score = mediana;
            } else {
                throw runtime_error("Neteisingas pasirinkimas a");
            }

            students.push_back(student);
        }
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Failo skaitymo laikas + siek tiek veiksmu: " << duration.count() << " mikrosekundes" << endl;

        start = high_resolution_clock::now();

        list<Student> durni;
        auto it = partition(students.begin(), students.end(), isDurni);
        copy(it, students.end(), back_inserter(durni));
        students.erase(it, students.end());

        if (b == 1) {
            students.sort(compareName);
            durni.sort(compareName);
        } else if (b == 2) {
            students.sort(compareSurname);
            durni.sort(compareSurname);
        } else if (b == 3) {
            students.sort(compareScore);
            durni.sort(compareScore);
        } else {
            throw runtime_error("Neteisingas pasirinkimas b");
        }
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        cout << "rusiavimo laikas: " << duration.count() << " mikrosekundes" << endl;

        start = high_resolution_clock::now();
        for (const auto &student : durni) {
            failas2 << setw(15) << left << student.vardas << setw(15) << left << student.pavarde << setw(15) << left << fixed << setprecision(2) << student.score << endl;
        }
        for (const auto &student : students) {
            failas1 << setw(15) << left << student.vardas << setw(15) << left << student.pavarde << setw(15) << left << fixed << setprecision(2) << student.score << endl;
        }
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        cout << "Rasymo i faila laikas/grupavimo laikas: " << duration.count() << " mikrosekundes" << endl;

        failas.close();
        failas1.close();
        failas2.close();

    }
    catch (const exception& e) {
        cerr << "Klaida: " << e.what() << endl;
    }
    return 0;
}

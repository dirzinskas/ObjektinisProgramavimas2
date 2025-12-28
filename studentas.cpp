#include "studentas.h"

int RandomSk(int max) {
    return rand() % (max + 1);
}

bool LyginimasStr(const Studentas &a, const Studentas &b) {
    return a.vardas < b.vardas;
}

void Rikiuoti(vector<Studentas>& s) {
    sort(s.begin(), s.end(), LyginimasStr);
}

void Rikiuoti(list<Studentas>& s) {
    s.sort(LyginimasStr);
}
void Rusiavimas(vector<Studentas>& s, vector<Studentas>& v) {
    auto it = partition(s.begin(), s.end(),
                        [](const Studentas& st){
                            return !(st.vidurkis < 5 && st.mediana < 5);
                        });
    v.insert(v.end(), it, s.end());
    s.erase(it, s.end());
}
void Rusiavimas(list<Studentas>& s, list<Studentas>& v) {
    auto it = s.begin();
    while (it != s.end()) {
        auto dabartinis = it++;
        if (dabartinis->vidurkis < 5 && dabartinis->mediana < 5) {
            v.splice(v.end(), s, dabartinis);
        }
    }
}
double Mediana(vector<int> pazymiai) {
    if (pazymiai.empty()) return 0.0;
    sort(pazymiai.begin(), pazymiai.end());
    int n = pazymiai.size();
    return (n % 2 == 0)
        ? (pazymiai[n/2 - 1] + pazymiai[n/2]) / 2.0
        : pazymiai[n/2];
}

double Vidurkis(vector<int> pazymiai) {
    if (pazymiai.empty()) return 0.0;
    double suma = 0;
    for (int x : pazymiai) suma += x;
    return suma / pazymiai.size();
}

void GeneruotiDuomenis() {
    int dydziai[] = {1000, 10000, 100000};
    for (int d : dydziai) {
        ofstream f("studentai" + to_string(d) + ".txt");
        f << "Pavarde Vardas ND1 ND2 ND3 ND4 ND5 Egzaminas\n";
        for (int i = 1; i <= d; i++) {
            f << "Pavarde" << i << " Vardas" << i << " ";
            for (int j = 0; j < 6; j++)
                f << RandomSk(10) << " ";
            f << "\n";
        }
    }
}

void Meniu() {
    cout << "-----------------------------------------" << endl;
    cout << "MENIU" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "1. Sugeneruoti testinius failus" << endl;
    cout << "2. Ivesti duomenis ranka" << endl;
    cout << "3. Ivesti duomenis sugeneruojant pazymius" << endl;
    cout << "4. Nuskaityti duomenis is failo" << endl;
    cout << "5. Rodyti rezultatus" << endl;
    cout << "6. Isvesti studentus i faila" << endl;
    cout << "7. Baigti darba" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "Pasirinkite veiksma 1-7" << endl;
}


#ifndef STUDENTAS_H
#define STUDENTAS_H

#include "zmogus.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include <list>

using namespace std;

class Studentas : public Zmogus {
    private:
        vector<int> nd;
        int egz;
        double vidurkis, mediana;

    public:
        Studentas(): Zmogus(), egz(0), vidurkis(0), mediana(0) {}
        Studentas(istream& is);

        Studentas(const Studentas& other);
        ~Studentas()=default;
        Studentas& operator=(const Studentas& other);

        void printInfo() const override;

        double vidurkis_() const { return vidurkis; }
        double mediana_() const { return mediana; }
        vector<int> nd_() const { return nd; }
        int egz_() const { return egz; }

    istream& readStudent(istream& is);
};
    int RandomSk(int max);
    bool LyginimasStr(const Studentas &petras, const Studentas &jonas);
    void Rikiuoti(vector<Studentas>& s);
    void Rikiuoti(list<Studentas>& s);
    void GeneruotiDuomenis();
void Meniu();


template<typename konteineris>
void Skaitymas(konteineris& s, string failas) {
    ifstream in(failas);
    if (!in) {
        cout << "Nepavyko atidaryti failo." << endl;
        return;
    }

    string eilute;
    getline(in, eilute);

    while (getline(in, eilute)) {
    if (eilute.empty()) continue;

    istringstream iss(eilute);
    s.push_back(Studentas(iss));
}
    cout << "Duomenys nuskaityti is failo. Viso: "
         << s.size() << " studentu." << endl;
}

template<typename konteineris>
void Ivedimas(konteineris& s, bool generuoti) {
    while (true) {
        string vardas, pavarde;
        cout << "Iveskite varda (Enter uzbaigs):" << endl;
        getline(cin, vardas);
        if (vardas.empty()) break;

        cout << "Iveskite pavarde:" << endl;
        getline(cin, pavarde);
        stringstream ss;
        ss << vardas << " " << pavarde << " ";
        if (generuoti) {
            int ndSk = RandomSk(15);
            for (int i = 0; i < ndSk; i++)
                ss << RandomSk(10) << " ";
            ss << RandomSk(10);
        } else {
            while (true) {
                string ndStr;
                cout << "Iveskite ND pazymi (Enter uzbaigs): ";
                getline(cin, ndStr);
                if (ndStr.empty()) break;
                try {
                    int paz = stoi(ndStr);
                    ss << paz << " ";
                } catch (...) {
                    cout << "Netinkama ivestis." << endl;
                }
            }

            string egzStr;
            cout << "Iveskite egzamino rezultata: ";
            getline(cin, egzStr);
            ss << stoi(egzStr);
        }

        istringstream iss(ss.str());
        Studentas petras(iss);

        s.push_back(petras);
        cout << "Studento duomenys ivesti!" << endl;
    }
}

template<typename konteineris>
void Rasymas(konteineris& s, string x) {
    ofstream rez("rezultatai_" + x + ".txt");
    rez << "Pavarde Vardas Galutinis(Vid.) Galutinis(Med.)\n";
    for (auto& st : s)
        rez << st.getPavarde() << " " << st.getVardas() << " "
            << st.vidurkis_() << " " << st.mediana_() << "\n";
}

void Rusiavimas(vector<Studentas>& s, vector<Studentas>& v);

void Rusiavimas(list<Studentas>& s, list<Studentas>& v);

template<typename konteineris>
void Rezultatai(konteineris s) {
    Rikiuoti(s);

    if (s.empty()) {
        cout << "Nera ivestu studentu." << endl;
        return;
    }

    cout << setw(20) << left << "Pavarde"
         << setw(20) << "Vardas"
         << setw(20) << "Galutinis (Vid.)"
         << setw(20) << "Galutinis (Med.)" << endl;

    for (auto& st : s)
        cout << setw(20) << st.getPavarde()
             << setw(20) << st.getVardas()
             << setw(20) << fixed << setprecision(2) << st.vidurkis_()
             << setw(20) << st.mediana_() << endl;
}



#endif

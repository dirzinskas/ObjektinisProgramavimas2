#ifndef STUDENTAS_H
#define STUDENTAS_H

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

class Studentas {
    private:
    string vardas, pavarde;
    vector<int> nd;
    int egz;
    double vidurkis, mediana;
    public:

    Studentas():egz(0), vidurkis(0), mediana(0) {}
    Studentas(istream& is);
    //getteriai
    inline string vardas_() const { return vardas; };
    inline string pavarde_() const { return pavarde; };
    double vidurkis_() const { return vidurkis; };
    double mediana_() const { return mediana; };
    vector<int> nd_() const { return nd; };
    int egz_() const { return egz; };

    istream& readStudent(istream& is);
};
    int RandomSk(int max);
    bool LyginimasStr(const Studentas &petras, const Studentas &jonas);
    void Rikiuoti(vector<Studentas>& s);
    void Rikiuoti(list<Studentas>& s);
    double Mediana(vector<int> pazymiai);
    double Vidurkis(vector<int> pazymiai);
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
        Studentas petras;
        iss >> petras.vardas >> petras.pavarde;

        string zodis;
        while (iss >> zodis) {
            try {
                petras.nd.push_back(stoi(zodis));
            } catch (...) {
                petras.nd.push_back(0);
            }
        }

        if (!petras.nd.empty()) {
            petras.egz = petras.nd.back();
            petras.nd.pop_back();
        }

        petras.vidurkis = 0.4 * Vidurkis(petras.nd) + 0.6 * petras.egz;
        petras.mediana = 0.4 * Mediana(petras.nd)  + 0.6 * petras.egz;

        s.push_back(petras);
    }

    cout << "Duomenys nuskaityti is failo. Viso: "
         << s.size() << " studentu." << endl;
}

template<typename konteineris>
void Ivedimas(konteineris& s, bool generuoti) {
    string zodis;
    while (true) {
        Studentas petras;

        cout << "Iveskite varda (Enter uzbaigs):" << endl;
        getline(cin, zodis);
        if (zodis.empty()) break;
        petras.vardas = zodis;

        cout << "Iveskite pavarde:" << endl;
        getline(cin, zodis);
        petras.pavarde = zodis;
        if (generuoti) {
            int ndSk = RandomSk(15);
            for (int i = 0; i < ndSk; i++)
                petras.nd.push_back(RandomSk(10));
            petras.egz  = RandomSk(10);
        } else {
            while (true) {
                cout << "Iveskite ND pazymi (Enter uzbaigs):" << endl;
                getline(cin, zodis);
                if (zodis.empty()) break;
                try {
                    petras.nd.push_back(stoi(zodis));
                } catch (...) {
                    cout << "Netinkama ivestis." << endl;
                }
            }

            cout << "Iveskite egzamino rezultata:" << endl;
            getline(cin, zodis);
            petras.egz = stoi(zodis);
        }

        petras.vidurkis = 0.4 * Vidurkis(petras.nd) + 0.6 * petras.egz;
        petras.mediana = 0.4 * Mediana(petras.nd)  + 0.6 * petras.egz;
        s.push_back(petras);
        cout << "Studento duomenys ivesti!" << endl;
    }
}

template<typename konteineris>
void Rasymas(konteineris& s, string x) {
    ofstream rez("rezultatai_" + x + ".txt");
    rez << "Pavarde Vardas Galutinis(Vid.) Galutinis(Med.)\n";
    for (auto& st : s)
        rez << st.pavarde << " " << st.vardas << " "
            << st.vidurkis << " " << st.mediana << "\n";
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
        cout << setw(20) << st.pavarde
             << setw(20) << st.vardas
             << setw(20) << fixed << setprecision(2) << st.vidurkis
             << setw(20) << st.mediana << endl;
}



#endif

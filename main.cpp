#include "studentas.h"
#include <chrono>

using namespace std;
using namespace std::chrono;
template<typename konteineris>
void runProgram(konteineris& s) {
    konteineris g;
    konteineris v;
    int y;
    char x;
    string failas;
    srand(time(0));

    do {
        Meniu();

        cin >> y;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        } else {
            cin.ignore(10000, '\n');
        }

        switch (y) {
            case 1: {
                auto start = high_resolution_clock::now();
                GeneruotiDuomenis();
                auto end = high_resolution_clock::now();
                cout << "Failu generavimas uztruko: "
                     << duration_cast<milliseconds>(end - start).count()
                     << " ms" << endl;
                break;
            }

            case 2:
                Ivedimas(s, false);
                break;

            case 3:
                Ivedimas(s, true);
                break;

            case 4: {
                cout << "Iveskite failo varda: ";
                cin >> failas;
                cin.ignore(10000, '\n');
                auto start = high_resolution_clock::now();
                Skaitymas(s, failas);
                auto end = high_resolution_clock::now();
                cout << "Failo skaitymas uztruko: "
                     << duration_cast<milliseconds>(end - start).count()
                     << " ms" << endl;
                break;
            }

            case 5:
            case 6: {
            
                while (true) {
                    cout << "Kokius studentus pateikti? g, v ar a? ";
                    cin >> x;
                    if (x == 'g' || x == 'v' || x == 'a') break;
                    cout << "Netinkama ivestis." << endl;
                }

                auto start = high_resolution_clock::now();

                v.clear();
                g.clear();
                for (auto &st : s) {
                    if (st.vidurkis < 5 && st.mediana < 5)
                        v.push_back(st);
                    else
                        g.push_back(st);
                }           

                auto end = high_resolution_clock::now();
                cout << "Rusiavimas i grupes uztruko: "
                     << duration_cast<milliseconds>(end - start).count()
                     << " ms" << endl;


                if (x == 'g') Rezultatai(g);
                else if (x == 'v') Rezultatai(v);
                else Rezultatai(s);


                if (y == 6) {
                    if (g.empty() && v.empty()) {
                        cout << "Klaida. Nera tinkamu studentu" << endl;
                    } else {
                        start = high_resolution_clock::now();
                        Rasymas(g, "g");
                        Rasymas(v, "v");
                        end = high_resolution_clock::now();
                        cout << "Rezultatu isvedimas i failus uztruko: "
                             << duration_cast<milliseconds>(end - start).count()
                             << " ms" << endl;
                    }
                }
                break;
            }

            case 7:
                cout << "Programa baigia darba." << endl;
                break;

            default:
                cout << "Netinkama ivestis. Pasirinkite skaiciu 1-7:" << endl;
        }

    } while (y != 7);
}

int main() {
    char x;

    while (true) {
        cout << "Ar studentus laikyti list ar vector tipo konteineryje? (v ar l) ";
        cin >> x;
        if (x == 'v' || x == 'l') break;
        cout << "Netinkama ivestis." << endl;
    }

    if (x == 'v') {
        vector<Studentas> s;
        runProgram(s);
    } else {
        list<Studentas> s;
        runProgram(s);
    }

    return 0;
}

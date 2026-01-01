#ifndef ZMOGUS_H
#define ZMOGUS_H

#include <string>

//pradesiu vartoti std:: vietoj namespace std  

class Zmogus {
protected:
    std::string vardas;
    std::string pavarde;
    
public:
    Zmogus(const std::string& v = "", const std::string& p = "")
        : vardas(v), pavarde(p) {}
    
    virtual ~Zmogus() = default;
    
    virtual void printInfo() const = 0;
    virtual double calculateGrade() const = 0;
    
    std::string getVardas() const { return vardas; }
    std::string getPavarde() const { return pavarde; }
    
    void setVardas(const std::string& v) { vardas = v; }
    void setPavarde(const std::string& p) { pavarde = p; }
};

#endif
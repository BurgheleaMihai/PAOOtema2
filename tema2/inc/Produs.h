#ifndef PRODUS_H
#define PRODUS_H

#include <string>
#include <iostream>

class Produs
{
private:
    std::string nume;
    double pret;
    int cantitate;

public:
    Produs();
    Produs(const std::string& nume, double pret, int cantitate);

    friend std::istream& operator>>(std::istream& in, Produs& p);
    friend std::ostream& operator<<(std::ostream& out, const Produs& p);
};

#endif

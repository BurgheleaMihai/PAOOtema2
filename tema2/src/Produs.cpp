#include "Produs.h"
#include <limits>

Produs::Produs()
    : nume("<neprecizat>"), pret(0.0), cantitate(0)
{
}

Produs::Produs(const std::string &n, double p, int c)
    : nume(n), pret(p), cantitate(c)
{
}

std::istream &operator>>(std::istream &in, Produs &p)
{
    std::cout << "Nume produs: ";
    std::getline(in >> std::ws, p.nume);

    std::cout << "Pret: ";
    in >> p.pret;

    std::cout << "Cantitate: ";
    in >> p.cantitate;

    in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return in;
}

std::ostream &operator<<(std::ostream &out, const Produs &p)
{
    out << "Produs{" << p.nume
        << ", pret=" << p.pret
        << ", cantitate=" << p.cantitate << "}";
    return out;
}

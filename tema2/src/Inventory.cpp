#include "Produs.h"
#include "Inventory.h"
#include "Logger.h"
#include <iostream>
#include <limits>

void citesteProdusSiAdauga(Inventory &inv)
{
    Produs p;
    std::cin >> p;
    inv.adaugaProdus(p);
}

int main()
{
    Logger log;
    log.log("Aplicatia a inceput.");

    Inventory magazin("Magazin Principal", 100);

    bool ruleaza = true;
    while (ruleaza)
    {
        std::cout << "\n=== Meniu ===\n";
        std::cout << "1. Adauga produs direct in magazin\n";
        std::cout << "2. Proceseaza o livrare (depozit temporar + move)\n";
        std::cout << "3. Afiseaza inventarul principal\n";
        std::cout << "0. Iesire\n";
        std::cout << "Optiune: ";

        int opt;
        std::cin >> opt;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (opt)
        {
        case 1:
        {
            std::cout << "\n--- Adaugare produs in magazin ---\n";
            citesteProdusSiAdauga(magazin);
            break;
        }
        case 2:
        {
            std::cout << "\n--- Livrare noua (depozit temporar) ---\n";
            int nr;
            std::cout << "Cate produse are livrarea? ";
            std::cin >> nr;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            Inventory depozitTemporar("Depozit Temporar", nr);

            for (int i = 0; i < nr; ++i)
            {
                std::cout << "\nProdus #" << (i + 1) << " pentru depozitul temporar:\n";
                citesteProdusSiAdauga(depozitTemporar);
            }

            Inventory livrare = std::move(depozitTemporar);

            for (std::size_t i = 0; i < livrare.getSize(); ++i)
            {
                magazin.adaugaProdus(livrare.getProdus(i));
            }

            std::cout << "\nLivrarea a fost integrata in magazin.\n";
            break;
        }
        case 3:
        {
            std::cout << "\n--- Inventarul principal ---\n";
            std::cout << magazin;
            break;
        }
        case 0:
            ruleaza = false;
            break;
        default:
            std::cout << "Optiune invalida.\n";
            break;
        }
    }

    log.log("Aplicatia s-a incheiat.");
    return 0;
}

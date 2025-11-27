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
        std::cout << "1. Proceseaza o livrare (depozit temporar)\n";
        std::cout << "2. Afiseaza inventarul principal\n";
        std::cout << "0. Iesire\n";
        std::cout << "Optiune: ";

        int opt;
        std::cin >> opt;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (opt)
        {
        case 1:
        {
            std::cout << "\n--- Livrare noua (depozit temporar) ---\n";
            int nr;
            std::cout << "Cate produse are livrarea? ";
            std::cin >> nr;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            if (nr <= 0)
            {
                std::cout << "Numar invalid de produse.\n";
                break;
            }

            Inventory depozitTemporar("Depozit Temporar", nr);

            for (int i = 0; i < nr; ++i)
            {
                std::cout << "\nProdus #" << (i + 1) << " pentru depozitul temporar:\n";
                citesteProdusSiAdauga(depozitTemporar);
            }

            bool finalizeazaLivrarea = false;
            bool anuleazaLivrarea = false;

            while (!finalizeazaLivrarea && !anuleazaLivrarea)
            {
                std::cout << "\n--- Verificare livrare in depozitul temporar ---\n";
                std::cout << depozitTemporar;

                std::cout << "\nOptiuni livrare:\n";
                std::cout << "1. Sterge un produs gresit din depozitul temporar\n";
                std::cout << "2. Integreaza livrarea in magazinul principal\n";
                std::cout << "0. Renunta la aceasta livrare\n";
                std::cout << "Optiune: ";

                int optLivrare;
                std::cin >> optLivrare;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                switch (optLivrare)
                {
                case 1:
                {
                    if (depozitTemporar.getSize() == 0)
                    {
                        std::cout << "Nu mai sunt produse in depozitul temporar.\n";
                        break;
                    }

                    std::cout << "Introdu indexul produsului de sters (0.."
                              << (depozitTemporar.getSize() - 1) << "): ";
                    std::size_t idx;
                    std::cin >> idx;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                    depozitTemporar.stergeProdus(idx);
                    break;
                }
                case 2:
                {
                    Inventory livrare = std::move(depozitTemporar);

                    for (std::size_t i = 0; i < livrare.getSize(); ++i)
                    {
                        magazin.adaugaProdus(livrare.getProdus(i));
                    }

                    std::cout << "Livrarea a fost integrata in magazinul principal.\n";
                    finalizeazaLivrarea = true;
                    break;
                }
                case 0:
                    std::cout << "Livrarea a fost anulata. Produsele NU au fost adaugate in magazin.\n";
                    anuleazaLivrarea = true;
                    break;
                default:
                    std::cout << "Optiune invalida.\n";
                    break;
                }
            }

            break;
        }
        case 2:
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

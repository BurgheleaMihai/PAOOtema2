#ifndef INVENTORY_H
#define INVENTORY_H

#include "Produs.h"
#include <string>
#include <cstddef>

class Inventory
{
private:
    std::string numeInventar;
    Produs* produse;
    std::size_t size;
    std::size_t capacity;

public:
    Inventory(const std::string& nume, std::size_t capacity);
    ~Inventory();

    Inventory(const Inventory& other);     // copy constructor
    Inventory(Inventory&& other) noexcept; // move constructor

    Inventory& operator=(const Inventory& other);     // copy assignment
    Inventory& operator=(Inventory&& other) noexcept; // move assignment

    void adaugaProdus(const Produs& p);

    friend std::ostream& operator<<(std::ostream& out, const Inventory& inv);
    std::size_t getSize() const { return size; }
    const Produs& getProdus(std::size_t index) const { return produse[index]; }
};

#endif

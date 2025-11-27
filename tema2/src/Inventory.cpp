#include "Inventory.h"

Inventory::Inventory(const std::string &nume, std::size_t cap)
    : numeInventar(nume), produse(new Produs[cap]), size(0), capacity(cap)
{
}

Inventory::~Inventory()
{
    delete[] produse;
}

Inventory::Inventory(const Inventory &other)
    : numeInventar(other.numeInventar),
      produse(new Produs[other.capacity]),
      size(other.size),
      capacity(other.capacity)
{
    for (std::size_t i = 0; i < size; ++i)
    {
        produse[i] = other.produse[i];
    }
}

Inventory::Inventory(Inventory &&other) noexcept
    : numeInventar(std::move(other.numeInventar)),
      produse(other.produse),
      size(other.size),
      capacity(other.capacity)
{
    other.produse = nullptr;
    other.size = 0;
    other.capacity = 0;
}

Inventory &Inventory::operator=(const Inventory &other)
{
    if (this == &other)
    {
        return *this;
    }

    delete[] produse;

    numeInventar = other.numeInventar;
    size = other.size;
    capacity = other.capacity;

    produse = new Produs[capacity];
    for (std::size_t i = 0; i < size; ++i)
    {
        produse[i] = other.produse[i];
    }

    return *this;
}

Inventory &Inventory::operator=(Inventory &&other) noexcept
{
    if (this == &other)
    {
        return *this;
    }

    delete[] produse;

    numeInventar = std::move(other.numeInventar);
    produse = other.produse;
    size = other.size;
    capacity = other.capacity;

    other.produse = nullptr;
    other.size = 0;
    other.capacity = 0;

    return *this;
}

void Inventory::adaugaProdus(const Produs &p)
{
    if (size < capacity)
    {
        produse[size++] = p;
    }
}

void Inventory::stergeProdus(std::size_t index)
{
    if (index >= size)
        return;

    for (std::size_t i = index; i + 1 < size; ++i)
    {
        produse[i] = produse[i + 1];
    }
    --size;
}

std::ostream &operator<<(std::ostream &out, const Inventory &inv)
{
    out << "Inventory \"" << inv.numeInventar << "\":\n";
    for (std::size_t i = 0; i < inv.getSize(); ++i)
    {
        out << "  - " << inv.produse[i] << "\n";
    }
    return out;
}

#include "Vektor.h"

#include <cassert>
#include <iostream>

// ---------- Konstruktor a destruktor ----------

Vektor::Vektor(std::size_t size, double initialValue)
    : m_data(new double[size]), m_size(size) {
    for (std::size_t i = 0; i < m_size; ++i) {
        m_data[i] = initialValue;
    }
    std::cout << "Vytvořen vektor o velikosti " << m_size << "\n";
}

Vektor::~Vektor() {
    std::cout << "Smazán vektor o velikosti " << m_size << "\n";
    delete[] m_data;
}

// ---------- Metody ----------

std::size_t Vektor::size() const {
    return m_size;
}

double& Vektor::at(std::size_t i) {
    assert(i < m_size);
    return m_data[i];
}

void Vektor::add(const Vektor& other) {
    assert(m_size == other.m_size);
    for (std::size_t i = 0; i < m_size; ++i) {
        m_data[i] += other.m_data[i];
    }
}

void Vektor::scale(double k) {
    for (std::size_t i = 0; i < m_size; ++i) {
        m_data[i] *= k;
    }
}

bool Vektor::equals(const Vektor& other) const {
    if (m_size != other.m_size) {
        return false;
    }
    for (std::size_t i = 0; i < m_size; ++i) {
        if (m_data[i] != other.m_data[i]) {
            return false;
        }
    }
    return true;
}

// ---------- Přetížené operátory ----------

double& Vektor::operator[](std::size_t i) {
    return at(i);
}

Vektor& Vektor::operator+=(const Vektor& other) {
    add(other);
    return *this;
}

Vektor& Vektor::operator*=(double k) {
    scale(k);
    return *this;
}

bool Vektor::operator==(const Vektor& other) const {
    return equals(other);
}

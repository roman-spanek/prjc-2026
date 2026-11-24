//
// Created by roman on 11/24/2026.
//

#include "Box.h"

Box::Box() : m_zvire(nullptr) {}

Box::~Box() {
    delete m_zvire;
}

void Box::vloz(Zvire* zvire) {
    delete m_zvire;
    m_zvire = zvire;
}

const Zvire* Box::zvire() const {
    return m_zvire;
}

#include "AbstractItem.h"

AbstractItem::AbstractItem(const unsigned int ID) : ID(ID) {}
AbstractItem::AbstractItem(const unsigned int ID, const std::string name) : ID(ID), name(name) {}

AbstractItem::~AbstractItem() {}

unsigned int AbstractItem::getID() const {
    return ID;
}

const std::string& AbstractItem::getName() const {
    return name;
}

AbstractItem& AbstractItem::setName(const std::string name) {
    this->name = name;
    return *this;
}


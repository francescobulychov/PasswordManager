#include "Card.h"

Card::Card(const unsigned int ID) : AbstractItem(ID) {}

Card::Card(const unsigned int ID, const std::string name, const std::string holderName, const std::string number, const std::string expDate, const std::string cvv) : AbstractItem(ID, name), holderName(holderName), number(number), expDate(expDate), cvv(cvv) {}

const std::string& Card::getHolderName() const {
    return holderName;
}

Card& Card::setHolderName(const std::string holderName) {
    this->holderName = holderName;
    return *this;
}

const std::string& Card::getNumber() const {
    return number;
}

Card& Card::setNumber(const std::string number) {
    this->number = number;
    return *this;
}

const std::string& Card::getExpDate() const {
    return expDate;
}

Card& Card::setExpDate(const std::string expDate) {
    this->expDate = expDate;
    return *this;
}

const std::string& Card::getCVV() const {
    return cvv;
}

Card& Card::setCVV(const std::string cvv) {
    this->cvv = cvv;
    return *this;
}

void Card::accept(IVisitor& visitor) {
    visitor.visit(*this);
}

void Card::accept(IConstVisitor& visitor) const {
    visitor.visit(*this);
}

Card* Card::clone() const {
    return new Card(*this);
}

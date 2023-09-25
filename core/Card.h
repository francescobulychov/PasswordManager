#ifndef CARD_H
#define CARD_H

#include "AbstractItem.h"

class Card : public AbstractItem {

private:
    std::string holderName;
    std::string number;
    std::string expDate;
    std::string cvv;

public:
    Card(const unsigned int ID);
    Card(const unsigned int ID, const std::string name, const std::string holderName, const std::string number, const std::string expDate, const std::string cvv);
    const std::string& getHolderName() const;
    Card& setHolderName(const std::string holderName);
    const std::string& getNumber() const;
    Card& setNumber(const std::string number);
    const std::string& getExpDate() const;
    Card& setExpDate(const std::string expDate);
    const std::string& getCVV() const;
    Card& setCVV(const std::string cvv);
    virtual void accept(IVisitor& visitor);
    virtual void accept(IConstVisitor& visitor) const;
    virtual Card* clone() const;
};

#endif

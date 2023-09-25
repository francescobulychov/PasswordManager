#ifndef ABSTRACTITEM_H
#define ABSTRACTITEM_H

#include "IVisitor.h"
#include "IConstVisitor.h"

#include <string>

class AbstractItem {

private:
    const unsigned int ID;
    std::string name;

protected:
    AbstractItem(const unsigned int ID);
    AbstractItem(const unsigned int ID, const std::string name);

public:
    virtual ~AbstractItem();
    unsigned int getID() const;
    const std::string& getName() const;
    AbstractItem& setName(const std::string name);
    virtual void accept(IVisitor& visitor) = 0;
    virtual void accept(IConstVisitor& visitor) const = 0;
    virtual AbstractItem* clone() const = 0;
};

#endif

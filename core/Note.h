#ifndef NOTE_H
#define NOTE_H

#include "AbstractItem.h"

class Note : public AbstractItem {

private:
    std::string text;

public:
    Note(const unsigned int ID);
    Note(const unsigned int ID, const std::string name, const std::string text);
    const std::string& getText() const;
    Note& setText(const std::string text);
    virtual void accept(IVisitor& visitor);
    virtual void accept(IConstVisitor& visitor) const;
    virtual Note* clone() const;
};

#endif

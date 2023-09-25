#ifndef IVISITOR_H
#define IVISITOR_H

class Login;
class Card;
class Note;

class IVisitor {

public:
    virtual ~IVisitor() {};
    virtual void visit(Login& login) = 0;
    virtual void visit(Card& card) = 0;
    virtual void visit(Note& note) = 0;
};

#endif

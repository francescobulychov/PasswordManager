#ifndef ICONSTVISITOR_H
#define ICONSTVISITOR_H

class Login;
class Card;
class Note;

class IConstVisitor {

public:
    virtual ~IConstVisitor() {};
    virtual void visit(const Login& login) = 0;
    virtual void visit(const Card& card) = 0;
    virtual void visit(const Note& note) = 0;

};

#endif

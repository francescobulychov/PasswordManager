#ifndef XMLWRITERVISITOR_H
#define XMLWRITERVISITOR_H

#include "../IConstVisitor.h"
#include "../AbstractItem.h"
#include "../Login.h"
#include "../Card.h"
#include "../Note.h"

#include<QXmlStreamWriter>

class XmlWriterVisitor : public IConstVisitor {

private:
    QXmlStreamWriter& writer;
    void writeCommonFields(const AbstractItem& item) const;

public:
    XmlWriterVisitor(QXmlStreamWriter& writer);
    void visit(const Login& login) override;
    void visit(const Card& card) override;
    void visit(const Note& note) override;
};

#endif

#ifndef XMLREADERVISITOR_H
#define XMLREADERVISITOR_H

#include "../IVisitor.h"
#include "../AbstractItem.h"
#include "../Login.h"
#include "../Card.h"
#include "../Note.h"

#include<QXmlStreamReader>

class XmlReaderVisitor : public IVisitor {
private:
    QXmlStreamReader& reader;
    void readCommonFields(AbstractItem& item) const;

public:
    XmlReaderVisitor(QXmlStreamReader& reader);
    void visit(Login& login) override;
    void visit(Card& card) override;
    void visit(Note& note) override;

};

#endif

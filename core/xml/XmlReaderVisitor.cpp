#include "XmlReaderVisitor.h"
#include "../../utils/Cryptography.h"

XmlReaderVisitor::XmlReaderVisitor(QXmlStreamReader& reader) : reader(reader) {}

void XmlReaderVisitor::readCommonFields(AbstractItem& item) const {
    reader.readNextStartElement();
    item.setName(Cryptography::decrypt(reader.readElementText().toStdString()));
}

void XmlReaderVisitor::visit(Login& login) {
    readCommonFields(login);
    reader.readNextStartElement();
    login.setUsername(Cryptography::decrypt(reader.readElementText().toStdString()));
    reader.readNextStartElement();
    login.setPassword(Cryptography::decrypt(reader.readElementText().toStdString()));
    reader.readNextStartElement();
    login.setSite(Cryptography::decrypt(reader.readElementText().toStdString()));
}

void XmlReaderVisitor::visit(Card& card) {
    readCommonFields(card);
    reader.readNextStartElement();
    card.setHolderName(Cryptography::decrypt(reader.readElementText().toStdString()));
    reader.readNextStartElement();
    card.setNumber(Cryptography::decrypt(reader.readElementText().toStdString()));
    reader.readNextStartElement();
    card.setExpDate(Cryptography::decrypt(reader.readElementText().toStdString()));
    reader.readNextStartElement();
    card.setCVV(Cryptography::decrypt(reader.readElementText().toStdString()));
}

void XmlReaderVisitor::visit(Note& note) {
    readCommonFields(note);
    reader.readNextStartElement();
    note.setText(Cryptography::decrypt(reader.readElementText().toStdString()));
}

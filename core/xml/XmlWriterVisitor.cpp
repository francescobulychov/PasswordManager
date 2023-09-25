#include "XmlWriterVisitor.h"
#include "../../utils/Cryptography.h"

XmlWriterVisitor::XmlWriterVisitor(QXmlStreamWriter& writer) : writer(writer) {}

void XmlWriterVisitor::writeCommonFields(const AbstractItem& item) const {
    writer.writeTextElement("Name", Cryptography::encrypt(item.getName()).c_str());
}

void XmlWriterVisitor::visit(const Login& login) {
    writer.writeStartElement("Item");
    writer.writeAttribute("Type", "Login");
    writeCommonFields(login);
    writer.writeTextElement("Username", Cryptography::encrypt(login.getUsername()).c_str());
    writer.writeTextElement("Password", Cryptography::encrypt(login.getPassword()).c_str());
    writer.writeTextElement("Site", Cryptography::encrypt(login.getSite()).c_str());
    writer.writeEndElement();
}

void XmlWriterVisitor::visit(const Card& card) {
    writer.writeStartElement("Item");
    writer.writeAttribute("Type", "Card");
    writeCommonFields(card);
    writer.writeTextElement("HolderName", Cryptography::encrypt(card.getHolderName()).c_str());
    writer.writeTextElement("Number", Cryptography::encrypt(card.getNumber()).c_str());
    writer.writeTextElement("ExpirationDate", Cryptography::encrypt(card.getExpDate()).c_str());
    writer.writeTextElement("CVV", Cryptography::encrypt(card.getCVV()).c_str());
    writer.writeEndElement();
}

void XmlWriterVisitor::visit(const Note& note) {
    writer.writeStartElement("Item");
    writer.writeAttribute("Type", "Note");
    writeCommonFields(note);
    writer.writeTextElement("Text", Cryptography::encrypt(note.getText()).c_str());
    writer.writeEndElement();
}

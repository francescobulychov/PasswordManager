#include "XmlStream.h"
#include "XmlWriterVisitor.h"
#include "XmlReaderVisitor.h"

#include<QXmlStreamWriter>
#include<QXmlStreamReader>
#include<QFile>

namespace XmlStream {

    void saveData(const Container& container, const std::string& path) {
        QXmlStreamWriter writer;

        QFile file(path.c_str());
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            return;

        writer.setDevice(&file);
        writer.setAutoFormatting(true);

        writer.writeStartDocument();
        writer.writeStartElement("PasswordManager");

        XmlWriterVisitor visitor(writer);

        for(Container::Iterator it = container.begin(); it != container.end(); ++it)
            it->accept(visitor);

        writer.writeEndElement();
        writer.writeEndDocument();

        file.close();
    }

    bool loadData(Container& container, const std::string& path) {
        try {
            QXmlStreamReader reader;

            QFile file(path.c_str());
            if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                return false;

            reader.setDevice(&file);

            Container temp;

            while (!reader.atEnd() && !reader.hasError()) {
                QXmlStreamReader::TokenType token = reader.readNext();
                if (token == QXmlStreamReader::StartElement) {
                    if (reader.name().toString() == "Item") {
                        QString type = reader.attributes().value("Type").toString();

                        AbstractItem* item = nullptr;
                        XmlReaderVisitor visitor(reader);

                        if (type == "Login") item = new Login(temp.generateUniqueID());
                        else if (type == "Card") item = new Card(temp.generateUniqueID());
                        else if (type == "Note") item = new Note(temp.generateUniqueID());

                        if (item != nullptr) {
                            item->accept(visitor);
                            temp.insert(item);
                        }
                    }
                }
            }

            for(Container::Iterator it = temp.begin(); it != temp.end(); ++it)
                container.insert(it->clone());

            file.close();
        } catch (...) {
            return false;
        }
        return true;
    }
}





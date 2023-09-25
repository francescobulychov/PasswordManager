#include "Note.h"

Note::Note(const unsigned int ID) : AbstractItem(ID) {}

Note::Note(const unsigned int ID, const std::string name, const std::string text) : AbstractItem(ID, name), text(text) {}

const std::string& Note::getText() const {
    return text;
}

Note& Note::setText(const std::string text) {
    this->text = text;
    return *this;
}

void Note::accept(IVisitor& visitor) {
    visitor.visit(*this);
}

void Note::accept(IConstVisitor& visitor) const {
    visitor.visit(*this);
}

Note* Note::clone() const {
    return new Note(*this);
}

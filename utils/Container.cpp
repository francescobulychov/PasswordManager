#include "Container.h"

Container::Node::Node(AbstractItem* item, Node* next) : item(item), next(next) {}

Container::Node::~Node() {
    delete item;
}

Container::Node* Container::copy(Node* node) {
    if (node == nullptr)
        return nullptr;
    else
        return new Node(node->item->clone(), copy(node->next));
}

void Container::destroy(Node* node) {
    if (node != nullptr) {
        destroy(node->next);
        delete node;
    }
}



bool Container::Iterator::operator==(const Iterator& i) const {
    return point == i.point;
}

bool Container::Iterator::operator!=(const Iterator& i) const {
    return point != i.point;
}

Container::Iterator& Container::Iterator::operator++() {
    if (point != nullptr)
        point = point->next;
    return *this;
}

Container::Iterator Container::Iterator::operator++(int) {
    Iterator aux = *this;
    if (point != nullptr)
        point = point->next;
    return aux;
}

AbstractItem* Container::Iterator::operator->() const {
    return point->item;
}

AbstractItem* Container::Iterator::operator*() const {
    return point->item;
}

Container::Iterator Container::begin() const {
    Iterator aux;
    aux.point = first;
    return aux;
}

Container::Iterator Container::end() const {
    Iterator aux;
    aux.point = nullptr;
    return aux;
}



Container::Container() : first(nullptr) {}

Container::Container(const Container& container) : first(copy(container.first)) {}

Container::~Container() {
    if (first != nullptr)
        destroy(first);
}

Container& Container::operator=(const Container& container) {
    if (this != &container) {
        destroy(first);
        first = copy(container.first);
    }
    return *this;
}

void Container::insert(AbstractItem* item) {
    first = new Node(item, first);
}

void Container::removeByID(const unsigned int ID) {
    Node* current = first;
    Node* prev = nullptr;

    while (current != nullptr && current->item->getID() != ID) {
        prev = current;
        current = current->next;
    }

    if (current != nullptr) {
        if (prev == nullptr)
            first = current->next;
        else
            prev->next = current->next;
        delete current;
    }
}

AbstractItem* Container::getByID(const unsigned int ID) const {
    Node* current = first;
    while (current != nullptr) {
        if(current->item->getID() == ID)
            return current->item;
        current = current->next;
    }
    return nullptr;
}

Container Container::searchByName(const std::string& searchedName) const {
    Container result;
    Node* current = first;

    std::string lowerSearchedName = searchedName;
    for(char& c : lowerSearchedName)
        c = std::tolower(c);

    while (current != nullptr) {

        std::string lowerCurrentName = current->item->getName();
        for(char& c : lowerCurrentName)
            c = std::tolower(c);

        if(lowerCurrentName.find(lowerSearchedName) != std::string::npos)
            result.insert(current->item->clone());
        current = current->next;
    }
    return result;

}

unsigned int Container::generateUniqueID() const {
    unsigned int newID = 0;
    bool uniqueIDFound = false;

    while (uniqueIDFound != true) {

        bool isDuplicate = false;
        for (Container::Iterator it = this->begin(); it != this->end(); ++it) {
            if (it->getID() == newID) {
                isDuplicate = true;
                break;
            }
        }

        if (isDuplicate == true)
            ++newID;
        else
            uniqueIDFound = true;
    }

    return newID;
}

void Container::clear() {
    if (first != nullptr)
        destroy(first);
    first = nullptr;
}


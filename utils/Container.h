#ifndef CONTAINER_H
#define CONTAINER_H

#include "../core/AbstractItem.h"

class Container {

private:
    class Node {
    public:
        AbstractItem* item;
        Node* next;
        Node(AbstractItem* item, Node* next);
        ~Node();
    };

    Node* first;
    static Node* copy(Node* node);
    static void destroy(Node* node);

public:
    class Iterator {
      friend class Container;
    private:
      Container::Node* point;
    public:
      bool operator==(const Iterator&) const;
      bool operator!=(const Iterator&) const;
      Iterator& operator++();
      Iterator operator++(int);
      AbstractItem* operator->() const;
      AbstractItem* operator*() const;
    };
    Iterator begin() const;
    Iterator end() const;

    Container();
    Container(const Container&);
    ~Container();

    Container& operator=(const Container&);

    void insert(AbstractItem* item);
    void removeByID(const unsigned int ID);
    AbstractItem* getByID(const unsigned int ID) const;
    Container searchByName(const std::string& name) const;
    unsigned int generateUniqueID() const;
    void clear();
};

#endif

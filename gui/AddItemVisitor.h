#ifndef ADDITEMVISITOR_H
#define ADDITEMVISITOR_H

#include "../core/IConstVisitor.h"
#include "../core/AbstractItem.h"
#include "../core/Login.h"
#include "../core/Card.h"
#include "../core/Note.h"

#include <QWidget>
#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>

class AddItemVisitor : public IConstVisitor {

private:
    QWidget* widget;
    QVBoxLayout* vBox;
    QLineEdit* name;
    QLineEdit* username;
    QLineEdit* password;
    QLineEdit* site;
    QLineEdit* holderName;
    QLineEdit* number;
    QLineEdit* expDate;
    QLineEdit* cvv;
    QTextEdit* text;
    QPushButton* passwordButton;
    void editCommonFields();

public:
    void visit(const Login& login) override;
    void visit(const Card& card) override;
    void visit(const Note& note) override;
    QWidget* getWidget() const;
    QLineEdit* getName() const;
    QLineEdit* getUsername() const;
    QLineEdit* getPassword() const;
    QLineEdit* getSite() const;
    QLineEdit* getHolderName() const;
    QLineEdit* getNumber() const;
    QLineEdit* getExpDate() const;
    QLineEdit* getCVV() const;
    QTextEdit* getText() const;
    QPushButton* getPasswordButton() const;
};

#endif

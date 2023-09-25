#ifndef INFOITEMVISITOR_H
#define INFOITEMVISITOR_H

#include "../core/IConstVisitor.h"
#include "../core/AbstractItem.h"
#include "../core/Login.h"
#include "../core/Card.h"
#include "../core/Note.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>

class InfoItemVisitor  : public IConstVisitor {

private:
    QWidget* widget;
    QVBoxLayout* vBox;
    QLineEdit* password;
    QPushButton* passwordButton;
    void showCommonFields(const AbstractItem& item);

public:
    void visit(const Login& login) override;
    void visit(const Card& card) override;
    void visit(const Note& note) override;
    QWidget* getWidget() const;
    QLineEdit* getPassword() const;
    QPushButton* getPasswordButton() const;
};

#endif

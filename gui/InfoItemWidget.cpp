#include "InfoItemWidget.h"

#include <QVBoxLayout>
#include <QScrollArea>

InfoItemWidget::InfoItemWidget(MainWindow* mainWindow, AbstractItem* item, QWidget* parent) : QWidget(parent), mainWindow(mainWindow), item(item) {

    QVBoxLayout* vBox = new QVBoxLayout(this);
    vBox->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    QScrollArea* scrollArea = new QScrollArea();
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scrollArea->setWidgetResizable(true);
    vBox->addWidget(scrollArea);

    item->accept(visitor);

    scrollArea->setWidget(visitor.getWidget());

    QHBoxLayout* hBox = new QHBoxLayout();
    hBox->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    vBox->addLayout(hBox);

    QPushButton* editButton = new QPushButton(QIcon(QPixmap((":/assets/icons/edit.svg"))), "  Edit Item");
    connect(editButton, &QPushButton::clicked, mainWindow, &MainWindow::editItem);
    hBox->addWidget(editButton);

    QPushButton* removeButton = new QPushButton(QIcon(QPixmap((":/assets/icons/remove.svg"))), "  Remove Item");
    connect(removeButton, &QPushButton::clicked, mainWindow, &MainWindow::removeItem);
    hBox->addWidget(removeButton);

    if (dynamic_cast<Login*>(item) != nullptr)
        connect(visitor.getPasswordButton(), &QPushButton::clicked, this, &InfoItemWidget::showPassword);
}

void InfoItemWidget::showPassword() {
    if (visitor.getPassword()->echoMode() == QLineEdit::Password) {
        visitor.getPassword()->setEchoMode(QLineEdit::Normal);
        visitor.getPasswordButton()->setIcon(QIcon(QPixmap((":/assets/icons/eye.svg"))));
    }
    else {
        visitor.getPassword()->setEchoMode(QLineEdit::Password);
        visitor.getPasswordButton()->setIcon(QIcon(QPixmap((":/assets/icons/closed_eye.svg"))));
    }
}

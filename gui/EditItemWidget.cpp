#include "EditItemWidget.h"

#include <QVBoxLayout>
#include <QScrollArea>

EditItemWidget::EditItemWidget(MainWindow* mainWindow, AbstractItem* item, QWidget* parent) : QWidget(parent), mainWindow(mainWindow), item(item) {

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

    QPushButton* applyButton = new QPushButton(QIcon(QPixmap((":/assets/icons/apply.svg"))), "  Apply");
    connect(applyButton, &QPushButton::clicked, this, &EditItemWidget::apply);
    hBox->addWidget(applyButton);

    QPushButton* cancelButton = new QPushButton(QIcon(QPixmap((":/assets/icons/cancel.svg"))), "  Cancel");
    connect(cancelButton, &QPushButton::clicked, mainWindow, &MainWindow::showInfoItem);
    hBox->addWidget(cancelButton);

    if (dynamic_cast<Login*>(item) != nullptr)
        connect(visitor.getPasswordButton(), &QPushButton::clicked, this, &EditItemWidget::showPassword);

}

void EditItemWidget::showPassword() {
    if (visitor.getPassword()->echoMode() == QLineEdit::Password) {
        visitor.getPassword()->setEchoMode(QLineEdit::Normal);
        visitor.getPasswordButton()->setIcon(QIcon(QPixmap((":/assets/icons/eye.svg"))));
    }
    else {
        visitor.getPassword()->setEchoMode(QLineEdit::Password);
        visitor.getPasswordButton()->setIcon(QIcon(QPixmap((":/assets/icons/closed_eye.svg"))));

    }
}

void EditItemWidget::apply() {
    QString name = visitor.getName()->text();
    item->setName(name.toStdString());

    if (dynamic_cast<Login*>(item) != nullptr) {
        Login* login = static_cast<Login*>(item);
        QString username = visitor.getUsername()->text();
        login->setUsername(username.toStdString());
        QString password = visitor.getPassword()->text();
        login->setPassword(password.toStdString());
        QString site = visitor.getSite()->text();
        login->setSite(site.toStdString());
    }
    else if (dynamic_cast<Card*>(item) != nullptr) {
        Card* card = static_cast<Card*>(item);
        QString holderName = visitor.getHolderName()->text();
        card->setHolderName(holderName.toStdString());
        QString number = visitor.getNumber()->text();
        card->setNumber(number.toStdString());
        QString expDate = visitor.getExpDate()->text();
        card->setExpDate(expDate.toStdString());
        QString cvv = visitor.getCVV()->text();
        card->setCVV(cvv.toStdString());
    }
    else if (dynamic_cast<Note*>(item) != nullptr) {
        Note* note = static_cast<Note*>(item);
        QString text = visitor.getText()->toPlainText();
        note->setText(text.toStdString());
    }

    mainWindow->showItems();
}

#include "InfoItemVisitor.h"

#include <QLabel>
#include <QTextEdit>

void InfoItemVisitor::showCommonFields(const AbstractItem& item) {
    widget = new QWidget();

    vBox = new QVBoxLayout(widget);
    vBox->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    QLabel* titleLabel = new QLabel("ITEM INFORMATION");
    QFont font;
    font.setPointSize(15);
    titleLabel->setFont(font);
    vBox->addWidget(titleLabel);
    vBox->addSpacing(5);

    vBox->addWidget(new QLabel("Name"));
    vBox->addSpacing(3);

    QLineEdit* name = new QLineEdit();
    name->setReadOnly(true);
    name->setText(QString::fromStdString(item.getName()));
    vBox->addWidget(name);

    vBox->addSpacing(5);

    QFrame* separator = new QFrame;
    separator->setFrameShape(QFrame::HLine);
    separator->setFrameShadow(QFrame::Sunken);
    vBox->addWidget(separator);

}

void InfoItemVisitor::visit(const Login& login) {
    showCommonFields(login);

    vBox->addWidget(new QLabel("Username"));
    vBox->addSpacing(3);

    QLineEdit* username = new QLineEdit();
    username->setReadOnly(true);
    username->setText(QString::fromStdString(login.getUsername()));
    vBox->addWidget(username);

    vBox->addSpacing(5);

    QFrame* separator = new QFrame;
    separator->setFrameShape(QFrame::HLine);
    separator->setFrameShadow(QFrame::Sunken);
    vBox->addWidget(separator);

    vBox->addWidget(new QLabel("Password"));
    vBox->addSpacing(3);

    QHBoxLayout* hBox = new QHBoxLayout();
    hBox->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    vBox->addLayout(hBox);

    password = new QLineEdit();
    password->setReadOnly(true);
    password->setText(QString::fromStdString(login.getPassword()));
    password->setEchoMode(QLineEdit::Password);
    hBox->addWidget(password);

    passwordButton = new QPushButton(QIcon(QPixmap((":/assets/icons/closed_eye.svg"))), "");
    hBox->addWidget(passwordButton);

    vBox->addSpacing(5);

    QFrame* separator2 = new QFrame;
    separator2->setFrameShape(QFrame::HLine);
    separator2->setFrameShadow(QFrame::Sunken);
    vBox->addWidget(separator2);

    vBox->addWidget(new QLabel("Site"));
    vBox->addSpacing(3);

    QLineEdit* site = new QLineEdit();
    site->setReadOnly(true);
    site->setText(QString::fromStdString(login.getSite()));
    vBox->addWidget(site);

    vBox->addSpacing(5);
}

void InfoItemVisitor::visit(const Card& card) {
    showCommonFields(card);

    vBox->addWidget(new QLabel("Holder Name"));
    vBox->addSpacing(3);

    QLineEdit* holderName = new QLineEdit();
    holderName->setReadOnly(true);
    holderName->setText(QString::fromStdString(card.getHolderName()));
    vBox->addWidget(holderName);

    vBox->addSpacing(5);

    QFrame* separator = new QFrame;
    separator->setFrameShape(QFrame::HLine);
    separator->setFrameShadow(QFrame::Sunken);
    vBox->addWidget(separator);

    vBox->addWidget(new QLabel("Number"));
    vBox->addSpacing(3);

    QLineEdit* number = new QLineEdit();
    number->setReadOnly(true);
    number->setText(QString::fromStdString(card.getNumber()));
    vBox->addWidget(number);

    vBox->addSpacing(5);

    QFrame* separator2 = new QFrame;
    separator2->setFrameShape(QFrame::HLine);
    separator2->setFrameShadow(QFrame::Sunken);
    vBox->addWidget(separator2);

    vBox->addWidget(new QLabel("Expiration Date"));
    vBox->addSpacing(3);

    QLineEdit* exp_date = new QLineEdit();
    exp_date->setReadOnly(true);
    exp_date->setText(QString::fromStdString(card.getExpDate()));
    vBox->addWidget(exp_date);

    vBox->addSpacing(5);

    QFrame* separator3 = new QFrame;
    separator3->setFrameShape(QFrame::HLine);
    separator3->setFrameShadow(QFrame::Sunken);
    vBox->addWidget(separator3);

    vBox->addWidget(new QLabel("CVV"));
    vBox->addSpacing(3);

    QLineEdit* cvv = new QLineEdit();
    cvv->setReadOnly(true);
    cvv->setText(QString::fromStdString(card.getCVV()));
    vBox->addWidget(cvv);

    vBox->addSpacing(5);
}

void InfoItemVisitor::visit(const Note& note) {
    showCommonFields(note);

    vBox->addWidget(new QLabel("Text"));
    vBox->addSpacing(3);

    QTextEdit* text = new QTextEdit();
    text->setReadOnly(true);
    text->setText(QString::fromStdString(note.getText()));
    vBox->addWidget(text);

    vBox->addSpacing(5);
}

QWidget* InfoItemVisitor::getWidget() const {
    return widget;
}

QLineEdit* InfoItemVisitor::getPassword() const {
    return password;
}

QPushButton* InfoItemVisitor::getPasswordButton() const {
    return passwordButton;
}




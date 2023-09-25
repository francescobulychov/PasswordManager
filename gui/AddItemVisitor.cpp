#include "AddItemVisitor.h"

#include <QLabel>
#include <QRegularExpression>
#include <QRegularExpressionValidator>

void AddItemVisitor::editCommonFields() {
    widget = new QWidget();

    vBox = new QVBoxLayout(widget);
    vBox->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    vBox->addSpacing(5);

    QFrame* separator = new QFrame;
    separator->setFrameShape(QFrame::HLine);
    separator->setFrameShadow(QFrame::Sunken);
    vBox->addWidget(separator);

    vBox->addWidget(new QLabel("Name"));
    vBox->addSpacing(3);

    name = new QLineEdit();
    vBox->addWidget(name);

    vBox->addSpacing(5);

    QFrame* separator2 = new QFrame;
    separator2->setFrameShape(QFrame::HLine);
    separator2->setFrameShadow(QFrame::Sunken);
    vBox->addWidget(separator2);
}

void AddItemVisitor::visit(const Login& login) {
    Q_UNUSED(login);
    editCommonFields();

    vBox->addWidget(new QLabel("Username"));
    vBox->addSpacing(3);

    username = new QLineEdit();
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

    site = new QLineEdit();
    vBox->addWidget(site);

    vBox->addSpacing(5);
}

void AddItemVisitor::visit(const Card& card) {
    Q_UNUSED(card);
    editCommonFields();

    vBox->addWidget(new QLabel("Holder Name"));
    vBox->addSpacing(3);

    holderName = new QLineEdit();
    vBox->addWidget(holderName);

    vBox->addSpacing(5);

    QFrame* separator = new QFrame;
    separator->setFrameShape(QFrame::HLine);
    separator->setFrameShadow(QFrame::Sunken);
    vBox->addWidget(separator);

    vBox->addWidget(new QLabel("Number"));
    vBox->addSpacing(3);

    number = new QLineEdit();
    vBox->addWidget(number);

    vBox->addSpacing(5);

    QFrame* separator2 = new QFrame;
    separator2->setFrameShape(QFrame::HLine);
    separator2->setFrameShadow(QFrame::Sunken);
    vBox->addWidget(separator2);

    vBox->addWidget(new QLabel("Expiration Date"));
    vBox->addSpacing(3);

    expDate = new QLineEdit();
    expDate->setPlaceholderText("mm/yy");
    QRegularExpression regex("\\d{2}\\s*/\\s*\\d{2}");
    QRegularExpressionValidator* validator = new QRegularExpressionValidator(regex, expDate);
    expDate->setValidator(validator);
    vBox->addWidget(expDate);

    vBox->addSpacing(5);

    QFrame* separator3 = new QFrame;
    separator3->setFrameShape(QFrame::HLine);
    separator3->setFrameShadow(QFrame::Sunken);
    vBox->addWidget(separator3);

    vBox->addWidget(new QLabel("CVV"));
    vBox->addSpacing(3);

    cvv = new QLineEdit();
    vBox->addWidget(cvv);

    vBox->addSpacing(5);
}

void AddItemVisitor::visit(const Note& note) {
    Q_UNUSED(note);
    editCommonFields();

    vBox->addWidget(new QLabel("Text"));
    vBox->addSpacing(3);

    text = new QTextEdit();
    vBox->addWidget(text);

    vBox->addSpacing(5);
}

QWidget* AddItemVisitor::getWidget() const {
    return widget;
}

QLineEdit* AddItemVisitor::getName() const {
    return name;
}

QLineEdit* AddItemVisitor::getUsername() const {
    return username;
}

QLineEdit* AddItemVisitor::getPassword() const {
    return password;
}

QLineEdit* AddItemVisitor::getSite() const {
    return site;
}

QLineEdit* AddItemVisitor::getHolderName() const {
    return holderName;
}

QLineEdit* AddItemVisitor::getNumber() const {
    return number;
}

QLineEdit* AddItemVisitor::getExpDate() const {
    return expDate;
}

QLineEdit* AddItemVisitor::getCVV() const {
    return cvv;
}

QTextEdit* AddItemVisitor::getText() const {
    return text;
}

QPushButton* AddItemVisitor::getPasswordButton() const {
    return passwordButton;
}



#include "EditItemVisitor.h"

#include <QLabel>
#include <QRegularExpression>
#include <QRegularExpressionValidator>

void EditItemVisitor::editCommonFields(const AbstractItem& item) {
    widget = new QWidget();

    vBox = new QVBoxLayout(widget);
    vBox->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    QLabel* titleLabel = new QLabel("EDIT ITEM");
    QFont font;
    font.setPointSize(15);
    titleLabel->setFont(font);
    vBox->addWidget(titleLabel);
    vBox->addSpacing(5);

    vBox->addWidget(new QLabel("Name"));
    vBox->addSpacing(3);

    name = new QLineEdit();
    name->setText(QString::fromStdString(item.getName()));
    vBox->addWidget(name);

    vBox->addSpacing(5);

    QFrame* separator = new QFrame;
    separator->setFrameShape(QFrame::HLine);
    separator->setFrameShadow(QFrame::Sunken);
    vBox->addWidget(separator);
}

void EditItemVisitor::visit(const Login& login) {
    editCommonFields(login);

    vBox->addWidget(new QLabel("Username"));
    vBox->addSpacing(3);

    username = new QLineEdit();
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

    site = new QLineEdit();
    site->setText(QString::fromStdString(login.getSite()));
    vBox->addWidget(site);

    vBox->addSpacing(5);
}

void EditItemVisitor::visit(const Card& card) {
    editCommonFields(card);

    vBox->addWidget(new QLabel("Holder Name"));
    vBox->addSpacing(3);

    holderName = new QLineEdit();
    holderName->setText(QString::fromStdString(card.getHolderName()));
    vBox->addWidget(holderName);

    vBox->addSpacing(5);

    QFrame* separator = new QFrame;
    separator->setFrameShape(QFrame::HLine);
    separator->setFrameShadow(QFrame::Sunken);
    vBox->addWidget(separator);

    vBox->addWidget(new QLabel("Number"));
    vBox->addSpacing(3);

    number = new QLineEdit();
    number->setText(QString::fromStdString(card.getNumber()));
    vBox->addWidget(number);

    vBox->addSpacing(5);

    QFrame* separator2 = new QFrame;
    separator2->setFrameShape(QFrame::HLine);
    separator2->setFrameShadow(QFrame::Sunken);
    vBox->addWidget(separator2);

    vBox->addWidget(new QLabel("Expiration Date"));
    vBox->addSpacing(3);

    expDate = new QLineEdit();
    expDate->setText(QString::fromStdString(card.getExpDate()));
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
    cvv->setText(QString::fromStdString(card.getCVV()));
    vBox->addWidget(cvv);

    vBox->addSpacing(5);
}

void EditItemVisitor::visit(const Note& note) {
    editCommonFields(note);

    vBox->addWidget(new QLabel("Text"));
    vBox->addSpacing(3);

    text = new QTextEdit();
    text->setText(QString::fromStdString(note.getText()));
    vBox->addWidget(text);

    vBox->addSpacing(5);
}

QWidget* EditItemVisitor::getWidget() const {
    return widget;
}

QLineEdit* EditItemVisitor::getName() const {
    return name;
}

QLineEdit* EditItemVisitor::getUsername() const {
    return username;
}

QLineEdit* EditItemVisitor::getPassword() const {
    return password;
}

QLineEdit* EditItemVisitor::getSite() const {
    return site;
}

QLineEdit* EditItemVisitor::getHolderName() const {
    return holderName;
}

QLineEdit* EditItemVisitor::getNumber() const {
    return number;
}

QLineEdit* EditItemVisitor::getExpDate() const {
    return expDate;
}

QLineEdit* EditItemVisitor::getCVV() const {
    return cvv;
}

QTextEdit* EditItemVisitor::getText() const {
    return text;
}

QPushButton* EditItemVisitor::getPasswordButton() const {
    return passwordButton;
}



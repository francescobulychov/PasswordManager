#include "AddItemWidget.h"


#include <QScrollArea>
#include <QLabel>

AddItemWidget::AddItemWidget(MainWindow* mainWindow, Container& container, AbstractItem* item, QWidget* parent) : QWidget(parent), mainWindow(mainWindow), container(container), item(item) {

    QVBoxLayout* MainVBox = new QVBoxLayout(this);
    MainVBox->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    QScrollArea* scrollArea = new QScrollArea();
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scrollArea->setWidgetResizable(true);
    MainVBox->addWidget(scrollArea);

    QWidget* widget = new QWidget();
    vBox = new QVBoxLayout(widget);
    vBox->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    QLabel* titleLabel = new QLabel("ADD ITEM");
    QFont font;
    font.setPointSize(15);
    titleLabel->setFont(font);
    vBox->addWidget(titleLabel);

    vBox->addSpacing(5);

    QHBoxLayout* hBox = new QHBoxLayout();
    hBox->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    vBox->addLayout(hBox);

    hBox->addWidget(new QLabel("Type: "));

    comboBox = new QComboBox();
    comboBox->addItem("- Select -");
    comboBox->addItem("Login");
    comboBox->addItem("Card");
    comboBox->addItem("Note");
    connect(comboBox, &QComboBox::currentIndexChanged, this, &AddItemWidget::indexChanged);
    hBox->addWidget(comboBox);

    scrollArea->setWidget(widget);

    QHBoxLayout* hBox2 = new QHBoxLayout();
    hBox2->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    MainVBox->addLayout(hBox2);

    applyButton = new QPushButton(QIcon(QPixmap((":/assets/icons/apply.svg"))), "  Apply");
    connect(applyButton, &QPushButton::clicked, this, &AddItemWidget::apply);
    applyButton->setEnabled(false);
    hBox2->addWidget(applyButton);

    QPushButton* cancelButton = new QPushButton(QIcon(QPixmap((":/assets/icons/cancel.svg"))), "  Cancel");
    connect(cancelButton, &QPushButton::clicked, mainWindow, &MainWindow::showInfoItem);
    hBox2->addWidget(cancelButton);
}

void AddItemWidget::showPassword() {
    if (visitor.getPassword()->echoMode() == QLineEdit::Password) {
        visitor.getPassword()->setEchoMode(QLineEdit::Normal);
        visitor.getPasswordButton()->setIcon(QIcon(QPixmap((":/assets/icons/eye.svg"))));
    }
    else {
        visitor.getPassword()->setEchoMode(QLineEdit::Password);
        visitor.getPasswordButton()->setIcon(QIcon(QPixmap((":/assets/icons/closed_eye.svg"))));

    }
}

void AddItemWidget::cleanVBox() const {
    QLayoutItem* layoutItem;
    while ((layoutItem = vBox->itemAt(3)) != nullptr) {
        vBox->removeItem(layoutItem);
        delete layoutItem->widget();
        delete layoutItem;
    }
}

void AddItemWidget::indexChanged() {
    cleanVBox();

    if (comboBox->currentText() == "Login") {
        item = new Login(container.generateUniqueID());
        item->accept(visitor);
        vBox->addWidget(visitor.getWidget());
        applyButton->setEnabled(true);
        connect(visitor.getPasswordButton(), &QPushButton::clicked, this, &AddItemWidget::showPassword);

    }
    else if (comboBox->currentText() == "Card") {
        item = new Card(container.generateUniqueID());
        item->accept(visitor);
        vBox->addWidget(visitor.getWidget());
        applyButton->setEnabled(true);
    }
    else if (comboBox->currentText() == "Note") {
        item = new Note(container.generateUniqueID());
        item->accept(visitor);
        vBox->addWidget(visitor.getWidget());
        applyButton->setEnabled(true);
    }
    else
        applyButton->setEnabled(false);
}

void AddItemWidget::apply() {
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

    container.insert(item);

    mainWindow->showItems();
}

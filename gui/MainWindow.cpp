#include "MainWindow.h"
#include "../core/AbstractItem.h"
#include "../core/Login.h"
#include "../core/Card.h"
#include "../core/Note.h"
#include "../core/xml/XmlStream.h"
#include "InfoItemWidget.h"
#include "EditItemWidget.h"
#include "AddItemWidget.h"

#include <QApplication>
#include <QSplitter>
#include <QFileDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QMessageBox>

MainWindow::MainWindow(Container& container, QWidget* parent) : QMainWindow(parent), container(container) {

    resize(730,550);

    createMenu();
    createToolBar();

    QSplitter* splitter = new QSplitter(this);
    setCentralWidget(splitter);

    splitter->addWidget(ItemListWidget());

    stackedWidget = new QStackedWidget(this);
    splitter->addWidget(stackedWidget);

    splitter->setSizes(QList<int>() << 1000 << 2000);
    splitter->setCollapsible(0, false);
    splitter->setCollapsible(1, false);
}

void MainWindow::createMenu() {
    fileMenu = menuBar()->addMenu("File");

    fileMenu->addAction(new QAction("New", fileMenu));
    fileMenu->actions().at(0)->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_N));
    connect(fileMenu->actions().at(0), &QAction::triggered, this, &MainWindow::createFile);

    fileMenu->addAction(new QAction("Open", fileMenu));
    fileMenu->actions().at(1)->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_O));
    connect(fileMenu->actions().at(1), &QAction::triggered, this, &MainWindow::openFile);

    fileMenu->addAction(new QAction("Save", fileMenu));
    fileMenu->actions().at(2)->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_S));
    connect(fileMenu->actions().at(2), &QAction::triggered, this, &MainWindow::saveFile);
    fileMenu->actions().at(2)->setEnabled(false);

    fileMenu->addAction(new QAction("Save As", fileMenu));
    fileMenu->actions().at(3)->setShortcut(QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_S));
    connect(fileMenu->actions().at(3), &QAction::triggered, this, &MainWindow::saveFileAs);
    fileMenu->actions().at(3)->setEnabled(false);

    fileMenu->addSeparator();

    fileMenu->addAction(new QAction("Quit", fileMenu));
    fileMenu->actions().at(5)->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_Q));
    connect(fileMenu->actions().at(5), &QAction::triggered, this, &QApplication::quit);
}

void MainWindow::createToolBar() {
    toolBar = addToolBar("ToolBar");
    toolBar->setMovable(false);

    toolBar->addAction(new QAction(QIcon(QPixmap((":/assets/icons/new.svg"))), "New"));
    connect(toolBar->actions().at(0), &QAction::triggered, this, &MainWindow::createFile);

    toolBar->addAction(new QAction(QIcon(QPixmap((":/assets/icons/open.svg"))), "Open"));
    connect(toolBar->actions().at(1), &QAction::triggered, this, &MainWindow::openFile);

    toolBar->addAction(new QAction(QIcon(QPixmap((":/assets/icons/save.svg"))), "Save"));
    connect(toolBar->actions().at(2), &QAction::triggered, this, &MainWindow::saveFile);
    toolBar->actions().at(2)->setEnabled(false);

    toolBar->addAction(new QAction(QIcon(QPixmap((":/assets/icons/save_as.svg"))), "Save As"));
    connect(toolBar->actions().at(3), &QAction::triggered, this, &MainWindow::saveFileAs);
    toolBar->actions().at(3)->setEnabled(false);
}

QWidget* MainWindow::ItemListWidget() {
    QWidget* widget = new QWidget(this);

    QVBoxLayout* vBox = new QVBoxLayout(widget);
    vBox->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    QHBoxLayout* hBox = new QHBoxLayout();
    hBox->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    vBox->addLayout(hBox);

    QPushButton* searchIcon = new QPushButton(QIcon(QPixmap((":/assets/icons/search.svg"))), "");
    searchIcon->setFlat(true);
    searchIcon->setStyleSheet("QPushButton{border: 0px;}");
    hBox->addWidget(searchIcon);

    searchBar = new QLineEdit();
    connect(searchBar, &QLineEdit::textChanged, this, &MainWindow::showItems);
    searchBar->setPlaceholderText("Search by name...");
    hBox->addWidget(searchBar);

    vBox->addSpacing(5);

    listWidget = new QListWidget();
    vBox->addWidget(listWidget);
    connect(listWidget, &QListWidget::itemSelectionChanged, this, &MainWindow::showInfoItem);

    addItemButton = new QPushButton(QIcon(QPixmap((":/assets/icons/add.svg"))), "  Add Item");
    connect(addItemButton, &QPushButton::clicked, this, &MainWindow::addItem);
    addItemButton->setEnabled(false);
    vBox->addWidget(addItemButton);

    return widget;
}

void MainWindow::showItems() {
    listWidget->clearSelection();
    clearStack();

    listWidget->clear();

    Container searchedList = container.searchByName(searchBar->text().toStdString());
    for(Container::Iterator it = searchedList.begin(); it != searchedList.end(); ++it) {

        QListWidgetItem* item = new QListWidgetItem(it->getName().c_str());

        if (dynamic_cast<Login*>(*it) != nullptr)
            item->setIcon(QIcon(QPixmap((":/assets/icons/login.svg"))));
        else if (dynamic_cast<Card*>(*it) != nullptr)
            item->setIcon(QIcon(QPixmap((":/assets/icons/card.svg"))));
        else if (dynamic_cast<Note*>(*it) != nullptr)
            item->setIcon(QIcon(QPixmap((":/assets/icons/note.svg"))));

        item->setData(Qt::UserRole, it->getID());
        listWidget->addItem(item);
    }
}

void MainWindow::clearStack() {
    while (stackedWidget->count() > 0) {
        QWidget* Widget = stackedWidget->widget(0);
        stackedWidget->removeWidget(Widget);
        delete Widget;
    }
}

void MainWindow::showInfoItem() {
    clearStack();

    if (listWidget->currentItem() != nullptr) {
        QListWidgetItem* listItem = listWidget->currentItem();
        int currentID = listItem->data(Qt::UserRole).toInt();
        AbstractItem* item = container.getByID(currentID);

        InfoItemWidget* infoWidget = new InfoItemWidget(this, item);

        stackedWidget->addWidget(infoWidget);
        stackedWidget->setCurrentIndex(0);
    }
}

void MainWindow::editItem() {
    clearStack();

    QListWidgetItem* listItem = listWidget->currentItem();
    int currentID = listItem->data(Qt::UserRole).toInt();
    AbstractItem* item = container.getByID(currentID);

    EditItemWidget* editWidget = new EditItemWidget(this, item);

    stackedWidget->addWidget(editWidget);
    stackedWidget->setCurrentIndex(0);

}

void MainWindow::addItem() {

    listWidget->clearSelection();
    listWidget->setCurrentItem(nullptr);
    clearStack();

    AbstractItem* item = nullptr;
    AddItemWidget* addWidget = new AddItemWidget(this, container, item);

    stackedWidget->addWidget(addWidget);
    stackedWidget->setCurrentIndex(0);
}

void MainWindow::removeItem() {

    listWidget->clearSelection();
    clearStack();

    QListWidgetItem* listItem = listWidget->currentItem();
    int currentID = listItem->data(Qt::UserRole).toInt();

    container.removeByID(currentID);

    showItems();
}

void MainWindow::createFile() {
    listWidget->clearSelection();
    clearStack();

    path = QFileDialog::getSaveFileName(this, "Create new file", "./", "XML files *.xml");
    if (path.isEmpty()) return;

    container.clear();
    XmlStream::saveData(container, path.toStdString());

    fileMenu->actions().at(2)->setEnabled(true);
    fileMenu->actions().at(3)->setEnabled(true);
    toolBar->actions().at(2)->setEnabled(true);
    toolBar->actions().at(3)->setEnabled(true);
    addItemButton->setEnabled(true);

    showItems();
}

void MainWindow::openFile() {
    listWidget->clearSelection();
    clearStack();

    path = QFileDialog::getOpenFileName(this, "Open file", "./", "XML files *.xml");
    if (path.isEmpty()) return;

    container.clear();

    if (XmlStream::loadData(container, path.toStdString()) == true) {
        fileMenu->actions().at(2)->setEnabled(true);
        fileMenu->actions().at(3)->setEnabled(true);
        toolBar->actions().at(2)->setEnabled(true);
        toolBar->actions().at(3)->setEnabled(true);
        addItemButton->setEnabled(true);
    }
    else {
        fileMenu->actions().at(2)->setEnabled(false);
        fileMenu->actions().at(3)->setEnabled(false);
        toolBar->actions().at(2)->setEnabled(false);
        toolBar->actions().at(3)->setEnabled(false);
        addItemButton->setEnabled(false);

        QMessageBox::critical(nullptr, "Error", "An error occurred while reading the file.", QMessageBox::Ok);
    }

    showItems();
}

void MainWindow::saveFile() {
    XmlStream::saveData(container, path.toStdString());
}

void MainWindow::saveFileAs() {
    path = QFileDialog::getSaveFileName(this, "Create new file", "./", "XML files *.xml");
    if (path.isEmpty()) return;

    XmlStream::saveData(container, path.toStdString());
}


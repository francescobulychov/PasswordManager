#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../utils/Container.h"

#include <QMainWindow>
#include <QMenuBar>
#include <QToolBar>
#include <QListWidget>
#include <QPushButton>
#include <QStackedWidget>

class MainWindow : public QMainWindow {
    Q_OBJECT

private:
    Container& container;
    QMenu* fileMenu;
    void createMenu();
    QToolBar* toolBar;
    void createToolBar();
    QListWidget* listWidget;
    QLineEdit* searchBar;
    QPushButton* addItemButton;
    QWidget* ItemListWidget();
    QStackedWidget* stackedWidget;
    QString path;

public:
    explicit MainWindow(Container& container, QWidget* parent = nullptr);

public slots:
    void showItems();
    void clearStack();
    void showInfoItem();
    void editItem();
    void addItem();
    void removeItem();
    void createFile();
    void openFile();
    void saveFile();
    void saveFileAs();
};

#endif

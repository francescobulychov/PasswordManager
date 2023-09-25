#ifndef ADDITEMWIDGET_H
#define ADDITEMWIDGET_H

#include "MainWindow.h"
#include "AddItemVisitor.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QComboBox>

class AddItemWidget : public QWidget {
    Q_OBJECT

private:
    MainWindow* mainWindow;
    Container& container;
    AbstractItem* item;
    AddItemVisitor visitor;
    QVBoxLayout* vBox;
    void cleanVBox() const;
    QComboBox* comboBox;
    QPushButton* applyButton;


public:
    AddItemWidget(MainWindow* mainWindow, Container& container, AbstractItem* item, QWidget* parent = nullptr);

private slots:
    void showPassword();
    void indexChanged();
    void apply();
};

#endif

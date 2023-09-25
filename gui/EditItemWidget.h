#ifndef EDITITEMWIDGET_H
#define EDITITEMWIDGET_H

#include "MainWindow.h"
#include "EditItemVisitor.h"

#include <QWidget>

class EditItemWidget : public QWidget {
    Q_OBJECT

private:
    MainWindow* mainWindow;
    AbstractItem* item;
    EditItemVisitor visitor;

public:
    explicit EditItemWidget(MainWindow* mainWindow, AbstractItem* item, QWidget* parent = nullptr);

private slots:
    void apply();
    void showPassword();
};

#endif

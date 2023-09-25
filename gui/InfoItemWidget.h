#ifndef INFOITEMWIDGET_H
#define INFOITEMWIDGET_H

#include "MainWindow.h"
#include "InfoItemVisitor.h"

#include <QWidget>

class InfoItemWidget : public QWidget {
    Q_OBJECT

private:
    MainWindow* mainWindow;
    AbstractItem* item;
    InfoItemVisitor visitor;

public:
    explicit InfoItemWidget(MainWindow* mainWindow, AbstractItem* item, QWidget* parent = nullptr);

private slots:
    void showPassword();
};

#endif

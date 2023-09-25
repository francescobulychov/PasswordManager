#include "gui/MainWindow.h"

#include <QApplication>

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);
    app.setWindowIcon(QIcon(QPixmap((":/assets/icons/key.svg"))));

    Container container;
    MainWindow window(container);
    window.show();

    return app.exec();
}

#include "UI/GetDollarUI.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    GetDollarUI window;
    window.show();
    return app.exec();
}

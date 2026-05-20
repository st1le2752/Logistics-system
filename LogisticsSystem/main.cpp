#include "LogisticsSystem.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    LogisticsSystem window;
    window.show();
    return app.exec();
}

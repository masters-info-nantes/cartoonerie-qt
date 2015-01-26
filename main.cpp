#include <QApplication>

#include "welcome.h"

int main(int argc, char** argv){
    QApplication app(argc, argv);
    Welcome welcome;
    welcome.show();
    return app.exec();
}


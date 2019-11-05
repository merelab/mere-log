#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication::setApplicationName("Mere Log");
    QCoreApplication::setApplicationVersion("0.0.1b");

    QCoreApplication app(argc, argv);

    return app.exec();
}

//qApp->installLogger(logger);
//qApp->looger()->log();

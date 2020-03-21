#include <QCoreApplication>

#include "mere/log/merelogger.h"
#include "mere/log/merelogfactory.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setApplicationName("Mere Log");
    QCoreApplication::setApplicationVersion("0.0.1b");

    QCoreApplication app(argc, argv);


    MereLogger *logger = MereLogFactory::logger();
    logger->info("about me!");
    logger->debug("about me! debug");

    return app.exec();
}

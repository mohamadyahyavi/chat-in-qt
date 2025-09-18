<<<<<<< HEAD
#include <QCoreApplication>
#include <QTcpServer>
#include <QTcpSocket>
#include <QThread>
#include <QDebug>
#include "clienthandler.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Create the TCP server
    QTcpServer server;

    // When a new client connects
    QObject::connect(&server, &QTcpServer::newConnection, [&server]() {
        QTcpSocket *clientSocket = server.nextPendingConnection();

        // Create a handler for this client
        ClientHandler *handler = new ClientHandler(clientSocket);
        QThread *thread = new QThread;

        // Move the handler to the new thread
        handler->moveToThread(thread);

        // Connect thread start to handler start
        QObject::connect(thread, &QThread::started, handler, &ClientHandler::start);

        // Cleanup when client disconnects
        QObject::connect(handler, &ClientHandler::finished, thread, &QThread::quit);
        QObject::connect(handler, &ClientHandler::finished, handler, &ClientHandler::deleteLater);
        QObject::connect(thread, &QThread::finished, thread, &QThread::deleteLater);

        // Start the thread
        thread->start();
    });

    // Start listening on port 1234
    if (!server.listen(QHostAddress::Any, 1234)) {
        qDebug() << "Server failed to start!";
        return 1;
    }

    qDebug() << "Server started on port 1234";

    return a.exec();
}

=======
#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
>>>>>>> 44c820c0cd4829b4cbd1ca3039dab8643aa35f5f

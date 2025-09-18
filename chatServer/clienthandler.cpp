#include "clienthandler.h"
#include <QDebug>

ClientHandler::ClientHandler(QTcpSocket *socket, QObject *parent)
    : QObject(parent), clientSocket(socket)
{
    connect(clientSocket, &QTcpSocket::readyRead, this, &ClientHandler::readyRead);
    connect(clientSocket, &QTcpSocket::disconnected, this, &ClientHandler::disconnected);
}

// Called when the thread starts
void ClientHandler::start()
{
    qDebug() << "Client connected:" << clientSocket->peerAddress().toString();
}

// Called when client sends data
void ClientHandler::readyRead()
{
    QByteArray data = clientSocket->readAll();
    qDebug() << "Received:" << data;

    // Echo back to client
    clientSocket->write("Server received: " + data);
}

// Called when client disconnects
void ClientHandler::disconnected()
{
    qDebug() << "Client disconnected:" << clientSocket->peerAddress().toString();
    clientSocket->deleteLater();
    emit finished();
}

#ifndef CLIENTHANDLER_H
#define CLIENTHANDLER_H

#include <QObject>
#include <QTcpSocket>
#include <QThread>

class ClientHandler : public QObject
{
    Q_OBJECT
public:
    explicit ClientHandler(QTcpSocket *socket, QObject *parent = nullptr);

signals:
    void finished();  // Emitted when client disconnects

public slots:
    void start();          // Called when thread starts
    void readyRead();      // Called when client sends data
    void disconnected();   // Called when client disconnects

private:
    QTcpSocket *clientSocket;  // Socket for this client
};

#endif // CLIENTHANDLER_H

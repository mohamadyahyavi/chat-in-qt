#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QHostAddress>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , socket(new QTcpSocket(this))
{
    ui->setupUi(this);

    // Connect socket signals to our slots
    connect(socket, &QTcpSocket::readyRead, this, &MainWindow::readMessage);
    connect(socket, &QTcpSocket::connected, this, [this]() {
        ui->chatHistory->append("✅ Connected to server.");
    });
    connect(socket, &QTcpSocket::disconnected, this, [this]() {
        ui->chatHistory->append("❌ Disconnected from server.");
    });

    // Try to connect to server
    socket->connectToHost(QHostAddress::LocalHost, 1234);

    // Send button action
    connect(ui->sendButton, &QPushButton::clicked, this, &MainWindow::on_sendButton_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Slot: send message to server
void MainWindow::on_sendButton_clicked()
{
    QString message = ui->messageInput->text().trimmed();
    if (!message.isEmpty() && socket->state() == QAbstractSocket::ConnectedState) {
        socket->write(message.toUtf8());              // Send to server
        socket->flush();
        ui->chatHistory->append("Me: " + message);    // Show in chat history
        ui->messageInput->clear();                    // Clear input
    }
}

// Slot: read incoming messages from server
void MainWindow::readMessage()
{
    while (socket->bytesAvailable() > 0) {
        QByteArray data = socket->readAll();
        ui->chatHistory->append("Server: " + QString::fromUtf8(data));
    }
}

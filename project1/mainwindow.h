#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_sendButton_clicked();  // Slot for send button
    void readMessage();            // Slot to handle incoming messages

private:
    Ui::MainWindow *ui;
    QTcpSocket *socket;            // TCP socket for client
};

#endif // MAINWINDOW_H

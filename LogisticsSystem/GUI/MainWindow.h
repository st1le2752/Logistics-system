#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QTextEdit>
#include <QLineEdit>
#include <QLabel>
#include "../Core/Services/Server.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private:
    QWidget* centralWidget;
    QVBoxLayout* mainLayout;
    QLabel* weightLabel;
    QLineEdit* weightInput;
    QLabel* distanceLabel;
    QLineEdit* distanceInput;
    QPushButton* createOrderBtn;
    QTextEdit* logConsole;

    Server* server;

private slots:
    void handleCreateOrder();
};

#endif
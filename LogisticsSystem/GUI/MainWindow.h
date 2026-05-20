#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QTextEdit>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private:
    QWidget* centralWidget;
    QVBoxLayout* mainLayout;
    QPushButton* createOrderBtn;
    QTextEdit* logConsole;

private slots:
    void handleCreateOrder();
};

#endif
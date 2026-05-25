#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>
#include <QTextEdit>
#include <QLineEdit>
#include <QLabel>
#include "AppInterface.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private:
    QWidget* centralWidget;
    QVBoxLayout* mainLayout;

    QHBoxLayout* inputLayout;
    QLabel* weightLabel;
    QLineEdit* weightInput;
    QLabel* distanceLabel;
    QLineEdit* distanceInput;
    QPushButton* createOrderBtn;

    QPushButton* simulateStepBtn;

    QHBoxLayout* pdfLayout;
    QLabel* orderIdLabel;
    QLineEdit* orderIdInput;
    QPushButton* generatePdfBtn;

    QTextEdit* logConsole;

    AppInterface* appInterface;

private slots:
    void handleCreateOrder();
    void handleSimulateStep();
    void handleGeneratePdf();
};

#endif
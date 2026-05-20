#include "MainWindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
    setWindowTitle("Cargo Logistics System");
    resize(800, 600);

    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    mainLayout = new QVBoxLayout(centralWidget);

    createOrderBtn = new QPushButton("Create New Order", this);
    mainLayout->addWidget(createOrderBtn);

    logConsole = new QTextEdit(this);
    logConsole->setReadOnly(true);
    mainLayout->addWidget(logConsole);

    connect(createOrderBtn, &QPushButton::clicked, this, &MainWindow::handleCreateOrder);
}

MainWindow::~MainWindow() {
}

void MainWindow::handleCreateOrder() {
    logConsole->append("System initialized");
}
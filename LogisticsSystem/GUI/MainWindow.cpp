#include "MainWindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
    setWindowTitle("Cargo Logistics System");
    resize(800, 600);

    server = new Server();

    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    mainLayout = new QVBoxLayout(centralWidget);

    weightLabel = new QLabel("Weight (kg):", this);
    mainLayout->addWidget(weightLabel);

    weightInput = new QLineEdit("100", this);
    mainLayout->addWidget(weightInput);

    distanceLabel = new QLabel("Distance (km):", this);
    mainLayout->addWidget(distanceLabel);

    distanceInput = new QLineEdit("50", this);
    mainLayout->addWidget(distanceInput);

    createOrderBtn = new QPushButton("Create New Order", this);
    mainLayout->addWidget(createOrderBtn);

    logConsole = new QTextEdit(this);
    logConsole->setReadOnly(true);
    mainLayout->addWidget(logConsole);

    connect(createOrderBtn, &QPushButton::clicked, this, &MainWindow::handleCreateOrder);
}

MainWindow::~MainWindow() {
    delete server;
}

void MainWindow::handleCreateOrder() {
    bool weightOk, distanceOk;
    double weight = weightInput->text().toDouble(&weightOk);
    double distance = distanceInput->text().toDouble(&distanceOk);

    if (weightOk && distanceOk) {
        std::string response = server->processNewOrderRequest(weight, distance);
        logConsole->append(QString::fromStdString(response));
    }
    else {
        logConsole->append("Error: Invalid input for weight or distance.");
    }
}
#include "MainWindow.h"
#include <QString>
#include <vector>

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

    simulateStepBtn = new QPushButton("Simulate Movement Step (+25%)", this);
    mainLayout->addWidget(simulateStepBtn);

    logConsole = new QTextEdit(this);
    logConsole->setReadOnly(true);
    mainLayout->addWidget(logConsole);

    connect(createOrderBtn, &QPushButton::clicked, this, &MainWindow::handleCreateOrder);
    connect(simulateStepBtn, &QPushButton::clicked, this, &MainWindow::handleSimulateStep);
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

void MainWindow::handleSimulateStep() {
    server->simulateSimulationStep();
    std::vector<std::string> notifications = server->getNotifications();

    if (notifications.empty()) {
        logConsole->append("Simulation step: No active movements or already delivered.");
    }
    else {
        for (const std::string& msg : notifications) {
            logConsole->append(QString::fromStdString(">> " + msg));
        }
    }
}
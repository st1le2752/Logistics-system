#include "MainWindow.h"
#include <QString>
#include <vector>
#include <QPdfWriter>
#include <QPainter>
#include <QDir>
#include <QCoreApplication>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
    setWindowTitle("Cargo Logistics System");
    resize(800, 600);

    appInterface = new AppInterface();

    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    mainLayout = new QVBoxLayout(centralWidget);

    inputLayout = new QHBoxLayout();
    weightLabel = new QLabel("Weight (kg):", this);
    weightInput = new QLineEdit("100", this);
    distanceLabel = new QLabel("Distance (km):", this);
    distanceInput = new QLineEdit("50", this);
    createOrderBtn = new QPushButton("Create Order", this);

    inputLayout->addWidget(weightLabel);
    inputLayout->addWidget(weightInput);
    inputLayout->addWidget(distanceLabel);
    inputLayout->addWidget(distanceInput);
    inputLayout->addWidget(createOrderBtn);
    mainLayout->addLayout(inputLayout);

    simulateStepBtn = new QPushButton("Simulate Movement Step (+25%)", this);
    mainLayout->addWidget(simulateStepBtn);

    pdfLayout = new QHBoxLayout();
    orderIdLabel = new QLabel("Order ID:", this);
    orderIdInput = new QLineEdit("1", this);
    generatePdfBtn = new QPushButton("Generate Waybill PDF", this);

    pdfLayout->addWidget(orderIdLabel);
    pdfLayout->addWidget(orderIdInput);
    pdfLayout->addWidget(generatePdfBtn);
    mainLayout->addLayout(pdfLayout);

    logConsole = new QTextEdit(this);
    logConsole->setReadOnly(true);
    mainLayout->addWidget(logConsole);

    connect(createOrderBtn, &QPushButton::clicked, this, &MainWindow::handleCreateOrder);
    connect(simulateStepBtn, &QPushButton::clicked, this, &MainWindow::handleSimulateStep);
    connect(generatePdfBtn, &QPushButton::clicked, this, &MainWindow::handleGeneratePdf);
}

MainWindow::~MainWindow() {
    delete appInterface;
}

void MainWindow::handleCreateOrder() {
    bool weightOk, distanceOk;
    double weight = weightInput->text().toDouble(&weightOk);
    double distance = distanceInput->text().toDouble(&distanceOk);

    if (weightOk && distanceOk) {
        std::string response = appInterface->createOrder(weight, distance);
        logConsole->append(QString::fromStdString(response));
    }
    else {
        logConsole->append("Error: Invalid input for weight or distance.");
    }
}

void MainWindow::handleSimulateStep() {
    appInterface->stepSimulation();
    std::vector<std::string> notifications = appInterface->getSystemMessages();

    if (notifications.empty()) {
        logConsole->append("Simulation step: No active movements or already delivered.");
    }
    else {
        for (const std::string& msg : notifications) {
            logConsole->append(QString::fromStdString(">> " + msg));
        }
    }
}

void MainWindow::handleGeneratePdf() {
    bool ok;
    int orderId = orderIdInput->text().toInt(&ok);

    if (!ok) {
        logConsole->append("Error: Invalid Order ID.");
        return;
    }

    std::string docText = appInterface->getOrderReport(orderId);

    if (docText.empty()) {
        logConsole->append("Error: Order not found.");
        return;
    }

    QString fileName = "Waybill_Order_" + QString::number(orderId) + ".pdf";
    QString filePath = QCoreApplication::applicationDirPath() + "/" + fileName;

    QPdfWriter writer(filePath);
    QPainter painter(&writer);

    QRect rect(100, 100, 9000, 9000);
    painter.drawText(rect, Qt::AlignTop | Qt::AlignLeft, QString::fromStdString(docText));
    painter.end();

    logConsole->append("PDF Generated successfully at: " + filePath);
}
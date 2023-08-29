#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "httprequest.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    HttpRequest httpRequest;

    std::string url = "https://api.exchangerate.host/symbols";
    std::string response;

    bool success = httpRequest.makeGetRequest(url, response);

    if (success) {
        //std::cout << "Request successful! Response:\n" << response << std::endl;

        nlohmann::json data = nlohmann::json::parse(response);

        for (const auto& [key, value] : data["symbols"].items()) {
            std::cout << "Key: " << key << ", Value: " << value << std::endl;
            ui->fromBox->addItem(QString::fromStdString(key));
            ui->toBox->addItem(QString::fromStdString(key));
        }

    } else {
        std::cout << "Request failed." << std::endl;


    }


}

MainWindow::~MainWindow()
{
    delete ui;
}


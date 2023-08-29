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
        std::cout << "Request successful! Response:\n" << response << std::endl;
    } else {
        std::cout << "Request failed." << std::endl;
    }


}

MainWindow::~MainWindow()
{
    delete ui;
}


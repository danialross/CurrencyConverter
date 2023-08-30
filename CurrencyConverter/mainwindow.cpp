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
    nlohmann::json response = httpRequest.makeGetRequest(url);

    if (!response.empty()) {
        //std::cout << "Request successful! Response:\n" << response << std::endl;

        for (const auto& [key, value] : response["symbols"].items()) {
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


void MainWindow::on_swapButton_clicked()
{
    if(ui->fromBox->currentIndex() != -1 && ui->toBox->currentIndex() != -1){

        int from = ui->fromBox->currentIndex();
        int to = ui->toBox->currentIndex();

        ui->fromBox->setCurrentIndex(to);
        ui->toBox->setCurrentIndex(from);

    }
}


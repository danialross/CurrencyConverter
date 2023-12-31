#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "httprequest.h"
#include <QValidator>
#include <QRegularExpression>
#include <QRegularExpressionValidator>>

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

    // Create a regular expression that allows only digits (0-9) an optional . then
    QRegularExpression rx("[0-9]*\\.?[0-9]+");

    // Create a validator with the regular expression
    QValidator* validator = new QRegularExpressionValidator(rx, ui->input);

    // Set the validator for the QLineEdit
    ui->input->setValidator(validator);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_swapButton_clicked()
{

    int from = ui->fromBox->currentIndex();
    int to = ui->toBox->currentIndex();

    ui->fromBox->setCurrentIndex(to);
    ui->toBox->setCurrentIndex(from);
    ui->output->setText("");
}


void MainWindow::on_convertButton_clicked()
{
    if(!ui->input->text().isEmpty()){

        HttpRequest httpRequest;

        std::string from = ui->fromBox->currentText().toStdString();
        std::string to = ui->toBox->currentText().toStdString();

        std::string url = "https://api.exchangerate.host/convert?from=" + from + "&to=" + to;
        nlohmann::json response = httpRequest.makeGetRequest(url);

        if (!response.empty()) {
            //std::cout << "Request successful! Response:\n" << response << std::endl;

            double input = ui->input->text().toDouble();
            double rate = response["info"]["rate"].get<double>();

            ui->output->setText(QString::number(input * rate));

            std::cout << from << std::endl;
            std::cout << to << std::endl;
            std::cout <<"rate : " << response["info"]["rate"] << std::endl;
            std::cout << ui->input->text().toStdString() << std::endl;
            std::cout << input << std::endl;

        } else {
            std::cout << "Request failed." << std::endl;
        }
    }else{
        std::cout << "input is empty" << std::endl;
    }
}

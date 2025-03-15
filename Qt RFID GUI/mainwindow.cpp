#include <QNetworkReply>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , manager(new QNetworkAccessManager(this))
    , model(new QStandardItemModel(this))
    , timer(new QTimer(this))
{
    ui->setupUi(this);
     setWindowTitle("Access Control Dashboard");

    // Tablo Ayarları
    model->setHorizontalHeaderLabels({"Zaman", "RFID", "Çalışan"});
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // Timer Ayarları (2 saniyede bir)
    timer->setInterval(2000);
    connect(timer, &QTimer::timeout, this, &MainWindow::fetchData);
    timer->start();

    // Ağ İsteği Bağlantısı
    connect(manager, &QNetworkAccessManager::finished, this, &MainWindow::onDataReceived);
}

void MainWindow::fetchData() {
    QUrl url("http://192.168.1.10/data"); // ESP IP'nizi girin
    manager->get(QNetworkRequest(url));
}

void MainWindow::onDataReceived(QNetworkReply *reply) {
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray data = reply->readAll();
        QJsonDocument doc = QJsonDocument::fromJson(data);
        QJsonObject json = doc.object();

        // Sıcaklık/Nem
        double temp = json["temperature"].toDouble();
        double hum = json["humidity"].toDouble();
        ui->lblTemperature->setText(QString::number(temp, 'f', 1) + " °C");
        ui->lblHumidity->setText(QString::number(hum, 'f', 1) + " %");

        // RFID
        QString uid = json["rfid"].toString().trimmed().toLower();
        if (uid != "none") {
            QString employee = "Antonio Vivaldi";
            if (uid == "59 ff 00 b9") employee = "Antonio Vivaldi";
            else if (uid == "85 b0 6d 9e") employee = "Ludwig van Beethoven";

            QList<QStandardItem*> row;
            row << new QStandardItem(QDateTime::currentDateTime().toString("dd.MM.yyyy HH:mm:ss"))
                << new QStandardItem(uid)
                << new QStandardItem(employee);
            model->insertRow(0, row);
        }
    }
    reply->deleteLater();
}

MainWindow::~MainWindow() {
    delete ui;
}

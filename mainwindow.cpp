#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , port(new Serial(this))
{
    ui->setupUi(this);
    connect(ui->ui_SendMesssageButton, SIGNAL(released()), this, SLOT(onClicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SendMessage() const
{
    QString text = ui->ui_SendMessageBox->toPlainText();
    port->SendData(text);
}

void MainWindow::onClicked()
{
    SendMessage();
}

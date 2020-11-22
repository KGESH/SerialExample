#include "serial.h"
#include <QEventLoop>


Serial::Serial(QObject *parent)
    : QObject(parent)
    , m_Port(new QSerialPort)
{
    m_Port->setPortName("COM6");
    m_Port->setBaudRate(QSerialPort::Baud9600);
    m_Port->setDataBits(QSerialPort::Data8);
    m_Port->setParity(QSerialPort::NoParity);
    m_Port->setStopBits(QSerialPort::OneStop);
    m_Port->setFlowControl(QSerialPort::NoFlowControl);

    connect(m_Port, SIGNAL(readyRead()), this, SLOT(ReceiveData()));

}


void Serial::ReceiveData()
{
    qDebug() << "resv";
    QByteArray readData;
    readData = m_Port->readAll();
    qDebug() << "data read";
    qDebug() << QString::fromStdString(readData.toStdString());
}


void Serial::SendData(QString& data)
{
    qDebug() << "send";
    CheckSerialPort();
    QByteArray sendData;
    sendData.fromStdString(data.toStdString());
    m_Port->write(sendData);
    m_Port->close();
}


void Serial::CheckSerialPort()
{
    if (!m_Port->open(QIODevice::ReadWrite)){
        qDebug() << "Serial Port Open Error!";
    } else {
        qDebug() << "connect!";
    }
}

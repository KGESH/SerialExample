#ifndef SERIAL_H
#define SERIAL_H

#include <QObject>
#include <QtSerialPort>

class Serial : public QObject
{
    Q_OBJECT
public:
    explicit Serial(QObject *parent = nullptr);
    void SendData(QString& data);


private slots:
    void ReceiveData();


private:
    void CheckSerialPort();
    QSerialPort *m_Port;

};

#endif // SERIAL_H

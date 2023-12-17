//todo: data type matching and split.

#include "serialconnector.h"
SerialConnector* SerialConnector::serialConnector=nullptr;

SerialConnector* SerialConnector::getInstance(QString name, QObject *parent){
    if(SerialConnector::serialConnector==nullptr)
        SerialConnector::serialConnector = new SerialConnector(name, parent);

    qDebug()<<SerialConnector::serialConnector->arduino;

    return SerialConnector::serialConnector;
}

SerialConnector *SerialConnector::getInstance(){
    return SerialConnector::serialConnector;
}

SerialConnector::SerialConnector(QString name, QObject *parent)
    : QObject{parent}{

    arduino = new QSerialPort();
    logFile = new QFile("log.txt");
    timer = new QElapsedTimer;

    //arduino init
    arduino->setPortName(name);
    arduino->setBaudRate(QSerialPort::Baud9600);
    arduino->setDataBits(QSerialPort::Data8);
    arduino->setParity(QSerialPort::NoParity);
    arduino->setStopBits(QSerialPort::OneStop);
    arduino->setFlowControl(QSerialPort::NoFlowControl);

    logFile->open(QIODevice::Append|QIODevice::Text);

    //connection opening
    while(!arduino->open(QSerialPort::ReadWrite)){
        QThread::sleep(1);
        qDebug()<<"error"<<arduino->error()<<"occured while openning serial port, trying again...";
    }
    //arduino->setDataTerminalReady(true);
    qDebug()<<"port opened";
    arduino->flush();
    QObject::connect(arduino,SIGNAL(readyRead()),this,SLOT(gotNewData()));
    QObject::connect(this,SIGNAL(disconnect()),this,SLOT(disconnectForced()));
    QObject::connect(this,SIGNAL(requestSignal()),this,SLOT(requestSlot()));
    qDebug()<<"connector connected";
    QThread::sleep(1);
    QThread::create([&](){
        QThread::sleep(1);
        while(1){
            QThread::sleep(1);
            emit requestSignal();
        }
    })->start();
    QThread::sleep(1);
}

int SerialConnector::writeToChanel(char *data, int64_t size){
    timer->restart();
    int result;
    if(size == -1)
        result = arduino->write(data);
    else
        result = arduino->write(data,size);
    qDebug()<<"Wrote to chanel"<<result<<"bytes:"<<data;
    return result;
}

int SerialConnector::sendRequest(){
    Request data = Request{Types::REQUEST};
    int length = writeToChanel((char*)&data,sizeof(Request));
    return length;
}

template<typename T>
int SerialConnector::writeToChanel(T data){
    timer->restart();
    int result;
    result = arduino->write(&data,sizeof(T));
    qDebug()<<"Wrote to chanel"<<result<<"bytes:"<<data;
    return result;
}

void SerialConnector::forceDisconnect(){
    emit disconnect();
}

void SerialConnector::gotNewData(){
    char* line = new char[44];
    arduino->waitForReadyRead(500);                     //waiting for another 32 byte buffer to come.
    QByteArray ba = arduino->readAll();
    Payload* payload = (Payload*)ba.data();
    QStringList log;
    //
    log<<QDateTime::currentDateTime().toString("[dd-MM-yyyy hh:mm:ss]")
        <<QString::number(payload->numberOfResistors)<<"{";
    for(int i = 0; i<payload->numberOfResistors; i++)
        log<<QString::number(payload->currentValues[i])<<",";
    log<<"};";
    log<<QString::number(payload->usefulVoltage)<<";"
        <<QString::number(payload->usefulAmperage)<<";"
        <<QString::number(payload->ballastVoltage)<<";"
        <<QString::number(payload->ballastAmperage);

    QTextStream ts(logFile);
    for(auto str:log) ts<<str;
    ts<<"\n";
    logFile->flush();

    qDebug()<<log;
}

void SerialConnector::disconnectForced(){
    arduino->close();
    qDebug()<<"connect closed";
}

void SerialConnector::requestSlot(){
    sendRequest();
    arduino->waitForReadyRead(220);
}

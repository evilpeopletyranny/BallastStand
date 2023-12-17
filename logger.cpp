#include "logger.h"

Logger::Logger(QObject *parent)
    : QObject{parent}
{

}

void Logger::logData(Payload* data){
    qDebug()<<"got new payload";
}

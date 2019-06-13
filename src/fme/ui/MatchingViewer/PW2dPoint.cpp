#include <QDebug>

#include "PW2dPoint.h"

PW2dPoint::PW2dPoint(PWPoint::PointType type):
    PWPoint(type)
{
}

PW2dPoint::PW2dPoint(double x, double y, QString name, PWPoint::PointType type):
    PWPoint(type, name),
    QPointF(x, y)
{

}

int PW2dPoint::getCoordsCount()
{
    return 2;
}

double PW2dPoint::getCoord(int index)
{
    if(index>=0 && index <2){
        switch(index){
        case 0:
            return x();
            break;
        case 1:
            return y();
            break;
        default:
            qCritical() << "Index out of bounds";
            return 0;

        }
    }
    qCritical() << "Index out of bounds";
    return 0;
}

QPointF PW2dPoint::getPoint()
{
    return QPointF(x(),y());
}

void PW2dPoint::setCoord(int index, double value)
{
    if(index>=0 && index <2){
        switch(index){
        case 0:
            setX(value);
            break;
        case 1:
            setY(value);
            break;
        default:
            qCritical() << "Index out of bounds";
        }
    }
    else
        qCritical() << "Index out of bounds";
}



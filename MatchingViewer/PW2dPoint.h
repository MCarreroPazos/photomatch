#ifndef PW2DPOINT_H
#define PW2DPOINT_H

#include <QPointF>

#include "PWPoint.h"



class  PW2dPoint : public PWPoint, public QPointF
{
public:
    PW2dPoint(PWPoint::PointType type = PWPoint::Control);
    PW2dPoint(double x, double y, QString name = "", PWPoint::PointType type = PWPoint::Control);

    /*!
     \brief Gets de number of components or dimensions of the point

     \return int
    */
    virtual int getCoordsCount();
    /*!
     \brief Gets the value of a component or coordinate.

     \param index
     \return double
    */
    virtual double getCoord(int index);

    /*!
     \brief Gets the 2d Point.

     \return QPointF
    */
    virtual QPointF getPoint();

    /*!
     \brief Sets the value of a component or coordinate.

     \param index
    */
    virtual void setCoord(int index, double value);


};

#endif // PW2DPOINT_H

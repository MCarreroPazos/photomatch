#ifndef PWPOINT_H
#define PWPOINT_H

#include <QObject>
#include <QList>



/*!
 \brief Base Class representing a generic point.

*/
class  PWPoint
{

public:

    /*!
     \brief

    */
    enum PointType {
        Control = 0x0000,
        Check = 0x0001
    };

    /*!
     \brief

    */
    PWPoint(PointType type, QString name = "");
    /*!
     \brief Gets the type of point

     \return PointType
    */
    virtual PointType getType();
    /*!
     \brief Gets de number of components or dimensions of the point

     \return int
    */
    virtual int getCoordsCount() = 0;
    /*!
     \brief Gets the value of a component or coordinate.

     \param index
     \return double
    */
    virtual double getCoord(int index) = 0;

    /*!
     \brief Gets a list of associated points (i.e.: Image points associated with a ground control point)

     \return QList<PWPoint *>
    */
    virtual QList<PWPoint *> getAssociatedPoints();

    /*!
     \brief Gets the name of the point.

     \return QString
    */
    virtual QString getName();

    /*!
     \brief Sets the name of the point

     \param name
    */
    virtual void setName(QString name);

    /*!
     \brief Sets the value of a component or coordinate.

     \param index
    */
    virtual void setCoord(int index, double value) = 0;

protected:
    QList<PWPoint *> mAssociatedPoints; /*!< list of associated points, i.e.: Image points associated with a ground control point*/
    PointType mType;
    QString mName;
};
#endif // PWPOINT_H

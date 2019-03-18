#ifndef EXTERNALORIENTATION_H
#define EXTERNALORIENTATION_H

#include <QVector>


/*!
 \brief Class representing external orientation of a camera

*/
class  ExteriorOrientation
{
public:


/*!
 \brief

*/
    ExteriorOrientation();


/*!
 \brief Constructor

 \param cp center of projection vector
 \param r Rotation matrix
*/
    ExteriorOrientation(QVector<double> cp, QVector< QVector<double> > r);

    /*!
     \brief Sets the center of projection vector.

     \param QVector<double> Center of projection
    */
    void setCP(QVector<double> cp);
    /*!
     \brief Sets the rotation Matrix

     \param QMatrix Rotation matrix
    */
    void setR(QVector< QVector<double> > r);

    /*!
     \brief Gets the center of projection vector.

     \return QVector<double>
    */
    QVector<double> *getCP();
    /*!
     \brief Gets the rotation Matrix

     \return QMatrix
    */
    QVector< QVector<double> > *getR();

private:

    QVector<double> mCP; //Center of rojection
    QVector< QVector<double> > mR;  // Rotation Matrix.
};


#endif // EXTERNALORIENTATION_H

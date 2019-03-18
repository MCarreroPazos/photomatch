#ifndef CAMERAMODEL_H
#define CAMERAMODEL_H

#include <QString>


class  CameraModel
{
public:
/*!
 \brief  Constructor.

*/
    CameraModel();
    virtual ~CameraModel();

    /*!
     \brief Undistort a image according to distortion model.

     \param inputImage image to undistort
     \return PWImage undistorted image
    */
    virtual QString undistort(QString inputImagePath) = 0;

    /*!
     \brief

     \return bool true if distortion model allows to undistort images.
    */
    virtual bool canUnistort() = 0;

private:
};


#endif // CAMERAMODEL_H

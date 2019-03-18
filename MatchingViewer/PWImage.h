#ifndef PWIMAGE_H
#define PWIMAGE_H

#include <QString>
#include <QPolygonF>

#include "PW2dPoint.h"
#include "ExternalOrientation.h"
#include "CameraModel.h"
#include "Camera.h"

/*!
 \brief Symple and provisional representation of an image.

*/



class  PWImage
{
public:
    PWImage();
    ~PWImage();
    PWImage(QString url);

    int getID();
    QString getFullPath();
    QPolygonF getMask();
    ExteriorOrientation * getExteriorOrientation(int index);
    ExteriorOrientation * getExteriorOrientation();
    QString getFileName();
    QList<PW2dPoint *> *getControlPoints();
    Camera * getCamera();
    QSize getSize();

    void setID(int id);
    void setBasePath(QString url);
    void setMask(QPolygonF mask);
    void setExteriorOrientation(ExteriorOrientation * orientation);
    void setCamera(Camera * camera);
    void setFullPath(QString basePath){mBasePath=basePath;};


private:
    int mID; //Persistence id.
    QString mBasePath; //Directory containing image
    QString mFileName; //File name (relative to mUrl).
    QPolygonF mMask;
    QList<PW2dPoint *> mControlPoints;

    QList<ExteriorOrientation *> mExtOrientations;

    Camera * mCamera;
    ExteriorOrientation * mActiveExtOrientation;

    QSize mSize;
};


#endif // PWIMAGE_H

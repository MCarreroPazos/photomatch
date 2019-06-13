#ifndef CAMERA_H
#define CAMERA_H

#include <QString>
#include <QList>

#include <fme/ui/MatchingViewer/CameraModel.h>

class Camera
{

public:

  /*!
   \brief Constructor.

  */
  Camera();

  /*!
   \brief constructor

   \param name Camera name.
   \param height Sensor height in mm.
   \param width Sensor width in mm.
  */
  Camera(QString name, QString lensName, double width, double height, double focal = 0, double scaleFactor = 0);

  ~Camera();

  /*!
   \brief Gets the camera name.

   \return QString
  */
  QString getName();

  /*!
   \brief Gets the lens name.

   \return QString
  */
  QString getLensName();

  /*!
   \brief Gets the sensor height in mm.

   \return int Sensor height.
  */
  double getSensorHeight();

  /*!
   \brief Gets the sensor width in mm.

   \return double Sensor width
  */
  double getSensorWidth();

  /*!
   \brief Gets the manufacturer's focal

   \return double declared focal
  */
  double getDeclaredFocal();

  /*!
   \brief Gets the scale factor to 35 mm (crop factor)

   \return double scale factor.
  */
  double getScaleFactor35();

  /*!
   \brief Sets the camera name.

   \param name
  */
  void setName(QString name);

  /*!
   \brief Sets the lens name.

   \param lensName
  */
  void setLensName(QString lensName);

  /*!
   \brief Sets the height sensor height in mm.

   \param height
  */
  void setSensorHeight(double height);

  /*!
   \brief Sets the sensor height in mm.

   \param width
  */
  void setSensorWidth(double width);

  /*!
   \brief Sets the manufacturer's focal in mm.

   \param width
  */
  void setDeclaredFocal(double focal);

  /*!
   \brief the scale factor to 35 mm (crop factor)

   \param scale factor
  */
  void setScaleFactor35(double scaleFactor);

  /*!
   \brief Gets the camera model.

   \return CameraModel * Camera model
  */
  CameraModel * getCameraModel(int index);
  CameraModel * getCameraModel();
  QList<CameraModel * > getCameraModels();
  void setCameraModel(CameraModel *cameraModel);

private:

  QString mName; /*!< TODO */
  QString mLensName; /*!< TODO */
  double mSensorHeight; /*!< TODO */
  double mSensorWidth; /*!< TODO */
  double mDeclaredFocal; /*!< TODO */
  double mScaleFactor35; /*!< TODO */

  CameraModel * mActiveCamModel;
  QList<CameraModel * > mCameraModels;

};


#endif // CAMERA_H

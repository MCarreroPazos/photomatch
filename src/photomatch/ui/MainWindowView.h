#ifndef PHOTOMATCH_MAINWINDOW_H
#define PHOTOMATCH_MAINWINDOW_H

#include <QMainWindow>

#include <tidop/core/flags.h>

namespace Ui {
class MainWindowView;
}

class QTreeWidget;
class QTreeWidgetItem;
class QComboBox;
class QProgressBar;

namespace photomatch
{

class ThumbnailsWidget;
class LogWidget;
class GraphicViewer;

class MainWindowView
  : public QMainWindow
{
  Q_OBJECT

public:

  enum class Flag
  {
    project_exists        = (1 << 0),  // Existe un proyecto
    project_modified      = (1 << 1),  // Se ha modificado el proyecto
    images_added          = (1 << 2),  // Se han añadido fotogramas
    image_open            = (1 << 3),  // Hay una imagen abierta
    session_created       = (1 << 4),
    preprocess            = (1 << 5),
    feature_extraction    = (1 << 6),
    feature_matching      = (1 << 7),
    processing            = (1 << 20),
    ground_truth          = (1 << 30),
  };

public:

  explicit MainWindowView(QWidget *parent = nullptr);
  ~MainWindowView() override;

  void clear();

  /*!
   * \brief Establece el nombre del proyecto
   * \param[in] title Titulo del proyecto
   */
  void setProjectTitle(const QString &title);

  void setFlag(Flag flag, bool value);
  void addImages(const QStringList &images);
  void setActiveImage(const QString &image);
  void setActiveImages(const QStringList &images);
  void addSession(const QString &sessionName, const QString &sessionDescription);
  void addPreprocess(const QString &sessionName, const QString &preprocess, const std::vector<QString> &preprocessImages);
  void addFeatures(const QString &sessionName, const QString &detector, const QString &descriptor, const std::vector<QString> &features);
  void addMatches(const QString &sessionName, const QString &matcher, const QString &left, const QString &right, const QString &file);

  /*!
   * \brief Añade un mensaje temporal en la barra de herramientas
   * \param msg Mensaje
   */
  void setStatusBarMsg(const QString &msg);

  /*!
   * \brief Establece las propiedades del elemento seleccionado en el árbol de proyecto
   */
  void setProperties(const std::list<std::pair<QString, QString> > &properties);

  QProgressBar *progressBar();

public slots:

  /*!
   * \brief Actualiza el historial de proyectos recientes
   * \param[in] history Listado con las rutas de los últimos proyectos
   */
  void updateHistory(const QStringList &history);

  /*!
   * \brief Borra el historial de proyectos recientes
   */
  void deleteHistory();

  void deleteSession(const QString &session);

  /*!
   * \brief Elimina una imagen
   * \param[in] file
   */
  void deleteImage(const QString &file);
  void deletePreprocess(const QString &session, const QString &preprocess);
  void deleteFeatures(const QString &session, const QString &feat);
  void deleteMatches(const QString &session, const QString &matches);

  /*!
   * \brief Abre una imagen
   * \param[in] file
   */
  void showImage(const QString &file);

  //bool showKeyPoints() const;
  //void setKeyPoints(const std::vector<QPointF> &keyPoints);
  //void setKeyPoints(const std::vector<std::tuple<QPointF, double, double>> &keyPoints);
  void addKeyPoint(const QPointF &pt, double size, double angle);

  void showMatches(const QString &pairLeft, const QString &pairRight, const std::vector<std::pair<QPointF, QPointF>> &matches);

  void setActiveSession(const QString &session);

signals:

  /* Menu File */

  void openNew();
  void openProject();
  void openProjectFromHistory(QString);
  void clearHistory();
  void saveProject();
  void saveProjectAs();
  void exportTiePoints();
  void exportMatches();
//  void exportTiePointsCvXml();
//  void exportTiePointsCvYml();
//  void exportMatchesCvYml();
//  void exportMatchesCvXml();
//  void exportMatchesTxt();
  void closeProject();
  void exit();
  void openSettings();

  /* Menú View */

  void openViewSettings();

  /* Menú herramientas */

  void loadImages();
  void newSession();
  void openPreprocess();
  void openFeatureExtraction();
  void openFeatureMatching();
  void openToolSettings();

  /* Quality Control */

  void featuresViewer();
  void matchesViewer();
  void groundTruthEditor();
  void homography();
  void repeatability();
  void prCurves();
  void rocCurves();
  void detCurves();
  void openQualityControlSettings();

  /* Menú Ayuda */

  void openHelpDialog();
  void openAboutDialog();

  /* Panel de vistas en miniatura */

  ///TODO: asegurarse que se utiliza siempre el mismo criterio como id de la imagen
  ///      O nombre de la imagen o ruta completa
  void openImage(QString);
  void selectImage(QString);
  void selectImages(QStringList);
  void deleteImages(QStringList);
  void selectSession(QString);
  void selectPreprocess(QString);
  void selectFeatures(QString);
  void selectDetector(QString);
  void selectDescriptor(QString);
  void selectImageFeatures(QString);

  void loadKeyPoints(QString);
  void openImageMatches(QString, QString, QString);

  void activeSessionChange(QString);
  void delete_session(QString);

  void openFeatures(QString, QString);

protected:

  void changeEvent(QEvent *e) override;

private slots:

  void update();
  void openFromHistory();
  void onSelectionChanged();
  void hideTab(int id);
  void tabChanged(int id);
  void onItemDoubleClicked(QTreeWidgetItem *item, int column);
  void openStartPage();
  void onCommandLinkButtonGitHubClicked();
  //void onShowKeyPoints(bool show);
  void onTreeContextMenu(const QPoint &point);
  void onTabWidgetContextMenu(const QPoint &point);

private:

  void init();

// QWidget interface

public:

  void closeEvent(QCloseEvent *event) override;


protected:

  QTreeWidget *mTreeWidgetProject;
  QAction *mActionNewProject;
  QAction *mActionOpenProject;
  QAction *mActionSaveProject;
  QAction *mActionSaveProjectAs;
  QAction *mActionCloseProject;
  QAction *mActionExit;
  QAction *mActionStartPage;
  QAction *mActionLoadImages;
  QAction *mActionNewSession;
  QAction *mActionPreprocess;
  QAction *mActionFeatureExtraction;
  QAction *mActionFeatureMatching;
  QAction *mActionViewSettings;
  QAction *mActionToolSettings;
  QAction *mActionHelp;
  QAction *mActionAbout;
  QAction *mActionExportTiePoints;
  QAction *mActionExportMatches;
//  QAction *mActionExportTiePointsCvXml;
//  QAction *mActionExportTiePointsCvYml;
//  QAction *mActionExportMatchesToCvXml;
//  QAction *mActionExportMatchesToCvYml;
//  QAction *mActionExportMatchesToTxt;
  QAction *mActionFeaturesViewer;
  QAction *mActionMatchesViewer;
  QAction *mActionGroundTruthEditor;
  QAction *mActionHomography;
  //QAction *mActionRepeatability;
  QAction *mActionPRCurves;
  QAction *mActionROCCurves;
  QAction *mActionDETCurves;
  QAction *mActionQualityControlSettings;
  QAction *mActionNotRecentProjects;
  QAction *mActionClearHistory;
  QAction *mActionZoomIn;
  QAction *mActionZoomOut;
  QAction *mActionZoomExtend;
  QAction *mActionZoom11;
  //QAction *mActionShowKeyPoints;
  QAction *mActionSetSession;
  QAction *mActionDeleteSession;
  QMenu *mMenuRecentProjects;
  QMenu *mMenuExport;
//  QMenu *mMenuExportTiePoints;
//  QMenu *mMenuExportMatches;
  ThumbnailsWidget *mThumbnailsWidget;
  LogWidget *mLogWidget;
  GraphicViewer *mGraphicViewer;
  QWidget *mStartPageWidget;
  QComboBox *mComboBoxActiveSession;
  QProgressBar *mProgressBar;

  tl::EnumFlags<Flag> mFlags;
  std::vector<QAction*> mHistory;

private:

  Ui::MainWindowView *ui;
};

ALLOW_BITWISE_FLAG_OPERATIONS(MainWindowView::Flag)

} // namespace photomatch

#endif // PHOTOMATCH_MAINWINDOW_H
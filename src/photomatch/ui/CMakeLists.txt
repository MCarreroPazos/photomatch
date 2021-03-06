include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_SOURCE_DIR}/third_party)

#--------------------------------------------------------------------------------------------#
# Configuración para Qt                                                                      #
#--------------------------------------------------------------------------------------------#

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

#--------------------------------------------------------------------------------------------#
# Ejecutable PhotoMatch                                                                             #
#--------------------------------------------------------------------------------------------#

project(photomatch)

set(PHOTOMATCH_SOURCES
    main.cpp
    ComponentsManager.cpp
    MainWindowModel.cpp
    MainWindowPresenter.cpp
    MainWindowView.cpp
    NewProjectView.cpp
    NewProjectPresenter.cpp
    NewSessionView.cpp
    NewSessionPresenter.cpp
    ProjectModel.cpp
    SettingsModel.cpp
    SettingsPresenter.cpp
    SettingsView.cpp
    PreprocessView.cpp
    PreprocessModel.cpp
    PreprocessPresenter.cpp
    FeatureExtractorView.cpp
    FeatureExtractorModel.cpp
    FeatureExtractorPresenter.cpp
    FeaturesViewerView.cpp
    FeaturesViewerModel.cpp
    FeaturesViewerPresenter.cpp
    DescriptorMatcherView.cpp
    DescriptorMatcherModel.cpp
    DescriptorMatcherPresenter.cpp
    MatchViewerModel.cpp
    MatchViewerView.cpp
    MatchViewerPresenter.cpp
    MultiViewModel.cpp
    MultiViewView.cpp
    MultiViewPresenter.cpp
    HomographyViewerModel.cpp
    HomographyViewerView.cpp
    HomographyViewerPresenter.cpp
    CurvesViewerModel.cpp
    CurvesViewerView.cpp
    CurvesViewerPresenter.cpp
    GroundTruthModel.cpp
    GroundTruthView.cpp
    GroundTruthPresenter.cpp
    RepeatabilityModel.cpp
    RepeatabilityView.cpp
    RepeatabilityPresenter.cpp
    ExportFeaturesModel.cpp
    ExportFeaturesView.cpp
    ExportFeaturesPresenter.cpp
    ExportMatchesModel.cpp
    ExportMatchesView.cpp
    ExportMatchesPresenter.cpp
    #BatchModel.cpp
    #BatchView.cpp
    #BatchPresenter.cpp
    AboutDialog.cpp
    HelpDialog.cpp
    utils/GraphicViewer.cpp
    utils/ProgressDialog.cpp
    utils/Progress.cpp
    #utils/KeyPointGraphicsItem.cpp
    #utils/CrossGraphicItem.cpp
    #utils/DiagonalCrossGraphicItem.cpp
    #utils/CircleGraphicItem.cpp
    utils/GraphicItem.cpp
    utils/TabHandler.cpp
    ${CMAKE_SOURCE_DIR}/third_party/easyexif/exif.cpp
)

set(PHOTOMATCH_HEADERS
    mvp.h
	ComponentsManager.h
    ComponentsManager.cpp
    MainWindowModel.h
    MainWindowPresenter.h
    MainWindowView.h
    NewProject.h
    NewProjectView.h
    NewProjectPresenter.h
    NewSession.h
    NewSessionView.h
    NewSessionPresenter.h
    ProjectModel.h
    Settings.h
    SettingsModel.h
    SettingsPresenter.h
    SettingsView.h
    Preprocess.h
    PreprocessView.h
    PreprocessModel.h
    PreprocessPresenter.h
    FeatureExtractor.h
    FeatureExtractorView.h
    FeatureExtractorModel.h
    FeatureExtractorPresenter.h
    FeaturesViewer.h
    FeaturesViewerView.h
    FeaturesViewerModel.h
    FeaturesViewerPresenter.h
    DescriptorMatcher.h
    DescriptorMatcherView.h
    DescriptorMatcherModel.h
    DescriptorMatcherPresenter.h
    MatchViewer.h
    MatchViewerModel.h
    MatchViewerView.h
    MatchViewerPresenter.h
    Multiview.h
    MultiViewModel.h
    MultiViewView.h
    MultiViewPresenter.h
    HomographyViewer.h
    HomographyViewerModel.h
    HomographyViewerView.h
    HomographyViewerPresenter.h
    CurvesViewer.h
    CurvesViewerModel.h
    CurvesViewerView.h
    CurvesViewerPresenter.h
    GroundTruth.h
    GroundTruthModel.h
    GroundTruthView.h
    GroundTruthPresenter.h
    Repeatability.h
    RepeatabilityModel.h
    RepeatabilityView.h
    RepeatabilityPresenter.h
    ExportFeatures.h
    ExportFeaturesModel.h
    ExportFeaturesView.h
    ExportFeaturesPresenter.h
    ExportMatches.h
    ExportMatchesModel.h
    ExportMatchesView.h
    ExportMatchesPresenter.h
    #BatchModel.h
    #BatchView.h
    #BatchPresenter.h
    AboutDialog.h
    HelpDialog.h
    utils/GraphicViewer.h
    utils/ProgressDialog.h
    utils/Progress.h
    #utils/KeyPointGraphicsItem.h
    #utils/CrossGraphicItem.h
    #utils/DiagonalCrossGraphicItem.h
    #utils/CircleGraphicItem.h
    utils/GraphicItem.h
    utils/TabHandler.h
    ${CMAKE_SOURCE_DIR}/third_party/easyexif/exif.h
)

if(MSVC)
  list(APPEND PHOTOMATCH_SOURCES resource.h photomatch.rc)
endif(MSVC)

# forms
set(PHOTOMATCH_FORMS
  MainWindowView.ui
  AboutDialog.ui
  utils/ProgressDialog.ui
)

# Translation files
### TODO: Por si se quiere añadir soporte para varios idiomas
#SET(PHOTOMATCH_TS_FILES
#    ${CMAKE_SOURCE_DIR}/resources/lang/photomatch_en.ts
#    ${CMAKE_SOURCE_DIR}/resources/lang/photomatch_es.ts
#)

#qt5_add_translation(PHOTOMATCH_QM_FILES ${PHOTOMATCH_TS_FILES})

QT5_ADD_RESOURCES(UI_PHOTOMATCH_RES ${PHOTOMATCH_RESOURCES} )

add_executable(${PROJECT_NAME} WIN32
               ${PHOTOMATCH_SOURCES}
               ${PHOTOMATCH_HEADERS}
               ${PHOTOMATCH_FORMS}
               ${UI_PHOTOMATCH_RES}
               #${PHOTOMATCH_TS_FILES}
)

source_group("Form Files"  FILES ${PHOTOMATCH_FORMS})
source_group("Resource Files"  FILES ${PHOTOMATCH_RESOURCES})
#source_group("Translation Files"  FILES ${PHOTOMATCH_TS_FILES})

# Lincado de librerias
target_link_libraries(${PROJECT_NAME}
                      tl_core
                      Qt5::Core
                      Qt5::Widgets
                      Qt5::Help
                      Qt5::Concurrent
                      Qt5::Charts
                      libcore
                      libwidgets
                      libprocess
                      ${OpenCV_LIBS}
#                      ${Boost_ATOMIC_LIBRARY}
                      ${PIXKIT_LIBRARIES}
)

target_link_libraries(${PROJECT_NAME}
                      ${Boost_FILESYSTEM_LIBRARY}
                      ${Boost_SYSTEM_LIBRARY}
                      ${Boost_THREAD_LIBRARY}
                      ${Boost_DATE_TIME_LIBRARY}
                      ${Boost_CHRONO_LIBRARY})

if(HAVE_VLD)
target_link_libraries(${PROJECT_NAME} ${VLD_LIBRARY})
endif()

if(ENABLE_SOLUTION_FOLDERS)
  set_target_properties(${PROJECT_NAME}  PROPERTIES FOLDER "photomatch")
endif()


##############################################################
# Install                                                    #
##############################################################

if(WIN32)
    if (MSVC AND NOT BUILD_SHARED_LIBS)
        set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS "/NODEFAULTLIB:atlthunk.lib /NODEFAULTLIB:atlsd.lib /DEBUG")
    endif()

    install(TARGETS ${PROJECT_NAME}
            RUNTIME DESTINATION "${PROJECT_BINARY_DIR}"
            COMPONENT bin)
endif()



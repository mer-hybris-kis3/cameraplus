// -*- c++ -*-

/*!
 * This file is part of CameraPlus.
 *
 * Copyright (C) 2012-2014 Mohammed Sameer <msameer@foolab.org>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>

class QSettings;
class DeviceSettings;

class Settings : public QObject {
  Q_OBJECT

  Q_PROPERTY(int mode READ mode WRITE setMode NOTIFY modeChanged);
  Q_PROPERTY(QString creatorName READ creatorName WRITE setCreatorName NOTIFY creatorNameChanged);
  Q_PROPERTY(bool useGps READ useGps WRITE setUseGps NOTIFY useGpsChanged);
  Q_PROPERTY(bool useGeotags READ useGeotags WRITE setUseGeotags NOTIFY useGeotagsChanged);
  Q_PROPERTY(bool soundEnabled READ isSoundEnabled WRITE setSoundEnabled NOTIFY soundEnabledChanged);
  Q_PROPERTY(bool showToolBar READ isToolBarShown WRITE setToolBarShown NOTIFY toolBarShownChanged);
  Q_PROPERTY(bool gridEnabled READ isGridEnabled WRITE setGridEnabled NOTIFY gridEnabledChanged);

  Q_PROPERTY(bool faceDetectionEnabled READ isFaceDetectionEnabled WRITE setFaceDetectionEnabled NOTIFY faceDetectionEnabledChanged);
  Q_PROPERTY(bool zoomAsShutter READ isZoomAsShutterEnabled WRITE setZoomAsShutterEnabled NOTIFY zoomAsShutterChanged);
  Q_PROPERTY(bool proximityAsShutter READ isProximityAsShutterEnabled WRITE setProximityAsShutterEnabled NOTIFY proximityAsShutterChanged);
  Q_PROPERTY(int device READ device WRITE setDevice NOTIFY deviceChanged);
  Q_PROPERTY(bool enablePreview READ isPreviewEnabled WRITE setPreviewEnabled NOTIFY previewEnabledChanged);
  Q_PROPERTY(bool nightMode READ isNightModeEnabled WRITE setNightModeEnabled NOTIFY nightModeChanged);
  Q_PROPERTY(QString plugin READ plugin WRITE setPlugin NOTIFY pluginChanged);
  Q_PROPERTY(int captureTimerDelay READ captureTimerDelay WRITE setCaptureTimerDelay NOTIFY captureTimerDelayChanged);
  Q_PROPERTY(bool leftHandedMode READ isLeftHandedModeEnabled WRITE setLeftHandedModeEnabled NOTIFY leftHandedModeChanged);
  Q_PROPERTY(int sequentialShotsCount READ sequentialShotsCount WRITE setSequentialShotsCount NOTIFY sequentialShotsCountChanged);
  Q_PROPERTY(int sequentialShotsInterval READ sequentialShotsInterval WRITE setSequentialShotsInterval NOTIFY sequentialShotsIntervalChanged);
  Q_PROPERTY(int sequentialShotsDelay READ sequentialShotsDelay WRITE setSequentialShotsDelay NOTIFY sequentialShotsDelayChanged);
  Q_PROPERTY(bool focusBeforeSequentialShots READ isFocusBeforeSequentialShotsEnabled WRITE setFocusBeforeSequentialShotsEnabled NOTIFY focusBeforeSequentialShotsChanged);
  Q_PROPERTY(bool panoramaKeepFrames READ panoramaKeepFrames WRITE setPanoramaKeepFrames NOTIFY panoramaKeepFramesChanged);
  Q_PROPERTY(bool panoramaUseHighResolution READ panoramaUseHighResolution WRITE setPanoramaUseHighResolution NOTIFY panoramaUseHighResolutionChanged);
  Q_PROPERTY(bool fileNamingInUtc READ isFileNamingInUtc WRITE setFileNamingInUtc NOTIFY fileNamingInUtcChanged);

public:
  Settings(QObject *parent = 0);
  ~Settings();

  int mode() const;
  void setMode(int mode);

  QString creatorName() const;
  void setCreatorName(const QString& name);

  bool useGps() const;
  void setUseGps(bool enable);

  bool useGeotags() const;
  void setUseGeotags(bool enable);

  bool isSoundEnabled() const;
  void setSoundEnabled(bool enabled);

  bool isToolBarShown() const;
  void setToolBarShown(bool shown);

  bool isGridEnabled() const;
  void setGridEnabled(bool enabled);

  bool isFaceDetectionEnabled() const;
  void setFaceDetectionEnabled(bool enabled);

  bool isZoomAsShutterEnabled() const;
  void setZoomAsShutterEnabled(bool enabled);

  bool isProximityAsShutterEnabled() const;
  void setProximityAsShutterEnabled(bool enabled);

  int device() const;
  void setDevice(int device);

  QString fileNamingStamp(const QString& id) const;
  void setFileNamingStamp(const QString& id, const QString& stamp);

  int fileNamingCounter(const QString& id) const;
  void setFileNamingCounter(const QString& id, int counter);

  bool isPreviewEnabled() const;
  void setPreviewEnabled(bool enabled);

  bool isNightModeEnabled() const;
  void setNightModeEnabled(bool enabled);

  QString plugin() const;
  void setPlugin(const QString& plugin);

  int captureTimerDelay() const;
  void setCaptureTimerDelay(int delay);

  QVariant value(const QString& key, const QVariant& defaultValue) const;
  void setValue(const QString& key, const QVariant& value);

  bool isLeftHandedModeEnabled();
  void setLeftHandedModeEnabled(bool enabled);

  int sequentialShotsCount() const;
  void setSequentialShotsCount(int count);

  int sequentialShotsInterval() const;
  void setSequentialShotsInterval(int interval);

  int sequentialShotsDelay() const;
  void setSequentialShotsDelay(int delay);

  bool isFocusBeforeSequentialShotsEnabled() const;
  void setFocusBeforeSequentialShotsEnabled(bool enabled);

  bool panoramaKeepFrames() const;
  void setPanoramaKeepFrames(bool keep);

  bool panoramaUseHighResolution() const;
  void setPanoramaUseHighResolution(bool use);

  bool isFileNamingInUtc() const;
  void setFileNamingInUtc(bool inUtc);

signals:
  void modeChanged();
  void creatorNameChanged();
  void useGpsChanged();
  void useGeotagsChanged();
  void soundEnabledChanged();
  void toolBarShownChanged();
  void gridEnabledChanged();
  void faceDetectionEnabledChanged();
  void zoomAsShutterChanged();
  void proximityAsShutterChanged();
  void deviceChanged();
  void previewEnabledChanged();
  void nightModeChanged();
  void pluginChanged();
  void captureTimerDelayChanged();
  void leftHandedModeChanged();
  void sequentialShotsCountChanged();
  void sequentialShotsIntervalChanged();
  void sequentialShotsDelayChanged();
  void focusBeforeSequentialShotsChanged();
  void panoramaKeepFramesChanged();
  void panoramaUseHighResolutionChanged();
  void fileNamingInUtcChanged();

private:
  QSettings *m_settings;
};

#endif /* SETTINGS_H */

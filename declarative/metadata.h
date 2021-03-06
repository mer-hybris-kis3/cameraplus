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

#ifndef META_DATA_H
#define META_DATA_H

#include <QObject>
#include "qtcammetadata.h"

class Camera;

class MetaData : public QObject {
  Q_OBJECT

  Q_PROPERTY(Camera* camera READ camera WRITE setCamera NOTIFY cameraChanged);
  Q_PROPERTY(QString manufacturer READ manufacturer WRITE setManufacturer NOTIFY manufacturerChanged);
  Q_PROPERTY(QString model READ model WRITE setModel NOTIFY modelChanged);
  Q_PROPERTY(QString country READ country WRITE setCountry NOTIFY countryChanged);
  Q_PROPERTY(QString city READ city WRITE setCity NOTIFY cityChanged);
  Q_PROPERTY(QString suburb READ suburb WRITE setSuburb NOTIFY suburbChanged);
  Q_PROPERTY(double longitude READ longitude WRITE setLongitude NOTIFY longitudeChanged);
  Q_PROPERTY(bool longitudeValid READ isLongitudeValid WRITE setLongitudeValid NOTIFY longitudeValidChanged);
  Q_PROPERTY(double latitude READ latitude WRITE setLatitude NOTIFY latitudeChanged);
  Q_PROPERTY(bool latitudeValid READ isLatitudeValid WRITE setLatitudeValid NOTIFY latitudeValidChanged);
  Q_PROPERTY(double elevation READ elevation WRITE setElevation NOTIFY elevationChanged);
  Q_PROPERTY(bool elevationValid READ isElevationValid WRITE setElevationValid NOTIFY elevationValidChanged);
  Q_PROPERTY(int orientationAngle READ orientationAngle WRITE setOrientationAngle NOTIFY orientationAngleChanged);
  Q_PROPERTY(QString artist READ artist WRITE setArtist NOTIFY artistChanged);
  Q_PROPERTY(int captureDirection READ captureDirection WRITE setCaptureDirection NOTIFY captureDirectionChanged);
  Q_PROPERTY(bool captureDirectionValid READ isCaptureDirectionValid WRITE setCaptureDirectionValid NOTIFY captureDirectionValidChanged);
  Q_PROPERTY(double horizontalError READ horizontalError WRITE setHorizontalError NOTIFY horizontalErrorChanged);
  Q_PROPERTY(bool horizontalErrorValid READ isHorizontalErrorValid WRITE setHorizontalErrorValid NOTIFY horizontalErrorValidChanged);
  Q_PROPERTY(bool dateTimeEnabled READ isDateTimeEnabled WRITE setDateTimeEnabled NOTIFY dateTimeEnabledChanged);
  Q_ENUMS(Orientation);

public:
  MetaData(QObject *parent = 0);
  ~MetaData();

  Camera *camera() const;
  void setCamera(Camera *camera);

  QString manufacturer() const;
  void setManufacturer(const QString& manufacturer);

  QString model() const;
  void setModel(const QString& model);

  QString country() const;
  void setCountry(const QString& country);

  QString city() const;
  void setCity(const QString& city);

  QString suburb() const;
  void setSuburb(const QString& suburb);

  double longitude() const;
  void setLongitude(double longitude);

  double latitude() const;
  void setLatitude(double latitude);

  double elevation() const;
  void setElevation(double elevation);

  int orientationAngle() const;
  void setOrientationAngle(int angle);

  QString artist() const;
  void setArtist(const QString& artist);

  int captureDirection() const;
  void setCaptureDirection(int captureDirection);

  double horizontalError() const;
  void setHorizontalError(double horizontalError);

  bool isLongitudeValid() const;
  void setLongitudeValid(bool valid);

  bool isLatitudeValid() const;
  void setLatitudeValid(bool valid);

  bool isElevationValid() const;
  void setElevationValid(bool valid);

  bool isCaptureDirectionValid() const;
  void setCaptureDirectionValid(bool valid);

  bool isHorizontalErrorValid() const;
  void setHorizontalErrorValid(bool valid);

  bool isDateTimeEnabled() const;
  void setDateTimeEnabled(bool enabled);

public slots:
  void setMetaData();

signals:
  void cameraChanged();
  void manufacturerChanged();
  void modelChanged();
  void countryChanged();
  void cityChanged();
  void suburbChanged();
  void longitudeChanged();
  void latitudeChanged();
  void elevationChanged();
  void orientationAngleChanged();
  void artistChanged();
  void dateTimeChanged();
  void captureDirectionChanged();
  void horizontalErrorChanged();
  void longitudeValidChanged();
  void latitudeValidChanged();
  void elevationValidChanged();
  void captureDirectionValidChanged();
  void horizontalErrorValidChanged();
  void dateTimeEnabledChanged();

private slots:
  void deviceChanged();

private:
  QtCamMetaData *m_data;
  Camera *m_cam;
  QString m_manufacturer;
  QString m_model;
  QString m_country;
  QString m_city;
  QString m_suburb;
  double m_longitude;
  double m_latitude;
  double m_elevation;
  int m_orientationAngle;
  QString m_artist;
  int m_captureDirection;
  double m_horizontalError;
  bool m_longitudeValid;
  bool m_latitudeValid;
  bool m_elevationValid;
  bool m_captureDirectionValid;
  bool m_horizontalErrorValid;
  bool m_dateTimeEnabled;
};

#endif /* META_DATA_H */

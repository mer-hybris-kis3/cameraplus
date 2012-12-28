/*!
 * This file is part of CameraPlus.
 *
 * Copyright (C) 2012 Mohammed Sameer <msameer@foolab.org>
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

#include "galleryhelper.h"
#include <maemo-meegotouch-interfaces/galleryinterface.h>
#include <QStringList>
#include <QUrl>
#include <QDeclarativeInfo>

GalleryHelper::GalleryHelper(QObject *parent) :
  QObject(parent),
  m_iface(new GalleryInterface) {

}

GalleryHelper::~GalleryHelper() {
  delete m_iface;
}

bool GalleryHelper::show(const QUrl& path) {
  if (!m_iface->isValid()) {
    qmlInfo(this) << "Failed to get gallery interface";
    return false;
  }

  return m_iface->showMediaInFullScreen(QStringList() << path.toLocalFile());
}

bool GalleryHelper::launch() {
  if (!m_iface->isValid()) {
    qmlInfo(this) << "Failed to get gallery interface";
    return false;
  }

  return m_iface->showCameraRoll();
}

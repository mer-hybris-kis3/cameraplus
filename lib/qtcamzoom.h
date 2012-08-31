// -*- c++ -*-

#include "qtcamcapability.h"

class QtCamZoomPrivate;

class QtCamZoom : public QtCamCapability {
  Q_OBJECT

public:
  QtCamZoom(QtCamDevice *dev, QObject *parent = 0);
  ~QtCamZoom();

  qreal value();
  bool setValue(qreal zoom);
  qreal minimumValue();
  qreal maximumValue();
};

// -*- qml -*-

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

import QtQuick 2.0
import QtCamera 1.0

CameraToolBarTools {
    property list<ToolsModelItem> toolsModel: [
        ToolsModelItem {icon: cameraTheme.flashAutoIconId; value: Flash.Auto; label: qsTr("Automatic"); visible: deviceFeatures().isAutoFlashModeSupported},
        ToolsModelItem {icon: cameraTheme.flashOnIconId; value: Flash.On; label: qsTr("Always on"); visible: deviceFeatures().isOnFlashModeSupported},
        ToolsModelItem {icon: cameraTheme.flashOffIconId; value: Flash.Off; label: qsTr("Always off"); visible: deviceFeatures().isOffFlashModeSupported},
        ToolsModelItem {icon: cameraTheme.flashRedEyeIconId; value: Flash.RedEye; label: qsTr("Red eye"); visible: deviceFeatures().isRedEyeFlashModeSupported}
    ]

    CameraLabel {
        height: parent.height
        text: qsTr("Flash")
        verticalAlignment: Text.AlignVCenter
    }

    Repeater {
        model: toolsModel

        delegate: CheckButton {
            iconSource: modelData.icon
            onClicked: deviceSettings().imageFlashMode = value
            checked: deviceSettings().imageFlashMode == value
            visible: modelData.visible
            onCheckedChanged: {
                if (checked) {
                    selectedLabel.text = label
                }
            }
        }
    }
}

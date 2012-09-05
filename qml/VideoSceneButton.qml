// -*- qml -*-
import QtQuick 1.1
import com.nokia.meego 1.1
import QtCamera 1.0

Selector {
        id: button

        property int value: settings.videoSceneMode

        iconSource: sceneIcon(scene.value);

        title: qsTr("Scene mode");

        function sceneIcon(val) {
                var x = row.children.length;
                var i = 0;
                for (i = 0; i < x; i++) {
                        if (row.children[i].value == val) {
                                return row.children[i].normalIcon;
                        }
                }
        }

        widget: Row {
                id: row
                height: button.checked ? 64 : 0
                width: button.checked ? (children.length * height) +  (children.length - 1) * spacing : 0
                spacing: 10

                Behavior on width {
                        // TODO: seems animation is not working
                        PropertyAnimation { duration: 250; }
                }

                CheckButton {
                        normalIcon: "image://theme/icon-m-camera-scene-auto"
                        checkedIcon: "image://theme/icon-m-camera-scene-auto-selected"
                        savedValue: settings.videoSceneMode
                        onClicked: settings.videoSceneMode = value;
                        value: Scene.Auto
                }

                CheckButton {
                        normalIcon: "image://theme/icon-m-camera-video-night"
                        checkedIcon: "image://theme/icon-m-camera-video-night-selected"
                        savedValue: settings.videoSceneMode
                        onClicked: settings.videoSceneMode = value;
                        value: Scene.Night
                }
        }
}

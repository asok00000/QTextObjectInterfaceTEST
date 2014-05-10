import QtQuick 2.2
import QtQuick.Window 2.1
import QtQuick.Controls 1.1
import "JSONListModel"

Window {
    visible: true
    width: 360
    height: 360
    TextEdit {

        id: tt
        objectName: 'teobj'
        width: 111
        height: 111
        text: "@cui See the <a href=\"asdf\">class</a>."
        textFormat: TextEdit.RichText
        selectByKeyboard: true
        selectByMouse: true
//        inputMethodComposing: true
//        renderType: Text.QtRendering

        ListView {
            id: ccs
            visible: false
            Keys.onPressed: {
                if (event.key === Qt.Key_Enter) {
                    //                        tt.state=="def"
                    event.accepted = true
                    console.log('enter app')
                }
            }

            width: 22
            height: 22
            JSONListModel {

                property var jsdata: {
                    [{
                        SG: "loginSG",
                            state: 1
                    }, {
                        SG: "pageSG",
                            state: 2
                    }, {
                        SG: "loginPGSG",
                            state: 3
                    }, {
                        SG: "mainPGSG",
                            state: 4
                    }, {
                        SG: "socket",
                            state: 5
                    }, {
                        SG: "socket.connectStates",
                            state: 6
                    }, {
                        SG: "loginFrame_state",
                            state: 7
                    }, {
                        SG: "loginMainPage_state",
                            state: 8
                    }]
                }
                id: jsmodel
                json: JSON.stringify(jsdata)
            }
            model: jsmodel.model
            delegate: Rectangle {
                width: childrenRect.width
                height: childrenRect.height
                color: 'green'
                opacity: 1
                Text {
                    id: x
                    text: SG
                }
            }
        }
        Rectangle {
            id: ccs1
            visible: false
            width: 20
            height: 30
            color: 'red'
            opacity: 0.3
        }
        state: 'def'
        onStateChanged: console.log(state)
        states: [
            State {
                name: "def"
                StateChangeScript {
                    script: {
                        tt.state = "def"
                        tt.focus = true
                        ccs.visible = false
                    }
                }
            },
            State {
                name: "@mode"
                StateChangeScript {
                    script: {
                        ccs.x = tt.cursorRectangle.x
                        ccs.y = tt.cursorRectangle.y
                        ccs.visible = true
                        ccs.z = 99
                        ccs.focus = true
                    }
                }
            }
        ]
        onCursorPositionChanged: {
            console.log(cursorPosition)
            console.log(getText(cursorPosition - 1, cursorPosition))
            if (getText(cursorPosition - 1, cursorPosition) === '@') {
                state = '@mode'
            } else {
                state = 'def'
            }
        }

        Keys.onReleased: {

            //            console.log(event.key)
            //            if(event.key===Qt.Key_Down)
            if (event.key === Qt.Key_At) {
                //                event.accepted=true
                if (state === "@mode")
                    event.accepted = true
                //                state="@mode"
            } else if (event.key === Qt.Key_Down) {

                //                state="def"
                //                tt.focus=true
                //                ccs.visible=false
            } else {
                    hlfa.doit(textDocument)
                //                state="def"
            }
        }

        MouseArea {
            id: am
            anchors.fill: parent

            z: 0
            acceptedButtons: Qt.NoButton
            hoverEnabled: true
            onPositionChanged: {
                aa.x = mouseX + 15
                aa.y = mouseY - 15
                aa.text = tt.linkAt(mouseX, mouseY)
            }
        }
        Text {
            id: aa
            y: 111
            text: qsTr("ccccc")
        }
        onLinkActivated: console.log(link + " link activated")
        Component.onCompleted: {
//            console.log(hl)
//            hl.sD(textDocument)
            //            te.setDocument(hl)
        }

        //        text: qsTr("Hello World")
        anchors.centerIn: parent
        //        onCursorPositionChanged:{
        //            var cp=cursorPosition
        //            var a=text

        //            var b=a.replace(/ (cui) /,' <span style=" color:#ff0000;">cui</span> ')
        //            b=b.replace(/ <span style=" color:#ff0000;">(?!cui)([\w]+)<\/span> /,' $1 ')
        //            text=b
        //            if (cp!==cursorPosition) cursorPosition=cp;

        //            console.log(cursorPosition,a)
        //        }
    }
}

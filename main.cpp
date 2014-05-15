#include <QGuiApplication>
#include <QQmlEngine>
#include <QQmlComponent>
#include <QQmlContext>
#include "highlighter.h"
#include <QTextEdit>
#include <QMainWindow>
#include <QApplication>
#include "framedtextattr.h"

int main(int argc, char *argv[])
{
//    QGuiApplication app(argc, argv);

    QApplication app(argc,argv);
    QQmlEngine engine;

//    engine.setBaseUrl(QUrl(QStringLiteral("qrc:///qml/main.qml")));
    Highlighter *highlighter;
    highlighter = new Highlighter();
    framedTextAttr *fa = new framedTextAttr; 
//    QQmlContext *cc = new QQmlContext(engine.rootContext());
    engine.rootContext()->setContextProperty("hlfa",fa);
    QQmlComponent com(&engine,QUrl(QStringLiteral("qrc:///qml/main.qml")));
//    engine.rootContext()->findChild("tt");

    com.create();

    QTextEdit *x = new QTextEdit;
    x->setPlainText("@cui sef");
    x->setHtml("@cui sef");
    framedTextAttr *fa2 = new framedTextAttr;

    QTextCharFormat tmp;
    tmp.setForeground(Qt::red);
      x->document()->documentLayout()->registerHandler(framedTextAttr::textFormat, fa2);
       tmp.setObjectType(fa2->textFormat);
       QTextCursor c=x->document()->find("@cui");
       tmp.setProperty(fa2->textProperty,c.selectedText());
       c.insertText(QString(QChar::ObjectReplacementCharacter), tmp);

    highlighter->sD2(x->document());

    QMainWindow xw;
    xw.setCentralWidget(x);
    xw.show();






    return app.exec();
}

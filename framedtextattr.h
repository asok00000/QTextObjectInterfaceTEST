#ifndef FRAMEDTEXTATTR_H
#define FRAMEDTEXTATTR_H
#include <QQuickTextDocument>
#include <QTextObjectInterface>

class framedTextAttr :public QObject, public QTextObjectInterface
{
    Q_OBJECT
         Q_INTERFACES(QTextObjectInterface)
public:
//    framedTextAttr();
   Q_INVOKABLE void doit(QQuickTextDocument *doc);
    enum types{
        textFormat = QTextFormat::UserObject + 20000,
        textProperty=QTextFormat::UserProperty+21,
    };

//    QString * slstr;
//    QTextFormat::ObjectTypes type();
//    QTextFormat::Property prop();
    
protected:
    virtual void drawObject ( QPainter * painter, const QRectF & rect, QTextDocument * doc, int posInDocument, const QTextFormat & format );
    virtual QSizeF intrinsicSize ( QTextDocument * doc, int posInDocument, const QTextFormat & format );
};

#endif // FRAMEDTEXTATTR_H

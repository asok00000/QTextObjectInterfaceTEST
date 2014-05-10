#include "framedtextattr.h"
#include <QFontMetrics>
#include <QPainter>
//framedTextAttr::framedTextAttr()
//    :QObject(),QTextObjectInterface()
//{
//}
void framedTextAttr::doit(QQuickTextDocument *doc){
//    framedTextAttr *fa = new framedTextAttr;
    QTextCharFormat tmp;
//    tmp.setForeground(Qt::red);
       doc->textDocument()->documentLayout()->registerHandler(framedTextAttr::textFormat, this);
       tmp.setObjectType(this->textFormat);
       QTextCursor c=doc->textDocument()->find("@cui");
       tmp.setProperty(this->textProperty,c.selectedText());
       c.insertText(QString(QChar::ObjectReplacementCharacter), tmp);
}

QSizeF framedTextAttr::intrinsicSize(QTextDocument *doc, int posInDocument, const QTextFormat &format)
{
    Q_UNUSED(doc)
    Q_UNUSED(posInDocument)

    Q_ASSERT(format.type() == format.CharFormat);
    const QTextCharFormat &tf = *(const QTextCharFormat*)(&format);
    QString s = format.property(textProperty).toString();
//    QString s = "chartt";
    QFont fn = tf.font();
    QFontMetrics fm(fn);
//    QFont font("times", 24);
//    QFontMetrics fm(font);
    QSizeF aacc= fm.boundingRect(s).size();
    return fm.boundingRect(s).size();
//    return QSizeF(20,20);


}

void framedTextAttr::drawObject(QPainter *painter, const QRectF &rect, QTextDocument *doc, int posInDocument, const QTextFormat &format)
{
    Q_UNUSED(doc)
        Q_UNUSED(posInDocument)

    Q_ASSERT(format.type() == format.CharFormat);
    QString s =   format.property(textProperty).toString();
    QPen pen(Qt::green, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    painter->setPen(pen);
    painter->setBrush(Qt::blue);
    painter->drawText(rect, s);
    painter->drawRoundedRect(rect, 3, 3);
}

//QTextFormat::ObjectTypes framedTextAttr::type(){
//    return QTextFormat::UserObject + 0x1;

//}
//QTextFormat::Property framedTextAttr::prop(){
//    return QTextFormat::UserProperty+0x1;
//}

#include "highlighter.h"
#include <QMessageLogger>
#include "framedtextattr.h"
#include <QTextCursor>
#include <QChar>
void Highlighter::sD(QQuickTextDocument *doc){

    setDocument(doc->textDocument());
    qDebug("set doc ok");
    framedTextAttr *fa = new framedTextAttr;
    QTextCharFormat tmp;
//    tmp.setForeground(Qt::red);
       doc->textDocument()->documentLayout()->registerHandler(framedTextAttr::textFormat, fa);
       tmp.setObjectType(fa->textFormat);
       QTextCursor c=doc->textDocument()->find("@cui");
       tmp.setProperty(fa->textProperty,c.selectedText());
       c.insertText(QString(QChar::ObjectReplacementCharacter), tmp);
}
void Highlighter::sD2(QTextDocument *doc){

    setDocument(doc);
    qDebug("set doc ok");
    framedTextAttr *fa = new framedTextAttr;
    QTextCharFormat tmp;
    tmp.setForeground(Qt::red);
       this->document()->documentLayout()->registerHandler(framedTextAttr::textFormat, fa);
       tmp.setObjectType(fa->textFormat);
       QTextCursor c=this->document()->find("@cui");
       tmp.setProperty(fa->textProperty,c.selectedText());
       c.insertText(QString(QChar::ObjectReplacementCharacter), tmp);
}

Highlighter::Highlighter(QTextDocument *parent)
    :QSyntaxHighlighter(parent)
{
    HighlightingRule rule;

    keywordFormat.setForeground(Qt::red);
    keywordFormat.setFontWeight(QFont::Bold);
    QStringList keywordPatterns;
    keywordPatterns << "char" << "\\bclass\\b" << "\\bconst\\b"
                    << "\\bdouble\\b" << "\\benum\\b" << "\\bexplicit\\b"
                    << "\\bfriend\\b" << "\\binline\\b" << "\\bint\\b"
                    << "\\blong\\b" << "\\bnamespace\\b" << "\\boperator\\b"
                    << "\\bprivate\\b" << "\\bprotected\\b" << "\\bpublic\\b"
                    << "\\bshort\\b" << "\\bsignals\\b" << "\\bsigned\\b"
                    << "\\bslots\\b" << "\\bstatic\\b" << "\\bstruct\\b"
                    << "\\btemplate\\b" << "\\btypedef\\b" << "\\btypename\\b"
                    << "\\bunion\\b" << "\\bunsigned\\b" << "\\bvirtual\\b"
                    << "\\bvoid\\b" << "\\bvolatile\\b";
    foreach (const QString &pattern, keywordPatterns) {
        rule.name="keyword";
        rule.pattern = QRegExp(pattern);
        rule.format = keywordFormat;
        highlightingRules.append(rule);
    }

//    atLinkFormat.setAnchor(true);


//    atLinkFormat.setForeground(Qt::red);

//    this->document()->documentLayout()->registerHandler(framedTextAttr::textFormat, fa);
//    atLinkFormat.setObjectType(fa->textFormat);
//    atLinkFormat.setProperty(fa->textProperty,"@cui");
//    rule.name="@";
//    rule.pattern=QRegExp("@[\\w\\u4e00-\\u9fa5]+");
//    rule.format=atLinkFormat;
//    highlightingRules.append(rule);


    }


void Highlighter::highlightBlock(const QString &text)
{
    foreach (const HighlightingRule &rule, highlightingRules) {
        QRegExp expression(rule.pattern);
        int index = expression.indexIn(text);
        while (index >= 0) {
            int length = expression.matchedLength();
            if(rule.name=="@"){
//                 framedTextAttr *fa = new framedTextAttr;
//                 QTextCharFormat tmp;
//                 tmp.setForeground(Qt::red);
//                    this->document()->documentLayout()->registerHandler(framedTextAttr::textFormat, fa);
//                    tmp.setObjectType(fa->textFormat);
//                    QTextCursor c=this->document()->find("@cui");
//                    tmp.setProperty(fa->textProperty,c.selectedText());
//                    c.insertText(QString(QChar::ObjectReplacementCharacter), tmp);


//            setFormat(index, length, tmp);
            }else{
                setFormat(index, length, rule.format);
            }
            index = expression.indexIn(text, index + length);
        }
    }
    
//     setCurrentBlockState(0);
     
//     int startIndex = 0;
//     if (previousBlockState() != 1)
//         startIndex = commentStartExpression.indexIn(text);
        
        
//        while (startIndex >= 0) {
//              int endIndex = commentEndExpression.indexIn(text, startIndex);
//              int commentLength;
//              if (endIndex == -1) {
//                  setCurrentBlockState(1);
//                  commentLength = text.length() - startIndex;
//              } else {
//                  commentLength = endIndex - startIndex
//                                  + commentEndExpression.matchedLength();
//              }
//              setFormat(startIndex, commentLength, multiLineCommentFormat);
//              startIndex = commentStartExpression.indexIn(text, startIndex + commentLength);
//          }
      }

#ifndef HIGHLIGHTER_H
#define HIGHLIGHTER_H
#include <QQuickTextDocument>
#include <QSyntaxHighlighter>

class Highlighter : public QSyntaxHighlighter
{
    Q_OBJECT

public:
    Highlighter(QTextDocument *parent = 0);
    Q_INVOKABLE void sD(QQuickTextDocument * doc);
    void sD2(QTextDocument * doc);


protected:
    void highlightBlock(const QString &text);



private:
    struct HighlightingRule
    {
        QString name="";
        QRegExp pattern;
        QTextCharFormat format;
//        int group;
    };
    QVector<HighlightingRule> highlightingRules;

    QRegExp commentStartExpression;
    QRegExp commentEndExpression;

    QTextCharFormat atLinkFormat;
    QTextCharFormat keywordFormat;
    QTextCharFormat classFormat;
    QTextCharFormat singleLineCommentFormat;
    QTextCharFormat multiLineCommentFormat;
    QTextCharFormat quotationFormat;
    QTextCharFormat functionFormat;

};
#endif // HIGHLIGHTER_H

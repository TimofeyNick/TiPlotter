#pragma once

#include "qnanoquickitem.h"
#include "TiPlotterPainter.h"

class TiPlotterItem : public QNanoQuickItem
{
    Q_OBJECT

    Q_PROPERTY(QString expression READ expression WRITE setExpression NOTIFY expressionChanged)

    public:
        TiPlotterItem(QQuickItem *parent = 0)
            :  QNanoQuickItem(parent)
        {
        }

        QNanoQuickItemPainter *createItemPainter() const;

        inline QString expression() const { return _expression; }

    public slots:
        void setExpression(QString expression);

    signals:
        void expressionChanged(QString expression);

    private:
        QString _expression;
};


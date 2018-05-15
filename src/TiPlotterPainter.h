#pragma once

#include "qnanoquickitempainter.h"

class TiPlotterPainter : public QObject, public QNanoQuickItemPainter
{
    Q_OBJECT

    public:
        TiPlotterPainter()
        {
        }

        void paint(QNanoPainter *p);

    public slots:
        void updateExpression(QString expression);

    private:
        QString _expression;
};

#include "TiPlotterItem.h"
#include "TiPlotterPainter.h"

QNanoQuickItemPainter *TiPlotterItem::createItemPainter() const
{
    auto *painter =  new TiPlotterPainter();
    painter->updateExpression(_expression);
    connect(this, &TiPlotterItem::expressionChanged, painter, &TiPlotterPainter::updateExpression);

    return painter;
}

void TiPlotterItem::setExpression(QString expression)
{
    if (_expression == expression)
        return;

    _expression = expression;
    emit expressionChanged(_expression);
}

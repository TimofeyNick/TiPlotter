#include "TiPlotterPainter.h"
#include "qnanopainter.h"
#include "tinyexpr.h"
#include <algorithm>
#include <QtMath>

void TiPlotterPainter::paint(QNanoPainter *p)
{
    // Параметры линии графика
    float lineWidth = 4.0f;

    p->setFillStyle(0xFFE0E0E0);
    p->setStrokeStyle(0xFFE00000);
    p->setLineWidth(lineWidth);
    p->setLineCap(QNanoPainter::CAP_ROUND);
    p->setLineJoin(QNanoPainter::JOIN_ROUND);

    // Рисуем график
    if (!_expression.isEmpty()) {
        //const char *expression = _expression.trimmed().toLatin1().data();
        char *expression = new char[_expression.size() + 1];
        strcpy(expression, _expression.toLatin1().data());

        bool first = true;
        double x, y;
        te_variable vars[] = {{"x", &x}, {"y", &y}};
        int err;
        te_expr *expressor = te_compile(expression, vars, 2, &err);

        if (expressor && err == 0) {
            p->beginPath();
                for (x = 0; x<width(); ++x) {
                    double y = te_eval(expressor);

                    if (first) {
                        first = false;
                        p->moveTo(x + width()/2, -y + height()/2);
                    } else {
                        p->lineTo(x + width()/2, -y + height()/2);
                    }
                }
            p->stroke();
        }
    }
}

void TiPlotterPainter::updateExpression(QString expression) {
    _expression = expression.trimmed();
    update();
}

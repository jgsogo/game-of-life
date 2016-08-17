#include "glwidget.h"
#include "helper.h"

#include <QPainter>
#include <QTimer>

GLWidget::GLWidget(Helper *helper, QWidget *parent) : QOpenGLWidget(parent), helper(helper) {
    elapsed = 0;
    setMinimumSize(200, 200);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    setAutoFillBackground(false);
}

void GLWidget::animate() {
    elapsed = (elapsed + qobject_cast<QTimer*>(sender())->interval()) % 1000;
    update();
}

void GLWidget::paintEvent(QPaintEvent *event) {
    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);
    helper->paint(&painter, event, elapsed, -1);
    painter.end();
}

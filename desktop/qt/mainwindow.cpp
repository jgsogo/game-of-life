#include "mainwindow.h"

#include <QGridLayout>
#include <QLabel>
#include <QTimer>

#include "glwidget.h"
#include "widget.h"


MainWindow::MainWindow() {
    setWindowTitle(tr("2D Painting on Native and OpenGL Widgets"));

    Widget *native = new Widget(&_helper, this);
    GLWidget *openGL = new GLWidget(&_helper, this);
    QLabel *nativeLabel = new QLabel(tr("Native"));
    nativeLabel->setAlignment(Qt::AlignHCenter);
    QLabel *openGLLabel = new QLabel(tr("OpenGL"));
    openGLLabel->setAlignment(Qt::AlignHCenter);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(native, 0, 0);
    layout->addWidget(openGL, 0, 1);
    layout->addWidget(nativeLabel, 1, 0);
    layout->addWidget(openGLLabel, 1, 1);
    setLayout(layout);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, native, &Widget::animate);
    connect(timer, &QTimer::timeout, openGL, &GLWidget::animate);
    timer->start(50);

}

MainWindow::~MainWindow() {
}



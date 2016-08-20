#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLWidget>

class Helper;

class GLWidget : public QOpenGLWidget {
        Q_OBJECT

    public:
        GLWidget(Helper *helper, QWidget *parent);

    public slots:
        void animate();

    protected:
        void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

    private:
        Helper *helper;
        int elapsed;
};

#endif

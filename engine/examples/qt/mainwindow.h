#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "helper.h"


class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();

private:
    Helper _helper;
};

#endif // MAINWINDOW_H

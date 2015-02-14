#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
/*
 * Main Window which is used to add the GLWidget used to display the
 * GL draw calls
 *
*/
class GLWidget;

class MainWindow : public QMainWindow, private Ui::MainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    GLWidget *glWidget;

    void initialiseGLWidget();
};

#endif // MAINWINDOW_H

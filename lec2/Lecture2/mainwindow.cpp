#include "mainwindow.h"
#include "glwidget.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setupUi(this);
    initialiseGLWidget();
}

MainWindow::~MainWindow()
{
    delete glWidget;
}

void MainWindow::initialiseGLWidget()
{
    glWidget = new GLWidget(this);
    this->setCentralWidget(glWidget);
}

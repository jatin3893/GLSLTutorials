#include "mainwindow.h"
#include "glwidget.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    // Setting up the Window Ui. You can change it by modifying the mainwindow.ui
    // file or manually changing the layout
    setupUi(this);
    initialiseGLWidget();
}

MainWindow::~MainWindow()
{
    delete glWidget;
}

void MainWindow::initialiseGLWidget()
{
    // Add the GLwidget in the main window to display
    // the draw calls
    glWidget = new GLWidget(this);
    this->setCentralWidget(glWidget);
}

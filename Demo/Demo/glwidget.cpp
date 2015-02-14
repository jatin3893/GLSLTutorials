#include "glwidget.h"

// QtGL Includes
#include <QGLFunctions>
#include <QGLShaderProgram>

GLWidget::GLWidget(QWidget *parent) : QGLWidget(parent)
{
    /*
     * The GL Window is updated by making the updateGL() call.
     * To update the window after specific intervals of time,
     * initialise  a clock (QTimer) and connect the timeout to updateGL
     * to update the window at every timeout
     *
    */
}

GLWidget::~GLWidget()
{

}

void GLWidget::initializeGL()
{
    QGLWidget::initializeGL();
   /*
    * Add initialisation commands here.
    * For Example, setting up clearColor value
    * Enable/Disable Depth Test, Alpha channels.
    * Initialising the shaders can also be done here.
    *
    */

}

void GLWidget::initShaders()
{
    /*
     * Load, compile and link the vertex and fragment shaders
     * in the OpenGL program.
     *
    */
}

void GLWidget::paintGL()
{
    /*
     * Add all the draw calls here.
     * Set shader variable values here.
     *
    */
}

void GLWidget::resizeGL(int w, int h)
{
    /*
     * Specify changes to be made when the window is being resized
     * like adjusting the viewport, camera
    */
}

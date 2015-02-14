#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QMatrix4x4>

/*
 * Widget to display the OpenGL draw commands in the Qt Window
*/
class QGLShaderProgram;

class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = 0);
    ~GLWidget();

    //Initialising the Widget
    void initializeGL();

    // Add information related to drawing calls
    void paintGL();

    // Resize callback to be used on resizing the window
    void resizeGL(int w, int h);

signals:

public slots:

protected:
    // The program which stores the shader information
    QGLShaderProgram *program;

    // Initialise the corresponding shaders here
    void initShaders();
};

#endif // GLWIDGET_H

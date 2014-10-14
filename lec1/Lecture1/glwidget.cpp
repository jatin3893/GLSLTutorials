#include "glwidget.h"

// Geometry Includes
#include "triangle.h"

// QtGL Includes
#include <QGLFunctions>
#include <QGLShaderProgram>

GLWidget::GLWidget(QWidget *parent) : QGLWidget(parent)
{
}

GLWidget::~GLWidget()
{
    delete program;
    delete object;
}

void GLWidget::initializeGL()
{
    QGLWidget::initializeGL();
    qglClearColor(Qt::black);

    // Initialise shaders
    program = new QGLShaderProgram();
    initShaders();

    // Initialise geometry objects
    object = new Triangle();
    object->init();
}

void GLWidget::initShaders()
{
    setlocale(LC_NUMERIC, "C");

    if (!program->addShaderFromSourceFile(QGLShader::Vertex, ":/vshader.glsl"))
        close();

    if (!program->addShaderFromSourceFile(QGLShader::Fragment, ":/fshader.glsl"))
        close();

    if (!program->link())
        close();

    if (!program->bind())
        close();

    setlocale(LC_ALL, "");
}

void GLWidget::paintGL()
{
    // Clear color and depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Calculate model view transformation
    QMatrix4x4 matrix;
    matrix.translate(0.0, 0.0, -5.0);

    // Set modelview-projection matrix
    program->setUniformValue("mvp_matrix", projection * matrix);

    object->render(program);
}

void GLWidget::resizeGL(int w, int h)
{
    // Set OpenGL viewport to cover whole widget
    glViewport(0, 0, w, h);

    // Calculate aspect ratio
    qreal aspect = qreal(w) / qreal(h ? h : 1);

    // Set near plane to 3.0, far plane to 7.0, field of view 45 degrees
    const qreal zNear = 3.0, zFar = 7.0, fov = 45.0;

    // Reset projection
    projection.setToIdentity();

    // Set perspective projection
    projection.perspective(fov, aspect, zNear, zFar);
}

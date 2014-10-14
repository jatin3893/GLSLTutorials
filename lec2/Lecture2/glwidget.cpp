#include "glwidget.h"

// Geometry Includes
#include "cube.h"

// QtGL Includes
#include <QGLShaderProgram>
#include <QTimer>

GLWidget::GLWidget(QWidget *parent) : QGLWidget(parent)
{
    rotation = 0;
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    timer->start(20);
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
    glEnable(GL_DEPTH_TEST);

    // Initialise shaders
    program = new QGLShaderProgram();
    initShaders();

    // Initialise geometry objects
    object = new Cube();
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

void GLWidget::updateGL()
{
    QGLWidget::updateGL();
    rotation = (rotation + 1) % 360;
}

void GLWidget::paintGL()
{
    // Clear color and depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Set modelview-projection matrix
    program->setUniformValue("projection", projection);

    // Set camera matrix
    program->setUniformValue("camera", camera);

    model.rotate(1, 0.4, 0.2, 0.8);

    // Set model matrix
    program->setUniformValue("model", model);

    object->render();
}

void GLWidget::resizeGL(int w, int h)
{
    // Set OpenGL viewport to cover whole widget
    glViewport(0, 0, w, h);

    // Calculate aspect ratio
    qreal aspect = qreal(w) / qreal(h ? h : 1);

    // Set near plane to 3.0, far plane to 7.0, field of view 45 degrees
    const qreal zNear = 0.1, zFar = 10.0, fov = 50.0;

    // Reset projection
    projection.setToIdentity();

    // Set perspective projection
    projection.perspective(fov, aspect, zNear, zFar);

    // Reset Camera
    camera.setToIdentity();

    // Set Camera Position
    camera.lookAt(QVector3D(0, 0, 5), QVector3D(0, 0, 0), QVector3D(0, 1, 0));}

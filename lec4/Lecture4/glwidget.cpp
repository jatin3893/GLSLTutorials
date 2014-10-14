#include "glwidget.h"

// std c++ includes
#include <iostream>

// Geometry Includes
#include "cube.h"

// QtGL Includes
#include <QGLShaderProgram>
#include <QTimer>
#include <QKeyEvent>
#include <QQuaternion>

GLWidget::GLWidget(QWidget *parent) : QGLWidget(parent)
{
    this->setFocusPolicy(Qt::WheelFocus);
    count = 0;
    pos = 10;
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
    glEnable(GL_CULL_FACE);
    glFrontFace(GL_CCW);
    glEnable(GL_NORMALIZE);


    // Initialise shaders
    program = new QGLShaderProgram();
    initShaders();
    resizeGL(this->size().width(), this->size().height());
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
}

void GLWidget::paintGL()
{
    // Clear color and depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Set modelview-projection matrix
    program->setUniformValue("projection", projection);

    // Set camera matrix
    program->setUniformValue("camera", camera);

    // Set Light properties
    QVector3D position(10, 0, pos);
    QVector3D intensity(0.2, 0.4, 0.2);
    program->setUniformValue("lightPosition", position);
    program->setUniformValue("lightIntensity", intensity);

    // Set model matrix
    model.setToIdentity();
    QQuaternion rotation = QQuaternion::fromAxisAndAngle(QVector3D(1, 0, 1), count);
    model.rotate(rotation);
    program->setUniformValue("model", model);

    object->render();
}

void GLWidget::resizeGL(int w, int h)
{
    // Set OpenGL viewport to cover whole widget
    glViewport(0, 0, w, h);

    // Calculate aspect ratio
    qreal aspect = qreal(w) / qreal(h ? h : 1);

    const qreal zNear = 0.1, zFar = 100.0, fov = 45.0;

    // Reset projection
    projection.setToIdentity();

    // Set perspective projection
    projection.perspective(fov, aspect, zNear, zFar);

    // Reset Camera
    camera.setToIdentity();

    // Set Camera Position
    camera.lookAt(QVector3D(5, 0, 5), QVector3D(0, 0, 0), QVector3D(0, 1, 0));
}

void GLWidget::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_A:
        count++;
        break;
    case Qt::Key_S:
        count--;
        break;
    case Qt::Key_D:
        pos++;
        break;
    case Qt::Key_F:
        pos--;
        break;
    }
    std::cout << "count: " << count << "Pos: " << pos << std::endl;
}

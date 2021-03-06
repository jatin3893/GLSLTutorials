#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QMatrix4x4>

class QTimer;
class QGLShaderProgram;
class Cube;

class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = 0);
    ~GLWidget();

    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);

signals:

public slots:
    void updateGL();
    void keyPressEvent(QKeyEvent *);

protected:
    QGLShaderProgram *program;
    Cube *object;
    Cube *object2;
    QTimer *timer;

    QMatrix4x4 projection;
    QMatrix4x4 camera;
    QMatrix4x4 model;

    void initShaders();

    int count;
    int pos;
};

#endif // GLWIDGET_H

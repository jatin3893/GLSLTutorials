#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QMatrix4x4>

class QGLShaderProgram;
class Triangle;

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

protected:
    QGLShaderProgram *program;
    Triangle *object;

    QMatrix4x4 projection;
    void initShaders();
};

#endif // GLWIDGET_H

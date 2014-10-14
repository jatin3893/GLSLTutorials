#ifndef GLOBJECT_H
#define GLOBJECT_H

#include <QGLFunctions>
#include <QVector3D>
#include <QMatrix4x4>

class QGLShaderProgram;

#define VertexPositionAttrib 0
#define VertexNormalAttrib 1
#define VertexColorAttrib 2

class GLObject : protected QGLFunctions
{
public:
    GLObject();
    virtual ~GLObject();

    QVector3D rotationAxis;
    GLfloat rotationAngle;
    QVector3D translation;
    QVector3D scale;
    QMatrix4x4 model;

    virtual void init() = 0;
    virtual void render() = 0;
    virtual void initialiseGeometry() = 0;
    virtual void update() = 0;
};

#endif // GLOBJECT_H

#ifndef GLOBJECT_H
#define GLOBJECT_H

#include <QGLFunctions>
class QGLShaderProgram;

class GLObject : protected QGLFunctions
{
public:
    GLObject();
    virtual ~GLObject();

    virtual void init() = 0;
    virtual void render() = 0;
    virtual void initialiseGeometry() = 0;
    virtual void update() = 0;
};

#endif // GLOBJECT_H

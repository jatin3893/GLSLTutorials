#ifndef GLOBJECT_H
#define GLOBJECT_H

#include <QGLFunctions>
class QGLShaderProgram;

class GLObject : protected QGLFunctions
{
public:
    GLObject();
    virtual ~GLObject();

    /*
     * A few functions that can be used to enforce the API in
     * the child geometry objects which simplify the process of
     * drawing different types of objects.
     *
    */
    virtual void init() = 0;
    virtual void render(QGLShaderProgram *program) = 0;
    virtual void initialiseGeometry() = 0;
    virtual void update() = 0;
};

#endif // GLOBJECT_H

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "globject.h"

struct VertexData
{
    GLfloat x;
    GLfloat y;
    GLfloat z;

    void Set(GLfloat _x, GLfloat _y, GLfloat _z)
    {
        x = _x; y = _y; z = _z;
    }
};

class Triangle : GLObject
{
public:
    Triangle();
    ~Triangle();

    void init();
    void render(QGLShaderProgram *program);
    void initialiseGeometry();
    void SetVertex(int index, GLfloat _x, GLfloat _y, GLfloat _z);
    void update();

protected:
    GLuint vboId[2];
    GLuint indicesCount;
    GLuint verticesCount;
    bool isModified;
    struct VertexData vertices[3];
};

#endif // TRIANGLE_H

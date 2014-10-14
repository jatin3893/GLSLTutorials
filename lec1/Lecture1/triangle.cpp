#include "triangle.h"

// QtGL Includes
#include <QGLShaderProgram>

#include <iostream>

Triangle::Triangle()
{
    verticesCount = 3;
    indicesCount = 3;

    vertices[0].Set(1, 0, 0);
    vertices[1].Set(0, 2, 0);
    vertices[2].Set(-1, 0, 0);

    isModified = false;
}

Triangle::~Triangle()
{
    glDeleteBuffers(2, vboId);
}

void Triangle::init()
{
    initializeGLFunctions();
    glGenBuffers(2, vboId);
    initialiseGeometry();
}

void Triangle::SetVertex(int i, GLfloat _x, GLfloat _y, GLfloat _z)
{
    GLuint index = i;
    if(index >= verticesCount)
    {
        // Invalid Index Specified
        return;
    }
    vertices[index].Set(_x, _y, _z);
    isModified = true;
}

void Triangle::initialiseGeometry()
{
    // Initialise indexes for the array
    GLushort indices[] = {
        0,  1,  2
    };

    // Transfer vertex data to VBO 0
    glBindBuffer(GL_ARRAY_BUFFER, vboId[0]);
    glBufferData(GL_ARRAY_BUFFER, verticesCount * sizeof(VertexData), this->vertices, GL_STATIC_DRAW);

    // Transfer index data to VBO 1
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboId[1]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicesCount * sizeof(GLushort), indices, GL_STATIC_DRAW);
}

void Triangle::render(QGLShaderProgram *program)
{
    // Tell OpenGL which VBOs to use
    glBindBuffer(GL_ARRAY_BUFFER, vboId[0]);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboId[1]);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(VertexData), 0);

    // Draw cube geometry using indices from VBO 1
    glDrawElements(GL_TRIANGLES, indicesCount, GL_UNSIGNED_SHORT, 0);
}

void Triangle::update()
{
    if(!isModified)
        return;

    // Transfer vertex data to VBO 0
    glBindBuffer(GL_ARRAY_BUFFER, vboId[0]);
    glBufferData(GL_ARRAY_BUFFER, verticesCount * sizeof(VertexData), this->vertices, GL_STATIC_DRAW);

    isModified = false;
}

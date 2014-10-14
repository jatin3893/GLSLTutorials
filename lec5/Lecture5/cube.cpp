#include "cube.h"

#include <iostream>

// QtGL Includes
#include <QGLShaderProgram>

Cube::Cube()
{
    height = 1;
    depth = 1;
    width = 1;
    center.SetPosition(0, 0, 0);
    VertexCount = 24;
    IndicesCount = 34;
}

void Cube::setHeight(GLfloat value)
{
    this->height = value;
    isModified = true;
}

void Cube::setDepth(GLfloat value)
{
    this->depth = value;
    isModified = true;
}

void Cube::setWidth(GLfloat value)
{
    this->width = value;
    isModified = true;
}

GLfloat Cube::getHeight()
{
    return this->height;
}

GLfloat Cube::getDepth()
{
    return this->depth;
}

GLfloat Cube::getWidth()
{
    return this->width;
}

void Cube::init()
{
    initializeGLFunctions();
    glGenBuffers(2, vboId);
    initialiseGeometry();
}

void Cube::initialiseGeometry()
{
    // Initialising Vertex Positions
    {
        // Face 0
        verts[0].SetPosition(center.x - height / 2, center.y - width / 2, center.z + depth / 2); verts[0].SetColor(1, 0, 1); verts[0].SetNormals(0, 0, 1);// v0
        verts[1].SetPosition(center.x + height / 2, center.y - width / 2, center.z + depth / 2); verts[1].SetColor(1, 0, 1); verts[1].SetNormals(0, 0, 1);// v1
        verts[2].SetPosition(center.x - height / 2, center.y + width / 2, center.z + depth / 2); verts[2].SetColor(1, 0, 1); verts[2].SetNormals(0, 0, 1);// v2
        verts[3].SetPosition(center.x + height / 2, center.y + width / 2, center.z + depth / 2); verts[3].SetColor(1, 0, 1); verts[3].SetNormals(0, 0, 1);// v3

        // Face 1
        verts[4].SetPosition(center.x + height / 2, center.y - width / 2, center.z + depth / 2); verts[4].SetColor(1, 1, 0); verts[4].SetNormals(1, 0, 0);// v4
        verts[5].SetPosition(center.x + height / 2, center.y - width / 2, center.z - depth / 2); verts[5].SetColor(1, 1, 0); verts[5].SetNormals(1, 0, 0);// v5
        verts[6].SetPosition(center.x + height / 2, center.y + width / 2, center.z + depth / 2); verts[6].SetColor(1, 1, 0); verts[6].SetNormals(1, 0, 0);// v6
        verts[7].SetPosition(center.x + height / 2, center.y + width / 2, center.z - depth / 2); verts[7].SetColor(1, 1, 0); verts[7].SetNormals(1, 0, 0);// v7

        // Face 2
        verts[8].SetPosition(center.x + height / 2, center.y - width / 2, center.z - depth / 2); verts[8].SetColor(0, 1, 1); verts[8].SetNormals(0, 0, -1);// v8
        verts[9].SetPosition(center.x - height / 2, center.y - width / 2, center.z - depth / 2); verts[9].SetColor(0, 1, 1); verts[9].SetNormals(0, 0, -1);// v9
        verts[10].SetPosition(center.x + height / 2, center.y + width / 2, center.z - depth / 2); verts[10].SetColor(0, 1, 1); verts[10].SetNormals(0, 0, -1);// v10
        verts[11].SetPosition(center.x - height / 2, center.y + width / 2, center.z - depth / 2); verts[11].SetColor(0, 1, 1); verts[11].SetNormals(0, 0, -1);// v11

        // Face 3
        verts[12].SetPosition(center.x - height / 2, center.y - width / 2, center.z - depth / 2); verts[12].SetColor(0, 0, 1); verts[12].SetNormals(-1, 0, 0);// v12
        verts[13].SetPosition(center.x - height / 2, center.y - width / 2, center.z + depth / 2); verts[13].SetColor(0, 0, 1); verts[13].SetNormals(-1, 0, 0);// v13
        verts[14].SetPosition(center.x - height / 2, center.y + width / 2, center.z - depth / 2); verts[14].SetColor(0, 0, 1); verts[14].SetNormals(-1, 0, 0);// v14
        verts[15].SetPosition(center.x - height / 2, center.y + width / 2, center.z + depth / 2); verts[15].SetColor(0, 0, 1); verts[15].SetNormals(-1, 0, 0);// v15

        // Face 4
        verts[16].SetPosition(center.x - height / 2, center.y - width / 2, center.z - depth / 2); verts[16].SetColor(1, 0, 0); verts[16].SetNormals(0, -1, 0);// v16
        verts[17].SetPosition(center.x + height / 2, center.y - width / 2, center.z - depth / 2); verts[17].SetColor(1, 0, 0); verts[17].SetNormals(0, -1, 0);// v17
        verts[18].SetPosition(center.x - height / 2, center.y - width / 2, center.z + depth / 2); verts[18].SetColor(1, 0, 0); verts[18].SetNormals(0, -1, 0);// v18
        verts[19].SetPosition(center.x + height / 2, center.y - width / 2, center.z + depth / 2); verts[19].SetColor(1, 0, 0); verts[19].SetNormals(0, -1, 0);// v19

        // Face 5
        verts[20].SetPosition(center.x - height / 2, center.y + width / 2, center.z + depth / 2); verts[20].SetColor(0, 1, 0); verts[20].SetNormals(0, 1, 0);// v20
        verts[21].SetPosition(center.x + height / 2, center.y + width / 2, center.z + depth / 2); verts[21].SetColor(0, 1, 0); verts[21].SetNormals(0, 1, 0);// v21
        verts[22].SetPosition(center.x - height / 2, center.y + width / 2, center.z - depth / 2); verts[22].SetColor(0, 1, 0); verts[22].SetNormals(0, 1, 0);// v22
        verts[23].SetPosition(center.x + height / 2, center.y + width / 2, center.z - depth / 2); verts[23].SetColor(0, 1, 0); verts[23].SetNormals(0, 1, 0);// v23
    }

    GLushort indices[] = {
        0,  1,  2,  3,  3,      // Face 0 - triangle strip ( v0,  v1,  v2,  v3)
        4,  4,  5,  6,  7,  7,  // Face 1 - triangle strip ( v4,  v5,  v6,  v7)
        8,  8,  9, 10, 11, 11,  // Face 2 - triangle strip ( v8,  v9, v10, v11)
        12, 12, 13, 14, 15, 15, // Face 3 - triangle strip (v12, v13, v14, v15)
        16, 16, 17, 18, 19, 19, // Face 4 - triangle strip (v16, v17, v18, v19)
        20, 20, 21, 22, 23      // Face 5 - triangle strip (v20, v21, v22, v23)
    };

    // Transfer vertex data to VBO 0
    glBindBuffer(GL_ARRAY_BUFFER, vboId[0]);
    glBufferData(GL_ARRAY_BUFFER, VertexCount * sizeof(VertexData), verts, GL_STATIC_DRAW);

    // Transfer index data to VBO 1
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboId[1]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, IndicesCount * sizeof(GLushort), indices, GL_STATIC_DRAW);
}

void Cube::render()
{
    // Tell OpenGL which VBOs to use
    glBindBuffer(GL_ARRAY_BUFFER, vboId[0]);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboId[1]);

    // Vertex Position
    glEnableVertexAttribArray(VertexPositionAttrib);
    glVertexAttribPointer(VertexPositionAttrib, 3, GL_FLOAT, GL_FALSE, sizeof(VertexData), 0);

    // Vertex Normals
    glEnableVertexAttribArray(VertexNormalAttrib);
    glVertexAttribPointer(VertexNormalAttrib, 3, GL_FLOAT, GL_FALSE, sizeof(VertexData), (void *)(3 * sizeof(GLfloat)));

    // Vertex Color
    glEnableVertexAttribArray(VertexColorAttrib);
    glVertexAttribPointer(VertexColorAttrib, 3, GL_FLOAT, GL_FALSE, sizeof(VertexData), (void *)(6 * sizeof(GLfloat)));

    // Draw cube geometry using indices from VBO 1
    glDrawElements(GL_TRIANGLE_STRIP, IndicesCount, GL_UNSIGNED_SHORT, 0);
}

void Cube::update()
{
    if(!isModified)
        return;
    // Face 0
    verts[0].SetPosition(center.x - height / 2, center.y - width / 2, center.z + depth / 2);// v0
    verts[1].SetPosition(center.x + height / 2, center.y - width / 2, center.z + depth / 2);// v1
    verts[2].SetPosition(center.x - height / 2, center.y + width / 2, center.z + depth / 2);// v2
    verts[3].SetPosition(center.x + height / 2, center.y + width / 2, center.z + depth / 2);// v3

    // Face 1
    verts[4].SetPosition(center.x + height / 2, center.y - width / 2, center.z + depth / 2);// v4
    verts[5].SetPosition(center.x + height / 2, center.y - width / 2, center.z - depth / 2);// v5
    verts[6].SetPosition(center.x + height / 2, center.y + width / 2, center.z + depth / 2);// v6
    verts[7].SetPosition(center.x + height / 2, center.y + width / 2, center.z - depth / 2);// v7

    // Face 2
    verts[8].SetPosition(center.x + height / 2, center.y - width / 2, center.z - depth / 2);// v8
    verts[9].SetPosition(center.x - height / 2, center.y - width / 2, center.z - depth / 2);// v9
    verts[10].SetPosition(center.x + height / 2, center.y + width / 2, center.z - depth / 2);// v10
    verts[11].SetPosition(center.x - height / 2, center.y + width / 2, center.z - depth / 2);// v11

    // Face 3
    verts[12].SetPosition(center.x - height / 2, center.y - width / 2, center.z - depth / 2);// v12
    verts[13].SetPosition(center.x - height / 2, center.y - width / 2, center.z + depth / 2);// v13
    verts[14].SetPosition(center.x - height / 2, center.y + width / 2, center.z - depth / 2);// v14
    verts[15].SetPosition(center.x - height / 2, center.y + width / 2, center.z + depth / 2);// v15

    // Face 4
    verts[16].SetPosition(center.x - height / 2, center.y - width / 2, center.z - depth / 2);// v16
    verts[17].SetPosition(center.x + height / 2, center.y - width / 2, center.z - depth / 2);// v17
    verts[18].SetPosition(center.x - height / 2, center.y - width / 2, center.z + depth / 2);// v18
    verts[19].SetPosition(center.x + height / 2, center.y - width / 2, center.z + depth / 2);// v19

    // Face 5
    verts[20].SetPosition(center.x - height / 2, center.y + width / 2, center.z + depth / 2);// v20
    verts[21].SetPosition(center.x + height / 2, center.y + width / 2, center.z + depth / 2);// v21
    verts[22].SetPosition(center.x - height / 2, center.y + width / 2, center.z - depth / 2);// v22
    verts[23].SetPosition(center.x + height / 2, center.y + width / 2, center.z - depth / 2);// v23

    // Transfer vertex data to VBO 0
    glBindBuffer(GL_ARRAY_BUFFER, vboId[0]);
    glBufferData(GL_ARRAY_BUFFER, VertexCount * sizeof(VertexData), verts, GL_STATIC_DRAW);

    isModified = false;
}

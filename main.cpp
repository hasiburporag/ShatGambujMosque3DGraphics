/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

#include <stdlib.h>
#include<Windows.h>
#ifdef __aPPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <math.h>
#define PI 3.1415927

#include <iostream>

#include<stdio.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/GLAUX.h>

using namespace std;
double a=0.0,b=-2.0,c=-2.0;
GLfloat	l_t=0,t_l=0.0;
GLuint texture[50];
int flag=0;
int up=0;
int down=0;
float _angle = -360.0f;
float zAxis = -6;
void LoadGLTextures()
{
    glPushMatrix();
    AUX_RGBImageRec* TextureImage;

    glGenTextures(10,texture);

    if (TextureImage = auxDIBImageLoad("D:\\CSE 16\\CSE-16\\Level 4 Term 2\\CSE 414\\SGM\\bin\\Debug\\brick.bmp"))
    {
        glBindTexture(GL_TEXTURE_2D, texture[0]);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
        glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
    }
    if (TextureImage = auxDIBImageLoad("D:\\CSE 16\\CSE-16\\Level 4 Term 2\\CSE 414\\SGM\\bin\\Debug\\brickH.bmp"))
    {
        glBindTexture(GL_TEXTURE_2D, texture[1]);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
        glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
    }
    if (TextureImage = auxDIBImageLoad("D:\\CSE 16\\CSE-16\\Level 4 Term 2\\CSE 414\\SGM\\bin\\Debug\\brickH1.bmp"))
    {
        glBindTexture(GL_TEXTURE_2D, texture[2]);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
        glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
    }
    if (TextureImage = auxDIBImageLoad("D:\\CSE 16\\CSE-16\\Level 4 Term 2\\CSE 414\\SGM\\bin\\Debug\\brickW.bmp"))
    {
        glBindTexture(GL_TEXTURE_2D, texture[3]);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
        glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
    }
    if (TextureImage = auxDIBImageLoad("D:\\CSE 16\\CSE-16\\Level 4 Term 2\\CSE 414\\SGM\\bin\\Debug\\brickW1.bmp"))
    {
        glBindTexture(GL_TEXTURE_2D, texture[4]);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
        glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
    }
    if (TextureImage = auxDIBImageLoad("D:\\CSE 16\\CSE-16\\Level 4 Term 2\\CSE 414\\SGM\\bin\\Debug\\grass.bmp"))
    {
        glBindTexture(GL_TEXTURE_2D, texture[5]);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
        glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
    }
    if (TextureImage = auxDIBImageLoad("D:\\CSE 16\\CSE-16\\Level 4 Term 2\\CSE 414\\SGM\\bin\\Debug\\road1.bmp"))
    {
        glBindTexture(GL_TEXTURE_2D, texture[7]);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
        glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
    }
    if (TextureImage = auxDIBImageLoad("D:\\CSE 16\\CSE-16\\Level 4 Term 2\\CSE 414\\SGM\\bin\\Debug\\sky.bmp"))
    {
        glBindTexture(GL_TEXTURE_2D, texture[6]);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
        glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
    }

}


// Draw A Quad with texture
void quad()
{

    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glBegin(GL_QUADS);


    //glColor3f(1.0f,1.0f,0.0f);
    glTexCoord2f(0.0f,1.0f);
    glVertex3f(-1.0f,1.0f,8.0f);					// Top front Of The Quad (left)
    glTexCoord2f(1.0f,1.0f);
    glVertex3f(-1.0f,1.0f,1.0f);					// Top back Of The Quad (left)
    glTexCoord2f(1.0f,0.0f);
    glVertex3f(-1.0f,-1.0f,1.0f);					// Bottom back Of The Quad (left)
    glTexCoord2f(0.0f,0.0f);
    glVertex3f(-1.0f,-1.0f,8.0f);					// Bottom front Of The Quad (left)

    //glColor3f(0.0f,1.0f,0.0f);

    glTexCoord2f(0.0f,1.0f);
    glVertex3f(1.0f,1.0f,8.0f);					 // Top front Of The Quad (right)
    glTexCoord2f(1.0f,1.0f);
    glVertex3f(1.0f,1.0f,1.0f);					// Top back Of The Quad (right)
    glTexCoord2f(1.0f,0.0f);
    glVertex3f(1.0f,-1.0f,1.0f);					// Bottom back Of The Quad (right)
    glTexCoord2f(0.0f,0.0f);
    glVertex3f(1.0f,-1.0f,8.0f);					// Bottom front Of The Quad (right)

    glEnd();

    glBindTexture(GL_TEXTURE_2D, texture[1]);
    glBegin(GL_QUADS);

    //glColor3f(1.0f,0.0f,1.0f);
    glTexCoord2f(0.0f,1.0f);
    glVertex3f(1.0f,1.0f,8.0f);					 // Right front Of The Quad (top)
    glTexCoord2f(1.0f,1.0f);
    glVertex3f(1.0f,1.0f,1.0f);					// Right back Of The Quad (top)
    glTexCoord2f(1.0f,0.0f);
    glVertex3f(-1.0f,1.0f,1.0f);				    // Left back Of The Quad (top)
    glTexCoord2f(0.0f,0.0f);
    glVertex3f(-1.0f,1.0f,8.0f);				    // Left front Of The Quad (top)


    //glColor3f(0.0f,1.0f,1.0f);
    glTexCoord2f(0.0f,1.0f);
    glVertex3f(1.0f,-1.0f,8.0f);					// Right front Of The Quad (bottom)
    glTexCoord2f(1.0f,1.0f);
    glVertex3f(1.0f,-1.0f,1.0f);					// Right back Of The Quad (bottom)
    glTexCoord2f(1.0f,0.0f);
    glVertex3f(-1.0f,-1.0f,1.0f);				    // Left back Of The Quad (bottom)
    glTexCoord2f(0.0f,0.0f);
    glVertex3f(-1.0f,-1.0f,8.0f);				    // Left front Of The Quad (bottom)

    glEnd();

    glBindTexture(GL_TEXTURE_2D, texture[2]);
    glBegin(GL_QUADS);

    //glColor3f(0.0f,0.0f,1.0f);
    glTexCoord2f(0.0f,1.0f);
    glVertex3f(1.0f,1.0f,1.0f);					 // Top Right Of The Quad (Back)
    glTexCoord2f(1.0f,1.0f);
    glVertex3f(-1.0f,1.0f,1.0f);					// Top Left Of The Quad (Back)
    glTexCoord2f(1.0f,0.0f);
    glVertex3f(-1.0f,-1.0f,1.0f);					// Bottom Left Of The Quad (Back)
    glTexCoord2f(0.0f,0.0f);
    glVertex3f(1.0f,-1.0f,1.0f);					// Bottom Right Of The Quad (Back)


    //glColor3f(1.0f,0.0f,0.0f);
    glTexCoord2f(0.0f,1.0f);
    glVertex3f(1.0f,1.0f,8.0f);					// Top Right Of The Quad (Front)
    glTexCoord2f(1.0f,1.0f);
    glVertex3f(-1.0f,1.0f,8.0f);					// Top Left Of The Quad (Front)
    glTexCoord2f(1.0f,0.0f);
    glVertex3f(-1.0f,-1.0f,8.0f);					// Bottom Left Of The Quad (Front)
    glTexCoord2f(0.0f,0.0f);
    glVertex3f(1.0f,-1.0f,8.0f);				    // Bottom Right Of The Quad (Front)


    glEnd();
}

void init(void)
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING); //Enable lighting
    glEnable(GL_LIGHT0); //Enable light #0
    glEnable(GL_LIGHT1); //Enable light #1
    glEnable(GL_LIGHT2); //Enable light #1

    glEnable(GL_LIGHT3); //Enable light #0
    glEnable(GL_LIGHT4); //Enable light #1
    glEnable(GL_LIGHT5); //Enable light #1
    glEnable(GL_LIGHT6); //Enable light #0
    glEnable(GL_LIGHT7); //Enable light #1

    glEnable(GL_NORMALIZE);

    LoadGLTextures();

    //glEnable(GL_TEXTURE_2D);
    glClearColor (0.39, 0.78, 0.52, 0.0);
}

void door()
{
    glBegin(GL_QUADS);


    glVertex3f(0.25f,-0.4f, 0.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(0.25f, 0.1f, 0.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(0.0f,  0.1f, 0.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(0.0f,  -0.15f, 0.0f);
    glTexCoord2f(0.0f, 0.0f);

    glVertex3f(-0.25f,-0.4f, 0.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-0.25f, 0.1f, 0.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(0.0f,  0.1f, 0.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(0.0f,  -0.15f, 0.0f);
    glTexCoord2f(0.0f, 0.0f);
    glEnd();

    glBegin(GL_QUADS); //
    //low
    glColor3f (0.9, 0.9, 0.9);
    glVertex3f(0.25f, -1.0f, 0.06f);
    glVertex3f(0.25f, -1.0f, -0.05f);
    glVertex3f(0.25f, 0.1f, -0.05f);
    glVertex3f(0.25f, 0.1f, 0.06f);

    glVertex3f(-0.25f, -1.0f, 0.06f);
    glVertex3f(-0.25f, -1.0f, -0.05f);
    glVertex3f(-0.25f, 0.1f, -0.05f);
    glVertex3f(-0.25f, 0.1f, 0.06f);


    glVertex3f(-0.25f, -1.0f, 0.06f);
    glVertex3f(-0.25f, -1.0f, -0.05f);
    glVertex3f(0.25f, -1.0f, -0.05f);
    glVertex3f(0.25f, -1.0f, 0.06f);

    glEnd();


    glBegin(GL_QUADS); //Begin quadrilateral coordinate
    //top first
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f(0.25f, -0.05f, 0.02f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(0.25f, 0.1f, 0.02f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-0.25f, 0.1f, 0.02f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-0.25f, -0.05f, 0.02f);
    glTexCoord2f(0.0f, 0.0f);

    glVertex3f(0.25f, -0.05f, 0.02f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(0.25f, -0.05f, 0.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-0.25f, -0.05f, 0.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-0.25f, -0.05f, 0.02f);
    glTexCoord2f(0.0f, 0.0f);
    glEnd();

    glBegin(GL_QUADS); //Begin quadrilateral coordinate
    //top second
    glVertex3f(0.25f, 0.0f, 0.04f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(0.25f, 0.1f, 0.04f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-0.25f, 0.1f, 0.04f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-0.25f, 0.0f, 0.04f);
    glTexCoord2f(0.0f, 0.0f);

    glVertex3f(0.25f, 0.0f, 0.04f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(0.25f, 0.0f, 0.02f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-0.25f, 0.0f, 0.02f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-0.25f, 0.0f, 0.04f);
    glTexCoord2f(0.0f, 0.0f);
    glEnd();


    glBegin(GL_QUADS); //Begin quadrilateral coordinate
    //top third

    glVertex3f(0.25f, 0.05f, 0.06f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(0.25f, 0.1f, 0.06f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-0.25f, 0.1f, 0.06f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-0.25f, 0.05f, 0.06f);
    glTexCoord2f(0.0f, 0.0f);

    glVertex3f(0.25f, 0.05f, 0.06f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(0.25f, 0.05f, 0.04f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-0.25f, 0.05f, 0.04f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-0.25f, 0.05f, 0.06f);
    glTexCoord2f(0.0f, 0.0f);
    glEnd();
}

void middelDoor()
{
    glBegin(GL_QUADS); //
    //top

    glVertex3f(0.325f,-0.3f, 0.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(0.325f, 0.3f, 0.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(0.0f,  0.3f, 0.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(0.0f,  0.0f, 0.0f);
    glTexCoord2f(0.0f, 0.0f);

    glVertex3f(-0.325f,-0.3f, 0.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-0.325f, 0.3f, 0.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(0.0f,  0.3f, 0.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(0.0f,  0.0f, 0.0f);
    glTexCoord2f(0.0f, 0.0f);
    glEnd();

    glBegin(GL_QUADS); //
    //low
    glColor3f (0.9, 0.9, 0.9);
    glVertex3f(0.325f, -1.0f, 0.06f);
    glVertex3f(0.325f, -1.0f, -0.05f);
    glVertex3f(0.325f, 0.3f, -0.05f);
    glVertex3f(0.325f, 0.3f, 0.06f);

    glVertex3f(-0.325f, -1.0f, 0.06f);
    glVertex3f(-0.325f, -1.0f, -0.05f);
    glVertex3f(-0.325f, 0.3f, -0.05f);
    glVertex3f(-0.325f, 0.3f, 0.06f);


    glVertex3f(-0.325f, -1.0f, 0.06f);
    glVertex3f(-0.325f, -1.0f, -0.05f);
    glVertex3f(0.325f, -1.0f, -0.05f);
    glVertex3f(0.325f, -1.0f, 0.06f);

    glEnd();


    glBegin(GL_QUADS); //Begin quadrilateral coordinate
    //top first
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f(0.325f, 0.15f, 0.02f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(0.325f, 0.3f, 0.02f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-0.325f, 0.3f, 0.02f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-0.325f, 0.15f, 0.02f);
    glTexCoord2f(0.0f, 0.0f);

    glVertex3f(0.325f, 0.15f, 0.02f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(0.325f, 0.15f, 0.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-0.325f, 0.15f, 0.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-0.325f, 0.15f, 0.02f);
    glTexCoord2f(0.0f, 0.0f);
    glEnd();

    glBegin(GL_QUADS); //Begin quadrilateral coordinate
    //top second

    glVertex3f(0.325f, 0.20f, 0.04f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(0.325f, 0.3f, 0.04f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-0.325f, 0.3f, 0.04f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-0.325f, 0.20f, 0.04f);
    glTexCoord2f(0.0f, 0.0f);

    glVertex3f(0.325f, 0.20f, 0.04f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(0.325f, 0.20f, 0.02f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-0.325f, 0.20f, 0.02f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-0.325f, 0.20f, 0.04f);
    glTexCoord2f(0.0f, 0.0f);
    glEnd();


    glBegin(GL_QUADS); //Begin quadrilateral coordinate
    //top third

    glVertex3f(0.325f, 0.25f, 0.06f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(0.325f, 0.3f, 0.06f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-0.325f, 0.3f, 0.06f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-0.325f, 0.25f, 0.06f);
    glTexCoord2f(0.0f, 0.0f);

    glVertex3f(0.325f, 0.25f, 0.06f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(0.325f, 0.25f, 0.04f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-0.325f, 0.25f, 0.04f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-0.325f, 0.25f, 0.06f);
    glTexCoord2f(0.0f, 0.0f);
    glEnd();

}

void mimbor()
{
    glBegin(GL_QUADS); //
    //top


    glVertex3f(0.1f,0.6f, 0.3f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(0.1f,0.6f, 0.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-0.1f,0.6f, 0.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-0.1f,0.6f, 0.3f);
    glTexCoord2f(0.0f, 0.0f);

    glVertex3f(0.1f,0.6f, 0.3f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(0.2f,0.3f, 0.3f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-0.2f,0.3f, 0.3f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-0.1f,0.6f, 0.3f);
    glTexCoord2f(0.0f, 0.0f);


    glVertex3f(0.2f,-0.5f, 0.3f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(0.2f, 0.3f, 0.3f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-0.2f,0.3f, 0.3f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-0.2f, -0.5f, 0.3f);
    glTexCoord2f(0.0f, 0.0f);

    //right

    glVertex3f(0.2f,-0.5f, 0.3f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(0.2f, 0.3f, 0.3f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(0.365f,0.3f, 0.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(0.365f, -0.5f, 0.0f);
    glTexCoord2f(0.0f, 0.0f);

    glVertex3f(0.1f,0.6f, 0.3f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(0.2f,0.3f, 0.3f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(0.365f,0.3f, 0.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(0.1f,0.6f, 0.0f);
    glTexCoord2f(0.0f, 0.0f);

    //left

    glVertex3f(-0.2f,-0.5f, 0.3f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-0.2f, 0.3f, 0.3f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-0.365f,0.3f, 0.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-0.365f, -0.5f, 0.0f);
    glTexCoord2f(0.0f, 0.0f);

    glVertex3f(-0.1f,0.6f, 0.3f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-0.2f,0.3f, 0.3f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-0.365f,0.3f, 0.0f);
    glTexCoord2f(0.0f,1.0f);
    glVertex3f(-0.1f,0.6f, 0.0f);
    glTexCoord2f(0.0f, 0.0f);

    glEnd();
}

void draw_cylinder(GLfloat radius,
                   GLfloat height,
                   GLubyte R,
                   GLubyte G,
                   GLubyte B)
{
    GLfloat x              = 0.0;
    GLfloat y              = 0.0;
    GLfloat angle          = 0.0;
    GLfloat angle_stepsize = 0.1;



    glRotatef(-90, 1.0, 0.0, 0.0);
    /** Draw the tube */
    glColor3ub(R-40,G-40,B-40);
    glBegin(GL_QUAD_STRIP);
    angle = 0.1;

    while( angle < 2*PI )
    {
        x = radius * cos(angle);
        y = radius * sin(angle);
        glVertex3f(x, y, height);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(x, y, 0.0f);
        glTexCoord2f(1.0f, 1.0f);
        angle = angle + angle_stepsize;
    }
    glVertex3f(radius, 0.0, height);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(radius, 0.0, 0.0f);
    glTexCoord2f(0.0f, 0.0f);
    glEnd();


    glColor3ub(R,G,B);
    glBegin(GL_POLYGON);
    angle = 0.0;
    while( angle < 2*PI )
    {
        x = radius * cos(angle);
        y = radius * sin(angle);
        glVertex3f(x, y, height);
        angle = angle + angle_stepsize;
    }
    glVertex3f(radius, 0.0, height);
    glEnd();
}
void drawHalfSphere(int scaley, int scalex, GLfloat r)
{
    glColor3f(1.0f, 1.0f, 0.0f);
    int i, j;
    GLfloat v[scalex*scaley][3];

    for (i=0; i<scalex; ++i)
    {
        for (j=0; j<scaley; ++j)
        {
            v[i*scaley+j][0]=r*cos(j*2*M_PI/scaley)*cos(i*M_PI/(2*scalex));
            v[i*scaley+j][1]=r*sin(i*M_PI/(2*scalex));
            v[i*scaley+j][2]=r*sin(j*2*M_PI/scaley)*cos(i*M_PI/(2*scalex));
        }
    }

    glBegin(GL_QUADS);
    for (i=0; i<scalex-1; ++i)
    {
        for (j=0; j<scaley; ++j)
        {
            glVertex3fv(v[i*scaley+j]);
            glVertex3fv(v[i*scaley+(j+1)%scaley]);
            glVertex3fv(v[(i+1)*scaley+(j+1)%scaley]);
            glVertex3fv(v[(i+1)*scaley+j]);
        }
    }
    glEnd();
}
void singleDom()
{
    glRotatef(0.0, 1.0, 0.0, 0.0);
    drawHalfSphere(50, 50, 0.5);
    glRotatef(0.0, 1.0, 0.0, 0.0);
}

void draw_ring_design(GLfloat radius,
                      GLfloat height,
                      GLubyte R,
                      GLubyte G,
                      GLubyte B)
{
    GLfloat x              = 0.0;
    GLfloat y              = 0.0;
    GLfloat angle          = 0.0;
    GLfloat angle_stepsize = 0.1;


    glColor3ub(R,G,B);
    glBegin(GL_POLYGON);
    angle = 0.0;
    while( angle < 2*PI )
    {
        x = radius * cos(angle);
        y = radius * sin(angle);
        glVertex3f(x, y, height);
        angle = angle + angle_stepsize;
    }
    glVertex3f(radius, 0.0, height);
    glEnd();
}

void drawMinarRing(float height)
{
    //glTranslatef(0.0,-0.4,-3.0);
    glRotatef(-90, 1.0, 0.0, 0.0);
    draw_ring_design(0.51, height, 10, 10, 40);
    height=height+0.01;
    draw_ring_design(0.52, height, 20, 20, 50);
    height=height+0.01;
    draw_ring_design(0.53, height, 30, 30, 60);
    height=height+0.01;
    draw_ring_design(0.54, height, 40, 40, 70);
    height=height+0.01;
    draw_ring_design(0.55, height, 50, 50, 80);
    height=height+0.01;
    draw_ring_design(0.55, height, 50, 50, 80);
    height=height+0.01;
    draw_ring_design(0.54, height, 40, 40, 70);
    height=height+0.01;
    draw_ring_design(0.53, height, 30, 30, 60);
    height=height+0.01;
    draw_ring_design(0.52, height, 20, 20, 50);
    height=height+0.01;
    draw_ring_design(0.51, height, 10, 10, 40);
    glRotatef(90, 1.0, 0.0, 0.0);
    //glTranslatef(0.0,0.4,3.0);
}

void topView()
{
    //glRotatef(0.0f, 1.0f, 0.0f, 0.0f);
    glColor3f(0.5f, 0.0f, 0.0f);

    //middle dom
    glTranslatef(0.0f, 1.2f, -1.35f);
    drawHalfSphere(50, 50, 0.5);
    glTranslatef(0.0f, -1.2f, 1.35f);

    glTranslatef(0.0f, 1.2f, 0.0f);
    drawHalfSphere(50, 50, 0.5);
    glTranslatef(0.0f, -1.2f, 0.0f);

    glTranslatef(0.0f, 1.2f, 1.35f);
    drawHalfSphere(50, 50, 0.5);
    glTranslatef(0.0f, -1.2f, -1.35f);

    float i=0,j=0,k=1.05,h=0;
    int count =0;
    for(j=-1.715; j<=2; j=j+0.57)//z axis
    {
        h=k;
        count++;
        float inc=(1.2-h)/5.0;
        for(i=-3.65; i<-0.56; i=i+0.7)//x axis
        {
            glTranslatef(i, h, j);
            drawHalfSphere(50, 50, 0.28);
            glTranslatef(-i, -h, -j);
            if(count==4) h=h;
            else h=h+inc;
        }
        if(count<=3) k=k+0.05;
        else k=k-0.05;
    }

    k=1.05;
    h=0;
    count =0;
    for(j=-1.715; j<=2; j=j+0.57)//z axis
    {
        h=k;
        count++;
        float inc=(1.2-h)/5.0;
        for(i=3.65; i>0.56; i=i-0.7)//x axis
        {
            glTranslatef(i, h, j);
            drawHalfSphere(50, 50, 0.28);
            glTranslatef(-i, -h, -j);
            if(count==4) h=h;
            else h=h+inc;
        }
        if(count<=3) k=k+0.05;
        else k=k-0.05;
    }


    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);

    glNormal3f(0.0f, 0.0f, 1.0f);

    glVertex3f(-4.0f, 1.0f, -2.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-4.0f, 1.2f, 0.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(0.0f, 1.20f, 0.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(0.0f, 1.20f, -2.0f);
    glTexCoord2f(0.0f, 0.0f);



    glVertex3f(0.0f, 1.20f, -2.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(0.0f, 1.20f, 0.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(4.0f, 1.2f, 0.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(4.0f, 1.0f, -2.0f);
    glTexCoord2f(0.0f, 0.0f);


    glNormal3f(0.0f, 0.0f, 1.0f);

    glVertex3f(-4.0f, 1.0f, 2.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-4.0f, 1.20f, 0.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(0.0f, 1.20f, 0.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(0.0f, 1.20f, 2.0f);
    glTexCoord2f(0.0f, 0.0f);



    glVertex3f(4.0f, 1.20f, 0.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(4.0f, 1.0f, 2.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(0.0f, 1.2f, 2.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(0.0f, 1.2f, 0.0f);
    glTexCoord2f(0.0f, 0.0f);

    glEnd();
}



float rF = 1.0f;
float gF = 1.0f;
float bF = 1.0f;


void sky()
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[6]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);


    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);

    glNormal3f(0.0f,1.0f,1.0f);

    glVertex3f(-18.0f, -10.0f, -6.5f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(18.0f, -10.0f, -6.5f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(18.0f, 10.0f, -6.5f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-18.0f, 10.0f, -6.5f);
    glTexCoord2f(0.0f, 0.0f);

    glEnd();


    glDisable(GL_TEXTURE_2D);
}

void grass()
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[5]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);

    glNormal3f(1.0f,1.0f,1.0f);

    glVertex3f(-16.0f, -1.0f, -10.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(16.0f, -1.0f, -10.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(16.0f, -1.0f, 10.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-16.0f, -1.0f, 10.0f);
    glTexCoord2f(0.0f, 0.0f);

    glEnd();

    glDisable(GL_TEXTURE_2D);
}

void display(void)
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();


    int w=glutGet(GLUT_WINDOW_WIDTH);
    int h=glutGet(GLUT_WINDOW_HEIGHT);
    gluPerspective(45,w/h,1,200);



    glMatrixMode(GL_MODELVIEW);


    glLoadIdentity();

    gluLookAt(                       //  eyex, eyey, eyez specify the position of the eye point, centerx, centery, centerz specify the position of reference point, upx, upy, upz specify the direction of up vector
        a,b,c,
        0,-2,-50,
        0,1,0
    );

    glTranslatef(0.0f, -2.0f, -13.0f);

    glPushMatrix();
    glRotatef(l_t,0.0f,1.0f,0.0f);
    glRotatef(t_l,1.0f,0.0f,0.0f);

    //Add ambient light
    GLfloat ambientColor[] = {rF, gF, bF, 1.0f}; //Color (0.2, 0.2, 0.2)
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);

    //Add positioned light
    GLfloat lightColor0[] = {rF, gF, bF, 1.0f}; //Color (0.5, 0.5, 0.5)
    GLfloat lightPos0[] = {4.0f, 0.0f, 8.0f, 1.0f}; //Positioned at (4, 0, 8)
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);

    //Add directed light
    GLfloat lightColor1[] = {rF, gF, bF, 1.0f}; //Color (0.5, 0.2, 0.2)
    //Coming from the direction (-1, 0.5, 0.5)
    GLfloat lightPos1[] = {-1.0f, 0.5f, 0.5f, 0.0f};
    glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
    glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);


    GLfloat lightColor2[] = {rF, gF, bF, 1.0f}; //Color (0.5, 0.2, 0.2)
    //Coming from the direction (-1, 0.5, 0.5)
    GLfloat lightPos2[] = {-1.0f, 0.5f, 0.5, 0.0f};
    glLightfv(GL_LIGHT2, GL_DIFFUSE, lightColor2);
    glLightfv(GL_LIGHT2, GL_POSITION, lightPos2);


    sky();
    grass();



    glRotatef(_angle, 0.0f, 1.0f, 0.0f);






    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[4]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);


    ///front er upore
    glNormal3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex3f(-4.0f, 1.0f, 2.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(0.0f, 1.2f, 2.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(4.0f, 1.0f, 2.0f);
    glTexCoord2f(1.0f, 1.0f);
    glEnd();

    ///front er upore
    glBegin(GL_QUADS);
    glVertex3f(-4.0f, 0.6f, 2.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(4.0f, 0.6f, 2.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(4.0f, 1.0f, 2.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-4.0f, 1.0f, 2.0f);
    glTexCoord2f(0.0f, 0.0f);
    glEnd();

    ///right side er upore
    glNormal3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLES);

    glVertex3f(4.0f, 1.0f, 2.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(4.0f, 1.2f, 0.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(4.0f, 1.0f, -2.0f);
    glTexCoord2f(1.0f, 1.0f);
    glEnd();

    ///right side er upore
    glBegin(GL_QUADS);
    glVertex3f(4.0f, 0.6f, -2.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(4.0f, 0.6f, 2.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(4.0f, 1.0f, 2.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(4.0f, 1.0f, -2.0f);
    glTexCoord2f(0.0f, 0.0f);
    glEnd();

    ///left side er upore
    glNormal3f(0.0f, 0.0f, -1.0f);
    glBegin(GL_TRIANGLES);

    glVertex3f(-4.0f, 1.0f, 2.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-4.0f, 1.2f, 0.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-4.0f, 1.0f, -2.0f);
    glTexCoord2f(1.0f, 1.0f);
    glEnd();

    ///left side er upore
    glBegin(GL_QUADS);
    glVertex3f(-4.0f, 0.6f, -2.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-4.0f, 0.6f, 2.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-4.0f, 1.0f, 2.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-4.0f, 1.0f, -2.0f);
    glTexCoord2f(0.0f, 0.0f);
    glEnd();

    ///back er upore
    glNormal3f(0.0f, 0.0f, -1.0f);
    glBegin(GL_TRIANGLES);
    glVertex3f(-4.0f, 1.0f, -2.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(0.0f, 1.2f, -2.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(4.0f, 1.0f, -2.0f);
    glTexCoord2f(1.0f, 1.0f);
    glEnd();

    ///back er upore
    glBegin(GL_QUADS);
    glNormal3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-4.0f, 0.6f, -2.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(4.0f, 0.6f, -2.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(4.0f, 1.0f, -2.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-4.0f, 1.0f, -2.0f);
    glTexCoord2f(0.0f, 0.0f);
    glEnd();
//    glDisable(GL_TEXTURE_2D);
//
//    glEnable(GL_TEXTURE_2D);
//    glBindTexture(GL_TEXTURE_2D, brickH);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

//front side slice
    glNormal3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS); //
    glVertex3f(-4.0f,-0.5f, 2.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-3.9f,-0.5f, 2.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-3.9f,0.6f, 2.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-4.0f,0.6f, 2.0f);
    glTexCoord2f(0.0f, 0.0f);


    glVertex3f(4.0f,-0.5f, 2.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(3.9f,-0.5f, 2.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(3.9f,0.6f, 2.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(4.0f,0.6f, 2.0f);
    glTexCoord2f(0.0f, 0.0f);
    glEnd();

    //left side slice
    glNormal3f(-1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS); //
    glVertex3f(-4.0f,-0.5f, 2.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-4.0f,-0.5f, 1.75f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-4.0f,0.6f, 1.75f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-4.0f,0.6f, 2.0f);
    glTexCoord2f(0.0f, 0.0f);


    glVertex3f(-4.0f,-0.5f, -2.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-4.0f,-0.5f, -1.75f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-4.0f,0.6f, -1.75f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-4.0f,0.6f, -2.0f);
    glTexCoord2f(0.0f, 0.0f);
    glEnd();

    //right side slice
    glNormal3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS); //

    glVertex3f(4.0f,-0.5f, 2.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(4.0f,-0.5f, 1.75f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(4.0f,0.6f, 1.75f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(4.0f,0.6f, 2.0f);
    glTexCoord2f(0.0f, 0.0f);


    glVertex3f(4.0f,-0.5f, -2.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(4.0f,-0.5f, -1.75f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(4.0f,0.6f, -1.75f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(4.0f,0.6f, -2.0f);
    glTexCoord2f(0.0f, 0.0f);
    glEnd();


    //back side slice
    glColor3f (1.0, 1.0, 1.0);
    glNormal3f(0.0f, 0.0f, -1.0f);
    glBegin(GL_QUADS);

    glVertex3f(4.0f,-0.5f, -2.0f);
    glTexCoord2f(1.0f,0.0f);
    glVertex3f(0.365f,-0.5f, -2.0f);
    glTexCoord2f(1.0f,1.0f);
    glVertex3f(0.365f,0.6f, -2.0f);
    glTexCoord2f(0.0f,1.0f);
    glVertex3f(4.0f,0.6f, -2.0f);
    glTexCoord2f(0.0f,0.0f);



    glVertex3f(-4.0f,-0.5f, -2.0f);
    glTexCoord2f(1.0f,0.0f);
    glVertex3f(-0.365f,-0.5f, -2.0f);
    glTexCoord2f(1.0f,1.0f);
    glVertex3f(-0.365f,0.6f, -2.0f);
    glTexCoord2f(0.0f,1.0f);
    glVertex3f(-4.0f,0.6f, -2.0f);
    glTexCoord2f(0.0f,0.0f);
    glEnd();

    ///mimbor er pase
    glBegin(GL_TRIANGLES);

    glVertex3f(-0.1f, 0.6f, -2.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-0.365f, 0.31f, -2.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-0.365f, 0.6f, -2.0f);
    glTexCoord2f(1.0f, 1.0f);

    glVertex3f(0.1f, 0.6f, -2.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(0.365f, 0.31f, -2.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(0.365f, 0.6f, -2.0f);
    glTexCoord2f(1.0f, 1.0f);
    glEnd();

    ///Front side
    for(float i=-3.65; i<=-0.323; i=i+0.714)
    {
        glNormal3f(0.0f, 0.0f, 1.0f);
        glTranslatef(i, 0.5f, 2.0f);
        door();
        glTranslatef(-i, -0.5f, -2.0f);


        float sl1 = i+0.25f;
        float sl2 = sl1+0.214f;
        glBegin(GL_QUADS);

        glVertex3f(sl1,-0.5f, 2.0f);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(sl2,-0.5f, 2.0f);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(sl2,0.6f, 2.0f);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(sl1,0.6f, 2.0f);
        glTexCoord2f(0.0f, 0.0f);
        glEnd();

    }

    glNormal3f(0.0f, 0.0f, 1.0f);
    glTranslatef(0.0f, 0.5f, 2.0f);
    middelDoor();
    glTranslatef(0.0f, -0.5f, -2.0f);

    glNormal3f(0.0f, 0.0f, 1.0f);
    for(float i=3.65; i>= 0.323; i=i-0.714)
    {
        glTranslatef(i, 0.5f, 2.0f);
        door();
        glTranslatef(-i, -0.5f, -2.0f);


        float sl1 = i-0.25f;
        float sl2 = sl1-0.214f;
        glBegin(GL_QUADS); //
        glVertex3f(sl1,-0.5f, 2.0f);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(sl2,-0.5f, 2.0f);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(sl2,0.6f, 2.0f);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(sl1,0.6f, 2.0f);
        glTexCoord2f(0.0f, 0.0f);
        glEnd();


    }

    //door right
    for(float i=1.5; i>= 0.786; i=i-0.714)
    {
        glNormal3f(1.0f, 0.0f, 0.0f);
        glTranslatef(4.0f, 0.5f, i);
        glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
        door();
        glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
        glTranslatef(-4.0f, -0.5f, -i);


        float sl1 = i-0.25f;
        float sl2 = sl1-0.214f;
        glBegin(GL_QUADS); //
        glVertex3f(4.0f,-0.5f, sl1);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(4.0f,-0.5f, sl2);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(4.0f,0.6f, sl2);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(4.0f,0.6f, sl1);
        glTexCoord2f(0.0f, 0.0f);
        glEnd();


    }

    glNormal3f(1.0f, 0.0f, 0.0f);
    glTranslatef(4.0f, 0.5f, 0.0f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    middelDoor();
    glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
    glTranslatef(-4.0f, -0.5f, 0.0f);

    for(float i=-1.50; i<=-0.786; i=i+0.714)
    {
        glNormal3f(1.0f, 0.0f, 0.0f);
        glTranslatef(4.0f, 0.5f, i);
        glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
        door();
        glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
        glTranslatef(-4.0f, -0.5f, -i);


        float sl1 = i+0.25f;
        float sl2 = sl1+0.214f;
        glBegin(GL_QUADS); //

        glVertex3f(4.0f,-0.5f, sl1);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(4.0f,-0.5f, sl2);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(4.0f,0.6f, sl2);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(4.0f,0.6f, sl1);
        glTexCoord2f(0.0f, 0.0f);
        glEnd();
    }


    //door left
    for(float i=1.5; i>=0.786; i=i-0.714)
    {
        glNormal3f(-1.0f, 0.0f, 0.0f);
        glTranslatef(-4.0f, 0.5f, i);
        glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
        door();
        glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
        glTranslatef(4.0f, -0.5f, -i);

        float sl1 = i-0.25f;
        float sl2 = sl1-0.214f;
        glBegin(GL_QUADS); //

        glVertex3f(-4.0f,-0.5f, sl1);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(-4.0f,-0.5f, sl2);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(-4.0f,0.6f, sl2);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-4.0f,0.6f, sl1);
        glTexCoord2f(0.0f, 0.0f);
        glEnd();

    }

    glNormal3f(-1.0f, 0.0f, 0.0f);
    glTranslatef(-4.0f, 0.5f, 0.0f);
    glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
    middelDoor();
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    glTranslatef(4.0f, -0.5f, 0.0f);

    for(float i=-1.50; i<=-0.786; i=i+0.714)
    {
        glNormal3f(-1.0f, 0.0f, 0.0f);
        glTranslatef(-4.0f, 0.5f, i);
        glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
        door();
        glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
        glTranslatef(4.0f, -0.5f, -i);


        float sl1 = i+0.25f;
        float sl2 = sl1+0.214f;
        glBegin(GL_QUADS); //
        glVertex3f(-4.0f,-0.5f, sl1);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(-4.0f,-0.5f, sl2);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(-4.0f,0.6f, sl2);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-4.0f,0.6f, sl1);
        glTexCoord2f(0.0f, 0.0f);
        glEnd();
    }

    glNormal3f(-1.0f, 0.0f, 0.0f);
    glTranslatef(0.0f, 0.0f, -2.0f);
    glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
    mimbor();
    glRotatef(-180.0f, 0.0f, 1.0f, 0.0f);
    glTranslatef(0.0f, 0.0f, 2.0f);

    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);

    /*
        Front
        glNormal3f(0.0f, 0.0f, 1.0f);
        glVertex3f(-4.0f, -1.0f, 2.0f);
        glNormal3f(1.0f, 0.0f, 1.0f);
        glVertex3f(0.0f, -1.0f, 2.0f);
        glNormal3f(1.0f, 0.0f, 1.0f);
        glVertex3f(0.0f, 1.20f, 2.0f);
        glNormal3f(-1.0f, 0.0f, 1.0f);
        glVertex3f(-4.0f, 1.0f, 2.0f);


        glVertex3f(0.0f, -1.0f, 2.0f);
        glNormal3f(1.0f, 0.0f, 1.0f);
        glVertex3f(4.0f, -1.0f, 2.0f);
        glNormal3f(1.0f, 0.0f, 1.0f);
        glVertex3f(4.0f, 1.0f, 2.0f);
        glNormal3f(-1.0f, 0.0f, 1.0f);
        glVertex3f(0.0f, 1.20f, 2.0f);
    */

    /*
        Right
        glNormal3f(1.0f, 0.0f, 0.0f);
        glNormal3f(1.0f, 0.0f, -1.0f);
        glVertex3f(4.0f, -1.0f, -2.0f);
        glNormal3f(1.0f, 0.0f, -1.0f);
        glVertex3f(4.0f, 1.0f, -2.0f);
        glNormal3f(1.0f, 0.0f, 1.0f);
        glVertex3f(4.0f, 1.2f, 0.0f);
        glNormal3f(1.0f, 0.0f, 1.0f);
        glVertex3f(4.0f, -1.0f, 0.0f);

        glNormal3f(1.0f, 0.0f, -1.0f);
        glVertex3f(4.0f, -1.0f, 0.0f);
        glNormal3f(1.0f, 0.0f, -1.0f);
        glVertex3f(4.0f, 1.2f, 0.0f);
        glNormal3f(1.0f, 0.0f, 1.0f);
        glVertex3f(4.0f, 1.0f, 2.0f);
        glNormal3f(1.0f, 0.0f, 1.0f);
        glVertex3f(4.0f, -1.0f, 2.0f);

    */

    /*
        Back
        glNormal3f(0.0f, 0.0f, -1.0f);
        glNormal3f(-1.0f, 0.0f, -1.0f);
        glVertex3f(-4.0f, -1.0f, -2.0f);
        glNormal3f(1.0f, 0.0f, 1.0f);
        glVertex3f(0.0f, -1.0f, -2.0f);
        glNormal3f(1.0f, 0.0f, 1.0f);
        glVertex3f(0.0f, 1.20f, -2.0f);
        glNormal3f(-1.0f, 0.0f, 1.0f);
        glVertex3f(-4.0f, 1.0f, -2.0f);

        glVertex3f(0.0f, -1.0f, -2.0f);
        glNormal3f(1.0f, 0.0f, 1.0f);
        glVertex3f(4.0f, -1.0f, -2.0f);
        glNormal3f(1.0f, 0.0f, 1.0f);
        glVertex3f(4.0f, 1.0f, -2.0f);
        glNormal3f(-1.0f, 0.0f, 1.0f);
        glVertex3f(0.0f, 1.20f, -2.0f);

        */
    /*
    Left
    glNormal3f(-1.0f, 0.0f, 0.0f);
    glNormal3f(1.0f, 0.0f, -1.0f);
    glVertex3f(-4.0f, -1.0f, -2.0f);
    glNormal3f(1.0f, 0.0f, -1.0f);
    glVertex3f(-4.0f, 1.0f, -2.0f);
    glNormal3f(1.0f, 0.0f, 1.0f);
    glVertex3f(-4.0f, 1.2f, 0.0f);
    glNormal3f(1.0f, 0.0f, 1.0f);
    glVertex3f(-4.0f, -1.0f, 0.0f);

    glNormal3f(1.0f, 0.0f, -1.0f);
    glVertex3f(-4.0f, -1.0f, 0.0f);
    glNormal3f(1.0f, 0.0f, -1.0f);
    glVertex3f(-4.0f, 1.2f, 0.0f);
    glNormal3f(1.0f, 0.0f, 1.0f);
    glVertex3f(-4.0f, 1.0f, 2.0f);
    glNormal3f(1.0f, 0.0f, 1.0f);
    glVertex3f(-4.0f, -1.0f, 2.0f);
    */

    glEnd();

    float domCil = 4.45f;

    glNormal3f(-1.0f, 0.0f, -1.0f);
    glTranslatef(-domCil,-0.5f,-2.2f);
    draw_cylinder(0.5, 2.0, 255, 160, 100);
    glRotatef(90, 1.0, 0.0, 0.0);
    glTranslatef(domCil,0.5f,2.2f);

    glTranslatef(-domCil, 1.5f, -2.2f);
    singleDom();
    glTranslatef(domCil,-1.5f,2.2f);

    glTranslatef(-domCil, 0.0f, -2.2f);
    drawMinarRing(1.45f);
    glTranslatef(domCil,0.0f,2.2f);

    glTranslatef(-domCil, 0.0f, -2.2f);
    drawMinarRing(1.05f);
    glTranslatef(domCil,0.0f,2.2f);

    glTranslatef(-domCil, 0.0f, -2.2f);
    drawMinarRing(0.90f);
    glTranslatef(domCil,0.0f,2.2f);



    //
    glNormal3f(-1.0f, 0.0f, 1.0f);
    glTranslatef(-domCil,-0.5f,2.2);
    draw_cylinder(0.5, 2.0, 255, 160, 100);
    glRotatef(90, 1.0, 0.0, 0.0);
    glTranslatef(domCil,0.5f,-2.2);

    glTranslatef(-domCil,1.5,2.2);
    singleDom();
    glTranslatef(domCil,-1.5,-2.2);

    glTranslatef(-domCil, 0.0f, 2.2f);
    drawMinarRing(1.45f);
    glTranslatef(domCil,0.0f,-2.2f);

    glTranslatef(-domCil, 0.0f, 2.2f);
    drawMinarRing(1.05f);
    glTranslatef(domCil,0.0f,-2.2f);

    glTranslatef(-domCil, 0.0f, 2.2f);
    drawMinarRing(0.90f);
    glTranslatef(domCil,0.0f,-2.2f);

    //
    glNormal3f(1.0f, 0.0f, 1.0f);
    glTranslatef(domCil,-0.5f,2.2);
    draw_cylinder(0.5, 2.0, 255, 160, 100);
    glRotatef(90, 1.0, 0.0, 0.0);
    glTranslatef(-domCil,0.5f,-2.2);

    glTranslatef(domCil,1.5,2.2);
    singleDom();
    glTranslatef(-domCil,-1.5,-2.2);

    glTranslatef(domCil, 0.0f, 2.2f);
    drawMinarRing(1.45f);
    glTranslatef(-domCil,0.0f,-2.2f);

    glTranslatef(domCil, 0.0f, 2.2f);
    drawMinarRing(1.05f);
    glTranslatef(-domCil,0.0f,-2.2f);

    glTranslatef(domCil, 0.0f, 2.2f);
    drawMinarRing(0.90f);
    glTranslatef(-domCil,0.0f,-2.2f);


    //
    glNormal3f(1.0f, 0.0f, -1.0f);
    glTranslatef(domCil,-0.5f,-2.2);
    draw_cylinder(0.5, 2.0, 255, 160, 100);
    glRotatef(90, 1.0, 0.0, 0.0);
    glTranslatef(-domCil,0.5f,2.2);

    glTranslatef(domCil,1.5,-2.2);
    singleDom();
    glTranslatef(-domCil,-1.5,2.2);

    glTranslatef(domCil, 0.0f, -2.2f);
    drawMinarRing(1.45f);
    glTranslatef(-domCil,0.0f,2.2f);

    glTranslatef(domCil, 0.0f, -2.2f);
    drawMinarRing(1.05f);
    glTranslatef(-domCil,0.0f,2.2f);

    glTranslatef(domCil, 0.0f, -2.2f);
    drawMinarRing(0.90f);
    glTranslatef(-domCil,0.0f,2.2f);

    glNormal3f(0.0f, 1.0f, 0.0f);
    topView();



    glBegin(GL_QUADS); //
    glVertex3f(-4.0f,-0.5f, 2.0);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-4.0f,-0.5f, -2.0);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(4.0f,-0.5f, -2.0);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(4.0f,-0.5f, 2.0);
    glTexCoord2f(0.0f, 0.0f);
    glEnd();

    glDisable(GL_TEXTURE_2D);



    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[7]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glColor3f(0.5f,0.5f,0.5f);
    glBegin(GL_QUADS);
    glVertex3f(-1.0f,-0.5f, 2.0);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.0f,-0.5f, 10.0);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(1.0f,-0.5f, 10.0);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(1.0f,-0.5f, 2.0);
    glTexCoord2f(0.0f, 1.0f);
    glEnd();

    glDisable(GL_TEXTURE_2D);

    glPopMatrix();




    glutSwapBuffers();

}


void specialKeys(unsigned char key, int p, int q)
{
    switch (key)
    {
//    case 'x': //LeftArrow
////        angleLF=1;
//        a+=0.1;
//        break;
//    //angleRF=0;
//    case 's': //RightArrow
//        //angleLF=0;
////        angleRF=1;
//        a-=0.1;
//        break;
    case 'u': //up
//        up=1;
        b+=0.1;
        cout<<a<<b<<c<<l_t<<endl;
        break;
    case 'd':
        b-=0.1;
        cout<<a<<b<<c<<l_t<<endl;
        break;
    //angleRF=0;
//    case 'z': //up
////        up=1;
//        c+=0.1;
//        break;
//    case 'a':
//        c-=0.1;
//        break;
    case 'r':
        if(l_t==360)
            l_t=0;
        l_t++;
        cout<<a<<b<<c<<l_t<<endl;
        break;
    case 'l':
        l_t--;
        if(l_t<0)
            l_t=360+l_t;
        cout<<a<<b<<c<<l_t<<endl;
        break;
         case 'x':
        if(t_l==360)
            t_l=0;
        t_l++;
        cout<<a<<b<<c<<t_l<<endl;
        break;
    case 'c':
        t_l--;
        if(t_l<0)
            t_l=360+t_l;
        cout<<a<<b<<c<<t_l<<endl;
        break;
    case 't':
        a=0.06;
        b=-0.9;
        c=-2.0;
        l_t=0;
        t_l=77.0;
        break;
    case 'f':
        a=0;
        b=-2.0;
        c=-2.0;
        l_t=0;
        t_l=0;
        break;
        case 's':
        a=-0.38;
        b=-2.0;
        c=-3.5;
        l_t=269;
        t_l=0;
        break;
        case 'b':
        a=0.3;
        b=-2;
        c=-6;
        l_t=186;
        t_l=0;
        break;
    case 'n':
        rF=0.0;
        gF=0.0;
        bF=0.1f;
        break;
         case 'm':
        rF=1.0;
        gF=1.0;
        bF=1.0f;
        break;

        break;
    }

    glutPostRedisplay();
}





void handleResize(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

void specialKey(int key,int x,int y)
{
    if(key==GLUT_KEY_RIGHT)
    {
        a+=0.5;
        cout<<a<<b<<c<<l_t<<endl;
    }
    else if(key==GLUT_KEY_LEFT)
    {

        a-=0.5;
        cout<<a<<b<<c<<l_t<<endl;
    }
    else if(key==GLUT_KEY_UP)
    {
        c=c-0.5;
        cout<<a<<b<<c<<l_t<<endl;
    }
    else if(key==GLUT_KEY_DOWN)
    {

        c=c+0.5;
        cout<<a<<b<<c<<l_t<<endl;
    }
    glutPostRedisplay();
}

int main()
{
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1300, 650);
    glutInitWindowPosition (0, 0);
    glutCreateWindow ("3D View of a Quad");
    init();

    glutDisplayFunc(display);

    glutKeyboardFunc(specialKeys);
    glutReshapeFunc(handleResize);
    glutSpecialFunc(specialKey);
    glutMainLoop();
    return 0;
}

#ifndef __mon_module_camera__
#define __mon_module_camera__

#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#define debug_camera 1

typedef struct camera
{
    GLdouble eyeX;
    GLdouble eyeY;
    GLdouble eyeZ;
    
    GLdouble centerX;
    GLdouble centerY;
    GLdouble centerZ;
    
    GLdouble upX;
    GLdouble upY;
    GLdouble upZ;
}Camera;

void initCamera(Camera *cam, GLdouble eyeX = 0, GLdouble eyeY = 0, GLdouble eyeZ = 0, GLdouble centerX = 0, GLdouble centerY = 0, GLdouble centerZ = 0, GLdouble upX = 0, GLdouble upY = 1, GLdouble upZ = 0);

void setEyeX(Camera *cam, GLdouble x);
void setEyeY(Camera *cam, GLdouble x);
void setEyeZ(Camera *cam, GLdouble x);

void setCenterX(Camera *cam, GLdouble x);
void setCenterY(Camera *cam, GLdouble x);
void setCenterZ(Camera *cam, GLdouble x);

void setUpX(Camera *cam, GLdouble x);
void setUpY(Camera *cam, GLdouble x);
void setUpZ(Camera *cam, GLdouble x);

void lookAt(Camera cam);

void afficherCam(Camera cam);

#endif

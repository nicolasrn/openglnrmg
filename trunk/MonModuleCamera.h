#ifndef __mon_module_camera__
#define __mon_module_camera__

#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#define debug_camera 0

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

extern Camera cameraLibre;
extern Camera cameraCabine;
extern Camera *cameraCourante;

extern void (*trajectoireCourante)(Camera*);

extern int angle;
extern int angleTrain;
extern int angleTrainCamera;

extern float monCosinus[360];
extern float monSinus[360];

extern float dist, hauteurCam;
extern float depCamX, depCamY, depCamZ;

//extern void (*trajectoire)(Camera);

void initCamera(Camera *cam, 
                GLdouble eyeX = 0,
                GLdouble eyeY = 0, 
                GLdouble eyeZ = -10, 
                GLdouble centerX = 0, 
                GLdouble centerY = 0, 
                GLdouble centerZ = 0, 
                GLdouble upX = 0, 
                GLdouble upY = 1, 
                GLdouble upZ = 0);

void setEyeX(Camera *cam, GLdouble x);
void setEyeY(Camera *cam, GLdouble y);
void setEyeZ(Camera *cam, GLdouble z);

void setCenterX(Camera *cam, GLdouble x);
void setCenterY(Camera *cam, GLdouble y);
void setCenterZ(Camera *cam, GLdouble z);

void setUpX(Camera *cam, GLdouble x);
void setUpY(Camera *cam, GLdouble y);
void setUpZ(Camera *cam, GLdouble z);

void lookAt(Camera *cam, void (*trajectoire)(Camera*) = NULL);
void afficherCam(Camera cam);

void trajectoireLibre(Camera*);
void trajectoireCabine(Camera*);

void resetDataLibre();
void resetDataCabine(int type = 1);

#endif

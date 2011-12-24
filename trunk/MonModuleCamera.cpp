#include "MonModuleCamera.h"

using namespace std;

//void (*trajectoire)(Camera) = NULL;
Camera cameraLibre;
Camera cameraCabine;
Camera *cameraCourante = NULL;
void (*trajectoireCourante)(Camera*) = NULL;

int angle = 90;
int angleTrain = 0;
int angleTrainCamera = 95;

float monCosinus[360];
float monSinus[360];

float dist = 1, hauteurCam = 1;
float depCamX = 0.0, depCamY = 0.0, depCamZ = 0.0;

void resetDataLibre()
{
    dist = hauteurCam = 4.5;
    depCamX = depCamY = depCamZ = 0.0;
}

void resetDataCabine()
{
    dist = 1;
    hauteurCam = 0;
    depCamX = 0;
    depCamY = 3;
    depCamZ = -21;
}

void initCamera(Camera *cam, GLdouble eyeX, GLdouble eyeY, GLdouble eyeZ, GLdouble centerX, GLdouble centerY, GLdouble centerZ, GLdouble upX, GLdouble upY, GLdouble upZ)
{
    cam->eyeX = eyeX;
    cam->eyeY = eyeY;
    cam->eyeZ = eyeZ;
    
    cam->centerX = centerX;
    cam->centerY = centerY;
    cam->centerZ = centerZ;
    
    cam->upX = upX;
    cam->upY = upY;
    cam->upZ = upZ;
}

void setEyeX(Camera *cam, GLdouble x)
{
    cam->eyeX = x;
}

void setEyeY(Camera *cam, GLdouble y)
{
    cam->eyeY = y;
}

void setEyeZ(Camera *cam, GLdouble z)
{
    cam->eyeZ = z;
}

void setCenterX(Camera *cam, GLdouble x)
{
    cam->centerX = x;
}

void setCenterY(Camera *cam, GLdouble y)
{
    cam->centerY = y;
}

void setCenterZ(Camera *cam, GLdouble z)
{
    cam->centerZ = z;
}

void setUpX(Camera *cam, GLdouble x)
{
    cam->upX = x;
}

void setUpY(Camera *cam, GLdouble y)
{
    cam->upY = y;
}

void setUpZ(Camera *cam, GLdouble z)
{
    cam->upZ = z;
}

void lookAt(Camera *cam, void (*trajectoire)(Camera*))
{
    if (trajectoire != NULL)
        trajectoire(cam);
    gluLookAt(cam->eyeX, cam->eyeY, cam->eyeZ, cam->centerX, cam->centerY, cam->centerZ, cam->upX, cam->upY, cam->upZ);
    
#if defined(debug_camera) && debug_camera == 1
    afficherCam(*cam);
#endif
}

void afficherCam(Camera cam)
{
    cout << "(" <<  cam.eyeX << ", " << cam.eyeY << ", " << cam.eyeZ << ", " <<
                    cam.centerX << ", " << cam.centerY << ", " << cam.centerZ << ", " << 
                    cam.upX << ", " << cam.upY << ", " << cam.upZ << ")" << endl;
}

void trajectoireLibre(Camera *cam)
{
    setEyeZ(cam, dist * monSinus[angle]);
	setEyeX(cam, dist * monCosinus[angle]);
    setEyeY(cam, hauteurCam);
    
    setCenterX(cam, depCamX);
    setCenterY(cam, depCamY);
    setCenterZ(cam, depCamZ);
#if defined(debug_camera) && debug_camera == 1
    cout << "trajectoireLibre attribué" << endl;
#endif
}

void trajectoireCabine(Camera *cam)
{
    GLfloat cx = 14.5, cy = 1, cz = -14.5;
    
    initCamera(cam, dist * cx * monCosinus[angleTrainCamera], cy, dist * cz * monSinus[angleTrainCamera]);
    glRotatef(90, 0, 1, 0);
    
#if defined(debug_camera) && debug_camera == 1
    cout << "trajectoireCabine attribué" << endl;
#endif
}

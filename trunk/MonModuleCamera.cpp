#include "MonModuleCamera.h"

using namespace std;

//void (*trajectoire)(Camera) = NULL;

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
                    cam.upX << ", " << cam.upY << ", " << cam.upZ << endl;
}

#include "MonModuleCamera.h"

using namespace std;

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

void setEyeY(Camera *cam, GLdouble x)
{
    cam->eyeY = x;
}

void setEyeZ(Camera *cam, GLdouble x)
{
    cam->eyeZ = x;
}

void setCenterX(Camera *cam, GLdouble x)
{
    cam->centerX = x;
}

void setCenterY(Camera *cam, GLdouble x)
{
    cam->centerY = x;
}

void setCenterZ(Camera *cam, GLdouble x)
{
    cam->centerZ = x;
}

void setUpX(Camera *cam, GLdouble x)
{
    cam->upX = x;
}

void setUpY(Camera *cam, GLdouble x)
{
    cam->upY = x;
}

void setUpZ(Camera *cam, GLdouble x)
{
    cam->upZ = x;
}

void lookAt(Camera cam)
{
    gluLookAt(cam.eyeX, cam.eyeY, cam.eyeZ, cam.centerX, cam.centerY, cam.centerZ, cam.upX, cam.upY, cam.upZ);
#if defined(debug_camera) && debug_camera == 1
    afficherCam(cam);
#endif
}

void afficherCam(Camera cam)
{
    cout << "(" <<  cam.eyeX << ", " << cam.eyeY << ", " << cam.eyeZ << ", " <<
                    cam.centerX << ", " << cam.centerY << ", " << cam.centerZ << ", " << 
                    cam.upX << ", " << cam.upY << ", " << cam.upZ << endl;
}

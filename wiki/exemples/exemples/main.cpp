#include <stdio.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "modulesutilitaires/modulecylindres.h"
#include "modulesutilitaires/ModuleCouleurs.h"
#include "modulesutilitaires/ModuleManipulateur.h"
#include "modulesutilitaires/ModuleMenus.h"
#include "modulesutilitaires/ModuleReshape.h"


#define GYRO_AXIS_TEAPOT 0
#define GYRO_AXIS_GIMBAL01 1
#define GYRO_AXIS_GIMBAL02 2
#define GYRO_MODE_WIRE 0
#define GYRO_MODE_SOLID 1
#define GYRO_FOG_OFF 0
#define GYRO_FOG_ON 1

float rotationIncrement = 10.0;
float rotationTeapot = 0.0;
float rotationT2 = 0.0;
float rotationGimbal01 = 0.0;
float rotationGimbal02 = 0.0;

int axis = 0;
int displayMode = 1;
int fog = 1;
GLfloat fogColor[] = {1.0,1.0,1.0,1.0};


static void resize(int width, int height) {
    const float ar = (float) width / (float) height;
    
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}//resize()

static void display(void) {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    //socle
    glPushMatrix();
    glTranslatef(0.0, -0.4, 0.0);
    glColor3f(0.4, 0.4, 0.4);
    if (displayMode == GYRO_MODE_WIRE) wireCylindre(0.14, 0.06, 10, 1);
    else solidCylindre(0.14, 0.06, 10, 10);
    glPopMatrix();
    
    //tige support du socle
    glPushMatrix();
    glTranslatef(0.0, -0.32, 0.0);
    glColor3f(0.4, 0.4, 0.4);
    if (displayMode == GYRO_MODE_WIRE) wireCylindre(0.02, 0.1, 10, 1);
    else solidCylindre(0.02, 0.1, 10, 10);
    glPopMatrix();

    glPushMatrix();
    //gimbal exterieur
    glRotatef(rotationGimbal02, 0.0, 1.0, 0.0);
    glColor3f(0.4, 0.4, 0.4);
    if (displayMode == GYRO_MODE_WIRE) glutWireTorus(0.02, 0.28, 10, 20);
    else glutSolidTorus(0.02, 0.28, 20, 30);
    glColor3f(0.2, 0.2, 0.2);
    //supports
    glRotatef(90.0, 0.0, 0.0, 1.0);
    glTranslatef(0.0, 0.24, 0.0);
    if (displayMode == GYRO_MODE_WIRE) wireCylindre(0.008, 0.06, 10, 1);
    else solidCylindre(0.008, 0.06, 10, 10);
    glTranslatef(0.0, -0.48, 0.0);
    if (displayMode == GYRO_MODE_WIRE) wireCylindre(0.008, 0.06, 10, 1);
    else solidCylindre(0.008, 0.06, 10, 10);
    glTranslatef(0.0, 0.24, 0.0);
    glRotatef(-90.0, 0.0, 0.0, 1.0);

    //gimbal interieur
    glRotatef(rotationGimbal01, 1.0, 0.0, 0.0);
    glColor3f(0.4, 0.4, 0.4);
    if (displayMode == GYRO_MODE_WIRE) glutWireTorus(0.02, 0.21, 10, 20);
    else glutSolidTorus(0.02, 0.21, 20, 30);
    glColor3f(0.2, 0.2, 0.2);
    if (displayMode == GYRO_MODE_WIRE) wireCylindre(0.008, 0.4, 10, 1);
    else solidCylindre(0.008, 0.4, 10, 10);

    //theiere
    glRotatef(rotationTeapot, 0.0, 1.0, 0.0);
    glRotatef(rotationT2, 1.0, 0.0, 0.0);
    glColor3d(1.0,0.0,0.0);
    if (displayMode == GYRO_MODE_WIRE) glutWireTeapot(0.1);
    else glutSolidTeapot(0.1);
    glPopMatrix();

    glutSwapBuffers();
}//display()


static void special(int key, int x, int y) {
       switch(axis) {
                     case GYRO_AXIS_TEAPOT:
                          switch(key) {
                   case GLUT_KEY_LEFT:
                        rotationTeapot += rotationIncrement;            
                        break;
                   case GLUT_KEY_RIGHT:
                        rotationTeapot -= rotationIncrement;
                        break;
                        }//switch
                          break;
                     case GYRO_AXIS_GIMBAL01:
                          switch(key) {
                   case GLUT_KEY_LEFT:
                        rotationGimbal01 += rotationIncrement;            
                        break;
                   case GLUT_KEY_RIGHT:
                        rotationGimbal01 -= rotationIncrement;
                        break;
                        }//switch
                          break;
                     case GYRO_AXIS_GIMBAL02:
                          switch(key) {
                   case GLUT_KEY_LEFT:
                        rotationGimbal02 += rotationIncrement;            
                        break;
                   case GLUT_KEY_RIGHT:
                        rotationGimbal02 -= rotationIncrement;
                        break;
                        }//switch
                          break;              
       }//switch
       
       switch(key) {
                   case GLUT_KEY_UP:
                        rotationT2 += rotationIncrement;            
                        break;
                   case GLUT_KEY_DOWN:
                        rotationT2 -= rotationIncrement;
                        break;
                        }//switch
                          
       
       glutPostRedisplay();
}//special()


void menu(int value) {
     
}//menu()


void menuAxe(int value) {
     axis = value;
}//menuAxe()


void menuMode(int value) {
     displayMode = value;
}//menuMode()


static void key(unsigned char key, int x, int y) {
    
}//key()


void myInit() {
  
  /*glEnable(GL_LIGHTING) ;
  glEnable(GL_LIGHT0) ;
  glEnable(GL_AUTO_NORMAL) ;
  glEnable(GL_NORMALIZE) ;
  float dir[] = { 0.0F,0.0F,-1.6F,0.0F } ;
  glLightfv(GL_LIGHT0,GL_POSITION,dir) ;*/

     
     if (fog == GYRO_FOG_ON) { 
        glEnable(GL_FOG); 
        glFogi(GL_FOG_MODE,GL_LINEAR); 
        glHint(GL_FOG_HINT,GL_NICEST); 
        glFogf(GL_FOG_START,0.05f); 
        glFogf(GL_FOG_END,0.3f); 
        glFogfv(GL_FOG_COLOR, fogColor); }
    else
        glDisable(GL_FOG);
        
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glDepthFunc(GL_LEQUAL); 
    glEnable(GL_DEPTH_TEST); 
    glShadeModel(GL_SMOOTH); 
}//myInit()


int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(400,400);
    glutInitWindowPosition(100,100);
    glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE);

    glutCreateWindow("Gyroscope");

    //glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutSpecialFunc(special);
    
    int choixAxe = glutCreateMenu(menuAxe);
    glutAddMenuEntry("Teapot", GYRO_AXIS_TEAPOT);
    glutAddMenuEntry("Internal Gimbal", GYRO_AXIS_GIMBAL01);
    glutAddMenuEntry("External Gimbal", GYRO_AXIS_GIMBAL02);
    int choixModeAffichage = glutCreateMenu(menuMode);
    glutAddMenuEntry("Wire", GYRO_MODE_WIRE);
    glutAddMenuEntry("Solid", GYRO_MODE_SOLID);
    int choixMenu = glutCreateMenu(menu);
    glutAddSubMenu("Choose axis", choixAxe);
    glutAddSubMenu("Choose display mode", choixModeAffichage); 
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    myInit();

    glutMainLoop();

    return 0;
}//main()


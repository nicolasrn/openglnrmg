
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <stdio.h>
#include <stdlib.h>

#include "../../modulesutilitaires/ModuleCouleurs.h"
#include "../../modulesutilitaires/ModuleManipulateur.h"
#include "../../modulesutilitaires/ModuleMenus.h"

static int proj = 0 ;
static int ww ;
static int hh ;
static float zoomPersp = 1.0F ;
static float zoomParal = 1.0F ;
static float ouverture = 1.0F ;

void projection(void) {
  if ( proj ) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0*ouverture,(double) ww/hh,0.5,200.0);
    glMatrixMode(GL_MODELVIEW);
    glTranslatef(0.0F,0.0F,-5.0F*zoomPersp);  
    setManipulateurDistance(5.0F*zoomPersp); }
    else {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2.5*zoomParal,2.5*zoomParal,-2.5*zoomParal*(double) hh/ww,2.5*zoomParal*(double) hh/ww,-25,25);
    glMatrixMode(GL_MODELVIEW);
    setManipulateurDistance(1.0F); }
}

void display(void) {   
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glPushMatrix();
  glColor4fv(couleurBlanc());
  projection();
  glPushMatrix();
  manipulateurSouris();
  manipulateurClavier();
  glTranslatef(-1.0F,0.0F,0.0F) ;
  glMaterialfv(GL_FRONT,GL_DIFFUSE,couleurJaune());
  glutSolidCube(2.0);
  glTranslatef(2.0F,0.0F,0.0F) ;
  glMaterialfv(GL_FRONT,GL_DIFFUSE,couleurBleu());
  glutSolidSphere(1.3,36,36);
  glPopMatrix();
  glPopMatrix();
  glFlush();
  glutSwapBuffers();
}

void myinit(void) {
  glShadeModel(GL_SMOOTH);
  glDepthFunc(GL_LESS) ;
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_AUTO_NORMAL);
  glEnable(GL_NORMALIZE);
}

void reshape(int w, int h) { 
  glViewport(0,0,w,h);
  ww = w ;
  hh = h ;
}

void key(unsigned char key,int x,int y) {
  if ( keyManipulateur(key,x,y) )
    glutPostRedisplay();
    else
    switch ( key ) {
      case 'o'  : ouverture *= 1.02F ;
                  glutPostRedisplay();
                  break;
      case 'O'  : ouverture /= 1.02F ;
                  glutPostRedisplay();
                  break;
      case '+'   : zoomPersp *= 1.01F ;
                  zoomParal *= 1.01F ;
                  glutPostRedisplay();
                  break;
      case '-'   : zoomPersp /= 1.01F ;
                  zoomParal /= 1.01F ;
                  glutPostRedisplay();
                  break;
      case 'P'  : 
      case 'p'  : proj =(proj+1)%2 ;
                  glutPostRedisplay();
                  break; }
}

int main(int argc,char **argv) {
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_RGBA|GLUT_DEPTH|GLUT_DOUBLE);
  glutInitWindowSize(200,200); 
  glutInitWindowPosition(50,50); 
  glutCreateWindow("Visualisations"); 
  myinit(); 
  creationMenuBasique();
  glutKeyboardFunc(key);
  glutSpecialFunc(specialBasique);
  glutMotionFunc(motionBasique);
  glutMouseFunc(sourisBasique);
  glutReshapeFunc(reshape);
  glutDisplayFunc(display);
  glutMainLoop();
  return(0);
}

/* Gestion du viewport d'affichage en OpenGL  */

/* 
x et X pour régler la position du viewport en x 
y et Y pour régler la position du viewport en y 
z et Z pour régler la position du viewport en z
a et A pour régler la taille du viewport en x 
q et Q pour régler la taille du viewport en y 
v et V pour autoriser les changements de viewport 
z et Z pour régler le zoom 
o et O pour régler l'ouverture en perspective 
p et P pour passer de la perspective à la projection orthographique 
up, down, left et right pour les contrôles d'orientation 
*/

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

#include "../modulesutilitaires/ModuleCouleurs.h"
#include "../modulesutilitaires/ModuleManipulateur.h"
#include "../modulesutilitaires/ModuleMenus.h"

static int proj = 0 ;
static int vp = 1 ;
static int vx = 0 ;
static int vy = 0 ;
static int vdx = 200 ;
static int vdy = 200 ;
static int ww ;
static int hh ;
static float zoomPersp = 1.0F ;
static float zoomParal = 1.0F ;
static float ouverture = 1.0F ;

void projection(void) {
  if ( vp )
    glViewport(0,0,ww,hh);
    else
    glViewport(vx,vy,vdx,vdy);
  if ( proj ) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0*ouverture,(double) ww/hh,0.5,200.0);
    glMatrixMode(GL_MODELVIEW);
    setManipulateurDistance(5.0F*zoomPersp);
    glTranslatef(0.0F,0.0F,-5.0F*zoomPersp); }
    else {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if ( ww > hh ) 
      glOrtho(-2.5*zoomParal*(double) ww/hh,2.5*zoomParal*(double) ww/hh,-2.5*zoomParal,2.5*zoomParal,-250.0,250.0);
      else
      glOrtho(-2.5*zoomParal,2.5*zoomParal,-2.5*zoomParal*(double) hh/ww,2.5*zoomParal*(double) hh/ww,-250.0,250.0);
    glMatrixMode(GL_MODELVIEW);
    setManipulateurDistance(5.0F);
    glTranslatef(0.0F,0.0F,-5.0F); }
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
  glutSolidSphere(1.3,18,18);
  glPopMatrix();
  glPopMatrix();
  glFlush();
  glutSwapBuffers() ;
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
  ww = w ;
  hh = h ;
  vx = 0;
  vy = 0;
  vdx = ww;
  vdy = hh;
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
      case 45   : zoomPersp *= 1.01F ;
                  zoomParal *= 1.01F ;
                  glutPostRedisplay();
                  break;
      case 43   : zoomPersp /= 1.01F ;
                  zoomParal /= 1.01F ;
                  glutPostRedisplay();
                  break;
      case 'V'  : 
      case 'v'  : vp =(vp+1)%2 ;
                  if ( vp == 0 ) {
                    vx = 0;
                    vy = 0;
                    vdx = ww;
                    vdy = hh; }
                  glutPostRedisplay();
                  break;
      case 'a'  : vx++;
                  glutPostRedisplay();
                  break;
      case 'A'  : vx--;
                  glutPostRedisplay();
                  break;
      case 'q'  : vy++;
                  glutPostRedisplay();
                  break;
      case 'Q'  : vy--;
                  glutPostRedisplay();
                  break;
      case 'e'  : vdx++;
                  glutPostRedisplay();
                  break;
      case 'E'  : vdx--;
                  glutPostRedisplay();
                  break;
      case 'd'  : vdy++;
                  glutPostRedisplay();
                  break;
      case 'D'  : vdy--;
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



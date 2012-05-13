/* Illustration des ombrages plat   */
/* et lisses en solid et fil de fer */


#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <stdio.h>
#include <stdlib.h>


#include "../modulesutilitaires/ModuleManipulateur.h"
#include "../modulesutilitaires/ModuleMenus.h"
#include "../modulesutilitaires/ModuleReshape.h"



static int mode = 0 ;
static int aff = 1 ;


void display(void) {
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

  glShadeModel(GL_SMOOTH);
   
  glPushMatrix() ;
  manipulateurClavier();
  glPushMatrix() ;
  glTranslatef(-0.8F,0.0F,0.0F);
  glRotatef(50.0F,1.0F,1.0F,1.0F);
  if ( aff )
    glutSolidSphere(1.1,15,15) ;
    else
    glutWireSphere(1.1,15,15) ;
  glPopMatrix() ;
  glPushMatrix() ;
  glTranslatef(0.9F,-0.9F,0.0F);
  glRotatef(-70.0F,1.0F,0.0F,0.0F);
  
  if ( aff )
    glutSolidTorus(0.35,0.8,15,15) ;
    else
    glutWireTorus(0.35,0.8,15,15) ;
  glPopMatrix() ;
  glPopMatrix() ;
  glFlush();
  glutSwapBuffers();
}

void myinit (void) {
  glClearColor(1.0,1.0,1.0,1.0);
  glEnable(GL_DEPTH_TEST) ;
  glEnable(GL_LIGHTING) ;
  glEnable(GL_LIGHT0) ;
  glEnable(GL_AUTO_NORMAL) ;
  glEnable(GL_NORMALIZE) ;
  float dir[] = { 0.1F,0.8F,1.6F,0.0F } ;
  glLightfv(GL_LIGHT0,GL_POSITION,dir) ;
}

void key(unsigned char key,int x,int y) {
  if ( keyManipulateur(key,x,y) )
    glutPostRedisplay();
    else
    switch ( key ) {
     
       case 0x0D   : aff = 1-aff ;
                    glutPostRedisplay();
                    break;
                    }
}

int main(int argc,char **argv) {
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_RGBA|GLUT_DEPTH|GLUT_DOUBLE);
  glutInitWindowSize(300,200); 
  glutInitWindowPosition(50,50); 
  glutCreateWindow("Affichages flat et smooth en solide et fil de fer"); 
  myinit(); 
  creationMenuBasique();
  setParametresOrthoBasique(-1.5,1.5,-1.5,1.5,-500.0,500.0);
  setManipulateurDistance(1.0F);
  glutReshapeFunc(reshapeOrthoBasique);
  glutKeyboardFunc(key);
  glutSpecialFunc(specialBasique);
  glutMotionFunc(motionBasique);
  glutMouseFunc(sourisBasique);
  glutDisplayFunc(display);
  glutMainLoop();
  return(0);
}

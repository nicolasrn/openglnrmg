#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include <stdio.h>
#include <stdlib.h>

#include "../modulesutilitaires/ModuleManipulateur.h"
#include "../modulesutilitaires/ModuleMenus.h"
#include "../modulesutilitaires/ModuleReshape.h"

/* les touches + et - pour changer le nb de facettes */
/* espace pour lisser ou non les objets */
/* f pour passer de filaire en plein */

static int faces = 15 ;
static int mode = 0 ;
static int aff = 1 ;

void display(void) {
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  if ( mode )
  /* affichage en mode ombré */
    glShadeModel(GL_SMOOTH);
    else
    /* affichage en mode facettes */
    glShadeModel(GL_FLAT);
    /*ouverture de la matrice principale */
  glPushMatrix() ;
  /* appel aux fonctions de manipulation */
  manipulateurSouris();
  manipulateurClavier();
  /* création de la matrice de la sphère */
  glPushMatrix() ;
  glTranslatef(-0.8F,0.0F,0.0F);
  glRotatef(50.0F,1.0F,1.0F,1.0F);
  /* choix du mode d'affichage de la sphere */
  if ( aff )
    glutSolidSphere(1.1,faces,faces) ;
    else
    glutWireSphere(1.1,faces,faces) ;
  glPopMatrix() ;
  
  /* création de la matrice du cone */
  glPushMatrix() ;
  glTranslatef(0.9F,-0.9F,0.0F);
  glRotatef(-70.0F,1.0F,0.0F,0.0F);
  /* choix du mode d'affichage du cone */
  if ( aff )
    glutSolidCone(0.9,2.0,faces,faces) ;
    else
    glutWireCone(0.9,2.0,faces,faces) ;
  glPopMatrix() ;
  
  /* création de la matrice du tore */
  glPushMatrix() ;
  glTranslatef(0.8F,0.1F,0.0F);
  glRotatef(-70.0F,1.0F,0.0F,0.0F);
  /*choix du mode d'affichage du tore */
  if ( aff )
    glutSolidTorus(0.35,0.8,faces,faces) ;
    else
    glutWireTorus(0.35,0.8,faces,faces) ;
  glPopMatrix() ;
  
  /* fermeture de la matrice principale */
  glPopMatrix() ;
  glFlush();
  glutSwapBuffers();
}

void myinit (void) {
  glClearColor(1.0,1.0,1.0,1.0);
  glEnable(GL_DEPTH_TEST) ;
  /* gestion de la source lumineuse */
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
      case '+'     : faces++ ;
                    glutPostRedisplay();
                    break;
      case '-'     : faces-- ;
                    if ( faces < 4 )
                      faces = 4 ;
                    glutPostRedisplay();
                    break;
      case ' '     : mode = 1-mode ;
                    glutPostRedisplay();
                    break;
      case 'f'   : aff = 1-aff ;
                    glutPostRedisplay();
                    break; }
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



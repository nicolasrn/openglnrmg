/* Illustration de l'utilisation  */
/* du multi-fenetrage avec GLUt   */



#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>

#include <math.h>
#include <stdio.h>

#include "../modulesutilitaires/ModuleCouleursSimple.h"
#include "../modulesutilitaires/ModuleManipulateur.h"
#include "../modulesutilitaires/ModuleMenus.h"
#include "../modulesutilitaires/ModuleReshape.h"

#define iw 128 
#define ih 128
#define tf "images/marbre.raw"

static GLubyte im[3*iw*ih]; 
static float f = 1.0F ;
int i;
int j;

GLfloat texpts[2][2][2] = { 
  {{0.0,0.0},{0.0,1.0}}, 
  {{1.0,0.0},{1.0,1.0}}}; 
  
void lectureTexture(char *fichier,int dx,int dy) {
  FILE *f = fopen(fichier,"rb") ;
  if ( f ) {
    for (i = 0 ; i < dx ; i++ )
      for (j = 0 ; j < dy ; j++ )
        fread(&im[(j*dy+i)*3],1,3,f) ;
    fclose(f) ; }
  } 

void display(void) { 
  glClear(GL_COLOR_BUFFER_BIT|
          GL_DEPTH_BUFFER_BIT); 
  glPushMatrix();
  glEnable(GL_DEPTH_TEST);
  manipulateurSouris();
  manipulateurClavier();
  glBegin(GL_QUADS) ;
  glTexCoord2f(0.0F,0.0F); 
  glVertex3f(-5.0F,5.0F,0.0F) ;
  glTexCoord2f(0.0F,f); 
  glVertex3f(-5.0F,-5.0F,0.0F) ;
  glTexCoord2f(f,f); 
  glVertex3f(5.0F,-5.0F,0.0F) ;
  glTexCoord2f(f,0.0F); 
  glVertex3f(5.0F,5.0F,0.0F) ;
  glEnd() ;
  glPopMatrix();
  glFlush();
  glutSwapBuffers();
} 

void initlights(void) { 
  GLfloat pos[] = { 0.0F,0.0F,-1.0F,0.0F }; 
  GLfloat shininess[] = { 50.0F }; 
  glEnable(GL_LIGHT0); 
  glEnable(GL_LIGHTING); 
  glLightfv(GL_LIGHT0,GL_AMBIENT,couleurGrisFonce()); 
  glLightfv(GL_LIGHT0,GL_DIFFUSE,couleurBlanc()); 
  glMaterialfv(GL_FRONT,GL_SPECULAR,couleurBlanc()); 
  glMaterialfv(GL_FRONT,GL_SHININESS,shininess); 
} 
  
void myinit(void) { 
  setManipulateurClavierAngle(50.0F,20.0F,10.0F);
  glClearColor(0.5F,0.5F,0.5F,1.0F); 
  lectureTexture(tf,iw,ih) ;
  glMap2f(GL_MAP2_TEXTURE_COORD_2,
          0.0F,1.0F,2,2,
          0.0F,1.0F,4,2,
          &texpts[0][0][0]); 
  glTexParameterf(GL_TEXTURE_2D,
                  GL_TEXTURE_WRAP_S,
                  GL_REPEAT); 
  glTexParameterf(GL_TEXTURE_2D,
                  GL_TEXTURE_WRAP_T,
                  GL_CLAMP);
  glTexParameterf(GL_TEXTURE_2D,
                  GL_TEXTURE_MAG_FILTER,
                  GL_NEAREST); 
  glTexParameterf(GL_TEXTURE_2D,
                  GL_TEXTURE_MIN_FILTER,
                  GL_NEAREST); 
  glEnable(GL_MAP2_TEXTURE_COORD_2); 
  glTexImage2D(GL_TEXTURE_2D,
               0,3,iw,ih,0,
               GL_RGB,
               GL_UNSIGNED_BYTE,
               im);
  glEnable(GL_TEXTURE_2D); 
  glEnable(GL_AUTO_NORMAL); 
  glEnable(GL_NORMALIZE); 
  glShadeModel(GL_SMOOTH); 
  glDepthFunc(GL_LESS);
  initlights(); 
} 
  
void key(unsigned char key,int x,int y) {
  if ( keyManipulateur(key,x,y) )
    glutPostRedisplay();
    else
    switch ( key ) {
      case 43   : f *= 1.01F ;
                  glutPostRedisplay();
                  break;
      case 45   : f /= 1.01F ;
                  glutPostRedisplay();
                  break; }
}
int main(int argc,char **argv) {
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_RGBA|GLUT_DEPTH|GLUT_DOUBLE);
  glutInitWindowSize(300,300); 
  glutInitWindowPosition(50,50); 
  glutCreateWindow("Facette avec texture"); 
  myinit(); 
  creationMenuBasique();
  setParametresOrthoBasique(-7.0,7.0,-7.0,7.0,-500.0,500.0);
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

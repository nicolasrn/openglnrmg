/*s ou S pour sauvegarder l'image dans un fichier RAW */

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

#include "../modulesutilitaires/ModuleCouleurs.h"
#include "../modulesutilitaires/ModuleManipulateur.h"
#include "../modulesutilitaires/ModuleMenus.h"
#include "../modulesutilitaires/ModuleReshape.h"

void myinit(void) {
  GLfloat shinines[] = { 50.0F };
  GLfloat l_pos[] = { 1.0F,1.0F,1.0F,0.0F };
  glClearColor(0.5F,0.5F,1.0F,1.0F) ;
  glMaterialfv(GL_FRONT,GL_SPECULAR,couleurBlanc());
  glMaterialfv(GL_FRONT,GL_SHININESS,shinines);
  glLightfv(GL_LIGHT0,GL_POSITION,l_pos);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glDepthFunc(GL_LESS);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_AUTO_NORMAL);
  glEnable(GL_NORMALIZE);
}

void display(void) {
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glPushMatrix();
  manipulateurSouris();
  manipulateurClavier();
  glutSolidTorus(0.3,1.0,36,36);
  glPopMatrix();
  glFlush();
  glutSwapBuffers();
}

void sauve(char *nom,int px,int py,int dx,int dy) {
  GLubyte *image ;
  FILE *num ;
  int y,x ;
  image =(GLubyte *) calloc(dx*dy*3,sizeof(GLubyte)); 
  glReadPixels(px,py,dx,dy,GL_RGB,GL_UNSIGNED_BYTE,image); 
  num = fopen(nom,"wb") ;
  if ( num ) {
    for ( y = dy-1 ; y >= 0 ; y-- ) {
      for ( x = 0 ; x < dx ; x++ ) {
        fwrite((void *) &image[(y*dx+x)*3],sizeof(GLubyte),3,num) ; } }
    fclose(num) ; }
  free(image) ;
}

void key(unsigned char key,int x,int y) {
  if ( keyManipulateur(key,x,y) )
    glutPostRedisplay();
    else
    switch ( key ) {
      case 's' :
      case 'S' : sauve("image.raw",0,0,glutGet(GLUT_WINDOW_WIDTH),glutGet(GLUT_WINDOW_HEIGHT)) ;
                 break; }
}

int main(int argc,char **argv) {
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_RGBA|GLUT_DEPTH|GLUT_DOUBLE);
  glutInitWindowSize(256,256); 
  glutInitWindowPosition(50,50); 
  glutCreateWindow("Tore blanc: Sauvegarde image"); 
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


#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/timeb.h>

/* L,l pour passer de l'affichage avec ou sans liste */
/* les temps s'affiche dans la console */

#include "../../modulesutilitaires/ModuleCouleurs.h"
#include "../../modulesutilitaires/ModuleMenus.h"
#include "../../modulesutilitaires/ModuleReshape.h"

#define PI 3.14159

static int l = 0 ;

void cercle() { 
  GLint i ; 
  GLfloat cosinus,sinus ; 
  glBegin(GL_POLYGON) ; 
  for ( i = 0 ; i < 100 ; i++ ) { 
    cosinus =(float) cos(i*2*PI/100.0); 
    sinus =(float) sin(i*2*PI/100.0); 
    glVertex2f(cosinus,sinus) ; } 
  glEnd() ; 
}

void display(void) {
     int i,j,k; 
  glClear(GL_COLOR_BUFFER_BIT);
  glColor4fv(couleurNoir());
  struct timeb t1 ;
  struct timeb t2 ;
  ftime(&t1);
  for (k = 0 ; k < 3000 ; k++ )
    for (j = 0 ; j < 3 ; j++ )
      for (i = 0 ; i < 3 ; i++ ) {
        glPushMatrix();
        glTranslatef(-3.0F+3*i,-3.0F+3*j,(float) -k) ;
        if ( l )
          cercle();
          else
          glCallList(1) ; 
        glPopMatrix(); }
  ftime(&t2);
  int milli = ((int) t2.time - (int) t1.time)*1000 + (int) t2.millitm - (int) t1.millitm ;
  printf("%d millisecondes avec l=%i\n",milli,l) ;
  glFlush();
  glutSwapBuffers();
} 
  
void cercleListe() { 
  GLint i ; 
  GLfloat cosinus,sinus ; 
  glNewList(1,GL_COMPILE) ; 
  glBegin(GL_POLYGON) ; 
  for ( i = 0 ; i < 100 ; i++ ) { 
    cosinus =(float) cos(i*2*PI/100.0); 
    sinus =(float) sin(i*2*PI/100.0); 
    glVertex2f(cosinus,sinus) ; } 
  glEnd() ; 
  glEndList() ; 
} 
 
void myinit(void) {
  glClearColor(1.0,1.0,1.0,1.0);
  cercleListe() ;
} 
  
void key(unsigned char key,int x,int y) {
  switch ( key ) {
    case 'L'  :
    case 'l'  : l++;
                l %= 2;
                glutPostRedisplay();
                break;
    case 0x1B : exit(0);
                break; }
}

int main(int argc,char **argv) {
  glutInit(&argc,argv);

  glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE);
  glutInitWindowSize(200,200); 
  glutInitWindowPosition(50,50); 
  glutCreateWindow("Liste d'affichage"); 
  myinit(); 
  creationMenuBasique();
  setParametresPerspectiveBasique(85.0F,1.0F,1.0F,20.0F,0.0F,0.0F,-5.0F);
  glutReshapeFunc(reshapePerspectiveBasique);
  setParametresPerspectiveBasique(85.0F,1.0F,1.0F,20.0F,0.0F,0.0F,-5.0F);
  glutReshapeFunc(reshapePerspectiveBasique);
  glutKeyboardFunc(key);
  glutDisplayFunc(display);
  glutMainLoop();
  return(0);
}



/* barre d'espace pour activer ou annuler le dephcueing */
/* les fleches pour les manipulations */
/* enter pour changer les modèles     */


#include <stdio.h> 


 
#include <GL/gl.h> 
#include <GL/glu.h>
#include <GL/glut.h> 
#include "../modulesutilitaires/ModuleMenus.h"
#include "../modulesutilitaires/ModuleReshape.h"
#include "../modulesutilitaires/ModuleManipulateur.h"
#include "../modulesutilitaires/ModuleCouleurs.h"

int scn = 0;
int dc = 1; /* variable booleene pour le depthcueing */
 
void init1(void) {
  if ( dc ) {
    /* active le brouillard */ 
    glEnable(GL_FOG);
    /*détermine le facteur de brume */
    glFogi(GL_FOG_MODE,GL_LINEAR); 
    /* gère l'anti aliassage donc la qualité d'image */
    glHint(GL_FOG_HINT,GL_NICEST); 
    /*détermine la position où la brume commence son effet */
    glFogf(GL_FOG_START,1.0F); 
    /*détermine la position ou la brume arrête son effet */
    glFogf(GL_FOG_END,3.0F); 
    /*affecte une couleur à la brume */
    glFogfv(GL_FOG_COLOR,couleurBlanc()); }
    else
    glDisable(GL_FOG); 
  glClearColor(0.0F,0.0F,0.0F,1.0F); 
  /* sert à faire le test dans le Zbuffer */
  /*Lequal veut dite <= */
  glDepthFunc(GL_LEQUAL); 
  glEnable(GL_DEPTH_TEST); 
  glShadeModel(GL_SMOOTH); 
} 
 
void init0(void) { 
  if ( dc ) { 
    glEnable(GL_FOG); 
    glFogi(GL_FOG_MODE,GL_LINEAR); 
    glHint(GL_FOG_HINT,GL_NICEST); 
    glFogf(GL_FOG_START,1.0F); 
    glFogf(GL_FOG_END,3.0F); 
    glFogfv(GL_FOG_COLOR,couleurBlanc()); }
    else
    glDisable(GL_FOG); 
  glClearColor(1.0F,1.0F,1.0F,1.0F); 
  glDepthFunc(GL_LEQUAL); 
  glEnable(GL_DEPTH_TEST); 
  glShadeModel(GL_SMOOTH); 
} 
 
void display2(void) { 
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); 
  glPushMatrix();
  glColor3f(1.0F,1.0F,1.0F);
  glTranslatef(0.0F,0.0F,-2.0F);
  manipulateurSouris();
  manipulateurClavier();
  glutWireCube(1.5); 
  glFlush(); 
  glPopMatrix();
  glutSwapBuffers();
} 
 
void display1(void) { 
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); 
  glPushMatrix();
  glColor3f(1.0F,0.0F,0.0F);
  glTranslatef(0.0F,0.0F,-2.0F);
  manipulateurSouris();
  manipulateurClavier();
  glutWireIcosahedron(); 
  glFlush(); 
  glPopMatrix();
  glutSwapBuffers();
} 
 
void display0(void) { 
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); 
  glPushMatrix();
  glColor3f(0.0F,0.0F,0.0F);
  glTranslatef(0.0F,0.0F,-2.0F);
  manipulateurSouris();
  manipulateurClavier();
  glutWireTeapot(1.0); 
  glFlush(); 
  glPopMatrix();
  glutSwapBuffers();
} 
 
void key(unsigned char key,int x,int y) {
  if ( keyManipulateur(key,x,y) )
    glutPostRedisplay();
    else
    switch ( key ) {
    /* la touche espace */
      case 0x20 : dc = !dc;
                  switch (scn) {
                    case 2 :
                    case 0 : init1();
                             glutPostRedisplay();
                             break;
                    case 1 : init0();
                             glutPostRedisplay();
                             break; } 
                  break;
      /* la touche enter */
      case 0x0D : scn = (scn+1)%3 ;
                  switch (scn) {
                    case 0 : { init1();
                               glutDisplayFunc(display1);
                               glutPostRedisplay(); }
                             break;
                    case 1 : { init0();
                               glutDisplayFunc(display0);
                               glutPostRedisplay(); }
                             break;
                    case 2 : { init1();
                               glutDisplayFunc(display2);
                               glutPostRedisplay(); }
                             break; }
                  break; }
}

int main(int argc,char **argv) {
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_RGBA|GLUT_DEPTH|GLUT_DOUBLE);
  glutInitWindowSize(300,300); 
  glutInitWindowPosition(50,50); 
  glutCreateWindow("Depth Cueing");
  init1(); 
  creationMenuBasique();
  setParametresOrthoBasique(-1.5,1.5,-1.5,1.5,-5.0,5.0);
  setManipulateurDistance(1.0F);
  glutReshapeFunc(reshapeOrthoBasique);
  glutKeyboardFunc(key);
  glutSpecialFunc(specialBasique);
  glutMotionFunc(motionBasique);
  glutMouseFunc(sourisBasique);
  glutIdleFunc(idleBasique);
  glutDisplayFunc(display1);
  glutMainLoop();
  return(0);
}



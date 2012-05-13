/* Illustration de l'utilisation  */
/* des menus avec GLUt            */


#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>

static int objet = 1 ;
static int mode = 1 ;
static GLfloat view_rotx = 20.0F ;
static GLfloat view_roty = 30.0F ;
static GLfloat view_rotz = 0.0F ;

void selectMode(int selection) {
  switch (selection) {
    case 11 : mode = 1 ;
              break ;
    case 12 : mode = 0 ;
              break ; }
  glutPostRedisplay();
}

void selectObjet(int selection) {
  switch (selection) {
    case 1  : /* si c'est une des trois premieres valeurs */
    case 2  :
    case 3  : objet = selection ;
              break ;
    case 0  : exit(0); }
  glutPostRedisplay();
}

void select(int selection) {
  switch (selection) {
    case 0  : exit(0); }
  glutPostRedisplay();
}

void redraw() {
  glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);
  glPushMatrix();
  glRotatef(view_rotx, 1.0, 0.0, 0.0);
  glRotatef(view_roty, 0.0, 1.0, 0.0);
  glRotatef(view_rotz, 0.0, 0.0, 1.0);
  if ( mode ) {
    switch(objet) {
      case 1 : glutSolidSphere(1.6,20,20) ;
               break ;
      case 2 : glutSolidCone(1.5,1.3,20,20) ;
               break ;
      case 3 : glutSolidTorus(0.7,1.4,20,20) ;
               break ; } }
    else {
    switch(objet) {
      case 1 : glutWireSphere(1.6,20,20) ;
               break ;
      case 2 : glutWireCone(1.5,1.3,20,20) ;
               break ;
      case 3 : glutWireTorus(0.7,1.4,20,20) ;
               break ; } }
  glPopMatrix();
  glutSwapBuffers();
}

void reshape(int w,int h) {
  glViewport(0,0,w,h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(65.,(float)w/(float)h,1.0,20.0); 
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(0.0F,0.0F,-5.0F) ;
}

void key(unsigned char key,int x,int y) {
  switch ( key ) {
    case 'z'    : view_rotz += 2.0;
                  break;
    case 'Z'    : view_rotz -= 2.0;
                  break;
    case '\033' : exit(0);
                  break ; }
}

static void special(int k, int x, int y) {
  switch (k) {
    case GLUT_KEY_UP    : view_rotx += 2.0;
                          break;
    case GLUT_KEY_DOWN  : view_rotx -= 2.0;
                          break;
    case GLUT_KEY_LEFT  : view_roty += 2.0;
                          break;
    case GLUT_KEY_RIGHT : view_roty -= 2.0;
                          break; }
  glutPostRedisplay();
}

int main(int argc,char **argv) {
  glutInit(&argc,argv);
  glutInitWindowSize(300,300);
  glutInitDisplayMode(GLUT_RGBA|GLUT_DEPTH|GLUT_DOUBLE);
  glutCreateWindow("Menus avec GLUt");
  glutDisplayFunc(redraw);
  glutReshapeFunc(reshape);
  
  /*creation du menu */
  int menuMode = glutCreateMenu(selectMode);
      glutAddMenuEntry("Plein",11);
      glutAddMenuEntry("Filaire",12);
  int menuObjet = glutCreateMenu(selectObjet);
          glutAddMenuEntry("Sphere",1);
          glutAddMenuEntry("Cone",2);
          glutAddMenuEntry("Tore",3);
  glutCreateMenu(select);
       glutAddSubMenu("Mode",menuMode);
       glutAddSubMenu("Objet",menuObjet);
       glutAddMenuEntry("Quitter",0);
       
  /* choix du bouton gauche de la souris */
  
  glutAttachMenu(GLUT_LEFT_BUTTON);
  
  
  glutKeyboardFunc(key);
  glutSpecialFunc(special);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glutMainLoop();
  return(0);
}

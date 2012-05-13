
#include <stdio.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>


#include "../modulesutilitaires/ModuleCouleurs.h"
#include "../modulesutilitaires/ModuleManipulateur.h"
#include "../modulesutilitaires/ModuleMenus.h"
#include "../modulesutilitaires/ModuleReshape.h"

static int epaule = 0, bras = 0; 
  
void display(void) { 
  glClear(GL_COLOR_BUFFER_BIT);
  glColor4fv(couleurNoir());
  
/* Matrice principale pour les deux objets */  
  glPushMatrix(); 
      manipulateurSouris();
      manipulateurClavier();

      /* definition de la matrice  secondaire */
      glPushMatrix(); 
      /* décalage de l'objet */
      glRotatef((GLfloat) bras,0.0,0.0,1.0);
      glTranslatef(2.0,0.0,0.0); 
      
      /* décalage de l'axe de rotation */ 
      glTranslatef(-1.0,0.0,0.0); 
              glPushMatrix();
                  /* creation du bras */
                  glScalef(2.0F,0.4F,1.0F);
                  glutWireCube(1.0); 
              glPopMatrix(); 
      /* decalage de l'objet */
      glTranslatef(2.0,0.0,0.0); 
      glRotatef((GLfloat) epaule,0.0,0.0,1.0); 
      /* decalage de l'axe de rotation */
         glTranslatef(1.0,0.0,0.0); 
         
     /* suite du dessin */         
         glPushMatrix();
          
        
          /* creation de l'avant bras */
              glScalef(2.0F,0.7F,1.0F);
              glutWireCube(1.0); 
         glPopMatrix(); 
     glPopMatrix(); 
  glPopMatrix(); 
  glFlush();
  glutSwapBuffers();
} 
  
void myinit(void) { 
  glClearColor(1.0,1.0,1.0,1.0);
} 
  
void special(int k, int x, int y) {
  switch (k) {
    case GLUT_KEY_UP    : bras = (bras + 5) % 360;
                          glutPostRedisplay();
                          break;
    case GLUT_KEY_DOWN  : bras = (bras - 5) % 360;
                          glutPostRedisplay();
                          break;
    case GLUT_KEY_LEFT  : epaule = (epaule + 5) % 360;
                          glutPostRedisplay();
                          break;
    case GLUT_KEY_RIGHT : epaule = (epaule - 5) % 360;
                          glutPostRedisplay();
                          break; }
}

int main(int argc,char **argv) {
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE);
  glutInitWindowSize(300,300); 
  glutInitWindowPosition(50,50); 
  glutCreateWindow("Bras robot"); 
  myinit(); 
  creationMenuBasique();
  setParametresPerspectiveBasique(65.0F,1.0F,1.0F,20.0F,0.0F,0.0F,-5.0F);
  setManipulateurDistance(5.0F);
  glutReshapeFunc(reshapePerspectiveBasique);
  glutKeyboardFunc(keyBasique);
  glutSpecialFunc(special);
  glutMotionFunc(motionBasique);
  glutMouseFunc(sourisBasique);
  glutDisplayFunc(display);
  glutMainLoop();
  return(0);
}



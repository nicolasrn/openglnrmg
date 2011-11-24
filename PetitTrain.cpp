
#include <stdio.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>


#include "ModuleCouleurs.h"
#include "ModuleManipulateur.h"
#include "ModuleMenus.h"
#include "ModuleReshape.h"
#include "ModuleCylindres.h"


static float anglex = 0.0F ;
static float angley = 0.0F ;
  
void display(void) { 
  glClear(GL_COLOR_BUFFER_BIT);
  glColor4fv(couleurNoir());
  
  //pour le recpouvremment: dessine ce qu'il faut
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT) ;


  
  /* Matrice principale pour les trois objets */  
  glPushMatrix(); 
  
      manipulateurSouris();
      manipulateurClavier();
      
      //rotation de toute la scene
        glRotatef(angley,0.0F,1.0F,0.0F) ;
        glRotatef(anglex,1.0F,0.0F,0.0F) ;
       
      //création de l'avant de la loco
      glPushMatrix();
         glColor4fv(couleurRougeFonce());
         glTranslatef(-0.9, 0.2, 0);
         glRotatef(90, 0, 0, 1);
         solidCylindre(0.7,1.5,20,10);
      glPopMatrix();
      
      glPushMatrix();
         glColor4fv(couleurRose());
         glTranslatef(-1.65, 0.2, 0);
         glRotatef(-90, 0, 1, 0);
         GLUquadric* cone = gluNewQuadric(); 
         gluCylinder(cone,0.7,0,0.3,20,1);
      glPopMatrix();
      
      glPushMatrix();
         glColor4fv(couleurRouge());
         glTranslatef(-1.8, 0.2, 0);
         GLUquadric* phare = gluNewQuadric(); 
         gluSphere(phare,0.2,20,20);
      glPopMatrix();
      
      glPushMatrix();
         glColor4fv(couleurJaune());
         glTranslatef(-1.82, 0.2, 0);
         GLUquadric* ampoule = gluNewQuadric(); 
         gluSphere(ampoule,0.19,20,20);
      glPopMatrix();
      
      //création de la cheminée
      glPushMatrix();
         glColor4fv(couleurRouge());
         glTranslatef(-1.4, 1.1, 0);
         solidCylindre(0.2,0.4,20,10);
      glPopMatrix();
      
      glPushMatrix();
         glColor4fv(couleurJaune());
         glTranslatef(-1.4, 1.1, 0);
         glRotatef(-90, 1, 0, 0);
         GLUquadric* cone1 = gluNewQuadric();         
         gluCylinder(cone1,0.18,0.4,0.4,20,1);
      glPopMatrix();
      
      glPushMatrix();
         glColor4fv(couleurVert());
         glTranslatef(-1.4, 1.5, 0);
         glRotatef(-90, 1, 0, 0);
         GLUquadric* cone2 = gluNewQuadric();         
         gluCylinder(cone2,0.4,0.18,0.4,20,1);
      glPopMatrix();
      
      
      
      //création de la cabine
                 //création du côté
                 glPushMatrix();
                     glColor4fv(couleurBleu());
                     glTranslatef(-0.1, 0.7, 0.7);
                     glScalef(0.2,2.4,0.2);
                     glutSolidCube(1.0);  
                 glPopMatrix();
                 
                 glPushMatrix();
                     glColor4fv(couleurBleu());
                     glTranslatef(1.3, 0.7, 0.7);
                     glScalef(0.2,2.4,0.2);
                     glutSolidCube(1.0); 
                 glPopMatrix();
                 
                 glPushMatrix();
                     glColor4fv(couleurBleu());
                     glTranslatef(0.6, 0.2, 0.7);
                     glScalef(1.2,1.4,0.2);
                    glutSolidCube(1.0);  
                 glPopMatrix();
                 
                 glPushMatrix();
                     glColor4fv(couleurBleu());
                     glTranslatef(0.6, 1.8, 0.7);
                     glScalef(1.2,0.2,0.2);
                     glutSolidCube(1.0);  
                 glPopMatrix();
                 
                 //création du côté en face
                 glPushMatrix();
                     glColor4fv(couleurBrun());
                     glTranslatef(-0.1, 0.7, -0.7);
                     glScalef(0.2,2.4,0.2);
                     glutSolidCube(1.0); 
                 glPopMatrix();
                 
                 glPushMatrix();
                     glColor4fv(couleurBrun());
                     glTranslatef(1.3, 0.7, -0.7);
                     glScalef(0.2,2.4,0.2);
                     glutSolidCube(1.0); 
                 glPopMatrix();
                 
                 glPushMatrix();
                     glColor4fv(couleurBrun());
                     glTranslatef(0.6, 0.2, -0.7);
                     glScalef(1.2,1.4,0.2);
                     glutSolidCube(1.0); 
                 glPopMatrix();
                 
                 glPushMatrix();
                     glColor4fv(couleurBrun());
                     glTranslatef(0.6, 1.8, -0.7);
                     glScalef(1.2,0.2,0.2);
                     glutSolidCube(1.0);  
                 glPopMatrix();
                 
                 //création de la face avant
                 glPushMatrix();
                     glColor4fv(couleurRouge());
                     glTranslatef(-0.1, 1.8, 0);
                     glScalef(0.2,0.2,1.2);
                     glutSolidCube(1.0);  
                 glPopMatrix();
                 
                 glPushMatrix();
                     glColor4fv(couleurRouge());
                     glTranslatef(-0.1, 0.2, 0);
                     glScalef(0.2,1.4,1.2);
                     glutSolidCube(1.0);  
                 glPopMatrix();
                 
                 //création de la face arrière (côté porte)
                 glPushMatrix();
                     glColor4fv(couleurRouge());
                     glTranslatef(1.3, 1.8, 0);
                     glScalef(0.2,0.2,1.2);
                     glutSolidCube(1.0);  
                 glPopMatrix();
                 
                 //création du sol
                 glPushMatrix();
                     glColor4fv(couleurGrisClair());
                     glTranslatef(0.7, -0.475, 0);
                     glScalef(1.4,0.05,1.2);
                     glutSolidCube(1.0);  
                 glPopMatrix();
                 
                 //création du toit
                 glPushMatrix();
                     glColor4fv(couleurCyan());
                     glTranslatef(0.6, 2.11, 0.42);
                     glRotatef(-60, 1, 0, 0);
                     glScalef(2,1,0.05);
                     glutSolidCube(1.0);  
                 glPopMatrix();
                 
                 glPushMatrix();
                     glColor4fv(couleurRouge());
                     glTranslatef(0.6, 2.11, -0.42);
                     glRotatef(60, 1, 0, 0);
                     glScalef(2,1,0.05);
                     glutSolidCube(1.0);  
                 glPopMatrix();
                 
                 //les pinions
               glBegin(GL_POLYGON);
                  glColor4fv(couleurRose());
                  glVertex3f(1.4,1.9, 0.8);//sommet
                  
                  glColor4fv(couleurRose());
                  glVertex3f(1.4,2.35, 0);
                  
                  glColor4fv(couleurRose());
                  glVertex3f(1.4,1.9, -0.8);//sommet           
               glEnd();
               
               glBegin(GL_POLYGON);
                  glColor4fv(couleurJaune());
                  glVertex3f(1.2,1.9, 0.8);//sommet
                  
                  glColor4fv(couleurJaune());
                  glVertex3f(1.2,2.35, 0);
                  
                  glColor4fv(couleurJaune());
                  glVertex3f(1.2,1.9, -0.8);//sommet  
               glEnd();
               
               glBegin(GL_POLYGON);
                  glColor4fv(couleurVert());
                  glVertex3f(0,1.9, 0.8);//sommet
                  
                  glColor4fv(couleurVert());
                  glVertex3f(0,2.35, 0);
                  
                  glColor4fv(couleurVert());
                  glVertex3f(0,1.9, -0.8);//sommet  
               glEnd();
               
               glBegin(GL_POLYGON);
                  glColor4fv(couleurRose());
                  glVertex3f(-0.2,1.9, 0.8);//sommet
                  
                  glColor4fv(couleurRose());
                  glVertex3f(-0.2,2.35, 0);
                  
                  glColor4fv(couleurRose());
                  glVertex3f(-0.2,1.9, -0.8);//sommet  
               glEnd();

                 
      
      
  glPopMatrix();
  

  glFlush();
  glutSwapBuffers();
} 
  
void myinit(void) { 
  glClearColor(1.0,1.0,1.0,1.0);
} 
  
void special(int key,int x,int y) {
  switch(key) {
    case GLUT_KEY_UP    : anglex--; 
                          break;
    case GLUT_KEY_DOWN  : anglex++; 
                          break;
    case GLUT_KEY_LEFT  : angley--; 
                          break;
    case GLUT_KEY_RIGHT : angley++; 
                          break; }
  glutPostRedisplay() ;
}

int main(int argc,char **argv) {
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE|GLUT_DEPTH);
  glutInitWindowSize(500,500); 
  glutInitWindowPosition(100,100); 
  glutCreateWindow("Petit train"); 
  myinit();
  
  //pour le recouvrement
  glEnable(GL_DEPTH_TEST) ;
  
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




/* Module de dessin des cylindres         */


#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "ModuleRoue.h"
#include "ModuleCylindres.h"

void Roue(float* couleur1, float* couleur2, float* couleur3) {
  glPushMatrix();
   double i=0;
   GLUquadric* param = gluNewQuadric();
         do
         {
                glPushMatrix();
                  glColor4fv(couleur1);
                  glTranslatef(0, 0, i);
                  glRotatef(90, 0, 0, 1);
                  glutWireTorus(0.2,0.4,2,20);
                  i = i + 0.001;
                glPopMatrix();
         }
         while( i<=0.16);
         
  glPushMatrix();
         glColor4fv(couleur2);
         glTranslatef(0, 0, 0.08);
         glRotatef(90, 1, 0, 0);
         solidCylindre(0.65,0.16,20,10);       
  glPopMatrix();
  
  glPushMatrix();
         glColor4fv(couleur2);
         glTranslatef(0, 0, 0.08);
         glRotatef(90, 1, 0, 0);
         solidCylindre(0.59,0.16,20,10);       
  glPopMatrix();
  
  glPushMatrix();
         glColor4fv(couleur3);
         glTranslatef(0, 0, 0);
         glRotatef(90, 0, 0, 1);         
         gluDisk(param,0.59,0.65,20,1);      
  glPopMatrix();
  
  glPushMatrix();
         glColor4fv(couleur3);
         glTranslatef(0, 0, 0.16);
         glRotatef(90, 0, 0, 1);
         gluDisk(param,0.59,0.65,20,1);              
  glPopMatrix();
  
  glPushMatrix();
         glColor4fv(couleur2);
         glTranslatef(0, 0, 0.08);
         glRotatef(90, 1, 0, 0);
         solidCylindre(0.19,0.16,20,10);       
  glPopMatrix();
  
  glPushMatrix();
         glColor4fv(couleur2);
         glTranslatef(0, 0, 0.08);
         glRotatef(90, 1, 0, 0);
         solidCylindre(0.24,0.16,20,10);       
  glPopMatrix();
  
  glPushMatrix();
         glColor4fv(couleur3);
         glTranslatef(0, 0, 0);
         glRotatef(90, 0, 0, 1);         
         gluDisk(param,0.19,0.24,20,1);      
  glPopMatrix();
  
  glPushMatrix();
         glColor4fv(couleur3);
         glTranslatef(0, 0, 0.16);
         glRotatef(90, 0, 0, 1);
         gluDisk(param,0.19,0.24,20,1);              
  glPopMatrix();
  
  glPopMatrix();
}


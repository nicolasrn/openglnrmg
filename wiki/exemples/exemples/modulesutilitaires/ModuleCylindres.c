
/* Module de dessin des cylindres         */


#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "ModuleCylindres.h"

void wireCylindre(float r,float h,int n,int m) {
  glPushMatrix();
  glRotatef(90.0F,1.0F,0.0F,0.0F);
  glTranslatef(0.0F,0.0F,-h/2);
  GLUquadricObj *qobj = gluNewQuadric();
  gluQuadricDrawStyle(qobj,GLU_LINE);
  gluCylinder(qobj,r,r,h,n,m);
  gluDeleteQuadric(qobj);  
  glPopMatrix();
}

void solidCylindre(float r,float h,int n,int m) {
  glPushMatrix();
  glRotatef(90.0F,1.0F,0.0F,0.0F);
  glTranslatef(0.0F,0.0F,-h/2);
  GLUquadricObj *qobj = gluNewQuadric();
  gluQuadricDrawStyle(qobj,GLU_FILL);
  gluCylinder(qobj,r,r,h,n,m);
  gluDeleteQuadric(qobj);  
  glPopMatrix();
}



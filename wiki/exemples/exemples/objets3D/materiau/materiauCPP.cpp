

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "../../ModulesUtilitaires/ModuleCouleurs.h"
#include "../../ModulesUtilitaires/ModuleManipulateur.h"
#include "../../ModulesUtilitaires/ModuleMenus.h"
#include "../../ModulesUtilitaires/ModuleReshape.h"

void myinit(void) { 
  GLfloat position[] = {0.0F,3.0F,2.0F,0.0F}; 
  GLfloat local_view[] = {0.0F}; 
  glEnable(GL_DEPTH_TEST); 
  glDepthFunc(GL_LESS); 
  glLightfv(GL_LIGHT0,GL_AMBIENT,couleurNoir()); 
  glLightfv(GL_LIGHT0,GL_DIFFUSE,couleurBlanc()); 
  glLightfv(GL_LIGHT0,GL_POSITION,position); 
  glLightModelfv(GL_LIGHT_MODEL_AMBIENT,couleurGrisMoyen()); 
  glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER,local_view); 
  glEnable(GL_LIGHTING); 
  glEnable(GL_LIGHT0); 
  glClearColor(0.0F,0.1F,0.1F,0.0F); 
  glEnable(GL_AUTO_NORMAL);
  glEnable(GL_NORMALIZE);
} 
  
void display(void) { 
  GLfloat no_mat[] = { 0.0F,0.0F,0.0F,1.0F };
  GLfloat mat_ambient[] = { 0.7F,0.7F,0.7F,1.0F };
  GLfloat mat_ambient_color[] = { 0.8F,0.8F,0.2F,1.0F };
  GLfloat mat_diffuse[] = { 0.1F,0.5F,0.8F,1.0F };
  GLfloat mat_specular[] = { 1.0F,1.0F,1.0F,1.0F };
  GLfloat no_shininess[] = { 0.0F };
  GLfloat low_shininess[] = { 5.0F };
  GLfloat high_shininess[] = { 100.0F };
  GLfloat mat_emission[] = {0.3F,0.2F,0.2F,0.0F};
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glPushMatrix();
  manipulateurSouris();
  manipulateurClavier();
  glPushMatrix();
  glTranslatef(-3.75F,3.0F,0.0F);
  glMaterialfv(GL_FRONT,GL_AMBIENT,no_mat);
  glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
  glMaterialfv(GL_FRONT,GL_SPECULAR,no_mat);
  glMaterialfv(GL_FRONT,GL_SHININESS,no_shininess);
  glMaterialfv(GL_FRONT,GL_EMISSION,no_mat);
  glutSolidSphere(1.0,24,24);
  glPopMatrix();
  glPushMatrix();
  glTranslatef(-1.25F,3.0F,0.0F);
  glMaterialfv(GL_FRONT,GL_AMBIENT,no_mat);
  glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
  glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
  glMaterialfv(GL_FRONT,GL_SHININESS,low_shininess);
  glMaterialfv(GL_FRONT,GL_EMISSION,no_mat);
  glutSolidSphere(1.0,24,24);
  glPopMatrix();
  glPushMatrix();
  glTranslatef(1.25F,3.0F,0.0F);
  glMaterialfv(GL_FRONT,GL_AMBIENT,no_mat);
  glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
  glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
  glMaterialfv(GL_FRONT,GL_SHININESS,high_shininess);
  glMaterialfv(GL_FRONT,GL_EMISSION,no_mat);
  glutSolidSphere(1.0,24,24);
  glPopMatrix();
  glPushMatrix();
  glTranslatef(3.75F,3.0F,0.0F);
  glMaterialfv(GL_FRONT,GL_AMBIENT,no_mat);
  glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
  glMaterialfv(GL_FRONT,GL_SPECULAR,no_mat);
  glMaterialfv(GL_FRONT,GL_SHININESS,no_shininess);
  glMaterialfv(GL_FRONT,GL_EMISSION,mat_emission);
  glutSolidSphere(1.0,24,24);
  glPopMatrix();
  glPushMatrix();
  glTranslatef(-3.75F,0.0F,0.0F);
  glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient);
  glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
  glMaterialfv(GL_FRONT,GL_SPECULAR,no_mat);
  glMaterialfv(GL_FRONT,GL_SHININESS,no_shininess);
  glMaterialfv(GL_FRONT,GL_EMISSION,no_mat);
  glutSolidSphere(1.0,24,24);
  glPopMatrix();
  glPushMatrix();
  glTranslatef(-1.25F,0.0F,0.0F);
  glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient);
  glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
  glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
  glMaterialfv(GL_FRONT,GL_SHININESS,low_shininess);
  glMaterialfv(GL_FRONT,GL_EMISSION,no_mat);
  glutSolidSphere(1.0,24,24);
  glPopMatrix();
  glPushMatrix();
  glTranslatef(1.25F,0.0F,0.0F);
  glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient);
  glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
  glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
  glMaterialfv(GL_FRONT,GL_SHININESS,high_shininess);
  glMaterialfv(GL_FRONT,GL_EMISSION,no_mat);
  glutSolidSphere(1.0,24,24);
  glPopMatrix();
  glPushMatrix();
  glTranslatef(3.75F,0.0F,0.0F);
  glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient);
  glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
  glMaterialfv(GL_FRONT,GL_SPECULAR,no_mat);
  glMaterialfv(GL_FRONT,GL_SHININESS,no_shininess);
  glMaterialfv(GL_FRONT,GL_EMISSION,mat_emission);
  glutSolidSphere(1.0,24,24);
  glPopMatrix();
  glPushMatrix();
  glTranslatef(-3.75F,-3.0F,0.0F);
  glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient_color);
  glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
  glMaterialfv(GL_FRONT,GL_SPECULAR,no_mat);
  glMaterialfv(GL_FRONT,GL_SHININESS,no_shininess);
  glMaterialfv(GL_FRONT,GL_EMISSION,no_mat);
  glutSolidSphere(1.0,24,24);
  glPopMatrix();
  glPushMatrix();
  glTranslatef(-1.25F,-3.0F,0.0F);
  glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient_color);
  glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
  glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
  glMaterialfv(GL_FRONT,GL_SHININESS,low_shininess);
  glMaterialfv(GL_FRONT,GL_EMISSION,no_mat);
  glutSolidSphere(1.0,24,24);
  glPopMatrix();
  glPushMatrix();
  glTranslatef(1.25F,-3.0F,0.0F);
  glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient_color);
  glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
  glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
  glMaterialfv(GL_FRONT,GL_SHININESS,high_shininess);
  glMaterialfv(GL_FRONT,GL_EMISSION,no_mat);
  glutSolidSphere(1.0,24,24);
  glPopMatrix();
  glPushMatrix();
  glTranslatef(3.75F,-3.0F,0.0F);
  glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient_color);
  glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
  glMaterialfv(GL_FRONT,GL_SPECULAR,no_mat);
  glMaterialfv(GL_FRONT,GL_SHININESS,no_shininess);
  glMaterialfv(GL_FRONT,GL_EMISSION,mat_emission);
  glutSolidSphere(1.0,24,24);
  glPopMatrix();
  glPopMatrix();
  glFlush(); 
  glutSwapBuffers();
} 
  
int main(int argc,char **argv) {
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_RGBA|GLUT_DEPTH|GLUT_DOUBLE);
  glutInitWindowSize(340,250); 
  glutInitWindowPosition(50,50); 
  glutCreateWindow("Material"); 
  myinit(); 
  creationMenuBasique();
  setParametresOrthoBasique(-4.5,4.5,-4.5,4.5,-500.0,500.0);
  setManipulateurDistance(1.0F);
  glutReshapeFunc(reshapeOrthoBasique);
  glutKeyboardFunc(keyBasique);
  glutSpecialFunc(specialBasique);
  glutMotionFunc(motionBasique);
  glutMouseFunc(sourisBasique);
  glutDisplayFunc(display);
  glutMainLoop();
  return(0);
}

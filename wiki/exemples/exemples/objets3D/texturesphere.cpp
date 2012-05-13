
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "../modulesutilitaires/ModuleManipulateur.h"
#include "../modulesutilitaires/ModuleMenus.h"
#include "../modulesutilitaires/ModuleReshape.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846264338327950288
#endif
#define LI 64 
#define LH 64 

struct coord3D {
  float x;
  float y;
  float z; } ;

struct coord2D {
  float x;
  float y; } ;

GLubyte image[LI][LH][3]; 
  
void makeImage(void) { 
  int i,j,c; 
  for( i = 0 ; i < LI ; i++ ) { 
    for( j = 0 ; j < LH ; j++ ) { 
      c =(((i&0x4)==0)^((j&0x4)==0))*255; 
      image[i][j][0] =(GLubyte) c; 
      image[i][j][1] =(GLubyte) c; 
      image[i][j][2] =(GLubyte) c; } } 
} 
  
void myinit(void) { 
  glClearColor(0.8F,0.8F,0.8F,0.0);
  glEnable(GL_DEPTH_TEST); 
  glEnable(GL_LIGHTING); 
  glEnable(GL_LIGHT0); 
  glDepthFunc(GL_LESS); 
  makeImage(); 
  glPixelStorei(GL_UNPACK_ALIGNMENT,1); 
  glTexImage2D(GL_TEXTURE_2D,0,3,LI,LH,0,GL_RGB,GL_UNSIGNED_BYTE,&image[0][0][0]); 
  glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP); 
  glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP); 
  glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST); 
  glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST); 
  glEnable(GL_TEXTURE_2D);
  glShadeModel(GL_SMOOTH); 
  glEnable(GL_AUTO_NORMAL);
  glEnable(GL_NORMALIZE);
} 

void solidSphere(double r,int lat,int lon) {
  int npt = 2 + (lat-1)*lon;
  int ntx = (lat+1)*(lon+1);
  coord3D *pts =(coord3D *) calloc(npt,sizeof(coord3D));
  coord2D *tex =(coord2D *) calloc(ntx,sizeof(coord2D));
  pts[0].x = 0.0f;
  pts[0].y = 0.0f;
  pts[0].z = 1.0f;
  pts[1].x = 0.0f;
  pts[1].y = 0.0f;
  pts[1].z = -1.0f;
  int n = 0 ;
  int i,j ;
  for ( j = 0 ; j < lat+1 ; j++ ) {
    for ( i = 0 ; i < lon+1 ; i++ ) {
      tex[n].x =(float) i/lon;
      tex[n].y =(float) j/lat;
      n++; } }
  n = 2 ;
  for ( j = 0 ; j < (lat-1) ; j++ ) {
    double aa = M_PI/2.0-(j+1)*M_PI/lat;
    double c = cos(aa);
    double s = sin(aa);
    for ( i = 0 ; i < lon ; i++ ) {
      double a = i*M_PI*2.0/lon;
      pts[n].x = c*cos(a);
      pts[n].y = c*sin(a);
      pts[n].z = s;
      n++; } }
  glBegin(GL_QUADS);
  for ( i = 0 ; i < lon ; i++ ) {
    glTexCoord2fv((float *) &tex[i]);
    glNormal3fv((float *) &pts[0]);
    glVertex3fv((float *) &pts[0]);
    glTexCoord2fv((float *) &tex[i+lon+1]);
    glNormal3fv((float *) &pts[2+i]);
    glVertex3fv((float *) &pts[2+i]);
    glTexCoord2fv((float *) &tex[i+lon+2]);
    glNormal3fv((float *) &pts[2+(i+1)%lon]);
    glVertex3fv((float *) &pts[2+(i+1)%lon]);
    glTexCoord2fv((float *) &tex[i+1]);
    glNormal3fv((float *) &pts[0]);
    glVertex3fv((float *) &pts[0]); }
  for ( j = 0 ; j < lat-2 ; j++ ) {
    for ( i = 0 ; i < lon ; i++ ) {
      glTexCoord2fv((float *) &tex[i+(j+1)*(lon+1)]);
      glNormal3fv((float *) &pts[2+i+j*lon]);
      glVertex3fv((float *) &pts[2+i+j*lon]);
      glTexCoord2fv((float *) &tex[i+1+(j+1)*(lon+1)]);
      glNormal3fv((float *) &pts[2+(i+1)%lon+j*lon]);
      glVertex3fv((float *) &pts[2+(i+1)%lon+j*lon]);
      glTexCoord2fv((float *) &tex[i+1+(j+2)*(lon+1)]);
      glNormal3fv((float *) &pts[2+(i+1)%lon+(j+1)*lon]);
      glVertex3fv((float *) &pts[2+(i+1)%lon+(j+1)*lon]);
      glTexCoord2fv((float *) &tex[i+(j+2)*(lon+1)]);
      glNormal3fv((float *) &pts[2+i+(j+1)*lon]);
      glVertex3fv((float *) &pts[2+i+(j+1)*lon]); } }
  for ( i = 0 ; i < lon ; i++ ) {
    glTexCoord2fv((float *) &tex[i+lat*(lon+1)]);
    glNormal3fv((float *) &pts[1]);
    glVertex3fv((float *) &pts[1]);
    glTexCoord2fv((float *) &tex[i+(lat-1)*(lon+1)]);
    glNormal3fv((float *) &pts[2+(lat-2)*lon+i]);
    glVertex3fv((float *) &pts[2+(lat-2)*lon+i]);
    glTexCoord2fv((float *) &tex[i+1+(lat-1)*(lon+1)]);
    glNormal3fv((float *) &pts[2+(lat-2)*lon+(i+1)%lon]);
    glVertex3fv((float *) &pts[2+(lat-2)*lon+(i+1)%lon]);
    glTexCoord2fv((float *) &tex[i+1+lat*(lon+1)]);
    glNormal3fv((float *) &pts[1]);
    glVertex3fv((float *) &pts[1]); }
  glEnd();
  free(tex);
  free(pts);
}
  
void display(void) { 
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); 
  glPushMatrix();
  manipulateurSouris();
  manipulateurClavier();
  solidSphere(1.0,18,36);
  glPopMatrix();
  glFlush(); 
  glutSwapBuffers();
} 
  
int main(int argc,char **argv) {
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_RGBA|GLUT_DEPTH|GLUT_DOUBLE);
  glutInitWindowSize(300,200); 
  glutInitWindowPosition(50,50); 
  glutCreateWindow("Une sphere avec texture"); 
  myinit(); 
  creationMenuBasique();
  setParametresPerspectiveBasique(43.0F,1.5F,1.0F,30.0F,0.0F,0.0F,-3.6F);
  setManipulateurDistance(3.6F);
  glutReshapeFunc(reshapePerspectiveBasique);
  glutKeyboardFunc(keyBasique);
  glutSpecialFunc(specialBasique);
  glutMotionFunc(motionBasique);
  glutMouseFunc(sourisBasique);
  glutDisplayFunc(display);
  glutMainLoop();
  return(0);
}

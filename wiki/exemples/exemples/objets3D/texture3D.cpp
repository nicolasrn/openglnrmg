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

#define TLI 16 
#define TLH 16 
#define TLL 16 

struct coord3D {
  float x;
  float y;
  float z; } ;

struct coord2D {
  float x;
  float y; } ;

GLubyte image3Dx1[TLI][TLH][TLL][3]; 
GLubyte image3Dx2[TLI][TLH][TLL][3]; 
GLubyte image3Dx3[TLI][TLH][TLL][3]; 
int aff = 0;
int obj = 0;
  
void makeImage3Dx1(void) { 
  int i,j,k,c; 
  for( i = 0 ; i < TLI ; i++ ) { 
    for( j = 0 ; j < TLH ; j++ ) { 
      for( k = 0 ; k < TLL ; k++ ) { 
        c =(((i&0x4)==0))*255; 
        image3Dx1[i][j][k][0] =(GLubyte) c; 
        image3Dx1[i][j][k][1] =(GLubyte) c; 
        image3Dx1[i][j][k][2] =(GLubyte) c; } } }
} 
  
void makeImage3Dx2(void) { 
  int i,j,k,c; 
  for( i = 0 ; i < TLI ; i++ ) { 
    for( j = 0 ; j < TLH ; j++ ) { 
      for( k = 0 ; k < TLL ; k++ ) { 
        c =(((i&0x4)==0)^((j&0x4)==0))*255; 
        image3Dx2[i][j][k][0] =(GLubyte) c; 
        image3Dx2[i][j][k][1] =(GLubyte) c; 
        image3Dx2[i][j][k][2] =(GLubyte) c; } } }
} 
  
void makeImage3Dx3(void) { 
  int i,j,k,c; 
  for( i = 0 ; i < TLI ; i++ ) { 
    for( j = 0 ; j < TLH ; j++ ) { 
      for( k = 0 ; k < TLL ; k++ ) { 
        c =(((i&0x4)==0)^((j&0x4)==0)^((k&0x4)==0))*255; 
        image3Dx3[i][j][k][0] =(GLubyte) c; 
        image3Dx3[i][j][k][1] =(GLubyte) c; 
        image3Dx3[i][j][k][2] =(GLubyte) c; } } }
} 
  
void myinit(void) { 
  glClearColor(0.8,0.8,0.8,0.0);
  glEnable(GL_DEPTH_TEST); 
  glEnable(GL_LIGHTING); 
  glEnable(GL_LIGHT0); 
  glDepthFunc(GL_LESS); 
  makeImage3Dx1(); 
  makeImage3Dx2(); 
  makeImage3Dx3(); 
  glPixelStorei(GL_UNPACK_ALIGNMENT,1); 
  glTexImage3D(GL_TEXTURE_3D,0,3,
               TLI,TLH,TLL,
               0,GL_RGB,
               GL_UNSIGNED_BYTE,
               &image3Dx1[0][0][0][0]);
  glTexParameterf(GL_TEXTURE_3D,GL_TEXTURE_WRAP_S,GL_REPEAT); 
  glTexParameterf(GL_TEXTURE_3D,GL_TEXTURE_WRAP_T,GL_REPEAT); 
  glTexParameterf(GL_TEXTURE_3D,GL_TEXTURE_WRAP_R,GL_REPEAT); 
  glTexParameterf(GL_TEXTURE_3D,GL_TEXTURE_MAG_FILTER,GL_NEAREST); 
  glTexParameterf(GL_TEXTURE_3D,GL_TEXTURE_MIN_FILTER,GL_NEAREST); 
  glEnable(GL_TEXTURE_3D);
  glShadeModel(GL_SMOOTH); 
  glEnable(GL_AUTO_NORMAL);
  glEnable(GL_NORMALIZE);
} 

void solidSphere(int lat,int lon) {
  int npt = 2 + (lat-1)*lon;
  coord3D *pts =(coord3D *) calloc(npt,sizeof(coord3D));
  pts[0].x = 0.0f;
  pts[0].y = 0.0f;
  pts[0].z = 1.0f;
  pts[1].x = 0.0f;
  pts[1].y = 0.0f;
  pts[1].z = -1.0f;
  int i,j ;
  int n = 2 ;
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
    glTexCoord3fv((float *) &pts[0]);
    glNormal3fv((float *) &pts[0]);
    glVertex3fv((float *) &pts[0]);
    glTexCoord3fv((float *) &pts[2+i]);
    glNormal3fv((float *) &pts[2+i]);
    glVertex3fv((float *) &pts[2+i]);
    glTexCoord3fv((float *) &pts[2+(i+1)%lon]);
    glNormal3fv((float *) &pts[2+(i+1)%lon]);
    glVertex3fv((float *) &pts[2+(i+1)%lon]);
    glTexCoord3fv((float *) &pts[0]);
    glNormal3fv((float *) &pts[0]);
    glVertex3fv((float *) &pts[0]); }
  for ( j = 0 ; j < lat-2 ; j++ ) {
    for ( i = 0 ; i < lon ; i++ ) {
      glTexCoord3fv((float *) &pts[2+i+j*lon]);
      glNormal3fv((float *) &pts[2+i+j*lon]);
      glVertex3fv((float *) &pts[2+i+j*lon]);
      glTexCoord3fv((float *) &pts[2+(i+1)%lon+j*lon]);
      glNormal3fv((float *) &pts[2+(i+1)%lon+j*lon]);
      glVertex3fv((float *) &pts[2+(i+1)%lon+j*lon]);
      glTexCoord3fv((float *) &pts[2+(i+1)%lon+(j+1)*lon]);
      glNormal3fv((float *) &pts[2+(i+1)%lon+(j+1)*lon]);
      glVertex3fv((float *) &pts[2+(i+1)%lon+(j+1)*lon]);
      glTexCoord3fv((float *) &pts[2+i+(j+1)*lon]);
      glNormal3fv((float *) &pts[2+i+(j+1)*lon]);
      glVertex3fv((float *) &pts[2+i+(j+1)*lon]); } }
  for ( i = 0 ; i < lon ; i++ ) {
    glTexCoord3fv((float *) &pts[1]);
    glNormal3fv((float *) &pts[1]);
    glVertex3fv((float *) &pts[1]);
    glTexCoord3fv((float *) &pts[2+(lat-2)*lon+i]);
    glNormal3fv((float *) &pts[2+(lat-2)*lon+i]);
    glVertex3fv((float *) &pts[2+(lat-2)*lon+i]);
    glTexCoord3fv((float *) &pts[2+(lat-2)*lon+(i+1)%lon]);
    glNormal3fv((float *) &pts[2+(lat-2)*lon+(i+1)%lon]);
    glVertex3fv((float *) &pts[2+(lat-2)*lon+(i+1)%lon]);
    glTexCoord3fv((float *) &pts[1]);
    glNormal3fv((float *) &pts[1]);
    glVertex3fv((float *) &pts[1]); }
  glEnd();
  free(pts);
}
  
void solidCube(void) {
  glBegin(GL_QUADS);
  glNormal3f(0.0F,0.0F,1.0F);
  glTexCoord3f(0.99F,0.99F,0.99F);
  glVertex3f(0.99F,0.99F,0.99F);
  glTexCoord3f(-0.99F,0.99F,0.99F);
  glVertex3f(-0.99F,0.99F,0.99F);
  glTexCoord3f(-0.99F,-0.99F,0.99F);
  glVertex3f(-0.99F,-0.99F,0.99F);
  glTexCoord3f(0.99F,-0.99F,0.99F);
  glVertex3f(0.99F,-0.99F,0.99F);
  glNormal3f(0.0F,0.0F,-1.0F);
  glTexCoord3f(0.99F,0.99F,-0.99F);
  glVertex3f(0.99F,0.99F,-0.99F);
  glTexCoord3f(-0.99F,0.99F,-0.99F);
  glVertex3f(-0.99F,0.99F,-0.99F);
  glTexCoord3f(-0.99F,-0.99F,-0.99F);
  glVertex3f(-0.99F,-0.99F,-0.99F);
  glTexCoord3f(0.99F,-0.99F,-0.99F);
  glVertex3f(0.99F,-0.99F,-0.99F);
  glNormal3f(0.0F,1.0F,0.0F);
  glTexCoord3f(0.99F,0.99F,0.99F);
  glVertex3f(0.99F,0.99F,0.99F);
  glTexCoord3f(-0.99F,0.99F,0.99F);
  glVertex3f(-0.99F,0.99F,0.99F);
  glTexCoord3f(-0.99F,0.99F,-0.99F);
  glVertex3f(-0.99F,0.99F,-0.99F);
  glTexCoord3f(0.99F,0.99F,-0.99F);
  glVertex3f(0.99F,0.99F,-0.99F);
  glNormal3f(0.0F,-1.0F,0.0F);
  glTexCoord3f(0.99F,-0.99F,0.99F);
  glVertex3f(0.99F,-0.99F,0.99F);
  glTexCoord3f(-0.99F,-0.99F,0.99F);
  glVertex3f(-0.99F,-0.99F,0.99F);
  glTexCoord3f(-0.99F,-0.99F,-0.99F);
  glVertex3f(-0.99F,-0.99F,-0.99F);
  glTexCoord3f(0.99F,-0.99F,-0.99F);
  glVertex3f(0.99F,-0.99F,-0.99F);
  glNormal3f(1.0F,0.0F,0.0F);
  glTexCoord3f(0.99F,0.99F,0.99F);
  glVertex3f(0.99F,0.99F,0.99F);
  glTexCoord3f(0.99F,-0.99F,0.99F);
  glVertex3f(0.99F,-0.99F,0.99F);
  glTexCoord3f(0.99F,-0.99F,-0.99F);
  glVertex3f(0.99F,-0.99F,-0.99F);
  glTexCoord3f(0.99F,0.99F,-0.99F);
  glVertex3f(0.99F,0.99F,-0.99F);
  glNormal3f(-1.0F,0.0F,0.0F);
  glTexCoord3f(-0.99F,0.99F,0.99F);
  glVertex3f(-0.99F,0.99F,0.99F);
  glTexCoord3f(-0.99F,-0.99F,0.99F);
  glVertex3f(-0.99F,-0.99F,0.99F);
  glTexCoord3f(-0.99F,-0.99F,-0.99F);
  glVertex3f(-0.99F,-0.99F,-0.99F);
  glTexCoord3f(-0.99F,0.99F,-0.99F);
  glVertex3f(-0.99F,0.99F,-0.99F);
  glEnd();
}
  
void display(void) { 
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); 
  glPushMatrix();
  manipulateurSouris();
  manipulateurClavier();
  switch(obj) {
    case 0 : solidSphere(18,36);
             break;
    case 1 : solidCube(); }
  glPopMatrix();
  glFlush(); 
  glutSwapBuffers();
} 
  
void key(unsigned char key,int x,int y) {
  if ( keyManipulateur(key,x,y) )
    glutPostRedisplay();
    else
    switch ( key ) {
      case ' '    : obj =(obj+1)%2 ;
                    glutPostRedisplay();
                    break;
      case 0x0D   : aff =(aff+1)%3 ;
                    switch (aff) {
                      case 0 : glTexImage3D(GL_TEXTURE_3D,0,3,
                                            TLI,TLH,TLL,
                                            0,
                                            GL_RGB,GL_UNSIGNED_BYTE,
                                            &image3Dx1[0][0][0][0]);
                               break;
                      case 1 : glTexImage3D(GL_TEXTURE_3D,0,3,
                                            TLI,TLH,TLL,
                                            0,
                                            GL_RGB,GL_UNSIGNED_BYTE,
                                            &image3Dx2[0][0][0][0]);
                               break;
                      case 2 : glTexImage3D(GL_TEXTURE_3D,0,3,
                                            TLI,TLH,TLL,
                                            0,
                                            GL_RGB,GL_UNSIGNED_BYTE,
                                            &image3Dx3[0][0][0][0]);
                               break; }
                    glutPostRedisplay();
                    break; }
}

void main(void) { 
  glutInitDisplayMode(GLUT_RGBA|GLUT_DEPTH|GLUT_DOUBLE);
  glutInitWindowSize(300,200); 
  glutInitWindowPosition(50,50); 
  glutCreateWindow("Une sphere ou un cube avec texture 3D"); 
  myinit(); 
  creationMenuBasique();
  setParametresOrthoBasique(-1.5,1.5,-1.5,1.5,-500.0,500.0);
  setManipulateurDistance(1.0F);
  setManipulateurClavierAngle(40.0F,140.0F,0.0F) ;
  glutReshapeFunc(reshapeOrthoBasique);
  glutKeyboardFunc(key);
  glutSpecialFunc(specialBasique);
  glutMotionFunc(motionBasique);
  glutMouseFunc(sourisBasique);
  glutDisplayFunc(display);
  glutMainLoop();
}

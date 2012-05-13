/* Les parametres de lumiere     */


#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "../modulesutilitaires/ModuleManipulateur.h"
#include "../modulesutilitaires/ModuleCouleurs.h"
#include "../modulesutilitaires/ModuleMenus.h"
#include "../modulesutilitaires/ModuleReshape.h"
#include "../modulesutilitaires/ModuleFleche.h"
#include "../modulesutilitaires/ModuleFont.h"

static float diffuse0[4] = { 0.8F,0.8F,0.8F,1.0F };
static float ambiant0[4] = { 0.0F,0.0F,0.0F,1.0F };
static float specular0[4] = { 0.0F,0.0F,0.0F,1.0F };
static float position0[4] = { 0.0F,0.0F,2.3F,1.0F };
static float spotCutOff0[1] = { 180.0F };
static float spotDir0[3] = { 0.0F,0.0F,-1.0F };

static float diffuse1[4] = { 0.0F,0.0F,0.0F,1.0F };
static float ambiant1[4] = { 0.7F,0.6F,0.5F,1.0F };
static float specular1[4] = { 0.0F,0.0F,0.0F,1.0F };
static float position1[4] = { 0.0F,0.0F,2.3F,1.0F };
static float spotCutOff1[1] = { 180.0F };
static float spotDir1[3] = { 0.0F,0.0F,-1.0F };

static float diffuse2[4] = { 0.0F,0.0F,0.0F,1.0F };
static float ambiant2[4] = { 0.0F,0.0F,0.0F,1.0F };
static float specular2[4] = { 0.4F,0.6F,0.8F,1.0F };
static float position2[4] = { 0.0F,0.0F,2.3F,1.0F };
static float spotCutOff2[1] = { 180.0F };
static float spotDir2[3] = { 0.0F,0.0F,-1.0F };

static float diffuse3[4] = { 0.3F,0.5F,0.3F,1.0F };
static float ambiant3[4] = { 0.1F,0.1F,0.1F,1.0F };
static float specular3[4] = { 0.8F,0.1F,0.2F,1.0F };
static float position3[4] = { 0.0F,0.0F,2.3F,1.0F };
static float spotCutOff3[1] = { 180.0F };
static float spotDir3[3] = { 0.0F,0.0F,-1.0F };

static float diffuse4[4] = { 0.3F,0.5F,0.3F,1.0F };
static float ambiant4[4] = { 0.1F,0.1F,0.1F,1.0F };
static float specular4[4] = { 0.8F,0.1F,0.2F,1.0F };
static float position4[4] = { 0.4F,0.5F,0.7F,0.0F };
static float spotCutOff4[1] = { 180.0F };
static float spotDir4[3] = { 0.0F,0.0F,-1.0F };

static float diffuse5[4] = { 0.3F,0.5F,0.3F,1.0F };
static float ambiant5[4] = { 0.1F,0.1F,0.1F,1.0F };
static float specular5[4] = { 0.8F,0.1F,0.2F,1.0F };
static float position5[4] = { 0.0F,0.0F,2.3F,1.0F };
static float spotCutOff5[1] = { 20.0F };
static float spotDir5[3] = { 0.0F,0.0F,-1.0F };

static float diffuse6[4] = { 0.3F,0.5F,0.3F,1.0F };
static float ambiant6[4] = { 0.1F,0.1F,0.1F,1.0F };
static float specular6[4] = { 0.8F,0.1F,0.2F,1.0F };
static float position6[4] = { 0.0F,0.0F,2.3F,1.0F };
static float spotCutOff6[1] = { 25.0F };
static float spotDir6[3] = { 0.2F,0.2F,-1.0F };

static float diffuse[4];
static float ambiant[4];
static float specular[4];
static float position[4];
static float spotCutOff[4];
static float spotDir[4];

static float spotCutOff180[1] = { 180.0F };
static float *tp[6] = { spotDir,spotCutOff,position,specular,ambiant,diffuse };
static float *tc[7] = { couleurBlanc(),couleurMagenta(),couleurCyan(),
                        couleurJaune(),couleurRouge(),couleurVert(),couleurBleu() };
static float shininess[1] = { 8.0F };
static int param = 5;
static int pparam = 0;
static int nbparam[6] = { 3,1,4,3,3,3 };
static int f1;
static int f2;
static int disc = 90;
static int aff = 0;
static int cc = 0;

void affecteLight(float *d,float *a,float *s,float *p,float *sc,float *sd){
  int i;
  for ( i = 0 ; i < 4 ; i++ ) {
    diffuse[i] = d[i];
    ambiant[i] = a[i];
    specular[i] = s[i];
    position[i] = p[i]; }
  spotCutOff[0] = sc[0];
  for ( i = 0 ; i < 3 ; i++ ) {
    spotDir[i] = sd[i]; }
}

void init(void) {
  setManipulateurClavierAngle(20.0F,30.0F,0.0F);
  affecteLight(diffuse0,ambiant0,specular0,position0,spotCutOff0,spotDir0);
}

void display1() {
  glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);
  glPushMatrix();
  manipulateurClavier();
  glEnable(GL_LIGHTING);
  glLightfv(GL_LIGHT0,GL_DIFFUSE,diffuse);
  glLightfv(GL_LIGHT0,GL_AMBIENT,ambiant);
  glLightfv(GL_LIGHT0,GL_SPECULAR,specular);
  glLightfv(GL_LIGHT0,GL_POSITION,position);
  glLightfv(GL_LIGHT0,GL_SPOT_DIRECTION,spotDir);
  glLightfv(GL_LIGHT0,GL_SPOT_CUTOFF,spotCutOff);
  glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,tc[cc]);
  glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,tc[cc]);
  glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,tc[cc]);
  glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,couleurNoir());
  glMaterialfv(GL_FRONT_AND_BACK,GL_SHININESS,shininess);
  glPushMatrix();
  manipulateurSouris();
  switch(aff) {
    case 0 : glutSolidTorus(0.4,0.9,disc,2*disc) ;
             break;
    case 1 : glutSolidSphere(1.2,disc,disc) ;
             break;
    case 2 : glNormal3f(0.0F,0.0F,1.0F);
             glBegin(GL_QUADS);
             for ( int i = 0 ; i < disc ; i++ )
               for ( int j = 0 ; j < disc ; j++ ) {
                 glVertex2f(-1.0F+i*2.0F/disc,-1.0F+j*2.0F/disc);
                 glVertex2f(-1.0F+(i+1)*2.0F/disc,-1.0F+j*2.0F/disc);
                 glVertex2f(-1.0F+(i+1)*2.0F/disc,-1.0F+(j+1)*2.0F/disc);
                 glVertex2f(-1.0F+i*2.0F/disc,-1.0F+(j+1)*2.0F/disc); }
             glEnd(); }
  glPopMatrix();
  float pos0[4] = { -1.0F,1.0F,0.0F,0.0F };
  float pos1[4] = { -1.0F,-1.0F,0.0F,0.0F };
  glLightfv(GL_LIGHT0,GL_DIFFUSE,couleurBlanc());
  glLightfv(GL_LIGHT0,GL_AMBIENT,couleurBlanc());
  glLightfv(GL_LIGHT0,GL_SPECULAR,couleurBlanc());
  glLightfv(GL_LIGHT0,GL_POSITION,pos0);
  glLightfv(GL_LIGHT0,GL_SPOT_CUTOFF,spotCutOff180);
  glLightfv(GL_LIGHT1,GL_DIFFUSE,couleurBlanc());
  glLightfv(GL_LIGHT1,GL_AMBIENT,couleurBlanc());
  glLightfv(GL_LIGHT1,GL_SPECULAR,couleurBlanc());
  glLightfv(GL_LIGHT1,GL_POSITION,pos1);
  glLightfv(GL_LIGHT1,GL_SPOT_CUTOFF,spotCutOff180);
  glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,couleurJaune());
  glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,couleurNoir());
  glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,couleurNoir());
  glPushMatrix();
  glTranslatef(position[0],position[1],position[2]);
  glEnable(GL_LIGHT1);
  if ( fabs(position[3]) < 0.0001F ) {
    flecheEnVolume(-position[0],-position[1],-position[2],0.1F,0.4F,0.04F); }
    else {
    glutSolidSphere(0.1F,32,32);
    if ( spotCutOff[0] < 180.0F ) {
      flecheEnVolume(spotDir[0],spotDir[1],spotDir[2],0.1F,0.4F,0.04F); 
      glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,couleurJaune(0.5F));
      coneOuverture(spotDir[0],spotDir[1],spotDir[2],spotCutOff[0]); } }
  glDisable(GL_LIGHT1);
  glPopMatrix();
  glPopMatrix();
  glDisable(GL_LIGHTING);
  glutSwapBuffers();
}

void display2() {
  glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);
  glPushMatrix();
  glColor4fv(couleurBlanc());
  glBegin(GL_LINES);
  glVertex2f(2.0F,0.0F);
  glVertex2f(423.0F,0.0F);
  glEnd();
  glColor4fv(couleurJaune());
  glBegin(GL_LINE_LOOP);
  glVertex2f(2.0F,5.0F+param*20.0F);
  glVertex2f(423.0F,5.0F+param*20.0F);
  glVertex2f(423.0F,25.0F+param*20.0F);
  glVertex2f(2.0F,25.0F+param*20.0F);
  glEnd();
  glColor4fv(couleurRouge());
  glBegin(GL_LINE_LOOP);
  glVertex2f(142.0F+70.0*pparam,6.0F+param*20.0F);
  glVertex2f(206.0F+70.0*pparam,6.0F+param*20.0F);
  glVertex2f(206.0F+70.0*pparam,24.0F+param*20.0F);
  glVertex2f(142.0F+70.0*pparam,24.0F+param*20.0F);
  glEnd();
  glPopMatrix();
  glPushMatrix();
  float pos = 0;
  glColor4fv((param == pos) ? couleurJaune() : couleurBlanc());
  placeFontCursor(5.0F,10.0F+pos*20.0F,0.0F) ;
  simpleBitmapOutput(REGULAR8x13,"SPOT DIR    : %6.2f %6.2f %6.2f",spotDir[0],spotDir[1],spotDir[2]);
  pos = 1;
  glColor4fv((param == pos) ? couleurJaune() : couleurBlanc());
  placeFontCursor(5.0F,10.0F+pos*20.0F,0.0F) ;
  simpleBitmapOutput(REGULAR8x13,"SPOT CUTOFF : %6.2f",spotCutOff[0]) ;
  pos = 2;
  glColor4fv((param == pos) ? couleurJaune() : couleurBlanc());
  placeFontCursor(5.0F,10.0F+pos*20.0F,0.0F) ;
  simpleBitmapOutput(REGULAR8x13,"POSITION    : %6.2f %6.2f %6.2f %6.2f",position[0],position[1],position[2],position[3]);
  pos = 3;
  glColor4fv((param == pos) ? couleurJaune() : couleurBlanc());
  placeFontCursor(5.0F,10.0F+pos*20.0F,0.0F) ;
  simpleBitmapOutput(REGULAR8x13,"SPECULAR    : %6.2f %6.2f %6.2f %6.2f",specular[0],specular[1],specular[2]);
  pos = 4;
  glColor4fv((param == pos) ? couleurJaune() : couleurBlanc());
  placeFontCursor(5.0F,10.0F+pos*20.0F,0.0F) ;
  simpleBitmapOutput(REGULAR8x13,"AMBIENT     : %6.2f %6.2f %6.2f %6.2f",ambiant[0],ambiant[1],ambiant[2]);
  pos = 5;
  glColor4fv((param == pos) ? couleurJaune() : couleurBlanc());
  placeFontCursor(5.0F,10.0F+pos*20.0F,0.0F) ;
  simpleBitmapOutput(REGULAR8x13,"DIFFUSE     : %6.2f %6.2f %6.2f %6.2f",diffuse[0],diffuse[1],diffuse[2]);
  pos = -5.5F;
  glColor4fv(couleurBlanc());
  placeFontCursor(5.0F,10.0F+pos*20.0F,0.0F) ;
  simpleBitmapOutput(REGULAR8x13,"SHININESS   : %6.2f",shininess[0]) ;
  pos = -4.5F;
  placeFontCursor(5.0F,10.0F+pos*20.0F,0.0F) ;
  simpleBitmapOutput(REGULAR8x13,"EMISSION    : %6.2f %6.2f %6.2f %6.2f",tc[cc][0],tc[cc][1],tc[cc][2]) ;
  pos = -3.5F;
  placeFontCursor(5.0F,10.0F+pos*20.0F,0.0F) ;
  simpleBitmapOutput(REGULAR8x13,"SPECULAR    : %6.2f %6.2f %6.2f %6.2f",tc[cc][0],tc[cc][1],tc[cc][2]) ;
  pos = -2.5F;
  placeFontCursor(5.0F,10.0F+pos*20.0F,0.0F) ;
  simpleBitmapOutput(REGULAR8x13,"AMBIENT     : %6.2f %6.2f %6.2f %6.2f",tc[cc][0],tc[cc][1],tc[cc][2]) ;
  pos = -1.5F;
  placeFontCursor(5.0F,10.0F+pos*20.0F,0.0F) ;
  simpleBitmapOutput(REGULAR8x13,"DIFFUSE     : %6.2f %6.2f %6.2f %6.2f",tc[cc][0],tc[cc][1],tc[cc][2]) ;
  glPopMatrix();
  glutSwapBuffers();
}

void augmente(float *v,float dif,float max) {
  *v += dif;
  if ( *v > max )
    *v = max;
}

void diminue(float *v,float dif,float min) {
  *v -= dif;
  if ( *v < min )
    *v = min;
}

void augmenteCoef(float *v) {
  *v += 0.01F;
  if ( *v > 1.0F )
    *v = 1.0F;
}

void diminueCoef(float *v) {
  *v -= 0.01F;
  if ( *v < 0.0F )
    *v = 0.0F;
}

void augmenteCutOff(float *v,float dif) {
  *v += dif;
  if ( *v > 90.0F )
    *v = 180.0F;
}

void diminueCutOff(float *v,float dif) {
  *v -= dif;
  if ( ( *v < 180.0F ) && ( *v > 90.0F ) )
    *v = 90.0F;
  if ( *v < 0.0F )
    *v = 0.0F;
}

void special2(int k,int x,int y) {
  switch (k) {
    case GLUT_KEY_PAGE_DOWN : switch (param) {
                                case 5 :
                                case 4 :
                                case 3 : diminue(&tp[param][pparam],0.1F,0.0F);
                                         break;
                                case 2 : 
                                case 0 : diminue(&tp[param][pparam],0.1F,-100.0F);
                                         break;
                                case 1 : diminueCutOff(&tp[param][pparam],5.0F);
                                         break; }
                              glutPostWindowRedisplay(f2);
                              glutPostWindowRedisplay(f1);
                              break;
    case GLUT_KEY_PAGE_UP   : switch (param) {
                                case 5 :
                                case 4 :
                                case 3 : augmente(&tp[param][pparam],0.1F,1.0F);
                                         break;
                                case 2 : 
                                case 0 : augmente(&tp[param][pparam],0.1F,100.0F);
                                         break;
                                case 1 : augmenteCutOff(&tp[param][pparam],5.0F);
                                         break; }
                              glutPostWindowRedisplay(f2);
                              glutPostWindowRedisplay(f1);
                              break;
    case GLUT_KEY_F1        : affecteLight(diffuse0,ambiant0,specular0,position0,spotCutOff0,spotDir0);
                              aff = 0;
                              setManipulateurClavierAngle(20.0F,30.0F,0.0F);
                              setManipulateurSourisAngle(0.0F,0.0F,0.0F);
                              glutPostWindowRedisplay(f1);
                              glutPostWindowRedisplay(f2);
                              break;
    case GLUT_KEY_F2        : affecteLight(diffuse1,ambiant1,specular1,position1,spotCutOff1,spotDir1);
                              aff = 0;
                              setManipulateurClavierAngle(20.0F,30.0F,0.0F);
                              setManipulateurSourisAngle(0.0F,0.0F,0.0F);
                              glutPostWindowRedisplay(f1);
                              glutPostWindowRedisplay(f2);
                              break;
    case GLUT_KEY_F3        : affecteLight(diffuse2,ambiant2,specular2,position2,spotCutOff2,spotDir2);
                              aff = 0;
                              setManipulateurClavierAngle(20.0F,30.0F,0.0F);
                              setManipulateurSourisAngle(0.0F,0.0F,0.0F);
                              glutPostWindowRedisplay(f1);
                              glutPostWindowRedisplay(f2);
                              break;
    case GLUT_KEY_F4        : affecteLight(diffuse3,ambiant3,specular3,position3,spotCutOff3,spotDir3);
                              aff = 0;
                              setManipulateurClavierAngle(20.0F,30.0F,0.0F);
                              setManipulateurSourisAngle(0.0F,0.0F,0.0F);
                              glutPostWindowRedisplay(f1);
                              glutPostWindowRedisplay(f2);
                              break;
    case GLUT_KEY_F5        : affecteLight(diffuse4,ambiant4,specular4,position4,spotCutOff4,spotDir4);
                              aff = 0;
                              setManipulateurClavierAngle(20.0F,30.0F,0.0F);
                              setManipulateurSourisAngle(0.0F,0.0F,0.0F);
                              glutPostWindowRedisplay(f1);
                              glutPostWindowRedisplay(f2);
                              break;
    case GLUT_KEY_F6        : affecteLight(diffuse5,ambiant5,specular5,position5,spotCutOff5,spotDir5);
                              aff = 0;
                              setManipulateurClavierAngle(20.0F,30.0F,0.0F);
                              setManipulateurSourisAngle(0.0F,0.0F,0.0F);
                              glutPostWindowRedisplay(f1);
                              glutPostWindowRedisplay(f2);
                              break;
    case GLUT_KEY_F7        : affecteLight(diffuse6,ambiant6,specular6,position6,spotCutOff6,spotDir6);
                              aff = 0;
                              setManipulateurClavierAngle(20.0F,30.0F,0.0F);
                              setManipulateurSourisAngle(0.0F,0.0F,0.0F);
                              glutPostWindowRedisplay(f1);
                              glutPostWindowRedisplay(f2);
                              break;
    case GLUT_KEY_UP        : param = (param+1)%6;
                              pparam = pparam%nbparam[param];
                              glutPostWindowRedisplay(f2);
                              break;
    case GLUT_KEY_DOWN      : param = (param+5)%6;
                              pparam = pparam%nbparam[param];
                              glutPostWindowRedisplay(f2);
                              break;
    case GLUT_KEY_RIGHT     : pparam = (pparam+1)%nbparam[param];
                              glutPostWindowRedisplay(f2);
                              break;
    case GLUT_KEY_LEFT      : pparam = (pparam+nbparam[param]-1)%nbparam[param];
                              glutPostWindowRedisplay(f2);
                              break; }
}

void special1(int k,int x,int y) {
  if ( specialManipulateur(k,x,y) )
    glutPostWindowRedisplay(f1);
    else
    special2(k,x,y);
}

void key2(unsigned char key,int x,int y) {
  switch ( key ) {
    case '8'    : special2(GLUT_KEY_UP,x,y);
                  break;
    case '2'    : special2(GLUT_KEY_DOWN,x,y);
                  break;
    case '4'    : special2(GLUT_KEY_LEFT,x,y);
                  break;
    case '6'    : special2(GLUT_KEY_RIGHT,x,y);
                  break;
    case '9'    : special2(GLUT_KEY_PAGE_UP,x,y);
                  break;
    case '3'    : special2(GLUT_KEY_PAGE_DOWN,x,y);
                  break;
    case 43     : switch (param) {
                    case 5 :
                    case 4 :
                    case 3 : augmente(&tp[param][pparam],0.01F,1.0F);
                             break;
                    case 2 : 
                    case 0 : augmente(&tp[param][pparam],0.02F,100.0F);
                             break;
                    case 1 : augmenteCutOff(&tp[param][pparam],0.5F);
                             break; }
                  glutPostWindowRedisplay(f2);
                  glutPostWindowRedisplay(f1);
                  break;
    case 45     : switch (param) {
                    case 5 :
                    case 4 :
                    case 3 : diminue(&tp[param][pparam],0.01F,0.0F);
                             break;
                    case 2 : 
                    case 0 : diminue(&tp[param][pparam],0.02F,-100.0F);
                             break;
                    case 1 : diminueCutOff(&tp[param][pparam],0.5F);
                             break; }
                  glutPostWindowRedisplay(f2);
                  glutPostWindowRedisplay(f1);
                  break;
    case '0'    : switch ( param ) {
                    case 5 : diffuse[0] = diffuse[1] = diffuse[2] = 0.0F;
                             break;
                    case 4 : ambiant[0] = ambiant[1] = ambiant[2] = 0.0F;
                             break;
                    case 3 : specular[0] = specular[1] = specular[2] = 0.0F;
                             break;
                    case 2 : position[0] = 0.4F;
                             position[1] = 0.5F;
                             position[2] = 0.7F;
                             position[3] = 0.0F;
                             break;
                    case 1 : spotCutOff[0] = 0.0F ;
                             break;
                    case 0 : spotDir[0] = 0.0F;
                             spotDir[1] = 0.0F;
                             spotDir[2] = -1.0F;
                             break; }
                  glutPostWindowRedisplay(f2);
                  glutPostWindowRedisplay(f1);
                  break;
    case '1'    : switch ( param ) {
                    case 5 : diffuse[0] = diffuse[1] = diffuse[2] = 1.0F;
                             break;
                    case 4 : ambiant[0] = ambiant[1] = ambiant[2] = 1.0F;
                             break;
                    case 3 : specular[0] = specular[1] = specular[2] = 1.0F;
                             break;
                    case 2 : position[0] = 0.0F;
                             position[1] = 0.0F;
                             position[2] = 2.0F;
                             position[3] = 1.0F;
                             break;
                    case 1 : spotCutOff[0] = 180.0F ;
                             break; }
                  glutPostWindowRedisplay(f2);
                  glutPostWindowRedisplay(f1);
                  break;
    case 'r'    : switch ( param ) {
                    case 5 : augmenteCoef(&diffuse[0]);
                             break;
                    case 4 : augmenteCoef(&ambiant[0]);
                             break;
                    case 3 : augmenteCoef(&specular[0]);
                             break; }
                  glutPostWindowRedisplay(f2);
                  glutPostWindowRedisplay(f1);
                  break;
    case 'R'    : switch ( param ) {
                    case 5 : diminueCoef(&diffuse[0]);
                             break;
                    case 4 : diminueCoef(&ambiant[0]);
                             break;
                    case 3 : diminueCoef(&specular[0]);
                             break; }
                  glutPostWindowRedisplay(f2);
                  glutPostWindowRedisplay(f1);
                  break;
    case 'v'    : switch ( param ) {
                    case 5 : augmenteCoef(&diffuse[1]);
                             break;
                    case 4 : augmenteCoef(&ambiant[1]);
                             break;
                    case 3 : augmenteCoef(&specular[1]);
                             break; }
                  glutPostWindowRedisplay(f2);
                  glutPostWindowRedisplay(f1);
                  break;
    case 'V'    : switch ( param ) {
                    case 5 : diminueCoef(&diffuse[1]);
                             break;
                    case 4 : diminueCoef(&ambiant[1]);
                             break;
                    case 3 : diminueCoef(&specular[1]);
                             break; }
                  glutPostWindowRedisplay(f2);
                  glutPostWindowRedisplay(f1);
                  break;
    case 'b'    : switch ( param ) {
                    case 5 : augmenteCoef(&diffuse[2]);
                             break;
                    case 4 : augmenteCoef(&ambiant[2]);
                             break;
                    case 3 : augmenteCoef(&specular[2]);
                             break; }
                  glutPostWindowRedisplay(f2);
                  glutPostWindowRedisplay(f1);
                  break;
    case 'B'    : switch ( param ) {
                    case 5 : diminueCoef(&diffuse[2]);
                             break;
                    case 4 : diminueCoef(&ambiant[2]);
                             break;
                    case 3 : diminueCoef(&specular[2]);
                             break; }
                  glutPostWindowRedisplay(f2);
                  glutPostWindowRedisplay(f1);
                  break;
    case 's'    : shininess[0] += 0.1F;
                  if ( shininess[0] > 128.0F )
                    shininess[0] = 128.0F;
                  glutPostWindowRedisplay(f2);
                  glutPostWindowRedisplay(f1);
                  break;
    case 'S'    : shininess[0] -= 0.1F;
                  if ( shininess[0] < 0.0F )
                    shininess[0] = 0.0F;
                  glutPostWindowRedisplay(f2);
                  glutPostWindowRedisplay(f1);
                  break;
    case 'd'    : disc += 5;
                  glutPostWindowRedisplay(f1);
                  break;
    case 'D'    : disc -= 5;
                  if ( disc < 5 )
                    disc = 5;
                  glutPostWindowRedisplay(f1);
                  break;
    case ' '    : cc = (cc+1)%7;
                  glutPostWindowRedisplay(f1);
                  glutPostWindowRedisplay(f2);
                  break;
    case 0x0D   : aff = (aff+1)%3;
                  glutPostWindowRedisplay(f1);
                  break;
    case 0x1B   : exit(0);
                  break; }
}

void key1(unsigned char ky,int x,int y) {
  if ( keyManipulateur(ky,x,y) )
    glutPostWindowRedisplay(f1);
    else
    key2(ky,x,y);
}

void reshape2(int w,int h) {
  glViewport(0,0,w,h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0,w,130-h,130,-1.0,1.0); 
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void myinit(void) {
  glEnable(GL_AUTO_NORMAL);
  glEnable(GL_NORMALIZE);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_LIGHT0);
  glEnable(GL_ALPHA_TEST);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
  glLightModelfv(GL_LIGHT_MODEL_AMBIENT,couleurNoir());
  setManipulateurClavierAngle(20.0F,30.0F,0.0F);
}

int main(int argc,char **argv) {
  glutInit(&argc,argv);
  init();
  glutInitWindowSize(200,200);
  glutInitWindowPosition(30,50);
  glutInitDisplayMode(GLUT_RGBA|GLUT_DEPTH|GLUT_DOUBLE);
  f1 = glutCreateWindow("Les lumieres");
  myinit();
  creationMenuBasique();
  setParametresOrthoBasique(-1.5,1.5,-1.5,1.5,-500.0,500.0);
  setManipulateurDistance(1.0F);
  glutReshapeFunc(reshapeOrthoBasique);
  glutDisplayFunc(display1);
  glutKeyboardFunc(key1);
  glutSpecialFunc(special1);
  glutMotionFunc(motionBasique);
  glutMouseFunc(sourisBasique);
  glutInitWindowSize(425,240);
  glutInitWindowPosition(40,290);
  glutInitDisplayMode(GLUT_RGBA|GLUT_DEPTH|GLUT_DOUBLE);
  f2 = glutCreateWindow("Valeurs lumiere");
  myinit();
  creationMenuBasique();
  glutDisplayFunc(display2);
  glutReshapeFunc(reshape2);
  glutKeyboardFunc(key2);
  glutSpecialFunc(special2);
  glutMainLoop();
  return(0);
}


#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "../modulesutilitaires/ModuleManipulateur.h"
#include "../modulesutilitaires/ModuleMenus.h"
#include "../modulesutilitaires/ModuleReshape.h"

#define LI 25 
#define LH 25 
GLubyte image[LI][LH][3]; 
 
 /* création des carreaux blancs et noirs */ 
void makeImage(void) { 
  int i,j,c; 
  for( i = 0 ; i < LI ; i++ ) { 
    for( j = 0 ; j < LH ; j++ ) { 
      c =(((i&0x8)==0)^((j&0x8)==0))*255; 
      image[i][j][0] =(GLubyte) c; 
      image[i][j][1] =(GLubyte) c; 
      image[i][j][2] =(GLubyte) c; } } 
} 
  
void myinit(void) { 
  glClearColor(0.0,0.0,0.0,0.0); 
  glEnable(GL_DEPTH_TEST); 
  /* spécifie la valeur utilisée pour la comparaison du buffer de profondeur */ 
  
  /* remplace si la future valeur de la profondeur est inférieure à la valeur stockée  */
  glDepthFunc(GL_LESS); 
  /* appel de la fonction de creation du pavage noir et blanc */
  makeImage(); 
  /* memorisation des pixels de la texture */
  glPixelStorei(GL_UNPACK_ALIGNMENT,1); 
  /* definition de la correspondance entre les pixels textures et pixels image */
  glTexImage2D(GL_TEXTURE_2D,0,3,LI,LH,0,GL_RGB,GL_UNSIGNED_BYTE,&image[0][0][0]); 
  /* instruction de gestion de la texture à l'horizontal et à la vertical */
  glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP); 
  glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP); 
  /* interpolation éventuelle des couleurs de la texture */
  glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST); 
  glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST); 
  glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL); 
  glEnable(GL_TEXTURE_2D); 
  glShadeModel(GL_FLAT); 
  glEnable(GL_AUTO_NORMAL);
  glEnable(GL_NORMALIZE);
} 
  
void display(void) { 
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); 
  glPushMatrix();
  manipulateurSouris();
  manipulateurClavier();
  /*debut de définition de placage de texture */
  glBegin(GL_QUADS); 
  /* coordonnées du premier carré */
  /* association du point de la texture avec le point de la face */
  glTexCoord2f(0.0F,0.0F); /* point de la texture bas gauche */
  glVertex3f(-2.0F,-1.0F,0.0F); 
  /* association du point de la texture avec le point de la face */
  glTexCoord2f(0.0F,1.0F); /* point de la texture haut gauche */
  glVertex3f(-2.0F,1.0F,0.0F); 
 /* association du point de la texture avec le point de la face */
  glTexCoord2f(1.0F,1.0F); /* point d ela texture haut droit */
  glVertex3f(0.0F,1.0F,0.0F); 
 /* association du point de la texture avec le point de la face */
  glTexCoord2f(1.0F,0.0F); /* point de la texture bas droit */
  glVertex3f(0.0F,-1.0F,0.0F);
  /* coordonnées du second carré */ 
  glTexCoord2f(0.0F,0.0F); 
  glVertex3f(1.0F,-1.0F,0.0F); 
  glTexCoord2f(0.0F,1.0F); 
  glVertex3f(1.0F,1.0F,0.0F); 
  glTexCoord2f(1.0F,1.0F); 
  glVertex3f(2.41421F,1.0F,-1.41421F); 
  glTexCoord2f(1.0F,0.0F); 
  glVertex3f(2.41421F,-1.0F,-1.41421F); 
  /* fin de placage de la texture */
  glEnd(); 
  glPopMatrix();
  glFlush(); 
  glutSwapBuffers();
} 
  
int main(int argc,char **argv) {
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_RGBA|GLUT_DEPTH|GLUT_DOUBLE);
  glutInitWindowSize(300,200); 
  glutInitWindowPosition(50,50); 
  glutCreateWindow("Les échiquiers"); 
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



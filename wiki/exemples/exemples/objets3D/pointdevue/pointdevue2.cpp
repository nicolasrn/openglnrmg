

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>


#include <stdio.h>
#include <stdlib.h>

#include "../../modulesutilitaires/ModuleCouleurs.h"
#include "../../modulesutilitaires/ModuleManipulateur.h"
#include "../../modulesutilitaires/ModuleMenus.h"
#include "../../modulesutilitaires/ModuleReshape.h"


static float angle = 0.0F ;
static float alpha = 0.5F ;
static int fenetre;





void myinit(void) {
  glClearColor(0.5F,0.5F,0.5F,1.0F);
  GLfloat light_position0[] = { 1.0F,1.0F,1.0F,0.0F };
  glLightfv(GL_LIGHT0,GL_AMBIENT,couleurNoir());
  glLightfv(GL_LIGHT0,GL_DIFFUSE,couleurBlanc());
  glLightfv(GL_LIGHT0,GL_SPECULAR,couleurBlanc());
  glLightfv(GL_LIGHT0,GL_POSITION,light_position0);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_AUTO_NORMAL);
  glEnable(GL_NORMALIZE);
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);
  glEnable(GL_CULL_FACE);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
}
void display(void) {   
     GLfloat no_mat[]= {0.0,0.0,0.0,1.0};
     GLfloat mat_ambient[]= {0.7,0.7,0.7,1.0};
     GLfloat mat_ambient_color[]= {0.8,0.8,0.2,0.5};
     GLfloat mat_diffuse[]= {1.0,0.5,0.8,1.0};
     GLfloat mat_specular[]= {1.0,1.0,1.0,1.0};     
     GLfloat no_shininess[]= {0.0};
     GLfloat low_shininess[]= {5.0};
     GLfloat hight_shininess[]= {100.0};
     GLfloat mat_demission[]= {0.3,0.2,0.2,0.0};
          

  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glPushMatrix();
      manipulateurSouris();
      manipulateurClavier();
      glRotatef(angle,0.0F,1.0F,0.0F);
      glPushMatrix();
          glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,couleurRouge(alpha)) ;
          glTranslatef(4.0F,0.0F,0.0F);
          glutSolidSphere(4.5,50,50);
        glPopMatrix();
        
        glPushMatrix();
          glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,mat_ambient_color) ;
          glTranslatef(-5.0F,0.0F,0.0F);
          glutSolidSphere(4.5,50,50);
      glPopMatrix();
  glPopMatrix();
  glFlush();
  glutSwapBuffers() ;
}

void idle(void) {
  angle += 0.05F;
  glutPostRedisplay();
}

void key(unsigned char key,int x,int y) {
  static int anim = 1;
  if ( keyManipulateur(key,x,y) )
    glutPostRedisplay();
    else
    switch ( key ) {
      case ' '  : anim = !anim;
                  glutIdleFunc((anim) ? idle : NULL);
                  break;
      case '-'   : alpha -= 0.05F;
                  if ( alpha < 0.0F )
                    alpha = 0.0F;
                  glutPostRedisplay();
                  break;
      case '+'   : alpha += 0.05F;
                  if ( alpha > 1.0F )
                    alpha = 1.0F;
                  glutPostRedisplay();
                  break; }
}

int main(int argc,char **argv) {
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_RGBA|GLUT_DEPTH|GLUT_DOUBLE);
  glutInitWindowSize(240,150); 
  glutInitWindowPosition(50,50); 
  fenetre = glutCreateWindow("Le blending"); 
  myinit();
  creationMenuBasique();
  setParametresOrthoBasique(-6.0,6.0,-6.0,6.0,-50.0,50.0);
  setManipulateurDistance(1.0F);
  glutReshapeFunc(reshapeOrthoBasique);
  glutIdleFunc(idle);
  glutKeyboardFunc(key);
  glutSpecialFunc(specialBasique);
  glutMotionFunc(motionBasique);
  glutMouseFunc(sourisBasique);
  glutDisplayFunc(display);
  glutMainLoop();
  return(0);
}




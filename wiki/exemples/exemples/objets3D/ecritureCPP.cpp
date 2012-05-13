
#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>

/* Le fichier d'en-tête stdarg.h déclare un type va_list */
/* et définit trois macros permettant de parcourir  */
/* la liste d'arguments dont le nombre et les types */
/* ne sont pas connus par la fonction appelée.      */

/* affichage d'un string */
void bitmap_output(int x,int y,char *string,void *font) {
  int len,i;
  glRasterPos2f(x,y);
  len = (int) strlen(string);
  for (i = 0; i < len; i++) {
    glutBitmapCharacter(font,string[i]); }
}

/*affichage caractère par caractère */
void stroke_output(GLfloat x,GLfloat y,char *format,...) {
  va_list args;
  char buffer[200],*p;
  /* initialisation de la liste */
  va_start(args,format);
  /* produit une sortie en accord avec le format */
  vsprintf(buffer,format,args);
  va_end(args);
  glPushMatrix();
  glTranslatef(x,y,0);
  glScalef(0.005F,0.005F,0.005F);
  /* boucle pour afficher tous les caractères */
  for ( p = buffer ; *p ; p++ )
    /* affichage d'un caractère */
    glutStrokeCharacter(GLUT_STROKE_ROMAN,*p);
  glPopMatrix();
}

void display(void) {
     /* reprend la couleur de glclearcolor */
  glClear(GL_COLOR_BUFFER_BIT);
  /* X,Y, chaine et fonte */
  /* On affiche le texte directement */
  bitmap_output(10,35,"Master IHM ecrit avec une fonte bitmap GLUt.",GLUT_BITMAP_TIMES_ROMAN_24);
  bitmap_output(100,400,"Du texte en taille 9 par 15.",GLUT_BITMAP_9_BY_15);
  bitmap_output(120,420,"Une autre police : Helvetica.",GLUT_BITMAP_HELVETICA_18);
  glMatrixMode(GL_PROJECTION);
  
  /* avec un petit effet d'orientation */
  glPushMatrix();
  glLoadIdentity();
  /* perspective de projection du texte */
  gluPerspective(50.0,1.0,0.1,20.0);
  glMatrixMode(GL_MODELVIEW);
  
  glPushMatrix();
  /* definition de l'observateur */
  gluLookAt(0.0,0.0,4.0,0.0,0.0,0.0,0.0,1.0,0.);
     glPushMatrix();
     /* on recadre le texte */
     glTranslatef(-1,0,-8);
     /* on le tourne */
     glRotatef(70,-1,0,0);
     /* X,Y, chaine, */
     stroke_output(-3.0F,0.5F,"Le generique de stars war");
     stroke_output(-1.7F,-0.5F,"Pour le plaisir.");
     glPopMatrix();
     
      glMatrixMode(GL_MODELVIEW);
      glPopMatrix();
      glMatrixMode(GL_PROJECTION);
       glPopMatrix();
  glMatrixMode(GL_MODELVIEW);
  glFlush();
  glutSwapBuffers();
}

void reshape(int w,int h) {
     /* definit la taille de la fenêtre d'affichage */
     /* dans laquelle l'image sera affichée         */
  glViewport(0,0,w,h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0,w,0,h);
  /* réduction de la taille */
  glScalef(1,-1,1);
  /* décalage de l'ecriture */
  glTranslatef(0,-h,0);
  glMatrixMode(GL_MODELVIEW);
}

int main(void) {
  glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
  glutInitWindowSize(500,500);
  glutCreateWindow("Polices de caractères en GLUt");
  glClearColor(1.0,1.0,1.0,1.0);
  glColor3f(0,0,0);
  /* largeur du trait pour l'écriture */
  glLineWidth(2.0);
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutMainLoop();
  return(0);
}



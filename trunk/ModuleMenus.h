#ifndef MODULE_MENUS
#define MODULE_MENUS

#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

static float *couleurCylindre = NULL;
static float *couleurAvant = NULL;
static float *couleurOptique = NULL;
static float *couleurPhare = NULL;
static float *couleurGdPhare = NULL;
static float *couleurGdPhare2 = NULL;
static float *couleurToit = NULL;
static float *couleurCadre = NULL;
static float *couleurMur = NULL;
static float *couleurFlanRoue = NULL;
static float *couleurRoueInterieur = NULL;
static float *couleurRoueExterieur = NULL;
static float *couleurAxe = NULL;
static float *couleurGrille = NULL;
static float *couleurSol = NULL;
static float *couleurCloche1 = NULL;
static float *couleurCloche2 = NULL;
static float *couleurClocheAccroche = NULL;
static float *couleurClocheBaton = NULL;
static float *couleurChemine = NULL;

static float couleurCourseCylindre[] = {1, .035, .12, 1};
static float couleurCourseAvant[] = {.85, .09, .007, 1};
static float couleurCourseOptique[] = {.3, 0.14, 0.117, 1};
static float couleurCoursePhare[] = {1, 1, .41, 1};
static float couleurCourseGdPhare[] = {.756, .749, .694, 1};
static float couleurCourseGdPhare2[] = {.07, .054, .039, 1};
static float couleurCourseToit[] = {1, .035, .12, 1};
static float couleurCourseCadre[] = {.756, .749, .694, 1};
static float couleurCourseMur[] = {.85, .09, .007, 1};
static float couleurCourseFlanRoue[] = {1, 1, 1, 1};
static float couleurCourseRoueInterieur[] = {0, 0, 0, 1};
static float couleurCourseRoueExterieur[] = {1, 0, 0, 1};
static float couleurCourseAxe[] = {1, .84, 0, 1};
static float couleurCourseGrille[] = {.85, .09, .007, 1};
static float couleurCourseSol[] = {.756, .749, .694, 1};
static float couleurCourseCloche1[] = {.8, .8, .8, 1};
static float couleurCourseCloche2[] = {.47, .5, .5, 1};
static float couleurCourseClocheAccroche[] =  {1, .84, 0, 1};
static float couleurCourseClocheBaton[] = {1, .84, 0, 1};
static float couleurCourseChemine[] = {.756, .749, .694, 1};

static float couleurFilleCylindre[] = {0, 0, 0, 1};
static float couleurFilleAvant[] = {0, 0, 0, 1};
static float couleurFilleOptique[] = {0, 0, 0, 1};
static float couleurFillePhare[] = {0, 0, 0, 1};
static float couleurFilleGdPhare[] = {0, 0, 0, 1};
static float couleurFilleGdPhare2[] = {0, 0, 0, 1};
static float couleurFilleToit[] = {0, 0, 0, 1};
static float couleurFilleCadre[] = {0, 0, 0, 1};
static float couleurFilleMur[] = {0, 0, 0, 1};
static float couleurFilleFlanRoue[] = {0, 0, 0, 1};
static float couleurFilleRoueInterieur[] = {0, 0, 0, 1};
static float couleurFilleRoueExterieur[] = {1, 0, 0, 1};
static float couleurFilleAxe[] = {0, 0, 0, 1};
static float couleurFilleGrille[] = {0, 0, 0, 1};
static float couleurFilleSol[] = {0, 0, 0, 1};
static float couleurFilleCloche1[] = {0, 0, 0, 1};
static float couleurFilleCloche2[] = {0, 0, 0, 1};
static float couleurFilleClocheAccroche[] =  {0, 0, 0, 1};
static float couleurFilleClocheBaton[] = {0, 0, 0, 1};
static float couleurFilleChemine[] = {0, 0, 0, 1};

void creationMenuBasique(void);

static  void select(int selection);

static void selectCouleur(int selection);

static void themeCourse();

static void themeFille();

#endif

#ifndef MODULE_MENUS
    #define MODULE_MENUS
    
    #include <stdio.h>
    #include <stdlib.h>
    #include <GL/gl.h>
    #include <GL/glu.h>
    #include <GL/glut.h>
    
    extern float *couleurCylindre;
    extern float *couleurAvant;
    extern float *couleurOptique;
    extern float *couleurPhare;
    extern float *couleurGdPhare;
    extern float *couleurGdPhare2;
    extern float *couleurToit;
    extern float *couleurCadre;
    extern float *couleurMur;
    extern float *couleurFlanRoue;
    extern float *couleurRoueInterieur;
    extern float *couleurRoueExterieur;
    extern float *couleurAxe;
    extern float *couleurGrille;
    extern float *couleurSol;
    extern float *couleurCloche1;
    extern float *couleurCloche2;
    extern float *couleurClocheAccroche;
    extern float *couleurClocheBaton;
    extern float *couleurChemine;
    
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
    
    void select(int selection);
    
    void selectCouleur(int selection);
    
    void themeCourse();
    
    void themeFille();
    
    typedef float pixel[4];

#endif

#ifndef MODULE_MENUS
    #define MODULE_MENUS
    
    #include <iostream>
    #include <GL/gl.h>
    #include <GL/glu.h>
    #include <GL/glut.h>
    #include "MonModuleCamera.h"
    #include "MonModuleSouris.h"
    
    #define debug_menu 1
    
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
    extern float *couleurSoupape1;
    extern float *couleurSoupape2;
    extern float *couleurWagon1;
    extern float *couleurWagon2;
    
    
    extern float anglex;
    extern float angley;
    extern float anglez;    
    
    //pour la manip souris
    extern void (*doActionSourisRotation)();
    extern void (*doActionClavierRotation)(int);
    
    static float couleurCourseCylindre[] = {1, .035, .12, 1};
    static float couleurCourseAvant[] = {.85, .09, .007, 1};
    static float couleurCourseOptique[] = {.3, 0.14, 0.117, 1};
    static float couleurCoursePhare[] = {1, 1, .41, 0.01};
    static float couleurCourseGdPhare[] = {.756, .749, .694, 1};
    static float couleurCourseGdPhare2[] = {.07, .054, .039, 1};
    static float couleurCourseToit[] = {.756, .749, .694, 1};
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
    static float couleurCourseSoupape1[] = {.8, .8, .8, 1};
    static float couleurCourseSoupape2[] = {.47, .5, .5, 1};
    static float couleurCourseWagon1[] = {.8, .8, .8, 1};
    static float couleurCourseWagon2[] = {.85, .09, .007, 1};
    
    static float couleurFilleCylindre[] = {0.776, 0.031, 0, 1};
    static float couleurFilleAvant[] = {0.78, 0.172, 0.282, 1};
    static float couleurFilleOptique[] = {0.6, 0.478, 0.553, 1};
    static float couleurFillePhare[] = {0.996, 0.89, 0.278, 1};
    static float couleurFilleGdPhare[] = {0.996, 0.89, 0.278, 1};
    static float couleurFilleGdPhare2[] = {0.913, 0.219, 0.247, 1};
    static float couleurFilleToit[] = {1, 0.286, 0.004, 1};
    static float couleurFilleCadre[] = {0.988, 0.823, 0.109, 1};
    static float couleurFilleMur[] = {0.78, 0.172, 0.282, 1} ;
    static float couleurFilleFlanRoue[] = {0.996, 0.588, 0.627, 1};
    static float couleurFilleRoueInterieur[] = {0.956, 0.4, 0.105, 1};
    static float couleurFilleRoueExterieur[] = {0.87, 1, 0.419, 1};
    static float couleurFilleAxe[] = {1, 1, 0.419, 1};
    static float couleurFilleGrille[] = {0.972, 0.556, 0.333, 1};
    static float couleurFilleSol[] ={0.988, 0.823, 0.109, 1};
    static float couleurFilleCloche1[] = {0.972, 0.556, 0.333, 1};
    static float couleurFilleCloche2[] = {0.878, 0.066, 0.372, 1};
    static float couleurFilleClocheAccroche[] =  {1, 0, 0.498, 1};
    static float couleurFilleClocheBaton[] = {0.768, 0.411, 0.56, 1};
    static float couleurFilleChemine[] = {0.988, 0.823, 0.109, 1};
    static float couleurFilleSoupape1[] = {0.631, 0.023, 0.517, 1};
    static float couleurFilleSoupape2[] = {0.972, 0.556, 0.333, 1};
    static float couleurFilleWagon1[] = {0.533, 0.301, 0.654, 1};
    static float couleurFilleWagon2[] = {0.741, 0.2, 0.643, 1};
    
    static float couleurGarconCylindre[] = {0.149, 0.768, 0.925, 1};
    static float couleurGarconAvant[] = {0.502, 0.816, 0.816, 1};
    static float couleurGarconOptique[] = {0.023, 0.466, 0.564, 1};
    static float couleurGarconPhare[] = {0.874, 0.949, 1, 1};
    static float couleurGarconGdPhare[] = {0.498, 0.866, 0.298, 1};
    static float couleurGarconGdPhare2[] = {0.003, 0.843, 0.345, 1};
    static float couleurGarconToit[] = {0.529, 0.913, 0.564, 1};
    static float couleurGarconCadre[] = {0.619, 0.992, 0.219, 1};
    static float couleurGarconMur[] = {0.003, 0.474, 0.435, 1};
    static float couleurGarconFlanRoue[] = {0, 1, 0.498, 1};
    static float couleurGarconRoueInterieur[] = {0.745, 0.96, 0.454, 1};
    static float couleurGarconRoueExterieur[] = {0.015, 0.545, 0.604, 1};
    static float couleurGarconAxe[] = {0.588,0.513, 0.925, 1};
    static float couleurGarconGrille[] = {0, 0.2, 0.4, 1};
    static float couleurGarconSol[] = {0.258, 0356, 0.541, 1};
    static float couleurGarconCloche1[] = {0.474, 0.972, 0.972, 1};
    static float couleurGarconCloche2[] = {0.407, 0.435, 0.549, 1};
    static float couleurGarconClocheAccroche[] =  {0.141, 0.266, 0.36, 1};
    static float couleurGarconClocheBaton[] = {0.4, 0, 1, 1};
    static float couleurGarconChemine[] = {0.09, 0.478, 0.717, 1};
    static float couleurGarconSoupape1[] = {0, 1, 1, 1};
    static float couleurGarconSoupape2[] = {0.082, 0.376, 0.741, 1};
    static float couleurGarconWagon1[] = {0.227, 0.556, 0.729, 1};
    static float couleurGarconWagon2[] = {0.329, 0.976, 0.552, 1};
    
	//ton couleur bois - marron 
    static float couleurVieuxCylindre[] = {0.74, 0.56, 0.56, 1};//bois de rose
    static float couleurVieuxAvant[] = {0.87, 0.596, 0.361, 1};//ocre rouge
    static float couleurVieuxOptique[] = {0.74, 0.56, 0.56, 1};//bois de rose
    static float couleurVieuxPhare[] = {0.87, 0.596, 0.361, 1};//ocre rouge
    static float couleurVieuxGdPhare[] = {0.53, 0.259, 0.114, 1};//accajou
    static float couleurVieuxGdPhare2[] = {0.87, 0.72, 0.53, 1};//bois dur
    static float couleurVieuxToit[] = {0.87, 0.596, 0.361, 1};//ocre rouge
    static float couleurVieuxCadre[] = {0.53, 0.259, 0.114, 1};//accajou
    static float couleurVieuxMur[] = {0.87, 0.72, 0.53, 1};//bois dur
    static float couleurVieuxFlanRoue[] = {0.87, 0.72, 0.53, 1};//bois dur
    static float couleurVieuxRoueInterieur[] = {0.53, 0.259, 0.114, 1};//accajou
    static float couleurVieuxRoueExterieur[] = {0.87, 0.596, 0.361, 1};//ocre rouge
    static float couleurVieuxAxe[] = {0.74, 0.56, 0.56, 1};//bois de rose
    static float couleurVieuxGrille[] = {0.87, 0.72, 0.53, 1};//bois dur
    static float couleurVieuxSol[] = {0.87, 0.72, 0.53, 1};//bois dur
    static float couleurVieuxCloche1[] = {0.74, 0.56, 0.56, 1};//bois de rose
    static float couleurVieuxCloche2[] = {0.87, 0.596, 0.361, 1};//ocre rouge
    static float couleurVieuxClocheAccroche[] =  {0.53, 0.259, 0.114, 1};//accajou
    static float couleurVieuxClocheBaton[] = {0.87, 0.72, 0.53, 1};//bois dur
    static float couleurVieuxChemine[] = {0.87, 0.72, 0.53, 1};//bois dur
    static float couleurVieuxSoupape1[] = {0.87, 0.596, 0.361, 1};//ocre rouge
    static float couleurVieuxSoupape2[] = {0.74, 0.56, 0.56, 1};//bois de rose
    static float couleurVieuxWagon1[] = {0.87, 0.72, 0.53, 1};//bois dur
    static float couleurVieuxWagon2[] = {0.53, 0.259, 0.114, 1};//accajou
    
    void creationMenuBasique(void);
    
    void select(int selection);
    
    void selectCouleur(int selection);
        
        void themeCourse();
        
        void themeFille();
        
        void themeGarcon();
        
        void themeVieux();
        
        extern void (*effetComplexOr) ();
        void effetOr();
        void effetPlastique();
        
        extern void (*effetComplexChrome) ();
        void effetChrome();
        
        extern void (*effetComplexArgent) ();
        void effetArgent();
    
    void selectTrajectoire(int selection);
        
        void activerTrajectoireLibre();
        
        void activerTrajectoireCabine(int i);
        
    void selectLumiere(int selection);
        
        void activerDesactiverPhare();
        
        void activerDesactiverSoleil();
    
    void doActionClavier(int key);

#endif

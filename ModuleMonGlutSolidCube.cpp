#include "ModuleMonGlutSolidCube.h"

using namespace std;

void Normal(int i, int j)
{
    static GLfloat n[6][3] =
    {
        {-1.0, 0.0, 0.0},
        {0.0, 1.0, 0.0},
        {1.0, 0.0, 0.0},
        {0.0, -1.0, 0.0},
        {0.0, 0.0, 1.0},
        {0.0, 0.0, -1.0}
    };
    
    glNormal3fv(&n[i][j]); 
}

void NormalSol(int i, int j)
{
    glNormal3f(0.0, 0.0, -1.0);
}

void NormalSolPos(int i, int j)
{
    glNormal3f(0, 0, 1);
    //glNormal3f(-monCosinus[angleTrain], 0, monSinus[angleTrain]);
}

void NormalSolNeg(int i, int j)
{
    glNormal3f(0, 0, -1);
    //glNormal3f(monCosinus[angleTrain], 0, -monSinus[angleTrain]);
}

void NormalOuest(int i, int j)
{
    glNormal3f(0, -1, 0);
}

void NormalEst(int i, int j)
{
    glNormal3f(0, 1, 0);
}

void NormalNord(int i, int j)
{
    glNormal3f(1, 0, 0);
}

void NormalSud(int i, int j)
{
    glNormal3f(-1, 0, 0);
}

void loadJpegImage(char *fichier, GLuint *numtex)
{
    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;
    FILE *file;
    unsigned char *ligne;
    unsigned char *image;
    
    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);
    if ((file=fopen(fichier,"rb" ))==NULL)
    {
        fprintf(stderr,"Erreur : impossible d'ouvrir le fichier %s\n", fichier );
        system("PAUSE" );
        exit(1);
    }
    jpeg_stdio_src(&cinfo, file);
    jpeg_read_header(&cinfo, TRUE);
    image= new unsigned char [cinfo.image_width*cinfo.image_height*3];
    if (cinfo.jpeg_color_space==JCS_GRAYSCALE) 
    {
        fprintf(stdout,"Erreur : l'image doit etre de type RGB\n" );
        system("PAUSE" );
        exit(1);
    }
    
    jpeg_start_decompress(&cinfo);
    ligne=image;
    while (cinfo.output_scanline<cinfo.output_height)
    {
        ligne=image+3*cinfo.image_height*cinfo.output_scanline;
        jpeg_read_scanlines(&cinfo,&ligne,1);
    }
    jpeg_finish_decompress(&cinfo);
    jpeg_destroy_decompress(&cinfo);
    /* Paramétrage de la texture */
    //glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glGenTextures(1, &(*numtex));
    glBindTexture(GL_TEXTURE_2D, *numtex);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,cinfo.image_width,cinfo.image_height,0,GL_RGB,GL_UNSIGNED_BYTE,image);
    
    delete [] image;
}

static void drawBox(GLfloat size, GLenum type, double xTexture, double yTexture, void (*normalf)(int, int))
{
    static GLint faces[6][4] =
    {
        {0, 1, 2, 3},
        {3, 2, 6, 7},
        {7, 6, 5, 4},
        {4, 5, 1, 0},
        {5, 6, 2, 1},
        {7, 4, 0, 3}
    };
    GLfloat v[8][3];
    GLint i;
    
    v[0][0] = v[1][0] = v[2][0] = v[3][0] = -size / 2;
    v[4][0] = v[5][0] = v[6][0] = v[7][0] = size / 2;
    v[0][1] = v[1][1] = v[4][1] = v[5][1] = -size / 2;
    v[2][1] = v[3][1] = v[6][1] = v[7][1] = size / 2;
    v[0][2] = v[3][2] = v[4][2] = v[7][2] = -size / 2;
    v[1][2] = v[2][2] = v[5][2] = v[6][2] = size / 2;
    
    for (i = 5; i >= 0; i--) 
    {
        glBegin(type);
                                                normalf(i, 0);
            
            glTexCoord2f(0, 0);                 glVertex3fv(&v[faces[i][0]][0]); 
            
            glTexCoord2f(xTexture, 0);          glVertex3fv(&v[faces[i][1]][0]); 
            
            glTexCoord2f(xTexture, yTexture);   glVertex3fv(&v[faces[i][2]][0]); 
            
            glTexCoord2f(0, yTexture);          glVertex3fv(&v[faces[i][3]][0]); 
        glEnd();
    }
}

void monGlutSolidCube(GLdouble size, double xTexture, double yTexture, void (*normalf)(int, int)) 
{
    drawBox(size, GL_QUADS, xTexture, yTexture, normalf);
}

void monGlutSolidCube(GLdouble size, double xTexture, void (*normalf)(int, int))
{
    drawBox(size, GL_QUADS, xTexture, xTexture, normalf);
}

void creerSol(GLint size)
{
    glNormal3i(0, 0, 1); //Définit la normale commune à tous les sommets
    double pas = 5;
    for (double i = -size/2; i < size/2; i += pas)
    {	
        glBegin(GL_QUAD_STRIP);
            //cout << "(" << i << ", -1)" << endl;
            glVertex2f(i,-pas);
            //cout << "(" << i+1 << ", -1)" << endl;
            glVertex2f(i+pas,-pas);
            for (double j = -size/2; j < size/2; j += pas)
            {	
                //cout << "(" << i << ", " << j+1 << ")" << endl;
                glVertex2f(i,j+pas); 
                //cout << "(" << i+1 << ", " << j+1 << ")" << endl;
                glVertex2f(i+pas,j+pas);
            }	
        glEnd();
    }	
}

void creerPlan(GLdouble size, void (*fct)(int, int))
{
    double taille = size/2;
    //fct(0, 0);
    glBegin(GL_QUADS);
        glTexCoord2f(-1, 1);glVertex2f(-taille, taille);
        glTexCoord2f(1, 1);glVertex2f(taille, taille);	
        glTexCoord2f(1, -1);glVertex2f(taille, -taille);
        glTexCoord2f(-1, -1);glVertex2f(-taille, -taille);
    glEnd();
}

void creerWall(GLdouble size, int rx, int ry, void (*fct)(int, int))
{
    for(double i = -rx; i <= rx; i++)
    {
        for(double j = -ry; j <= ry; j++)
        {
            glPushMatrix();
            glTranslatef(i*size, j*size, 0);
            //creerPlan(size, fct);
            monGlutSolidCube(size, 1, fct);
            //attention selon que l'on se trouve dans la partie z > 0 => 1 sinon -1 
            glPopMatrix();
        }
    }
}

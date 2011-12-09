#include "ModuleMonGlutSolidCube.h"

static void loadJpegImage(char *fichier, GLuint numtex)
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
    glGenTextures(1, &numtex);
    glBindTexture(GL_TEXTURE_2D,numtex);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,cinfo.image_width,cinfo.image_height,0,GL_RGB,GL_UNSIGNED_BYTE,image);
    
    delete [] image;
}

static void drawBox(GLfloat size, GLenum type, char* filename)
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
    
    loadJpegImage(filename, idTextureHerbe);
    
    for (i = 5; i >= 0; i--) 
    {
        glBegin(type);
        glNormal3fv(&n[i][0]);
        glTexCoord2i(0,0); glVertex3fv(&v[faces[i][0]][0]); 
        glTexCoord2i(1,0); glVertex3fv(&v[faces[i][1]][0]); 
        glTexCoord2i(1,1); glVertex3fv(&v[faces[i][2]][0]); 
        glTexCoord2i(0,1); glVertex3fv(&v[faces[i][3]][0]); 
        glEnd();
    }
}

void monGlutSolidCube(GLdouble size, char* filename) 
{
    drawBox(size, GL_QUADS, filename);
}

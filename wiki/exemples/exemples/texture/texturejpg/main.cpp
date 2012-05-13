    #include <iostream>
    #include <cstdlib>
    #include <windows.h>
    #include <GL/glut.h>
    
    #include <jpeglib.h>
    #include <jerror.h>
    #define MAX_PARTICLES 50  // Number Of Particles To Create
   
    unsigned char *image;
   bool keys[256];     // Array Used For The Keyboard Routine
   bool active=TRUE;    // Window Active Flag Set To TRUE By Default
   bool fullscreen=TRUE;   // Fullscreen Flag Set To Fullscreen Mode By Default
   bool rainbow=true;    // Rainbow Mode?
   bool sp;       // Spacebar Pressed?
   bool rp;       // Enter Key Pressed?
  
   float slowdown=1.5f;    // Slow Down Particles
   float xspeed;      // Base X Speed (To Allow Keyboard Direction Of Tail)
   float yspeed;      // Base Y Speed (To Allow Keyboard Direction Of Tail)
  
   GLuint loop;      // Misc Loop Variable
   GLuint col;      // Current Color Selection
   GLuint delay;      // Rainbow Effect Delay
   GLuint texture[1];     // Storage For Our Particle Texture
 
  void idle(int);
  
   typedef struct      // Create A Structure For Particle
   {
   bool active;     // Active (Yes/No)
   float life;     // Particle Life
   float fade;     // Fade Speed
   float r;      // Red Value
   float g;      // Green Value
   float b;      // Blue Value
   float x;      // X Position
   float y;      // Y Position
   float z;      // Z Position
   float xi;      // X Direction
   float yi;      // Y Direction
   float zi;      // Z Direction
   float xg;      // X Gravity
   float yg;      // Y Gravity
   float zg;      // Z Gravity
   }
   particles;       // Particles Structure
  
   particles particle[MAX_PARTICLES]; // Particle Array (Room For Particle Info)
  

   /* ----------------------------------------------------------------------------*/
   void loadJpegImage(char *fichier, int numtex)
   {
  
     struct jpeg_decompress_struct cinfo;
     struct jpeg_error_mgr jerr;
     FILE *file;
     unsigned char *ligne;
 
     cinfo.err = jpeg_std_error(&jerr);
     jpeg_create_decompress(&cinfo);
     if ((file=fopen(fichier,"rb" ))==NULL)
      {
         fprintf(stderr,"Erreur : impossible d'ouvrir le fichier texture.jpg\n" );
         system("PAUSE" );
         exit(1);
       }
     jpeg_stdio_src(&cinfo, file);
     jpeg_read_header(&cinfo, TRUE);
     image= new unsigned char [cinfo.image_width*cinfo.image_height*3];
     if (cinfo.jpeg_color_space==JCS_GRAYSCALE) {
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
     glBindTexture(GL_TEXTURE_2D,numtex);
     glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
     glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
     glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,cinfo.image_width,cinfo.image_height,0,GL_RGB,GL_UNSIGNED_BYTE,image);
  
     delete [] image;
   
  }
 
  /* ----------------------------------------------------------------------------*/

  void resize(int width, int height)
  {
  glViewport(0,0,width,height);      // Reset The Current Viewport
 
  glMatrixMode(GL_PROJECTION);      // Select The Projection Matrix
  glLoadIdentity();         // Reset The Projection Matrix
 
  // Calculate The Aspect Ratio Of The Window
  gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,90.0f);
 
  glMatrixMode(GL_MODELVIEW);       // Select The Modelview Matrix
  glLoadIdentity();
  }
 
  /* ----------------------------------------------------------------------------*/
 
  void display()
  {
  glutTimerFunc(30,idle,0);        // Le timer
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      glTranslatef(0.0,0.0,-4.3);
      glRotatef(25.0,1.0,0.0,0.0);
      glScalef(0.1,0.1,0.1);
      for (loop=0;loop<MAX_PARTICLES;loop++)     
      // Loop Through All The Particles
  {
    float x=particle[loop].x;      // Grab Our Particle X Position
    float y=particle[loop].y;      // Grab Our Particle Y Position
    float z=particle[loop].z;     // Particle Z Pos + Zoom
      // Draw The Particle Using Our RGB Values, Fade The Particle Based On It's Life
    glColor4f(particle[loop].r,particle[loop].g,particle[loop].b,particle[loop].life);
 
    glBegin(GL_TRIANGLE_STRIP);      // Build Quad From A Triangle Strip
        glTexCoord2d(1,1); glVertex3f(x+3.5f,y,z+3.5f); // Top Right
     glTexCoord2d(0,1); glVertex3f(x-3.5f,y,z+3.5f); // Top Left
    glTexCoord2d(1,0); glVertex3f(x+3.5f,y,z-3.5f); // Bottom Right
     glTexCoord2d(0,0); glVertex3f(x-3.5f,y,z-3.5f); // Bottom Left
    glEnd();          // Done Building Triangle Strip
     }
 
      glutSwapBuffers();
  }
 
  /* ----------------------------------------------------------------------------*/

  void idle(int numero)
  {
  glLoadIdentity();          // Reset The ModelView Matrix
 
 
  for (loop=0;loop<MAX_PARTICLES;loop++)     // Loop Through All The Particles
  {
   if (particle[loop].active)       // If The Particle Is Active
   {
    float x=particle[loop].x;      // Grab Our Particle X Position
    float y=particle[loop].y;      // Grab Our Particle Y Position
    float z=particle[loop].z;     // Particle Z Pos + Zoom
 
    particle[loop].x+=particle[loop].xi/(slowdown*1000);// Move On The X Axis By X Speed
    particle[loop].y+=particle[loop].yi/(slowdown*1000);// Move On The Y Axis By Y Speed
    particle[loop].z+=particle[loop].zi/(slowdown*1000);// Move On The Z Axis By Z Speed
 
    particle[loop].xi+=particle[loop].xg;   // Take Pull On X Axis Into Account
    particle[loop].yi+=particle[loop].yg;   // Take Pull On Y Axis Into Account
    particle[loop].zi+=particle[loop].zg;   // Take Pull On Z Axis Into Account
    particle[loop].life-=particle[loop].fade;  // Reduce Particles Life By 'Fade'
 
    }    
       
         }
     
    glutPostRedisplay();
 
  }
  
  /* ----------------------------------------------------------------------------*/
  
  /* Program entry point */
 
 int main(int argc, char *argv[])
  {
      glutInit(&argc, argv);
      glutInitWindowSize(800,600);
      glutInitWindowPosition(10,10);
      glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
 
      glutCreateWindow("Test particules" );
     
      // OpenGL
      glShadeModel(GL_SMOOTH);       // Enable Smooth Shading
      glClearColor(0.0f,0.0f,0.0f,0.0f);     // Black Background
      glClearDepth(1.0f);         // Depth Buffer Setup
      glEnable(GL_BLEND);         // Enable Blending
      glBlendFunc(GL_SRC_ALPHA,GL_ONE);     // Type Of Blending To Perform
      glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST); // Really Nice Perspective Calculations
      glHint(GL_POINT_SMOOTH_HINT,GL_NICEST);    // Really Nice Point Smoothing
      glEnable(GL_TEXTURE_2D);       // Enable Texture Mapping
      glGenTextures(1,texture);
      loadJpegImage("particle.jpg",texture[0]);
      glBindTexture(GL_TEXTURE_2D,texture[0]);   // Select Our Texture
 
  for (loop=0;loop<MAX_PARTICLES;loop++)    // Initials All The Textures
  {
   particle[loop].active=true;        // Make All The Particles Active
   particle[loop].life=16.0f;        // Give All The Particles Full Life
   particle[loop].fade=float(rand()%100)/1000.0f+0.003f; // Random Fade Speed
   particle[loop].r=1.0;
   particle[loop].g=1.0;
   particle[loop].b=0.67;
   particle[loop].xi=float((rand()%50)-26.0f)*5.0f;  // Random Speed On X Axis
   particle[loop].yi=float((rand()%50)-25.0f);             // Random Speed On Y Axis
   particle[loop].zi=float((rand()%50)-25.0f)*5.0f;  // Random Speed On Z Axis
   particle[loop].xg=0.0f;         // Set Horizontal Pull To Zero
   particle[loop].yg=-0.8f;        // Set Vertical Pull Downward
   particle[loop].zg=0.0f;         // Set Pull On Z Axis To Zero
  }
  // Fin initialisation opengl
     glClearColor(0,0,0,1);
     
     glutReshapeFunc(resize);
     glutDisplayFunc(display);
     glutMainLoop(); 
  }

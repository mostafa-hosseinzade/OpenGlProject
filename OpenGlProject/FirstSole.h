static unsigned int texture[2]; // Array of texture indices.
static unsigned char chessboard[64][64][3]; // Storage for chessboard image.
static int id = 0; // Currently displayed texture id.

void DrawSole(int i)
    {
    glPushMatrix();
    GLfloat fExtent = 40.0f;
    GLfloat fStep = 1.0f;
    GLfloat y = -0.4f;
    GLint iLine;
    if(i == 0){
      id=0;
      glTranslatef(0,-5,0);
      glRotatef(90,1,0,0);
    }else if(i == 1){
        id =1;
      	//saghf
      glTranslatef(0,15,0);
      glRotatef(90,1,0,0);
    }else if(i == 2){
        id=2;
      	//divar posht
      glTranslatef(-42,20,-40);
      glRotatef(180,1,0,0);
    }else if(i == 3){
       id=2;
      	//divar golo
      glTranslatef(-42,20,40);
      glRotatef(180,1,0,0);
    }else if(i == 4){
       id=2;
      	//divar rast
       //////////////////////////////////
      glTranslatef(40,-10,41);
      glRotatef(90,0,1,0);
    }else if(i == 5){
       id=2;
      	//divar chap
      glTranslatef(-40,-10,42);
      glRotatef(90,0,1,0);
    }
    glEnable(GL_TEXTURE_2D);
    if(i == 2 || i == 3 || i == 4 || i == 5){
      int j = 0;
      int s = 0;
      for (j = 0; j < 17; j++)
      {
        glBindTexture(GL_TEXTURE_2D, texture[id]);
        glTranslatef(5,0,0);
        for(s = 0;s<20;s++){
        glPushMatrix();
            glTranslatef(0,s+5,0);
              glBegin(GL_POLYGON);
              glTexCoord2f(0.0, 0.0);glVertex3f(-3, -3, 0.0);
              glTexCoord2f(1.0, 0.0);glVertex3f(3, -3, 0.0);
              glTexCoord2f(1.0, 1.0);glVertex3f(3,3, 0.0);
              glTexCoord2f(0.0, 1.0);glVertex3f(-3, 3, 0.0);
            glEnd();
        glPopMatrix();
        }
        
      }

    }
  
    if(i==0 || i == 1){
    glBindTexture(GL_TEXTURE_2D, texture[id]);
   glBegin(GL_POLYGON);
      //mokhtasat texture      //   mokan morabaA
      glTexCoord2f(0.0, 0.0);  glVertex3f(-fExtent, -fExtent, 0.0);
      glTexCoord2f(1.0, 0.0); glVertex3f(fExtent, -fExtent, 0.0);
      glTexCoord2f(1.0, 1.0); glVertex3f(fExtent, fExtent, 0.0);
      glTexCoord2f(0.0, 1.0); glVertex3f(-fExtent, fExtent, 0.0);
   glEnd();
  }
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    }



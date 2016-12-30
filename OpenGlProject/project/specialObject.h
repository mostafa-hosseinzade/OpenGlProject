

void mhSolidCube(int size){
	glEnable(GL_TEXTURE_2D);
	//poshti
	glPushMatrix();
	
	glBindTexture(GL_TEXTURE_2D, texture[3]);
   glBegin(GL_POLYGON);
      //mokhtasat texture      //   mokan morabaA
      glTexCoord2f(0.0, 0.0);  glVertex3f(-size, -size, 0.0);
      glTexCoord2f(1.0, 0.0); glVertex3f(size, -size, 0.0);
      glTexCoord2f(1.0, 1.0); glVertex3f(size, size, 0.0);
      glTexCoord2f(0.0, 1.0); glVertex3f(-size, size, 0.0);
   glEnd();
   
   glPopMatrix();

   //bala
   glPushMatrix();
   glTranslatef(0,size,size);
   glRotatef(90,1,0,0);
	glBindTexture(GL_TEXTURE_2D, texture[3]);
   glBegin(GL_POLYGON);
      //mokhtasat texture      //   mokan morabaA
      glTexCoord2f(0.0, 0.0);  glVertex3f(-size, -size, 0.0);
      glTexCoord2f(1.0, 0.0); glVertex3f(size, -size, 0.0);
      glTexCoord2f(1.0, 1.0); glVertex3f(size, size, 0.0);
      glTexCoord2f(0.0, 1.0); glVertex3f(-size, size, 0.0);
   glEnd();
   glPopMatrix();

   //golo
   glPushMatrix();
   glTranslatef(0,0,size*2);
   glRotatef(90,0,0,1);
	glBindTexture(GL_TEXTURE_2D, texture[3]);
   glBegin(GL_POLYGON);
      //mokhtasat texture      //   mokan morabaA
      glTexCoord2f(0.0, 0.0);  glVertex3f(-size, -size, 0.0);
      glTexCoord2f(1.0, 0.0); glVertex3f(size, -size, 0.0);
      glTexCoord2f(1.0, 1.0); glVertex3f(size, size, 0.0);
      glTexCoord2f(0.0, 1.0); glVertex3f(-size, size, 0.0);
   glEnd();
   glPopMatrix();

   //payeen
   glPushMatrix();
   glTranslatef(0,-size,size);
   glRotatef(90,1,0,0);
	glBindTexture(GL_TEXTURE_2D, texture[3]);
   glBegin(GL_POLYGON);
      //mokhtasat texture      //   mokan morabaA
      glTexCoord2f(0.0, 0.0);  glVertex3f(-size, -size, 0.0);
      glTexCoord2f(1.0, 0.0); glVertex3f(size, -size, 0.0);
      glTexCoord2f(1.0, 1.0); glVertex3f(size, size, 0.0);
      glTexCoord2f(0.0, 1.0); glVertex3f(-size, size, 0.0);
   glEnd();
   glPopMatrix();

   //rast
   glPushMatrix();
   glTranslatef(size,0,size);
   glRotatef(90,0,1,0);
	glBindTexture(GL_TEXTURE_2D, texture[3]);
   glBegin(GL_POLYGON);
      //mokhtasat texture      //   mokan morabaA
      glTexCoord2f(0.0, 0.0);  glVertex3f(-size, -size, 0.0);
      glTexCoord2f(1.0, 0.0); glVertex3f(size, -size, 0.0);
      glTexCoord2f(1.0, 1.0); glVertex3f(size, size, 0.0);
      glTexCoord2f(0.0, 1.0); glVertex3f(-size, size, 0.0);
   glEnd();
   glPopMatrix();

   //chap
   glPushMatrix();
   glTranslatef(-size,0,size);
   glRotatef(90,0,1,0);
	glBindTexture(GL_TEXTURE_2D, texture[3]);
   glBegin(GL_POLYGON);
      //mokhtasat texture      //   mokan morabaA
      glTexCoord2f(0.0, 0.0);  glVertex3f(-size, -size, 0.0);
      glTexCoord2f(1.0, 0.0); glVertex3f(size, -size, 0.0);
      glTexCoord2f(1.0, 1.0); glVertex3f(size, size, 0.0);
      glTexCoord2f(0.0, 1.0); glVertex3f(-size, size, 0.0);
   glEnd();
   glPopMatrix();
   glDisable(GL_TEXTURE_2D);
}
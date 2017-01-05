
void DrawBox(){
        
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);       
                            // Crosshair  
                 glDisable(GL_DEPTH_TEST);
                 glLoadIdentity();
                 glTranslated(0.0f,0.0f,-35.0f);   

                 glBlendFunc(GL_SRC_ALPHA,GL_ONE);

                 glColor4f(1,1,1,1);
                 glBindTexture(GL_TEXTURE_2D,texture[4]);
                 glBegin(GL_QUADS);
                 glTexCoord2d(1,1); glVertex2f(1,1);
                 glTexCoord2d(1,0); glVertex2f(1,-1);
                 glTexCoord2d(0,0); glVertex2f(-1,-1);
                 glTexCoord2d(0,1); glVertex2f(-1,1);
                 glEnd();

                 glEnable(GL_DEPTH_TEST);
            glDisable(GL_TEXTURE_2D);
    glPopMatrix();
    
    
	glPushMatrix();
		glTranslatef(20,-3,0);
		glScalef(1.3,1,1);
		mhSolidCube(2);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-20,-3,0);
		glScalef(1.3,1,1);
		mhSolidCube(5);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-10,-3,-20);
		glScalef(1.3,1,1);
		mhSolidCube(4);
	glPopMatrix();

}

void DrawBox(){
        
    
    
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

void DrawTargetPointer()
{
    
    glPushMatrix();
    
    glTranslatef(x+lx,y+ly,z+lz);
     glRotatef(t,0,1,0);
        
        glPushMatrix();
        glScalef(2.5,0.3,1);
        glutSolidCube(0.1);
        glPopMatrix();
        
        glPushMatrix();
        glTranslatef(0.2,0.16,0);
        glRotatef(90,0,0,1);
        glScalef(2.5,0.3,1);
        glutSolidCube(0.1);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0.2,-0.16,0);
        glRotatef(90,0,0,1);
        glScalef(2.5,0.3,1);
        glutSolidCube(0.1);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0.4,0,0);
        glScalef(2.5,0.3,1);
        glutSolidCube(0.1);
        glPopMatrix();
        
    glPopMatrix();
}
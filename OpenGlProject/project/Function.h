
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
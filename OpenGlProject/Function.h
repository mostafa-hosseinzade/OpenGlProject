

void DrawBox() {

    glPushMatrix();
    //set position box
    //x position
    Postion[0][0][0] = -32;
    Postion[0][0][1] = -28;
    //z position
    Postion[0][1][0] = -35;
    Postion[0][1][1] = -18;

    glTranslatef(-30, 0, -35);
    glScalef(1, 1, 1.5);
    mhTargetShooter(4, 6);

    glPopMatrix();

    glPushMatrix();

    //set position box
    Postion[1][0][0] = 18;
    Postion[1][0][1] = 22;

    Postion[1][1][0] = -35;
    Postion[1][1][1] = -18;

    glTranslatef(20, 0, -35);
    glScalef(1, 1, 1.5);
    mhTargetShooter(4, 5);

    glPopMatrix();

    glPushMatrix();
    //set position box
    //x position
    Postion[0][0][0] = 28;
    Postion[0][0][1] = 32;
    //z position
    Postion[0][1][0] = -35;
    Postion[0][1][1] = -18;
    glTranslatef(30, 0, -35);
    glScalef(1, 1, 1.5);
    mhTargetShooter(4, 7);

    glPopMatrix();

    glPushMatrix();
    glTranslatef(20, -3, 0);
    glScalef(1.3, 1, 1);
    mhSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-20, -3, 0);
    glScalef(1.3, 1, 1);
    mhSolidCube(5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-10, -3, -20);
    glScalef(1.3, 1, 1);
    mhSolidCube(4);
    glPopMatrix();

}

void DrawTargetPointer() {

    glPushMatrix();
    glColor3f(0.540, 808, 408);
    glTranslatef(x + lx, y + ly, z + lz);
    glScalef(0.2, 0.2, 0.2);
    glRotatef(t, 0, 1, 0);

    glPushMatrix();
    glScalef(2.5, 0.3, 1);
    glutSolidCube(0.1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.2, 0.16, 0);
    glRotatef(90, 0, 0, 1);
    glScalef(2.5, 0.3, 1);
    glutSolidCube(0.1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.2, -0.16, 0);
    glRotatef(90, 0, 0, 1);
    glScalef(2.5, 0.3, 1);
    glutSolidCube(0.1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.4, 0, 0);
    glScalef(2.5, 0.3, 1);
    glutSolidCube(0.1);
    glPopMatrix();

    glPopMatrix();
}

void DrawText() {
    glPushMatrix();
    glTranslatef(x + lx, 0, z + lz);
    glScalef(0.04, 1, 1);
    glColor3f(1, 0, 0);
    //    emitString("test",1,0);
    glPopMatrix();
}

void DrawBoxSections() {
    if (moveCamera == 0) {
        DrawTargetPointer();
        glPushMatrix();
        glTranslatef(x + lx, 0.5, lz+z);
        glScalef(0.04, 1, 1);
        glColor3f(1, 0, 0);
            emitString("Your Score : ",1,0);
        glPopMatrix();
    }
    if (DrawPointShoot == 1) {
        glPushMatrix();
        glTranslatef(xDrawPoint, YDrawPoint, zDrawPoint);
        glColor3f(1, 0, 0);
        glScalef(0.1, 0.1, 0.1);
        glutSolidSphere(0.3, 15, 15);
        glPopMatrix();
    }

}

float upx = 0.0f, upy = 1.0f, upz = 0.0f;
float _angle = 30.0f;
float _cameraAngle = 0.0f;
bool lbuttonDown;
int direction;
float moveZ = 1, moveX = 1, moveY = 1;
float MoveS[2][2] = {
    {1, 1},
    {1, 1}};

void checkPosition() {
    int i = 0;
    for (i = 0; i <= 10; i++) {
        if (x > Postion[i][0][0] && x < Postion[i][0][1] && z > Postion[i][1][0] && z < Postion[i][1][1]) {
            moveCamera = 0;
            DrawTargetPointer();
        }
    }
}

void CheckPostionMove() {
    if (x + lx + 4 >= 39) {
        MoveS[0][0] = 0;
    }else if(x+lx+4 <= 39){
        MoveS[0][0] =1;
    }
    
    if (x + lx - 4 <= -39) {
        MoveS[0][1] = 0;
    }else if(x + lx - 4 >= -39){
        MoveS[0][1] = 1;
    }
    
    if (z + lz + 4 >= 39) {
        MoveS[1][0] = 0;
    }else if(z + lz + 4 <= 39){
        MoveS[1][0] = 1;
    }
    
    if (z + lz - 4 <= -39) {
        MoveS[1][1] = 0;
    }else if(z + lz - 4 >= -39){
        MoveS[1][1] = 1;
    }
}

void orientMe(float ang) {
    lx = sin(ang);
    lz = -cos(ang);
    glLoadIdentity();
    gluLookAt(x, y, z,
            x + lx, y + ly, z + lz,
            0.0f, 1.0f, 0.0f);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear Screen And Depth Buffer
}

void moveMeFlat(int i) {
    x = x + i * (lx)*0.1;
    z = z + i * (lz)*0.1;
    cout << "z is " << z << " lz is " << lz << "x is " << x << " lx is " << lx << "y is " << y << " ly is " << ly << "\n";
    glLoadIdentity();
    gluLookAt(x, y, z,
            x + lx, y + ly, z + lz,
            0.0f, 1.0f, 0.0f);
}

void moveMeAroundRight(int i) {

    ///////z is mines
    if (lx < 0.2 && lx >= 0 && lz <= 1 && lz <= 0) {
        x = x + i + 4 * (lx)*0.1;
    } else if (lx < 0.4 && lx > 0 && lz <= 0) {
        z = z + i / 3 * (lz)*0.1;
        x = x - i * (lx)*0.1;
    } else if (lx < 0.6 && lx > 0.4 && lz <= 0) {
        z = z + i / 2 * (lz)*0.1;
        x = x - i * (lx)*0.1;
    } else if (lx < 0.8 && lx > 0.6 && lz <= 0) {
        z = z + i / 1.5 * (lz)*0.1;
        x = x - i * (lx)*0.1;
    } else if (lx <= 1.0 && lx > 0.8 && lz <= 0) {
        z = z + i + 1 * (lz)*0.1;

    } else if (lx <= 0 && lx >= -0.2 && lz <= 0) {
        x = x + i + 4 * (lx)*0.1;
    } else if (lx <= -0.2 && lx >= -0.4 && lz <= 0) {
        z = z - i / 3 * (lz)*0.1;
        x = x + i + 2 * (lx)*0.1;
    } else if (lx <= -0.4 && lx >= -0.6 && lz <= 0) {
        z = z - i / 2 * (lz)*0.1;
        x = x + i + 1 * (lx)*0.1;
    } else if (lx <= -0.6 && lx >= -0.8 && lz <= 0) {
        z = z + i * (lz)*0.1;
        x = x - i / 2 * (lx)*0.1;
    } else if (lx <= -0.8 && lx >= -1.0 && lz <= 0) {
        z = z - i + 1 * (lz)*0.1;
    }/// z is plus
    else if (lx < 0.2 && lx >= 0 && lz <= 1 && lz >= 0) {
        x = x - i + 4 * (lx)*0.1;
    } else if (lx < 0.4 && lx > 0 && lz >= 0) {
        z = z + i / 3 * (lz)*0.1;
        x = x - i * (lx)*0.1;
    } else if (lx < 0.6 && lx > 0.4 && lz >= 0) {
        z = z + i / 2 * (lz)*0.1;
        x = x - i * (lx)*0.1;
    } else if (lx < 0.8 && lx > 0.6 && lz >= 0) {
        z = z + i / 1.5 * (lz)*0.1;
        x = x - i * (lx)*0.1;
    } else if (lx <= 1.0 && lx > 0.8 && lz >= 0) {
        z = z + i + 1 * (lz)*0.1;

    } else if (lx <= 0 && lx >= -0.2 && lz >= 0) {
        x = x - i + 4 * (lx)*0.1;
    } else if (lx <= -0.2 && lx >= -0.4 && lz >= 0) {
        z = z + i / 3 * (lz)*0.1;
        x = x - i + 2 * (lx)*0.1;
    } else if (lx <= -0.4 && lx >= -0.6 && lz >= 0) {
        z = z + i / 2 * (lz)*0.1;
        x = x - i + 1 * (lx)*0.1;
    } else if (lx <= -0.6 && lx >= -0.8 && lz >= 0) {
        z = z - i * (lz)*0.1;
        x = x + i / 2 * (lx)*0.1;
    } else if (lx <= -0.8 && lx >= -1.0 && lz >= 0) {
        z = z - i + 1 * (lz)*0.1;
    }
    ///////////////////////////

    glLoadIdentity();
    gluLookAt(x, y, z,
            x + lx, y + ly, z + lz,
            0.0f, 1.0f, 0.0f);
}

void moveMeAroundLeft(int i) {

    ///////z is mines
    if (lx < 0.2 && lx >= 0 && lz <= 1 && lz <= 0) {
        x = x - i + 4 * (lx)*0.1;
    } else if (lx < 0.4 && lx > 0 && lz <= 0) {
        z = z - i / 3 * (lz)*0.1;
        x = x + i * (lx)*0.1;
    } else if (lx < 0.6 && lx > 0.4 && lz <= 0) {
        z = z + i / 2 * (lz)*0.1;
        x = x - i * (lx)*0.1;
    } else if (lx < 0.8 && lx > 0.6 && lz <= 0) {
        z = z + i / 1.5 * (lz)*0.1;
        x = x + i * (lx)*0.1;
    } else if (lx <= 1.0 && lx > 0.8 && lz <= 0) {
        z = z - i + 0.5 * (lz)*0.1;

    } else if (lx <= 0 && lx >= -0.2 && lz <= 0) {
        x = x - i + 4 * (lx)*0.1;
    } else if (lx <= -0.2 && lx >= -0.4 && lz <= 0) {
        z = z + i / 3 * (lz)*0.1;
        x = x - i + 2 * (lx)*0.1;
    } else if (lx <= -0.4 && lx >= -0.6 && lz <= 0) {
        z = z - i / 2 * (lz)*0.1;
        x = x - i + 0.5 * (lx)*0.1;
    } else if (lx <= -0.6 && lx >= -0.8 && lz <= 0) {
        z = z - i * (lz)*0.1;
        x = x + i / 2 * (lx)*0.1;
    } else if (lx <= -0.8 && lx >= -1.0 && lz <= 0) {
        z = z + i + 1 * (lz)*0.1;
    }/// z is plus
    else if (lx < 0.2 && lx >= 0 && lz <= 1 && lz >= 0) {
        x = x + i + 4 * (lx)*0.1;
    } else if (lx < 0.4 && lx > 0 && lz >= 0) {
        z = z - i / 3 * (lz)*0.1;
        x = x + i * (lx)*0.1;
    } else if (lx < 0.6 && lx > 0.4 && lz >= 0) {
        z = z - i / 2 * (lz)*0.1;
        x = x + i * (lx)*0.1;
    } else if (lx < 0.8 && lx > 0.6 && lz >= 0) {
        z = z - i / 1.5 * (lz)*0.1;
        x = x + i * (lx)*0.1;
    } else if (lx <= 1.0 && lx > 0.8 && lz >= 0) {
        z = z - i + 1 * (lz)*0.1;

    } else if (lx <= 0 && lx >= -0.2 && lz >= 0) {
        x = x + i + 4 * (lx)*0.1;
    } else if (lx <= -0.2 && lx >= -0.4 && lz >= 0) {
        z = z - i / 3 * (lz)*0.1;
        x = x + i + 2 * (lx)*0.1;
    } else if (lx <= -0.4 && lx >= -0.6 && lz >= 0) {
        z = z - i / 2 * (lz)*0.1;
        x = x + i + 1 * (lx)*0.1;
    } else if (lx <= -0.6 && lx >= -0.8 && lz >= 0) {
        z = z + i * (lz)*0.1;
        x = x - i / 2 * (lx)*0.1;
    } else if (lx <= -0.8 && lx >= -1.0 && lz >= 0) {
        z = z + i + 1 * (lz)*0.1;
    }
    ///////////////////////////

    //    cout << "XX value is " << x << "\n";
    //    cout << "LYYY value is " << ly << "\n";
    //    cout << "LXXX value is " << lx << "\n";
    //    cout << "LZZZ value is " << lz << "\n";
    glLoadIdentity();
    gluLookAt(x, y, z,
            x + lx, y + ly, z + lz,
            0.0f, 1.0f, 0.0f);
}

void RotX(float ang) {
    ly = sin(ang);
    lz = -cos(ang);
    //    cout << "y is " << y << " ly is " << ly << "\n" << "x is " << x << " lx is " << lx;
    glLoadIdentity();
    gluLookAt(x, y, z,
            x + lx, y + ly, z + lz,
            0, 1, 0);
}

void RotY(float ang) {
    lx = sin(ang);
    lz = -cos(ang);
    glLoadIdentity();
    //    cout << "z is " << y << " lz is " << lz << "\n" << "x is " << x << " lx is " << lx << "move camera is " << moveCamera;
    gluLookAt(x, y, z,
            x + lx, y + ly, z + lz,
            0.0f, 1.0f, 0.0f);
}

void processNormalKeys(unsigned char key, int x, int y) {
    checkPosition();
    CheckPostionMove();
    if (moveCamera == 1) {
        if (key == 'a' || key == 'A') {
            if (MoveS[0][1] != 0 && lz < -0.2) {
                moveMeAroundLeft(4);
            }else if(MoveS[0][0] != 0 && lz > 0.2){
                moveMeAroundLeft(4);
            }else if(MoveS[1][1] != 0 && lz < 0.2 && lz > -0.2 && lx > 0){
                moveMeAroundLeft(4);
            }else if(MoveS[1][0] != 0 && lz < 0.2 && lz > -0.2 && lx < 0){
                moveMeAroundLeft(4);
            }
        }
        if (key == 'd' || key == 'D') {
            if (MoveS[0][0] != 0 && lz < -0.2) {
                moveMeAroundRight(4);
            }else if(MoveS[0][1] != 0 && lz > 0.2){
                moveMeAroundRight(4);
            }else if(MoveS[1][0] != 0 && lz < 0.2 && lz > -0.2 && lx > 0){
                moveMeAroundRight(4);
            }else if(MoveS[1][1] != 0 && lz < 0.2 && lz > -0.2 && lx < 0){
                moveMeAroundRight(4);
            }
        }
        if (key == 'w' || key == 'W') {
            if (MoveS[1][1] != 0 && lz < -0.2) {
                deltaMove = 2;
            }else if(MoveS[1][0] != 0 && lz > 0.2){
                deltaMove = 2;
            }else if(MoveS[0][1] != 0 && lz < 0.2 && lz > -0.2 && lx < 0){
                deltaMove = 2;
            }else if(MoveS[0][0] != 0 && lz < 0.2 && lz > -0.2 && lx > 0){
                deltaMove = 2;
            }
        }

        if (key == 's' || key == 'S') {
            if (MoveS[1][0] != 0 && lz < -0.2) {
                deltaMove = -2;
            }else if(MoveS[1][1] != 0 && lz > 0.2){
                deltaMove = -2;
            }else if(MoveS[0][0] != 0 && lz < 0.2 && lz > -0.2 && lx < 0){
                deltaMove = -2;
            }else if(MoveS[0][1] != 0 && lz < 0.2 && lz > -0.2 && lx > 0){
                deltaMove = -2;
            }
        }
    } else if (moveCamera == 0) {
        if (key == 'q' || key == 'Q') {
            moveCamera = 1;
            x = x - x;
            z = z + 4;
            RotY(0);
        }
    }

    if (key == 27)
        exit(0);
}

void processNormalUpKeys(unsigned char key, int x, int y) {
    if (key == 'a' || key == 'A') {
        if (deltaAngle < 0.0f)
            deltaAngle = 0.0f;
    }

    if (key == 'd' || key == 'D') {
        if (deltaAngle > 0.0f)
            deltaAngle = 0.0f;
    }
    if (key == 'w' || key == 'W') {
        if (deltaMove > 0)
            deltaMove = 0;
    }

    if (key == 's' || key == 'S') {
        if (deltaMove < 0)
            deltaMove = 0;
    }


    if (key == 27)
        exit(0);
}


void pressKey(int key, int x, int y) {
    checkPosition();
    if (moveCamera == 1) {
        switch (key) {
            case GLUT_KEY_LEFT: deltaAngle = -0.01f;
                t += 3.0;
                break;
            case GLUT_KEY_RIGHT: deltaAngle = 0.01f;
                t -= 3.0;
                break;
            case GLUT_KEY_UP: deltaMove = 1;
                break;
            case GLUT_KEY_DOWN: deltaMove = -1;
                break;

            case 27:
                exit(0);
                break;
        }
    }
}

void releaseKey(int key, int x, int y) {

    switch (key) {
        case GLUT_KEY_LEFT: if (deltaAngle < 0.0f)
                deltaAngle = 0.0f;
            break;
        case GLUT_KEY_RIGHT: if (deltaAngle > 0.0f)
                deltaAngle = 0.0f;
            break;
        case GLUT_KEY_UP: if (deltaMove > 0)
                deltaMove = 0;
            break;
        case GLUT_KEY_DOWN: if (deltaMove < 0)
                deltaMove = 0;
            break;

    }
}

void mouse(int button, int state, int xIn, int yIn) {
    if (button == GLUT_RIGHT_BUTTON) {
        if (state == GLUT_DOWN)
            glScalef(2.0, 2.0, 2.0);
        else

            cout << "right button lifted at (" << x << "," << y << ")" << endl;
    } else if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN)

            if (moveCamera == 0) {
                cout << "you info is X is ==> " << x << " lx is ==> " << lx << " Y is ==> "
                        << y << " LY is ==> " << ly << " Z is ==> " << z << " LZ is ==> " << lz << "\n";
                xDrawPoint = x + lx, YDrawPoint = y + ly, zDrawPoint = z + lz + (-1);
                DrawPointShoot = 1;

                glPushMatrix();
                glTranslatef(xDrawPoint, YDrawPoint, zDrawPoint);
                glColor3f(1, 0, 0);
                glScalef(0.1, 0.1, 0.1);
                glutSolidSphere(0.3, 15, 15);
                glPopMatrix();
                glutPostRedisplay();
            }
    }
}

void motionPassive(int xInput, int yInput) {
    //    glutSetCursor(GLUT_CURSOR_FULL_CROSSHAIR);
    //    cout << "Mouse moved at "
    //            << "(" << x << "," << y << ")" << endl;
    float angleX = 0;
    angleX = xInput / 10 * 0.1f; //- (GLUT_WINDOW_WIDTH)* 0.1f;
    //        cout <<"x is "<<x<<"\n";
    if (moveCamera == 0) {
        lx = sin(angleX);
        if (moveCamera == 0 && lx > -0.5 && lx < 0.150 && lz < 0) {
            RotY(angleX);
        }
        if (yInput < 210 && yInput > 120 && lz < 0) {
            float angleY;
            yInput = yInput - 170;
            angleY = yInput / 10 * 0.1f; //- (GLUT_WINDOW_HEIGHT)* 0.1f;
            RotX(angleY);
        }
    } else if (moveCamera == 1) {
        RotY(angleX);
    }

    //    cout << "Y INPUT IS  " << yInput << " lz is " << lz << "\n";
}


///////////////////////////////////////////////////////////
// Called by GLUT library when idle (window not being
// resized or moved)

void TimerFunction(int value) {
    yRot += 5;
    if (value == 2) {
        if (CP == 0) {
            CTR = 0.080;
            CTG = 0.568;
            CTB = 0.620;
            CP = 1;
        } else {
            CP = 0;
            CTR = 0.080;
            CTG = 0.620;
            CTB = 0.444;
        }
    }

    glutPostRedisplay();
    glutTimerFunc(3, TimerFunction, 1);
}


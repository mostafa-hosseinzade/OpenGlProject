/**
 * Author Mr Mostafa Hosseinzade
 * Date 2016/04/30
 **/
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <GL/glut.h>
#include <GL/glext.h>
#include <cstdlib>
#include <fstream>
using namespace std;
#include "FirstSole.h";
#include "Texture.h";
#include "specialObject.h";
#include "header.h";
#include "camera.h";    
#include "Function.h";

void RenderScene(void) {

    if (deltaMove)
        moveMeFlat(deltaMove);
    if (deltaAngle) {
        angle += deltaAngle;
        orientMe(angle);
    }
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_COLOR_MATERIAL);
    glShadeModel(GL_SMOOTH);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glTranslatef(xTranslate,yTranslate,zTranslate);


    //draw sole
    DrawBox();
    DrawTargetPointer();
    DrawSole(0);
    DrawSole(1);
    DrawSole(2);
    DrawSole(3);
    DrawSole(4);
    DrawSole(5);
    glutSwapBuffers();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(800, 600);
    glutCreateWindow("SnowMen from Lighthouse3D");
    // register all callbacks
    glutKeyboardFunc(processNormalKeys);
    glutKeyboardUpFunc(processNormalUpKeys);
    glutSpecialFunc(pressKey);
    glutSpecialUpFunc(releaseKey);
    glutMouseFunc(mouse);
    glutPassiveMotionFunc(motionPassive);
    setupTextur();
    glDisable(GL_TEXTURE_2D);

    glutDisplayFunc(RenderScene);
    SetupRC();
    glEnable(GL_TEXTURE_2D);
    glutTimerFunc(33, TimerFunction, 1);
    glutReshapeFunc(changeSize);

    cout << "\n The camera move by Arrow keys\n";
    glutMainLoop();
    return (0);
}
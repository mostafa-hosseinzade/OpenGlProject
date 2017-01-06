double camera_angle_h = 0;
double camera_angle_v = 0;

int drag_x_origin;
int drag_y_origin;
int dragging = 0;
//
//void display() {
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    glLoadIdentity();
//    gluLookAt(0.0, 0.0, 25.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
//    glRotated(camera_angle_v, 1.0, 0.0, 0.0);
//    glRotated(camera_angle_h, 0.0, 1.0, 0.0);
//
//
//    glFlush();
//    glutSwapBuffers();
//}
//
//void mouse_click(int button, int state, int x, int y) {
//    if(button == GLUT_LEFT_BUTTON) {
//        if(state == GLUT_DOWN) {
//            dragging = 1;
//            drag_x_origin = x;
//            drag_y_origin = y;
//        }
//        else
//            dragging = 0;
//    }
//}

void mouse_move(int x, int y) {
    if(dragging) {
        camera_angle_v += (y - drag_y_origin)*0.3;
        camera_angle_h += (x - drag_x_origin)*0.3;
        drag_x_origin = x;
        drag_y_origin = y;
    }
}
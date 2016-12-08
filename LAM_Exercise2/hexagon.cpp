#include <math.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <stdio.h>
#include <stdlib.h>

int screenHeight = 480, screenWidth = 640;


void myInit(void){
    glClearColor(1.0,1.0,1.0,0.0);
    glColor3f(0.0f,0.0f,0.0f);
    glViewport (0.0, 0.0, screenHeight, screenWidth);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);

    //glMatrixMode (GL_MODELVIEW);

}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINE_LOOP);
    int r = 100;
    int x = 240, y = 320;
    for (int i = 0; i < 6; i++){
        glVertex2i(x + r * cos(M_PI*i/3), y + r * sin(M_PI*i/3));
    }
    glEnd();
    glFlush();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(screenWidth,screenHeight);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Hexagon");
    glutDisplayFunc(display);
    myInit();
    glutMainLoop();
}

#include <math.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <iostream>


int screenHeight = 480, screenWidth = 640;
int interval = 1000/60;
int score_left = 0;
int score_right = 0;

// rackets in general
int paddle_width = 10;
int paddle_height = 80;
int paddle_speed = 10;

// left racket position
float paddle_left_x = 10.0f;
float paddle_left_y = 50.0f;

// right racket position
float paddle_right_x = screenWidth - paddle_width - 10;
float paddle_right_y = 50;

float ball_pos_x = screenWidth / 2;
float ball_pos_y = screenHeight / 2;
float ball_dir_x = 0.0f;
float ball_dir_y = 1.0f;
int ball_size = 10;
int ball_speed = 2;

void update_ball(){
  ball_pos_x += ball_dir_x * ball_speed;
  ball_pos_y += ball_dir_y * ball_speed;
}

void draw_paddle(float x, float y, float width, float height) {
    glBegin(GL_QUADS);
        glVertex2f(x, y);
        glVertex2f(x + width, y);
        glVertex2f(x + width, y + height);
        glVertex2f(x, y + height);
    glEnd();
}

void print(int x, int y, char *string)
{
  glRasterPos2f(x,y);
  int len = (int) strlen(string);

  for (int i = 0; i < len; i++)
  {
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,string[i]);
  }
};

void myInit(void){
    glViewport(0, 0, screenWidth, screenHeight);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0f, screenWidth, 0.0f, screenHeight, 0.0f, 1.0f);
    glMatrixMode (GL_MODELVIEW);
    glLoadIdentity();

    //glMatrixMode (GL_MODELVIEW);


}
void keyboard(unsigned char Key, int x, int y) {
    switch(Key){
      case 'w': paddle_left_y += paddle_speed;break;
      case 's': paddle_left_y -= paddle_speed;break;

      //case 'i': paddle_right_y += paddle_speed;break;
      //case 'k': paddle_right_y -= paddle_speed;break;
    }
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    draw_paddle(paddle_left_x, paddle_left_y, paddle_width, paddle_height);
    draw_paddle(paddle_right_x, paddle_right_y, paddle_width, paddle_height);

    draw_paddle(ball_pos_x - ball_size / 2, ball_pos_y - ball_size / 2, ball_size, ball_size);

    print(screenWidth / 2 - 120, screenHeight - 30, "The best Pong game ever");

    glutSwapBuffers();
}

void update(int value){
  paddle_right_y = ball_pos_y;
  glutKeyboardFunc(keyboard);
  update_ball();
  glutTimerFunc(interval, update, 0);
  glutPostRedisplay();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(screenWidth,screenHeight);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Pong Game");

    glutDisplayFunc(display);
    glutTimerFunc(interval, update, 0);

    myInit();
    glColor3f(1.0f, 1.0f, 1.0f);

    glutMainLoop();
}

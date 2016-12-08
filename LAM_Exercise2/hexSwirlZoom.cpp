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
	gluOrtho2D(-5.0, 5.0, -5.0, 5.0);
    //glMatrixMode (GL_MODELVIEW);

}

void hexSwirl() {
    glClear (GL_COLOR_BUFFER_BIT);

    const GLfloat radPerDeg = 0.017453393f;
    GLfloat x, y;//, cx, cy;
    GLfloat length = 10.0f;
    GLfloat scale = 0.001f;
    GLfloat theta = 0.0f;
    for( int i = 0; i < 50; i++ ) {
        x = y = 0.0f;
        x -= 11.18034f * sin( radPerDeg * 30.0f );
        y -= 11.18034f * cos( radPerDeg * 30.0f );
        glPushMatrix();
        glScalef( scale, scale, scale );
        glRotatef( theta, 0, 0, 1 );
        theta += 1.5f;
        scale += 0.007f;
        glBegin( GL_LINE_LOOP );
        for(int c = 0; c < 6; c++ ) {
            glVertex2f( x, y );
            x += ( length * cos( radPerDeg * ( c * 60.0f ) ) );
            y += ( length * sin( radPerDeg * ( c * 60.0f ) ) );
        }
        glEnd();
        glPopMatrix();
        //glFlush();
    }
    //glutPostRedisplay();

    glutSwapBuffers();
    //glutPostRedisplay();
        //glFlush();

    glFlush();

}

void zoomIn(){
    float Cx = 0,Cy =0;
    float H,W = 0.8, aspect = 1;
    int frame ;
    for(frame =0;frame <1;frame++)
    	{
    		W *=aspect;
    		H =W*aspect;
    		gluOrtho2D(Cx - W,Cx + W,Cy - H,Cy + H);
    		//hexSwirl();
            glutPostRedisplay();
            //glutSwapBuffers();
    	   }
           //glutSwapBuffers();
           //glutPostRedisplay();
           //glFlush();


}

void zoomOut(){
    float Cx = 0,Cy =0;
	float H,W = 1.2, aspect = 1;
	int frame ;
	for(frame =0;frame <1;frame++)
	{
		W *=aspect;
		H =W*aspect;
		gluOrtho2D(Cx - W,Cx + W,Cy - H,Cy +H);
		//hexSwirl();
        //glutSwapBuffers();
        glutPostRedisplay();
	}
    //glutPostRedisplay();
    //glFlush();
    //glutSwapBuffers();


}

void mouse(int button, int state, int x, int y){
    glClearColor(1.0,1.0,1.0,0.0);

    if ( state == GLUT_DOWN)
    {
        if (button == GLUT_LEFT_BUTTON)
            zoomIn();
        if (button == GLUT_RIGHT_BUTTON)
            zoomOut();
    }
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(screenWidth,screenHeight);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Connect points");
    glutDisplayFunc(hexSwirl);
    glutMouseFunc(mouse);
    myInit();
    glutMainLoop();
}

#include<iostream>
#include<gl\glut.h>
#include<stdlib.h>
int WIDTH = 800;
int HEIGHT = 900;
void Render();
void Reshape(int w,int h);
void SetupViewTransform();
void SetupViewVolume();
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GL_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("CG");
	glutDisplayFunc(Render);
	glutReshapeFunc(Reshape);
	glutMainLoop();
	return 0;
}
void Render()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	SetupViewTransform();
	SetupViewVolume();
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(1.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.0, 560.0, 0.0);
	glVertex3f(0.0, 600.0, 0.0);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(255.0, 600.0, 0.0);
	glVertex3f(255.0, 560.0, 0.0);
	glEnd();
	glPopMatrix();
	glBegin(GL_LINES);
	glVertex3f(50, 50, 0);
	glVertex3f(200, 200, 0);
	glEnd();
	glColor3f(0.0, 0.0, 1.0);
	double t = 0;
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINE_STRIP);
	for (t = 0; t <= 3.1415 * 2; t = t + 6.28 / 100)
		glVertex3f(5 * cos(t), 5 * sin(t), 0.0);
	glEnd();
	glutSwapBuffers();
	

}
void SetupViewTransform()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -10.0);
}
void SetupViewVolume()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 800.0, 0.0, 600.0, -100.0, 100.0);
}
void Reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	WIDTH = w;
	HEIGHT = h;
	
}

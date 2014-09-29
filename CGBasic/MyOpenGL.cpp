#include <iostream>
#include <GL/glut.h>

const int SIZE_X = 640;
const int SIZE_Y = 480;

struct Camera
{
	GLdouble EyeX = 0.0;
	GLdouble EyeY = 0.0;
	GLdouble EyeZ = 0.0;
	GLdouble TarX = 0.0;
	GLdouble TarY = 0.0;
	GLdouble TarZ = 0.0;
};

Camera camera;

int count = 0;

void Init();
void Display();
void Reshape(int w, int h);
void Timer(int v);

void Init(){
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void Display(){
	camera.EyeX = sin(3.14 * 2 / 360 * count) * 10;
	camera.EyeY = sin(3.14 * 2 / 180 * count) * 10;

	glClear(GL_COLOR_BUFFER_BIT);

	glLoadIdentity();
	gluLookAt(
		camera.EyeX, camera.EyeY, 5.0,
		camera.TarX, camera.TarY, camera.TarZ,
		0.0, 1.0, 0.0);

	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.9f, 0.0f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-0.9f, -0.9f, 0.0f);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.9f, -0.9f, 0.0f);
	glEnd();

	glFlush();

	count++;
}

void Reshape(int w, int h){
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(30.0, (double)w / (double)h, 1.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
}

void Timer(int v){
	glutPostRedisplay();
	glutTimerFunc(v, Timer, 30);
}

// -------------------- ÉÅÉCÉìä÷êî --------------------
int main(int argc, char *argv[]){
	glutInit(&argc, argv);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(SIZE_X, SIZE_Y);
	glutInitDisplayMode(GLUT_RGBA);
	glutCreateWindow("My OpenGL");

	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);
	glutTimerFunc(0, Timer, 17);
	Init();
	glutMainLoop();

	return 0;
}
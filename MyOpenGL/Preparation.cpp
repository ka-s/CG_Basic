/// ----------------------------------------
///  CG��b��4��\�K
/// ----------------------------------------

#include <stdio.h>
#include <GL/glut.h>

// ---------- �萔 ----------

// ��ʃT�C�Y
const int SIZE_X = 640;
const int SIZE_Y = 480;
// ��ʏo�����W
const int SPAWN_X = 100;
const int SPAWN_Y = 100;

// ESC�L�[
#define KEY_ESC 27

// ---------- �֐��v���g�錾 ----------

void Display();
void Init(char *progname);
void MyKeyboard(unsigned char key, int x, int y);
void DrawCircle(double x, double y, double r, int accuracy);

// --------------------

// �`��֐�
void Display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
    glTranslatef(0.5f, 0.0f, 0.5f);
    glutSolidTeapot(0.1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.5f, 0.0f, 0.5f);
    glBegin(GL_POINT);
    glVertex3f(0.1f, 0.1f, 0.1f);
    glEnd();
    glPopMatrix();

    glFlush();
}

// �����ݒ�֐�
void Init(char *progname){
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(SIZE_X, SIZE_Y);
    glutInitWindowPosition(SPAWN_X, SPAWN_Y);
    glutCreateWindow(progname);

    // �w�i�F
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutKeyboardFunc(MyKeyboard);

    // �J����
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, SIZE_X/SIZE_Y, 0.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
}

// �L�[�֐�
void MyKeyboard(unsigned char key, int x, int y){
    if (key == KEY_ESC){
        exit(0);
    }
}

// ���C���֐�
int main(int argc, char *argv[]){
    // ��������
    glutInit(&argc, argv);
    Init("CGBasic Subject02");

    // �����C������
    glutDisplayFunc(Display);
    glutMainLoop();

    return 0;
}
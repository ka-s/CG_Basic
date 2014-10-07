/// ----------------------------------------
///  CG��b��3��ۑ�
/// ----------------------------------------

// @date 2014-10-07
// @author Kazuma Ito

#include <stdio.h>
#include <GL/glut.h>

// ---------- �萔 ----------

// ��ʃT�C�Y
const int SIZE_X = 700;
const int SIZE_Y = 500;
// ��ʏo�����W
const int SPAWN_X = 70;
const int SPAWN_Y = 100;

// ESC�L�[
#define KEY_ESC 27

// ---------- �֐��v���g�錾 ----------

void Display();
void Init(char *progname);
void MyKeyboard(unsigned char key, int x, int y);

// --------------------

// �`��֐�
void Display(){
    glClear(GL_COLOR_BUFFER_BIT);

    // �Ԃ��O�p�`
    glColor3d(1.0, 0.0, 0.0);
    glBegin(GL_TRIANGLES);
        glVertex2d(-0.9, 0.9);
        glVertex2d(0.0, 0.0);
        glVertex2d(0.9, 0.9);
    glEnd();

    // �΂̎O�p�`
    glColor3d(0.0, 1.0, 0.0);
    glBegin(GL_TRIANGLES);
        glVertex2d(-0.9, -0.9);
        glVertex2d(0.0, 0.0);
        glVertex2d(0.9, -0.9);
    glEnd();

    glFlush();
}

// �����ݒ�֐�
void Init(char *progname){
    glutInitDisplayMode(GLUT_RGBA);
    glutInitWindowSize(SIZE_X, SIZE_Y);
    glutInitWindowPosition(SPAWN_X, SPAWN_Y);
    glutCreateWindow(progname);
    // �w�i���D�F
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
    glutKeyboardFunc(MyKeyboard);
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
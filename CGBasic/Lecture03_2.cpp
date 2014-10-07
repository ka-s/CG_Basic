/// ----------------------------------------
///  CG��b��3��ǉ��ۑ�
/// ----------------------------------------

// @date 2014-10-07
// @author Kazuma Ito

#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

// ---------- �萔 ----------

// ��ʃT�C�Y
const int SIZE_X = 640;
const int SIZE_Y = 480;
// ��ʏo�����W
const int SPAWN_X = 70;
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
    glClear(GL_COLOR_BUFFER_BIT);

    // �I�����W�F�̎O�p�`8�̉~
    glColor3d(1.0, 0.5, 0.0);
    DrawCircle(-0.5, 0.0, 0.25, 8);

    // ���F�̎O�p�`16�̉~
    glColor3d(1.0, 0.0, 1.0);
    DrawCircle(0.5, 0.0, 0.3, 16);

    glFlush();
}

// �����ݒ�֐�
void Init(char *progname){
    glutInitDisplayMode(GLUT_RGBA);
    glutInitWindowSize(SIZE_X, SIZE_Y);
    glutInitWindowPosition(SPAWN_X, SPAWN_Y);
    glutCreateWindow(progname);
    // �w�i���D�F
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutKeyboardFunc(MyKeyboard);
}

// �L�[�֐�
void MyKeyboard(unsigned char key, int x, int y){
    if (key == KEY_ESC){
        exit(0);
    }
}

// --------------------
//  �~��`�悷��֐�
//  x, y        : ���S���W
//  r           : �~�̔��a
//  accuracy    : �~�̐��x�E�|���S����
// --------------------
void DrawCircle(double x, double y, double r, int accuracy){
    glBegin(GL_TRIANGLES);

    double degree = 360 / (double)accuracy;

    for (int i = 0; i < accuracy; ++i){
        glVertex2d(x, y);
        glVertex2d(
            cos(degree * i * 3.14 / 180) * r + x,
            sin(degree * i * 3.14 / 180) * r + y);
        glVertex2d(
            cos(degree * (i + 1) * 3.14 / 180) * r + x,
            sin(degree * (i + 1) * 3.14 / 180) * r + y);
    }

    glEnd();
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
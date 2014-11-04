/// ================================
///  CG��b��6�񉉏K�ۑ� 
/// ================================

// @date    2014-11-04
// @author  Kazuma Ito

#include <stdlib.h>
#include <GL/glut.h>
#define KEY_ESC 27

// �_�̔z��
double vertex[][3] = {
    { 0.0, 0.0, 0.0 },
    { 1.0, -1.0, 1.0 },
    { 1.0, -1.0, -1.0 },
    { -1.0, -1.0, -1.0 },
    { -1.0, -1.0, 1.0 },
};

// �����̃x�N�g��
int edge[][2] = {
    { 0, 1 },
    { 0, 2 },
    { 0, 3 },
    { 0, 4 },
    { 1, 2 },
    { 2, 3 },
    { 3, 4 },
    { 4, 1 },
};

void myKeyboard(unsigned char key, int x, int y){
    if (key == KEY_ESC)
        exit(0);
}

void xyzAxes(){
    glBegin(GL_LINES);
    glColor3d(1.0, 0.0, 0.0);
    glVertex3d(0.0, 0.0, 0.0);
    glVertex3d(1.0, 0.0, 0.0);

    glColor3d(0.0, 1.0, 0.0);
    glVertex3d(0.0, 0.0, 0.0);
    glVertex3d(0.0, 1.0, 0.0);

    glColor3d(0.0, 0.0, 1.0);
    glVertex3d(0.0, 0.0, 0.0);
    glVertex3d(0.0, 0.0, 1.0);
    glEnd();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    // ���̕`��
    xyzAxes();

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // ���_�Ɛ�������̃s���~�b�h
    glPushMatrix();
    //   �F�͔�
    glColor3d(1.0, 1.0, 1.0);
    //   Y�����ɕ��s�ړ�
    glTranslated(0.0, 1.0, 0.0);
    glBegin(GL_LINES);
    for (int i = 0; i < 8; ++i){
        glVertex3dv(vertex[edge[i][0]]);
        glVertex3dv(vertex[edge[i][1]]);
    }
    glEnd();
    glPopMatrix();

    // ���F�̒��g���l�܂����~��
    glPushMatrix();
    //   �F�͉��F
    glColor3d(1.0, 1.0, 0.0);
    //   X�����ɕ��s�ړ�
    glTranslated(2.0, 0.0, 0.0);
    //   �R�[���̂Ƃ񂪂肪��ɂȂ�悤�ɉ�]
    glRotated(-90, 1.0, 0.0, 0.0);
    glutSolidCone(1.0, 2.0, 16.0, 16.0);
    glPopMatrix();

    // �~���̏�Ɏ��̒��g���l�܂����h�[�i�c�����Ԃ�
    glPushMatrix();
    //   �F�͎�
    glColor3d(0.63, 0.13, 0.94);
    //   �R�[���ɔ��悤�ɕ��s�ړ�
    glTranslated(2.0, 1.5, 0.0);
    //   ����悤�ɉ�]
    glRotated(90, 1.0, 0.0, 0.0);
    //   �k������
    glScaled(0.3, 0.3, 0.3);
    glutSolidTorus(1.0, 4.0, 16.0, 16.0);
    glPopMatrix();

    glDisable(GL_DEPTH_TEST);
    glFlush();
}

void myInit(char *progname){
    int width = 500, height = 500;
    double aspect = (double)width / (double)height;

    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(width, height);
    glutInitWindowPosition(0, 0);
    glutCreateWindow(progname);
    // �w�i�����ɐݒ�
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glutKeyboardFunc(myKeyboard);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, aspect, 1.0, 20.0);
    // �J�����̐ݒ�
    gluLookAt(
        2.0, 4.0, 4.0,
        1.5, 0.0, 0.0, 
        0.0, 1.0, 0.0);
}

int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    myInit(argv[0]);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

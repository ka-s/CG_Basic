#include <GL/glut.h>

//------------ �v���g�^�C�v�錾 -------------------//
void LIGHT_INIT();
void display();
void reshape(int w, int h);
void SetMaterialGold();

//------------- OpenGL�̏����ݒ� --------------//
void GLUT_INIT(){
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Golden Ball");
}

void GLUT_CALL_FUNC(){
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
}


void MY_INIT(){
    glClearColor(1.0, 1.0, 1.0, 1.0);

    LIGHT_INIT();
    glEnable(GL_NORMALIZE);//�@���̗L����
    glEnable(GL_DEPTH_TEST);//Z�o�b�t�@ON
}



//�����̐ݒ�
void LIGHT_INIT(){
    glEnable(GL_LIGHTING);//�����̗L����
    glEnable(GL_LIGHT0);
}


//----------- ���C���֐� --------------//
int main(int argc, char **argv){
    glutInit(&argc, argv);
    GLUT_INIT();
    GLUT_CALL_FUNC();
    MY_INIT();
    glutMainLoop();

    return 0;
}

//------------ ��������e��R�[���o�b�N ---------------//
void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(3.0, 4.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); //���_�̐ݒ�

    static float Light0Pos[] = { 1, 1, 1, 0 }; //�����̈ʒu
    glLightfv(GL_LIGHT0, GL_POSITION, Light0Pos);//�ʒu�����ݒ�(���Ƃ̓f�t�H���g)
    SetMaterialGold(); //�ގ�
    glutSolidSphere(0.5, 60, 60);//���̕`��

    glutSwapBuffers();
}


void reshape(int w, int h){
    glViewport(0, 0, w, h);  //�r���[�|�[�g�̐ݒ�

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30.0, (double)w / (double)h, 1.0, 100.0); //����̐ݒ�

    glMatrixMode(GL_MODELVIEW);
}




//---------- ��������e��֐� ------------//
void SetMaterialGold(){
    static GLfloat gold_amb[] = { 0.24725, 0.1995, 0.0745, 1.0 };
    static GLfloat gold_diff[] = { 0.75164, 0.60648, 0.22648, 1.0 };
    static GLfloat gold_spe[] = { 0.628281, 0.555802, 0.366065, 1.0 };
    static GLfloat gold_shin = 51.2;

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, gold_amb);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, gold_diff);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, gold_spe);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, gold_shin);

}
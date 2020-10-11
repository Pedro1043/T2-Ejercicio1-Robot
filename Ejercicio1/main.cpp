#include <GL/glut.h>

float anguloTronco=0;
float anguloBrazo=0;
float anguloAntebrazo=0;

GLUquadricObj *p = gluNewQuadric();

void inicializar()
{
    glClearColor(0.7,0.7,0.7,0.0);
    glEnable(GL_DEPTH_TEST);
    gluQuadricDrawStyle(p,GLU_LINE);
}

void graficarEjes()
{
    glColor3f(0,0,0);
    glBegin(GL_LINES);
        glColor3f(1,0,0);
        glVertex3f(0,0,0);
        glVertex3f(50,0,0);

        glColor3f(0,1,0);
        glVertex3f(0,0,0);
        glVertex3f(0,50,0);

        glColor3f(0,0,1);
        glVertex3f(0,0,0);
        glVertex3f(0,0,50);
    glEnd();
}

void graficar()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(20,20,20, 0,0,0, 0,1,0);

    graficarEjes();



    glPushMatrix();
        glRotatef(anguloTronco,0,1,0);
        ///tronco
        glColor3f(1,0,0);
        glutWireCube(4);
        glPushMatrix();
            ///cabeza
            glTranslatef(0,3,0);
            glColor3f(1,1,1);
            glutWireSphere(1.5,32,32);
        glPopMatrix();
        glPushMatrix();
            ///BI
            glTranslatef(0,0,2);
            glRotatef(anguloBrazo,0,0,1);
            gluCylinder(p, 1.5, 1.5, 6, 16, 16);
            glPushMatrix();
                ///AI
                glTranslatef(0,0,6);
                glRotatef(anguloAntebrazo,0,1,0);
                glColor3f(0,0,0);
                gluCylinder(p, 1.5, 0.5, 4, 16, 16);
                glPushMatrix();
                    ///D11
                glPopMatrix();
                glPushMatrix();
                    ///D12
                glPopMatrix();
                glPushMatrix();
                    ///D13
                glPopMatrix();
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();



    glutSwapBuffers();
}

void redimensionar(int w, int h)
{
    glViewport(0,0,w,h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0,(float)w/(float)h,1,100);

}


void rotarTronco(int i)
{
    anguloTronco = anguloTronco + 5;
    glutPostRedisplay();
    glutTimerFunc(500,rotarTronco,1);
}

void rotarBrazo(int i)
{
    anguloBrazo = anguloBrazo + 5;
    glutPostRedisplay();
    glutTimerFunc(50,rotarBrazo,2);
}

void rotarAntebrazo(int i)
{
    anguloAntebrazo = anguloAntebrazo + 5;
    glutPostRedisplay();
    glutTimerFunc(250,rotarAntebrazo,3);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600,400);
    glutInitWindowPosition(100,200);
    glutCreateWindow("JLPERALTA");
    inicializar();

    glutDisplayFunc(graficar);
    glutReshapeFunc(redimensionar);
    glutTimerFunc(500,rotarTronco,1);
    glutTimerFunc(50,rotarBrazo,2);
    glutTimerFunc(250,rotarAntebrazo,3);

    glutMainLoop();

    return 0;
}


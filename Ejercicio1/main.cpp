#include <GL/glut.h>

float anguloTronco=0;
float anguloBrazo=0;
float anguloAntebrazo=0;

GLUquadricObj *p = gluNewQuadric();

void inicializar()
{
    glClearColor(0.7,0.7,0.7,0.0);
    glEnable(GL_DEPTH_TEST);
    gluQuadricDrawStyle(p,GLU_FILL);
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
        glColor3f(0,0,0);
        glutSolidSphere(3,32,32);
        glPushMatrix();
            ///cabeza
            glTranslatef(0,4,0);
            glRotatef(90,1,0,0);
            glColor3f(1,0,0); gluCylinder(p, 0.5, 0.5, 2, 16, 16);
        glPopMatrix();

        glPushMatrix();
            ///Conexión BI
            glTranslatef(0,0,2);
            //glRotatef(anguloBrazo,0,0,1);
            glutSolidSphere(1.5,32,32);
            glPushMatrix();
              ///Brazo IZ
              glTranslatef(0,0,1.5);
              glColor3f(0,0,0);
              gluCylinder(p, 0.7, 0.7, 6.0, 16, 16);
                  ///AI
                  glTranslatef(0,0,5.3);
                  glRotatef(anguloAntebrazo,0,1,0);
                  glColor3f(1,0,0);
                  glutSolidCube(1.5);
                  glPushMatrix();
                    ///Brazo IZ2
                  glTranslatef(0,0,0.2);
                  glRotatef(90,0,1,0);
                  glColor3f(0,0,0); gluCylinder(p, 0.5, 0.5, 2.4, 16, 16);
                  glPushMatrix();
                    ///Mano
                   glTranslatef(0,0,4.3);
                   glRotatef(90,1,0,0);
                   glColor3f(1,0,0); glutSolidTorus(0.5,1.5,2,9);
                   glPopMatrix();
                glPopMatrix();
            glPopMatrix();
        glPopMatrix();

        glPushMatrix();
            ///Conexión BD
            glTranslatef(2,0,0);
            //glRotatef(anguloBrazo,0,0,1);
            glutSolidSphere(1.5,32,32);
            glPushMatrix();
              ///Brazo IZ
              glTranslatef(1.5,0,0);
              glRotatef(90,0,1,0);
              glColor3f(0,0,0);
              gluCylinder(p, 0.7, 0.7, 6.0, 16, 16);
                  ///AI
                  glTranslatef(0,0,5.3);
                  glRotatef(anguloAntebrazo,0,1,0);
                  glColor3f(1,0,0);
                  glutSolidCube(1.5);
                  glPushMatrix();
                    ///Brazo IZ2
                  glRotatef(180,0,1,0);
                  glTranslatef(0,0,0.2);
                  glRotatef(90,0,1,0);
                  glColor3f(0,0,0); gluCylinder(p, 0.5, 0.5, 2.4, 16, 16);
                  glPushMatrix();
                    ///Mano
                   glTranslatef(0,0,4.3);
                   glRotatef(90,1,0,0);
                   glColor3f(1,0,0); glutSolidTorus(0.5,1.5,2,9);
                   glPopMatrix();
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
    //anguloTronco = anguloTronco + 5;
    glutPostRedisplay();
    glutTimerFunc(500,rotarTronco,1);
}

void rotarBrazo(int i)
{
    //anguloBrazo = anguloBrazo + 5;
    glutPostRedisplay();
    glutTimerFunc(50,rotarBrazo,2);
}

void rotarAntebrazo(int i)
{
    //anguloAntebrazo = anguloAntebrazo + 5;
    glutPostRedisplay();
    glutTimerFunc(250,rotarAntebrazo,3);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600,400);
    glutInitWindowPosition(100,200);
    glutCreateWindow("Ejercicio");
    inicializar();

    glutDisplayFunc(graficar);
    glutReshapeFunc(redimensionar);
    glutTimerFunc(500,rotarTronco,1);
    glutTimerFunc(50,rotarBrazo,2);
    glutTimerFunc(250,rotarAntebrazo,3);

    glutMainLoop();

    return 0;
}


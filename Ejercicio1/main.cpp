#include <GL/glut.h>

float movX = 0;
float movY = 0;
float movZ = 0;
float cabeza = 0;
float varRotar = 360;

///---------------------------------------------------------------
///PARTE IZQUIERDA


float conexionBi = 360;

float brazoIz = 360;

float brazoIz2 = 360;

///----------------------------------------------------------------
///PARTE DERECHA

float conexionBe = 360;

float brazoDe = 360;

float brazoDe2 = 360;



const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };


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
        glColor3f(0,1,0);
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

    glTranslatef(movX,movY,movZ);
    glRotatef(varRotar,0,1,0);


        ///tronco

        glColor3f(0,0,0); glutSolidSphere(3,32,32);
        glPushMatrix();
            ///cabeza
            glRotatef(cabeza,0,1,0);
            glTranslatef(0,4,0);
            glRotatef(90,1,0,0);
            glColor3f(1,0,0); gluCylinder(p, 0.5, 0.5, 2, 16, 16);
        glPopMatrix();

        glPushMatrix();
            ///Conexión BI
            glRotatef(conexionBi,1,0,0);
            glTranslatef(0,0,2);
            glutSolidSphere(1.5,32,32);
            glPushMatrix();
              ///Brazo IZ
              glRotatef(brazoIz,0,0,1);
              glTranslatef(0,0,1.5);
              glColor3f(0,0,0);
              gluCylinder(p, 0.7, 0.7, 6.0, 16, 16);
                  ///AI
                  glTranslatef(0,0,5.3);

                  glColor3f(1,0,0);
                  glutSolidCube(1.5);
                  glPushMatrix();
                    ///Brazo IZ2
                  glRotatef(brazoIz2,1,0,0);
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
///--------------------------------------------------------------------------------------
        glPushMatrix();
            ///Conexión BD
            glRotatef(conexionBe,0,0,1);
            glTranslatef(2,0,0);
            glutSolidSphere(1.5,32,32);
            glPushMatrix();
              ///Brazo DE
              glRotatef(brazoDe,1,0,0);
              glTranslatef(1.5,0,0);
              glRotatef(90,0,1,0);
              glColor3f(0,0,0);
              gluCylinder(p, 0.7, 0.7, 6.0, 16, 16);
                  ///AD
                  glTranslatef(0,0,5.3);

                  glColor3f(1,0,0);
                  glutSolidCube(1.5);
                  glPushMatrix();
                    ///Brazo DE2
                  glRotatef(brazoDe2,1,0,0);
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

static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 'w' :
            movX++;
            movZ++;
        break;
        case 's' :
            movX--;
            movZ--;
        break;
        case 'q' :
            movY++;
        break;
        case 'e' :
            movY--;
        break;
        case 'a' :
            varRotar+=2.5;
        break;
        case 'd' :
            varRotar-=2.5;
        break;

        case '7':
            cabeza+=5;
        break;

        case '8':
            conexionBi-=5;
        break;

        case '9':
            conexionBi+=5;
        break;

        case '4':
            brazoIz+=5;
        break;

        case '5':
            brazoIz-=5;
        break;

        case '6':
            brazoIz2+=5;
        break;

        case '1':
            brazoIz2-=5;
        break;

        ///------------------------------------------------------------------------------------------------------------------------

        case 'r':
            conexionBe+=5;
        break;

        case 't':
            conexionBe-=5;
        break;

        case 'y':
            brazoDe+=5;
        break;

        case 'u':
            brazoDe-=5;
        break;

        case 'i':
            brazoDe2+=5;
        break;

        case 'o':
            brazoDe2-=5;
        break;
    }
    glutPostRedisplay();
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
    glutKeyboardFunc(key);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutMainLoop();

    return 0;
}


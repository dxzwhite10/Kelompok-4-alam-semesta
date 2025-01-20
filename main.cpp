#include<GL/glut.h>
#include <math.h>
#include <cstring>

const int numStars = 100; 
float rotationAngle = 0.0;
float rotation =0.0;
float rotationCube = 0.0;
float planetOrbit = 0.0;
float moonOrbit = 0.0;
float rotationX = 0.0f;
float rotationY = 0.0f;
float scale = 1.0f;
float cameraX = 0.0, cameraY = 0.0, cameraZ = 20.0;
float cameraAngleX = 0.0, cameraAngleY = 0.0;
float star[numStars][3];
float lightPos[] = {0.0f, 10.0f, 0.0f, 1.0f}; // posisi cahaya x, y, z, w
float lightPos1[] = {5.0f, 10.0f, 0.0f, 1.0f}; // Posisi cahaya kedua (x, y, z, w)


bool isMoving = true;
bool hidden = false;

void Sphere();
void Muter();
void Tetap(int w, int h);
void drawcartecius();
void Anak();
void hiddenCarte();
void Bintang();
void drawBintang();
void drawText(float x , float y , float z, const char* text, int fontSize);
void keyboard(unsigned char key, int x, int y);

int main (int argc , char**argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//	glutInitWindowSize(800, 800);
//  glutInitWindowPosition(100, 100);
	glutCreateWindow("Kelompok 4");
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, 1.0,1.0,100.0);
	//Display
	glutDisplayFunc(Sphere);
	glutIdleFunc(Muter);
	glutReshapeFunc(Tetap);
	glutKeyboardFunc(keyboard);
	glutFullScreen();
	glutMainLoop();
	return 0;
}
void Sphere()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
    gluLookAt(cameraX, cameraY, cameraZ, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0); // cahaya 1
    glEnable(GL_COLOR_MATERIAL);
    GLfloat ambientLight[] = {0.3f, 0.3f, 0.3f, 1.0f};
    GLfloat diffuseLight[] = {1.0f, 1.0f, 1.0f, 1.0f};

   
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

    // cahaya 2
    glEnable(GL_LIGHT1);
    GLfloat ambientLigh1[] = {0.2f, 0.2f, 0.2f, 1.0f};
    GLfloat diffuseLight1[] = {0.8f, 0.8f, 0.8f, 1.0f};
    glLightfv(GL_LIGHT1, GL_AMBIENT, ambientLight);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuseLight1);
    glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);
    
	drawBintang();	  
	hiddenCarte();
	
	glPushMatrix();
	glColor3ub(236,131,5); // Warna planet utama  (orange)
	glRotatef(rotation += 0.01,0,1,0);
	glRotated(90,1.0,0.0,0.0);
	glutSolidSphere(6.0,20,20);
	
	glPushMatrix();
    glTranslatef(0.0,0.0,-7.0);
    drawText(0.0,0.0,0.0,"Matahari",20);
    glPopMatrix();
    

	glPopMatrix();
	Anak();
	Bintang();
	glutSwapBuffers();
	glutPostRedisplay ();

}
void drawOrbit(float radius, int segments) //pipit
{
    glColor3ub(255, 255, 255); // Warna putih untuk garis orbit
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < segments; i++)
    {
        float angle = 2.0f * M_PI * i / segments; // Sudut tiap segmen
        float x = radius * cos(angle);
        float z = radius * sin(angle);
        glVertex3f(x, 0.0, z);
    }
    glEnd();
}
void Anak() // Oleh pipit
{
  // Planet pertama
  	drawOrbit(8.0, 100);
  	
    glPushMatrix();
    glColor3ub(169, 169, 169); // abu-abu
    glRotatef(planetOrbit, 0.0, 1.0, 0.0);
    glTranslatef(8.0, 0.0, 0.0);
    glRotatef(rotation * 2, 0.0, 1.0, 0.0);
    glutSolidSphere(0.5, 16, 16);
    
    glPushMatrix();
    glTranslatef(0.0,1.0,0.0);
    drawText(0.0,0.0,0.0,"Merkurius",12);
    glPopMatrix();
    
    glPopMatrix();
	
    // Planet kedua
    drawOrbit(10.0, 100);
    
    glPushMatrix();
    glColor3ub(233, 223, 196); // Warna krem
    glRotatef(planetOrbit + 120, 0.0, 1.0, 0.0); // Rotasi dengan offset 120 derajat
    glTranslatef(8.0, 0.0, 0.0); // posisi planet
    glRotatef(rotation * 45, 0.0, 1.0, 0.0);
    glutSolidSphere(0.9, 20, 20);
    
    glPushMatrix();
    glTranslatef(0.0,1.2,0.0);
    drawText(0.0,0.0,0.0,"venus",12);
    glPopMatrix();
    
    glPopMatrix();

    // Planet ketiga
    drawOrbit(12.0, 100);
    
    glPushMatrix();
    glColor3ub(0, 0, 255); // Warna biru
    glRotatef(planetOrbit + 90, 0.0, 1.0, 0.0); // Rotasi dengan offset 240 derajat
    glTranslatef(10.0, 0.0, 0.0); // Orbit lebih jauh
    glRotatef(rotation * 12.0, 0.0, 1.0, 0.0);
    glutSolidSphere(1.0, 20, 20);
    
    glPushMatrix();
    glTranslatef(0.0,1.5,0.0);
    drawText(0.0,0.0,0.0,"Bumi",12);
    glPopMatrix();
    
    glPushMatrix();
    glColor3ub(200,200,200);
    glRotatef(moonOrbit,0.0,0.1,0.0);
    glTranslatef(3.0,0.0,1.5);
    drawText(0.0,0.0,0.0,"Bulan",12);
    glutSolidSphere(0.3,16,16);
    glPopMatrix();
    
    glPopMatrix();
    
    // Planet keempat
    drawOrbit(14.0, 100);
    
    glPushMatrix();
    glColor3ub(255, 69, 0); // Warna (Merah)
    glRotatef(planetOrbit + 135, 0.0, 1.0, 0.0);
    glTranslatef(14.0, 0.0, 0.0);
    glRotatef(rotation * 1.2, 0.0, 1.0, 0.0);
    
    glutSolidSphere(0.7, 20, 20);
    
    glPushMatrix();
    glTranslatef(0.0,1.2,0.0);
    drawText(0.0,0.0,0.0,"Mars",12);
    glPopMatrix();
    glPopMatrix();

    // Planet kelima
    drawOrbit(18.0, 100);
    
    glPushMatrix();
    glColor3ub(255, 165, 0); // Warna (oranye)
    glRotatef(planetOrbit + 180, 0.0, 1.0, 0.0);
    glTranslatef(18.0, 0.0, 0.0);
    glRotatef(rotation * 0.5, 0.0, 1.0, 0.0);
    glutSolidSphere(2.0, 25, 25);
    glPushMatrix();
    glTranslatef(0.0,2.2,0.0);
    drawText(0.0,0.0,0.0,"Jupiter",12);
    glPopMatrix();
    glPopMatrix();

    // Planet keenam
    drawOrbit(22.0, 100);
    
    glPushMatrix();
    glColor3ub(210, 180, 140); // Warna (coklat)
    glRotatef(planetOrbit + 255, 0.0, 1.0, 0.0);
    glTranslatef(22.0, 0.0, 0.0);
    glRotatef(rotation * 0.3, 0.0, 1.0, 0.0);
    glutSolidSphere(1.7, 25, 25);
    
    glPushMatrix();//Cicin saturnus
    glColor3ub(169,169,169); 
    glTranslatef(0.0, 0.1, 0.0);
    glutSolidTorus(0.1,2.0,30,30);
    glPopMatrix();
    
    glTranslatef(0.0,0.85,0.0);
    drawText(0.0,0.0,0.0,"Saturnus",12);
    glPopMatrix();
    glPopMatrix();

    // Planet ketujuh
    drawOrbit(26.0, 100);
    
    glPushMatrix();
    glColor3ub(135, 206, 250); // Warna (ungu)
    glRotatef(planetOrbit + 270, 0.0, 1.0, 0.0);
    glTranslatef(26.0, 0.0, 0.0);
    glRotatef(rotation * 0.2, 0.0, 1.0, 0.0);
    glutSolidSphere(1.5, 20, 20);
    glPushMatrix();
    glTranslatef(0.0,2.0,0.0);
    drawText(0.0,0.0,0.0,"Uranus",12);
    glPopMatrix();
    glPopMatrix();
}
void Bintang()
{
    for (int i = 0; i < numStars; ++i)
    {                                              // 100 bintang
        star[i][0] = (rand() % 201 - 100) / 10.0f; // Posisi X acak
        star[i][1] = (rand() % 201 - 100) / 10.0f; // Posisi Y acak
        star[i][2] = (rand() % 201 - 100) / 10.0f; // Posisi Z acak
    }
    glEnd();
}
void drawBintang()
{
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
    glPointSize(2.0); // Ukuran bintang kecil
    glBegin(GL_POINTS);
    glColor3ub(255, 255, 255); // Warna bintang (putih)
    for (int i = 0; i < numStars; ++i)
    {                                                   // 100 bintang
        glVertex3f(star[i][0], star[i][1], star[i][2]); // Posisi bintang
    }
    glEnd();
    glPopMatrix();
}
void Muter()
{
	rotation += 0.05;
	if (rotation > 360.0){
		rotation -= 360.0;
	}
	planetOrbit += 0.02;
    if (planetOrbit > 360.0) {
    	planetOrbit-= 360.0;
	}
	moonOrbit+=0.1;
	if (moonOrbit > 360.0){
		moonOrbit -= 360.0;
	}
        
	glutPostRedisplay();
}
void Tetap(int w, int h) 
{
    
    if (h == 0) h = 1;

    
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (float)w / (float)h, 1.0, 100.0);
}
void drawcartecius()
{
glLineWidth(1.0);
glColor3f(1.0,0.0,0.0);
glBegin(GL_LINES);

glVertex3f(-50.0,0.0,0.0);
glVertex3f(50.0,0.0,0.0);

glVertex3f(0.0,-50.0,0.0);
glVertex3f(0.0,50.0,0.0);

glVertex3f(0.0,0.0,-50.0);
glVertex3f(0.0,0.0,50.0);
glEnd();
}
void keyboard(unsigned char key, int x, int y) 
{
	float step = 0.5;
    switch (key) {
    case 'w':
        cameraZ -= step;
        break;
    case 's':
        cameraZ += step;
        break;
    case 'a':
        cameraX -= step;
        break;
    case 'd':
        cameraX += step;
        break;
    case 'q':
        cameraY += step;
        break;
    case 'e':
        cameraY -= step;
        break;
    case 'c':
        hidden = !hidden;
        break;
    case 27: // ESC untuk keluar
        exit(0);
        break;
    }
    glutPostRedisplay();
    
     }
     
void hiddenCarte()
{
    if (hidden) {
        drawcartecius();
    }
}

void drawText(float x , float y , float z, const char* text, int fontSize)
{
 glColor3ub(0,255,255);
 glPushMatrix();
 glTranslatef(x, y, z);
 glScalef(fontSize/8.0f, fontSize / 13.0f, 1.0f);
 glRasterPos2f(0,0);
 for (const char* c = text; *c != '\0';++c){
 	glutBitmapCharacter(GLUT_BITMAP_8_BY_13, *c);
 }
 glPopMatrix();
 glEnd();
}

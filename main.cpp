#include<GL/glut.h>
#include <math.h>
#include <cstring>

float rotationAngle = 0.0;
float rotation =0.0;
float rotationCube = 0.0;
float planetOrbit = 0.0;
float rotationX = 0.0f;
float rotationY = 0.0f;
float scale = 1.0f;
float cameraX = 0.0, cameraY = 0.0, cameraZ = 20.0;
float cameraAngleX = 0.0, cameraAngleY = 0.0;


bool isMoving = true;
bool hidden = false;

void Sphere();
void Muter();
void Tetap(int w, int h);
void drawcartecius();
void Anak();
void astronout();
void hiddenCarte();
void Bintang();
void drawText(float x , float y , float z, const char* text, int fontSize);
void keyboard(unsigned char key, int x, int y);
//Kalo ada referensi di AI jangan langsung di masukan 
//ke kodingan secara langsung.intinya jangan sampe mengubah 
//kodingan sebelum nya.

int main (int argc , char**argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 100);
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
	//glutFullScreen();
	glutMainLoop();
	return 0;
}
void Sphere()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	hiddenCarte();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
    gluLookAt(cameraX, cameraY, cameraZ, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
			  
	
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
void Anak() // Oleh pipit
{
  // Planet pertama
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
    glPushMatrix();
    glColor3ub(233, 223, 196); // Warna krem
    glRotatef(planetOrbit + 120, 0.0, 1.0, 0.0); // Rotasi dengan offset 120 derajat
    glTranslatef(8.0, 0.0, 0.0); // Orbit lebih jauh
    glRotatef(rotation * 45, 0.0, 1.0, 0.0);
    glutSolidSphere(0.9, 20, 20);
    
    glPushMatrix();
    glTranslatef(0.0,1.2,0.0);
    drawText(0.0,0.0,0.0,"venus",12);
    glPopMatrix();
    
    glPopMatrix();

    // Planet ketiga
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
    
    glPopMatrix();
    
    // Planet keempat
    glPushMatrix();
    glColor3ub(255, 69, 0); // Warna planet keempat (Merah)
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
    glPushMatrix();
    glColor3ub(255, 165, 0); // Warna planet kelima (oranye)
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
    glPushMatrix();
    glColor3ub(210, 180, 140); // Warna planet keenam (coklat)
    glRotatef(planetOrbit + 255, 0.0, 1.0, 0.0);
    glTranslatef(22.0, 0.0, 0.0);
    glRotatef(rotation * 0.3, 0.0, 1.0, 0.0);
    glutSolidSphere(1.7, 25, 25);
    
    glPushMatrix();//Cicin saturnus
    glColor3ub(169,169,169);
    glutSolidTorus(0.1,2.0,30,30);
    glPopMatrix();
    
    glTranslatef(0.0,0.85,0.0);
    drawText(0.0,0.0,0.0,"Saturnus",12);
    glPopMatrix();
    glPopMatrix();

    // Planet ketujuh
    glPushMatrix();
    glColor3ub(135, 206, 250); // Warna planet ketujuh (ungu)
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
	  glPointSize(2.0); // Ukuran bintang kecil
    glBegin(GL_POINTS);
    glColor3ub(255, 255, 255); // Warna bintang (putih)
    for (int i = 0; i < 100; ++i) { // 100 bintang
        float x = (rand() % 100 - 50) / 2.0f; // Posisi X acak
        float y = (rand() % 100 - 50) / 2.0f; // Posisi Y acak
        float z = (rand() % 100 - 50) / 2.0f; // Posisi Z acak
        glVertex3f(x, y, z);
    }
    glEnd();
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
void astronout()
{
glColor3f(1.0, 1.0, 1.0); // white color for helmet 
glBegin(GL_POLYGON);     
for (int i = 0; i < 360; i++) {
    float angle = i * 3.14159 / 180; // Convert degrees to radians
    glVertex2f(0.1 * cos(angle), 0.1 * sin(angle)); // circle with radius 0.1
}
glEnd();

// Draw body (torso)
glColor3f(0.0, 0.0, 0.0); // black color for body
glLineWidth(5);

// Draw torso
glBegin(GL_LINES);
glVertex2f(0.0, 0.1); // start at the bottom of the helmet
glVertex2f(0.0, -0.4); // body goes down
glEnd(); 

// Draw right arm
glBegin(GL_LINES);
glVertex2f(0.0, 0.0); // torso connection point
glVertex2f(0.3, -0.1); // right arm
glEnd();

// Draw left arm
glBegin(GL_LINES);
glVertex2f(0.0, 0.0); // torso connection point
glVertex2f(-0.3, -0.1); // left arm 
glEnd();	
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


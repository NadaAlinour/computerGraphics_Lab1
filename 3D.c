#include <gl/freeglut.h>
#include <stdio.h>

/*struct Coordinates {
	float x, y;
};

struct Character {
	int isLineStrip;
	int isLineLoop;
	struct Coordinates coordinatesArray[10];
	int coordinatesCount;
	float xPos, yPos;
};

struct Character charArray[50];
int charCount = 0;*/


void keyboard3(unsigned char key, int x, int y) {

	printf("key pressed: %d\n", key);
	glutPostRedisplay();
}

void display3DKeyboard() {
	//glClear(GL_COLOR_BUFFER_BIT);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	glColor3f(0.0f, 0.0f, 0.0f);

	float z = 1.0;
	float y = 0.8;
	float x = 0.5;

	glBegin(GL_QUADS);
	glVertex3f(0.0f, 0.0f, 0.0f);    // Vertex 1
	glVertex3f(1.0f, 0.0f, 0.0f);    // Vertex 2
	glVertex3f(0.5f, 1.0f, 0.0f);    // Vertex 3
	glEnd();

	// glFlush();
	glMatrixMode(GL_MODELVIEW);
	glutSwapBuffers();
	printf("exist display function\n");
}


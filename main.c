#include <gl/freeglut.h>
#include <stdio.h>

// create structs

struct Coordinates {
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
int charCount = 0;

/*float lineColor[3] = {1.0f, 0.0f, 0.0f};
int isN = 1;
int isA = 0;*/

void keyboard(unsigned char key, int x, int y) {

	printf("key pressed: %d\n", key);

	switch (key)
	{

	case 'a': case 'A':
		charArray[charCount].isLineStrip = 0;
		charArray[charCount].coordinatesCount = 6;

		charArray[charCount].coordinatesArray[0].x = -0.5;
		charArray[charCount].coordinatesArray[0].y = -0.5;
		charArray[charCount].coordinatesArray[1].x = 0.0;
		charArray[charCount].coordinatesArray[1].y = 0.5;
		charArray[charCount].coordinatesArray[2].x = 0.0;
		charArray[charCount].coordinatesArray[2].y = 0.5;
		charArray[charCount].coordinatesArray[3].x = 0.5;
		charArray[charCount].coordinatesArray[3].y = -0.5;
		charArray[charCount].coordinatesArray[4].x = -0.25;
		charArray[charCount].coordinatesArray[4].y = 0.0;
		charArray[charCount].coordinatesArray[5].x = 0.25;
		charArray[charCount].coordinatesArray[5].y = 0.0;

		if (charCount == 0) {
			charArray[charCount].xPos = -14.0;
			charArray[charCount].yPos = -14.0;
		}
		else {
			charArray[charCount].xPos = 2.0 + charArray[charCount - 1].xPos;
			charArray[charCount].yPos = -14.0;
		}
		charCount++;
		break;

	case 'c': case 'C':
		charArray[charCount].isLineStrip = 1;
		charArray[charCount].coordinatesCount = 4;

		charArray[charCount].coordinatesArray[0].x = 0.5;
		charArray[charCount].coordinatesArray[0].y = 0.5;
		charArray[charCount].coordinatesArray[1].x = -0.5;
		charArray[charCount].coordinatesArray[1].y = 0.5;
		charArray[charCount].coordinatesArray[2].x = -0.5;
		charArray[charCount].coordinatesArray[2].y = -0.5;
		charArray[charCount].coordinatesArray[3].x = 0.5;
		charArray[charCount].coordinatesArray[3].y = -0.5;
		

		if (charCount == 0) {
			charArray[charCount].xPos = -14.0;
			charArray[charCount].yPos = -14.0;
		}
		else {
			charArray[charCount].xPos = 2.0 + charArray[charCount - 1].xPos;
			charArray[charCount].yPos = -14.0;
		}
		charCount++;
		break;

	case 'i': case 'I':
		charArray[charCount].isLineStrip = 0;
		charArray[charCount].coordinatesCount = 6;

		charArray[charCount].coordinatesArray[0].x = -0.5;
		charArray[charCount].coordinatesArray[0].y = 0.5;
		charArray[charCount].coordinatesArray[1].x = 0.5;
		charArray[charCount].coordinatesArray[1].y = 0.5;
		charArray[charCount].coordinatesArray[2].x = -0.5;
		charArray[charCount].coordinatesArray[2].y = -0.5;
		charArray[charCount].coordinatesArray[3].x = 0.5;
		charArray[charCount].coordinatesArray[3].y = -0.5;
		charArray[charCount].coordinatesArray[4].x = 0.0;
		charArray[charCount].coordinatesArray[4].y = 0.5;
		charArray[charCount].coordinatesArray[5].x = 0.0;
		charArray[charCount].coordinatesArray[5].y = -0.5;

		if (charCount == 0) {
			charArray[charCount].xPos = -14.0;
			charArray[charCount].yPos = -14.0;
		}
		else {
			charArray[charCount].xPos = 2.0 + charArray[charCount - 1].xPos;
			charArray[charCount].yPos = -14.0;
		}
		charCount++;
		break;

	case 'h': case 'H':
		charArray[charCount].isLineStrip = 0;
		charArray[charCount].coordinatesCount = 6;

		charArray[charCount].coordinatesArray[0].x = -0.5;
		charArray[charCount].coordinatesArray[0].y = -0.5;
		charArray[charCount].coordinatesArray[1].x = -0.5;
		charArray[charCount].coordinatesArray[1].y = 0.5;
		charArray[charCount].coordinatesArray[2].x = -0.5;
		charArray[charCount].coordinatesArray[2].y = 0.0;
		charArray[charCount].coordinatesArray[3].x = 0.5;
		charArray[charCount].coordinatesArray[3].y = 0.0;
		charArray[charCount].coordinatesArray[4].x = 0.5;
		charArray[charCount].coordinatesArray[4].y = -0.5;
		charArray[charCount].coordinatesArray[5].x = 0.5;
		charArray[charCount].coordinatesArray[5].y = 0.5;

		if (charCount == 0) {
			charArray[charCount].xPos = -14.0;
			charArray[charCount].yPos = -14.0;
		}
		else {
			charArray[charCount].xPos = 2.0 + charArray[charCount - 1].xPos;
			charArray[charCount].yPos = -14.0;
		}
		charCount++;
		break;

	case 'l': case 'L':
		charArray[charCount].isLineStrip = 1;
		charArray[charCount].coordinatesCount = 3;

		charArray[charCount].coordinatesArray[0].x = -0.5;
		charArray[charCount].coordinatesArray[0].y = 1.0;
		charArray[charCount].coordinatesArray[1].x = -0.5;
		charArray[charCount].coordinatesArray[1].y = -0.5;
		charArray[charCount].coordinatesArray[2].x = 0.5;
		charArray[charCount].coordinatesArray[2].y = -0.5;


		if (charCount == 0) {
			charArray[charCount].xPos = -14.0;
			charArray[charCount].yPos = -14.0;
		}
		else {
			charArray[charCount].xPos = 2.0 + charArray[charCount - 1].xPos;
			charArray[charCount].yPos = -14.0;
		}

		charCount++;
		break;

	case 'm': case 'M':
		charArray[charCount].isLineStrip = 1;
		charArray[charCount].coordinatesCount = 5;

		charArray[charCount].coordinatesArray[0].x = -0.5;
		charArray[charCount].coordinatesArray[0].y = -0.5;
		charArray[charCount].coordinatesArray[1].x = -0.5;
		charArray[charCount].coordinatesArray[1].y = 0.5;
		charArray[charCount].coordinatesArray[2].x = 0.0;
		charArray[charCount].coordinatesArray[2].y = 0.0;
		charArray[charCount].coordinatesArray[3].x = 0.5;
		charArray[charCount].coordinatesArray[3].y = 0.5;
		charArray[charCount].coordinatesArray[4].x = 0.5;
		charArray[charCount].coordinatesArray[4].y = -0.5;

		if (charCount == 0) {
			charArray[charCount].xPos = -14.0;
			charArray[charCount].yPos = -14.0;
		}
		else {
			charArray[charCount].xPos = 2.0 + charArray[charCount - 1].xPos;
			charArray[charCount].yPos = -14.0;
		}

		charCount++;
		break;

	case 'n': case 'N':
		charArray[charCount].isLineStrip = 1;
		charArray[charCount].coordinatesCount = 4;

		charArray[charCount].coordinatesArray[0].x = -0.5;
		charArray[charCount].coordinatesArray[0].y = -0.5;
		charArray[charCount].coordinatesArray[1].x = -0.5;
		charArray[charCount].coordinatesArray[1].y = 0.5;
		charArray[charCount].coordinatesArray[2].x = 0.5;
		charArray[charCount].coordinatesArray[2].y = -0.5;
		charArray[charCount].coordinatesArray[3].x = 0.5;
		charArray[charCount].coordinatesArray[3].y = 0.5;

		if (charCount == 0) {
			charArray[charCount].xPos = -14.0;
			charArray[charCount].yPos = -14.0;
		}
		else {
			charArray[charCount].xPos = 2.0 + charArray[charCount - 1].xPos;
			charArray[charCount].yPos = -14.0 + charArray[charCount - 1].yPos;
		}

		charCount++;
		break;

		// circle thingy
		// make it into a circle thingy
	case 'o': case 'O':
		charArray[charCount].isLineLoop = 1;
		charArray[charCount].coordinatesCount = 4;

		charArray[charCount].coordinatesArray[0].x = -0.5;
		charArray[charCount].coordinatesArray[0].y = 0.5;
		charArray[charCount].coordinatesArray[1].x = 0.5;
		charArray[charCount].coordinatesArray[1].y = 0.5;
		charArray[charCount].coordinatesArray[2].x = 0.5;
		charArray[charCount].coordinatesArray[2].y = -0.5;
		charArray[charCount].coordinatesArray[3].x = -0.5;
		charArray[charCount].coordinatesArray[3].y = -0.5;
	

		if (charCount == 0) {
			charArray[charCount].xPos = -14.0;
			charArray[charCount].yPos = -14.0;
		}
		else {
			charArray[charCount].xPos = 2.0 + charArray[charCount - 1].xPos;
			charArray[charCount].yPos = -14.0;
		}
		charCount++;
		break;

	

	case 'r': case 'R':
		charArray[charCount].isLineStrip = 1;
		charArray[charCount].coordinatesCount = 6;

		charArray[charCount].coordinatesArray[0].x = -0.5;
		charArray[charCount].coordinatesArray[0].y = -0.5;
		charArray[charCount].coordinatesArray[1].x = -0.5;
		charArray[charCount].coordinatesArray[1].y = 0.5;
		charArray[charCount].coordinatesArray[2].x = 0.5;
		charArray[charCount].coordinatesArray[2].y = 0.5;
		charArray[charCount].coordinatesArray[3].x = 0.5;
		charArray[charCount].coordinatesArray[3].y = 0.0;
		charArray[charCount].coordinatesArray[4].x = -0.5;
		charArray[charCount].coordinatesArray[4].y = 0.0;
		charArray[charCount].coordinatesArray[5].x = 0.5;
		charArray[charCount].coordinatesArray[5].y = -0.5;

		if (charCount == 0) {
			charArray[charCount].xPos = -14.0;
			charArray[charCount].yPos = -14.0;
		}
		else {
			charArray[charCount].xPos = 2.0 + charArray[charCount - 1].xPos;
			charArray[charCount].yPos = -14.0;
		}
		charCount++;
		break;

	case 's': case 'S':
		charArray[charCount].isLineStrip = 1;
		charArray[charCount].coordinatesCount = 6;

		charArray[charCount].coordinatesArray[0].x = -0.5;
		charArray[charCount].coordinatesArray[0].y = -0.5;
		charArray[charCount].coordinatesArray[1].x = 0.5;
		charArray[charCount].coordinatesArray[1].y = -0.5;
		charArray[charCount].coordinatesArray[2].x = 0.5;
		charArray[charCount].coordinatesArray[2].y = 0.0;
		charArray[charCount].coordinatesArray[3].x = -0.5;
		charArray[charCount].coordinatesArray[3].y = 0.0;
		charArray[charCount].coordinatesArray[4].x = -0.5;
		charArray[charCount].coordinatesArray[4].y = 0.5;
		charArray[charCount].coordinatesArray[5].x = 0.5;
		charArray[charCount].coordinatesArray[5].y = 0.5;


		if (charCount == 0) {
			charArray[charCount].xPos = -14.0;
			charArray[charCount].yPos = -14.0;
		}
		else {
			charArray[charCount].xPos = 2.0 + charArray[charCount - 1].xPos;
			charArray[charCount].yPos = -14.0;
		}

		charCount++;
		break;

	case 't': case 'T':
		charArray[charCount].isLineStrip = 0;
		charArray[charCount].coordinatesCount = 4;

		charArray[charCount].coordinatesArray[0].x = -0.5;
		charArray[charCount].coordinatesArray[0].y = 0.5;
		charArray[charCount].coordinatesArray[1].x = 0.5;
		charArray[charCount].coordinatesArray[1].y = 0.5;
		charArray[charCount].coordinatesArray[2].x = 0.0;
		charArray[charCount].coordinatesArray[2].y = 0.5;
		charArray[charCount].coordinatesArray[3].x = 0.0;
		charArray[charCount].coordinatesArray[3].y = -0.5;
	

		if (charCount == 0) {
			charArray[charCount].xPos = -14.0;
			charArray[charCount].yPos = -14.0;
		}
		else {
			charArray[charCount].xPos = 2.0 + charArray[charCount - 1].xPos;
			charArray[charCount].yPos = -14.0;
		}

		charCount++;
		break;

	case 'v': case 'V':
		charArray[charCount].isLineStrip = 1;
		charArray[charCount].coordinatesCount = 3;

		charArray[charCount].coordinatesArray[0].x = -0.5;
		charArray[charCount].coordinatesArray[0].y = 0.5;
		charArray[charCount].coordinatesArray[1].x = 0.0;
		charArray[charCount].coordinatesArray[1].y = -0.5;
		charArray[charCount].coordinatesArray[2].x = 0.5;
		charArray[charCount].coordinatesArray[2].y = 0.5;
		

		if (charCount == 0) {
			charArray[charCount].xPos = -14.0;
			charArray[charCount].yPos = -14.0;
		}
		else {
			charArray[charCount].xPos = 2.0 + charArray[charCount - 1].xPos;
			charArray[charCount].yPos = -14.0;
		}

		charCount++;
		break;

	case 'x': case 'X':
		charArray[charCount].isLineStrip = 0;
		charArray[charCount].coordinatesCount = 4;

		charArray[charCount].coordinatesArray[0].x = -0.5;
		charArray[charCount].coordinatesArray[0].y = 0.5;
		charArray[charCount].coordinatesArray[1].x = 0.5;
		charArray[charCount].coordinatesArray[1].y = -0.5;
		charArray[charCount].coordinatesArray[2].x = -0.5;
		charArray[charCount].coordinatesArray[2].y = -0.5;
		charArray[charCount].coordinatesArray[3].x = 0.5;
		charArray[charCount].coordinatesArray[3].y = 0.5;

		if (charCount == 0) {
			charArray[charCount].xPos = -14.0;
			charArray[charCount].yPos = -14.0;
		}
		else {
			charArray[charCount].xPos = 2.0 + charArray[charCount - 1].xPos;
			charArray[charCount].yPos = -14.0;
		}

		charCount++;
		break;

	case 'w': case 'W':
		charArray[charCount].isLineStrip = 1;
		charArray[charCount].coordinatesCount = 5;

		charArray[charCount].coordinatesArray[0].x = -0.5;
		charArray[charCount].coordinatesArray[0].y = 0.5;
		charArray[charCount].coordinatesArray[1].x = -0.25;
		charArray[charCount].coordinatesArray[1].y = -0.5;
		charArray[charCount].coordinatesArray[2].x = 0.0;
		charArray[charCount].coordinatesArray[2].y = 0.0;
		charArray[charCount].coordinatesArray[3].x = 0.25;
		charArray[charCount].coordinatesArray[3].y = -0.5;
		charArray[charCount].coordinatesArray[4].x = 0.5;
		charArray[charCount].coordinatesArray[4].y = 0.5;

		if (charCount == 0) {
			charArray[charCount].xPos = -14.0;
			charArray[charCount].yPos = -14.0;
		}
		else {
			charArray[charCount].xPos = 2.0 + charArray[charCount - 1].xPos;
			charArray[charCount].yPos = -14.0;
		}

		charCount++;
		break;

	case 'y': case 'Y':
		charArray[charCount].isLineStrip = 0;
		charArray[charCount].coordinatesCount = 6;

		charArray[charCount].coordinatesArray[0].x = -0.5;
		charArray[charCount].coordinatesArray[0].y = 0.5;
		charArray[charCount].coordinatesArray[1].x = 0.0;
		charArray[charCount].coordinatesArray[1].y = 0.0;
		charArray[charCount].coordinatesArray[2].x = 0.0;
		charArray[charCount].coordinatesArray[2].y = 0.0;
		charArray[charCount].coordinatesArray[3].x = 0.5;
		charArray[charCount].coordinatesArray[3].y = 0.5;
		charArray[charCount].coordinatesArray[4].x = 0.0;
		charArray[charCount].coordinatesArray[4].y = 0.0;
		charArray[charCount].coordinatesArray[4].y = 0.0;
		charArray[charCount].coordinatesArray[4].y = -0.5;


		if (charCount == 0) {
			charArray[charCount].xPos = -14.0;
			charArray[charCount].yPos = -14.0;
		}
		else {
			charArray[charCount].xPos = 2.0 + charArray[charCount - 1].xPos;
			charArray[charCount].yPos = -14.0;
		}

		charCount++;
		break;

	case 'z': case 'Z':
		charArray[charCount].isLineStrip = 1;
		charArray[charCount].coordinatesCount = 4;

		charArray[charCount].coordinatesArray[0].x = -0.5;
		charArray[charCount].coordinatesArray[0].y = 0.5;
		charArray[charCount].coordinatesArray[1].x = 0.5;
		charArray[charCount].coordinatesArray[1].y = 0.5;
		charArray[charCount].coordinatesArray[2].x = -0.5;
		charArray[charCount].coordinatesArray[2].y = -0.5;
		charArray[charCount].coordinatesArray[3].x = 0.5;
		charArray[charCount].coordinatesArray[3].y = -0.5;

		if (charCount == 0) {
			charArray[charCount].xPos = -14.0;
			charArray[charCount].yPos = -14.0;
		}
		else {
			charArray[charCount].xPos = 2.0 + charArray[charCount - 1].xPos;
			charArray[charCount].yPos = -14.0;
		}

		charCount++;
		break;

	
	case 8:
		if (charCount > 0) {
			charCount--;
		}
		break;

	default: printf("Non-handled key pressed.\n");

	}


	printf("array count: %d\n", charCount);
	GLenum error = glGetError();
	printf("OpenGL Error: %d\n", error);


	glutPostRedisplay();
}

void display() {
	//glClear(GL_COLOR_BUFFER_BIT);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	glColor3f(0.0f, 0.0f, 0.0f);


	if (charCount > 0) {
		printf("char array count in display func: %d\n", charCount);

		for (int i = 0; i < charCount; i++) {
			printf("i: %d\n", i);
			if (charArray[i].isLineStrip == 1) {
				glBegin(GL_LINE_STRIP);
				for (int j = 0; j < charArray[i].coordinatesCount; j++) {
					glVertex2f(charArray[i].coordinatesArray[j].x + charArray[i].xPos, charArray[i].coordinatesArray[j].y);
				}

				glEnd();
			}
			else if (charArray[i].isLineStrip == 0) {
				glBegin(GL_LINES);
				for (int j = 0; j < charArray[i].coordinatesCount; j++) {
					glVertex2f(charArray[i].coordinatesArray[j].x + charArray[i].xPos, charArray[i].coordinatesArray[j].y);
				
				}

				glEnd();
			}
			else if (charArray[i].isLineLoop == 1) {
				glBegin(GL_LINE_LOOP);
				for (int j = 0; j < charArray[i].coordinatesCount; j++) {
					glVertex2f(charArray[i].coordinatesArray[j].x + charArray[i].xPos, charArray[i].coordinatesArray[j].y);

				}

				glEnd();

			}
		}

	}


	// glFlush();
	glutSwapBuffers();
	printf("exist display function\n");
}

void init() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);  // Set the background color to white
	gluOrtho2D(-15.0, 15.0, -15.0, 15.0);       // Set the coordinate system
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(1000, 400); // has to be called before glutCreateWindow
	glutCreateWindow("Simple Line");
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	init();
	glutMainLoop();

	return 0;
}
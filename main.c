#include <gl/freeglut.h>
#include <stdio.h>


// alphabet stuff 
void displayKeyboard();
void keyboard1(unsigned char key, int x, int y);

// car stuff
void carDisplay();
void carUpdate();
void keyboard2(unsigned char key, int x, int y);



void init() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);  // Set the background color to white
	gluOrtho2D(-15.0, 15.0, -15.0, 15.0);       // Set the coordinate system
}

void openWindow() {

}

int main(int argc, char** argv) {

	// menu
	int mode;
	while (1) {

		// loop not really working cuz program exits when openGL window is closed
		printf("Enter a number to choose mode\n");
		printf("1. Keyboard\n2. Car\n");
		scanf_s("%d", &mode);
		printf("Selected mode: %d\n", mode);

		switch (mode) {
		case 1:
			glutInit(&argc, argv);
			glutInitWindowSize(1200, 1200); // has to be called before glutCreateWindow
			glutCreateWindow("Keyboard");
			glutDisplayFunc(displayKeyboard);
			glutKeyboardFunc(keyboard1);
			init();
			glutMainLoop();
			break;
		case 2:
			glutInit(&argc, argv);
			glutInitWindowSize(750, 750); // has to be called before glutCreateWindow
			glutCreateWindow("Car transformation");
			glutDisplayFunc(carDisplay);
			glutTimerFunc(25, carUpdate, 0);
			glutKeyboardFunc(keyboard2);
			init();
			glutMainLoop();
			break;
		default:
			printf("Non-handled option entered\n");
		}
	}

	/*glutInit(&argc, argv);
	glutInitWindowSize(1000, 400); // has to be called before glutCreateWindow
	glutCreateWindow("Simple Line");
	glutDisplayFunc(displayKeyboard);
	glutKeyboardFunc(keyboard1);
	init();
	glutMainLoop();*/

	return 0;
}
#include <gl/freeglut.h>
#include <stdio.h>


// alphabet
void displayKeyboard();
void keyboard1(unsigned char key, int x, int y);

void display3DKeyboard();
void keyboard3(unsigned char key, int x, int y);

// car
void carDisplay();
void carUpdate();
void keyboard2(unsigned char key, int x, int y);

// chart
void chartDisplay();
void setInputs();





void init() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);  // Set the background color to white
	gluOrtho2D(-15.0, 15.0, -15.0, 15.0);       // Set the coordinate system
}



int main(int argc, char** argv) {

	// menu
	int mode;
	while (1) {

		// loop not really working cuz program exits when openGL window is closed
		printf("Enter a number to choose mode\n");
		printf("1. Keyboard\n2. 3D charactesr\n3. Car\n4. Chart\n");
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
			glutInitWindowSize(600, 600); // has to be called before glutCreateWindow
			glutCreateWindow("3D Keyboard");
			glutDisplayFunc(display3DKeyboard);
			glutKeyboardFunc(keyboard3);
			init();
			glutMainLoop();
			break;

		case 3:
			glutInit(&argc, argv);
			glutInitWindowSize(750, 750); // has to be called before glutCreateWindow
			glutCreateWindow("Car transformation");
			glutDisplayFunc(carDisplay);
			glutTimerFunc(25, carUpdate, 0);
			glutKeyboardFunc(keyboard2);
			init();
			glutMainLoop();
			break;

		case 4:
			setInputs();
			glutInit(&argc, argv);
			glutInitWindowSize(600, 600); // has to be called before glutCreateWindow
			glutCreateWindow("Bar Chart");
			glutDisplayFunc(chartDisplay);
			init();
			glutMainLoop();
			break;
		
		default:
			printf("Non-handled option entered\n");
		}
	}


	return 0;
}
#include <gl/freeglut.h>
#include <stdio.h>


// alphabet
void displayKeyboard();
void keyboard1(unsigned char key, int x, int y);

void display3D();

// car
void carDisplay();
void carUpdate();
void keyboard2(unsigned char key, int x, int y);

// chart
void chartDisplay();
void setInputs();

// graph
void graphDisplay();
void setGraphInputs();

// question 3
void thirdDisplay();
void mouse(int button, int state, int x, int y);
void thirdKeyboard(unsigned char key, int x, int y);




void init() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);  // set the background color to white
	gluOrtho2D(-15.0, 15.0, -15.0, 15.0);       // set the coordinate system
}

void init2() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);  // set the background color to white
	glOrtho(-15.0, 15.0, -15.0, 15.0, 15.0, -15.0);
	//gluOrtho2D(-15.0, 15.0, -15.0, 15.0);       // set the coordinate system


}



int main(int argc, char** argv) {

	// menu
	int mode;
	while (1) {

		// loop not really working cuz program exits when openGL window is closed
		printf("Enter a number to choose mode\n");
		printf("1. Keyboard\n2. 3D characters\n3. Car\n4. Chart\n5. Graph\n6. Question 3\n");
		scanf_s("%d", &mode);
		//printf("Selected mode: %d\n", mode);

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
			glutInitWindowSize(750, 600); // has to be called before glutCreateWindow
			glutCreateWindow("3D Keyboard");
			glEnable(GL_DEPTH_TEST);
			glutDisplayFunc(display3D);
			init2();
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

		case 5:
			setGraphInputs();
			glutInit(&argc, argv);
			glutInitWindowSize(600, 600); // has to be called before glutCreateWindow
			glutCreateWindow("Graph");
			glutDisplayFunc(graphDisplay);
			init();
			glutMainLoop();
			break;

		case 6:
			glutInit(&argc, argv);
			glutInitWindowSize(600, 600); // has to be called before glutCreateWindow
			glutCreateWindow("Question 3");
			glutDisplayFunc(thirdDisplay);
			glutMouseFunc(mouse);
			glutKeyboardFunc(thirdKeyboard);
			init();
			glutMainLoop();
			break;
		
		default:
			printf("Non-handled option entered\n");
		}
	}


	return 0;
}
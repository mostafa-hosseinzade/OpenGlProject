#define NUM_SPHERES      50
static GLfloat yRot = 0.0f;         // Rotation angle for animation

float angle=0.0,deltaAngle = 0.0,ratio;
float x=0.0f,y=0.0f,z=2.0f;
float lx=0.0f,ly=0.0f,lz=-1.0f;
int deltaMove = 0,h,w;
static GLint DL;

void changeSize(int w1, int h1)
	{

	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if(h1 == 0)
		h1 = 1;

	//Very Important: we store w1 and h1 in w , h for next transformations in 
	// SetOrthographicProjection function and others...
	w = w1;
	h = h1;
	ratio = 1.0f * w / h;
	// Reset the coordinate system before modifying
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	// Set the viewport to be the entire window
    glViewport(0, 0, w, h);

	// Set the clipping volume
	gluPerspective(100,ratio,0.1,50);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(x, y, z, 
		      x + lx,y + ly,z + lz,
			  0.0f,1.0f,0.0f);
	}

void SetupRC() {

	glEnable(GL_DEPTH_TEST);
//	createDL();
	// Bluish background
    glClearColor(0.0f, 0.0f, .50f, 1.0f );
         
    // Draw everything as wire frame
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}
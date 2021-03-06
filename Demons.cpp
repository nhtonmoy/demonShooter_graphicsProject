

bool firstDemonLeftMost=false;
bool secondDemonLeftMost=false;
bool firstDemonRightMost=false;
bool secondDemonRightMost=false;


bool isShotLeft1=false;
bool isShotLeft2=false;
bool isShotRight1=false;
bool isShotRight2=false;

bool heatVisionLeft1=false;
bool heatVisionRight1=false;
bool heatVisionLeft2=false;
bool heatVisionRight2=false;

bool isShot=false;


float _angle1 = 90.0f; //Leftward 2 er angle
float _angle2 = 90.0f; //Leftward 1 er angle
float _angle3 = 90.0f; //Rightward 1 er angle
float _angle4 = 90.0f; //Rightward 2 er angle

void updateDemonLeftward1(int value);
void updateDemonLeftward2(int value);
void updateDemonRightward1(int value);
void updateDemonRightward2(int value);

bool isInitiatedLeft1=false;
bool isInitiatedLeft2=false;
bool isInitiatedRight1=false;
bool isInitiatedRight2=false;

void initiateLeft1()
{
    glutTimerFunc(50, updateDemonLeftward1, 0);
    isInitiatedLeft1=true;
}

void initiateLeft2()
{
    glutTimerFunc(50, updateDemonLeftward2, 0);
    isInitiatedLeft2=true;
}

void initiateRight1()
{
    glutTimerFunc(50, updateDemonRightward1, 0);
    isInitiatedRight1=true;
}

void initiateRight2()
{
    glutTimerFunc(50, updateDemonRightward2, 0);
    isInitiatedRight2=true;
}

int rotateCount=0;
int rotateCountLeftward1=0;
int rotateCountRightward1=0;
int rotateCountRightward2=0;
//Initializes 3D rendering
void initRendering() {
	glEnable(GL_DEPTH_TEST);
}
//Called when the window is resized
void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}


//float _move = 0.0f;

void drawDemonLeftward1() {

    if(!isInitiatedLeft1)
    {
        initiateLeft1();
    }
    //glutTimerFunc(50, updateDemons, 0);

	glPushMatrix();
	glRotatef(_angle2, 0.0, 0.0, 1.0);
	glTranslatef(0.41, .7, 0.0);


	glBegin(GL_POLYGON); //gola
        glColor3f(1.0,1.0,0.7);
        glVertex2f(-.15,-.05);
        glVertex2f(-.15,.04);
        glVertex2f(.05,.04);
        glVertex2f(.05,-.05);
	glEnd();

	glBegin(GL_POLYGON); //body
        glColor3f(1.0,0.0,0.7);
        glVertex2f(-.4,-.1);
        glVertex2f(-.4,.1);
        glVertex2f(-.15,.1);
        glVertex2f(-.15,-.1);
	glEnd();

	glBegin(GL_POLYGON); //matha
	glColor3f(1.0,1.0,0.0);
	for(int i=0;i<50;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50 ;
		float r=0.1;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();

	glBegin(GL_POLYGON); //chokh
        glColor3f(0.0,1.0,1.0);
        glVertex2f(.01,.035);
        glVertex2f(.02,.025);
        glVertex2f(.03,.035);
        glVertex2f(.03,.065);
        glVertex2f(.02,.075);
        glVertex2f(.01,.065);

	glEnd();

    glPopMatrix();

	glutSwapBuffers();
	//glutTimerFunc(25, updateDemons, 0);
}

void updateDemonLeftward1(int value) { //ei method ta leftward 1 ke update korbe

    //isShotLeft1=true;
    //rotateCount=1;
    if(!isGameOver)
    {
        bool isRightMost=false;
        bool isLeftMost=false;

        if (_angle2 > 105) {
            rotateCountLeftward1=0;
            isLeftMost=true;
            firstDemonLeftMost=true;
            //glutTimerFunc(2500,update,0);
        }
        else if(_angle2 < 90){
            rotateCountLeftward1=1;
            isRightMost=true;
             firstDemonLeftMost=false;
        }
        else
        {
            firstDemonLeftMost=false;
            isShotLeft1=false;
        }
        //else rotateCount=0;
        if(rotateCountLeftward1==0 && !isLeftMost)
        {

            _angle2 -= 0.5f;
            glutTimerFunc(5, updateDemonLeftward1, 0);

        }
        else if(rotateCountLeftward1==0 && isLeftMost && !isShotLeft1)
        {

            glutTimerFunc(2000, updateDemonLeftward1, 0);
            isRightMost=false;

            //Sleep(1000);
            //_angle2 -= 0.5f;
            isShotLeft1=true;



            //glutTimerFunc(1000,updateDemonLeftward1, 0);
            //glutTimerFunc(25, update, 0);
        }
        else if(rotateCountLeftward1==0 && isLeftMost && isShotLeft1)
        {
            glutTimerFunc(500, updateDemonLeftward1, 0);
            isRightMost=false;

            //Sleep(1000);
            _angle2 -= 0.5f;
            heatVisionLeft1=true;

            Sound(4);
            Sleep(200);
            Sound(2);



            //glutTimerFunc(1000,updateDemonLeftward1, 0);

            //printf("%d")
            //glutTimerFunc(25, update, 0);
        }
        else if(rotateCountLeftward1==1 && !isRightMost){

            _angle2 += 0.5f;
            glutTimerFunc(5, updateDemonLeftward1, 0);
        }
        else if(rotateCountLeftward1==1 && isRightMost){

            _angle2 += 0.5f;
            glutTimerFunc(2200, updateDemonLeftward1, 0);
            //Shot hoise ki na sheita check korbe
            if(!heatVisionLeft1) //shot hoy nai, agei maira felse
            {
                printf("safe\n");
            }
            else if(heatVisionLeft1){ //shot korte pare nai time moton, opponent maira dise
                shotCounter++;

                if(xLife!=-.8 && xDeath!=-.8)
                {
                    xLife-=xDef;
                    xDeath-=xDef;
                }

                printf("shot: %d\n",shotCounter);
            }
            heatVisionLeft1=false;
        }
        glutPostRedisplay(); //Tell GLUT that the display has changed
    }


}
//
//
//
//
//

void drawDemonLeftward2() {

    if(!isInitiatedLeft2)
    {
        initiateLeft2();
    }
    //glutTimerFunc(50, updateDemons, 0);

	glPushMatrix();
	glRotatef(_angle1, 0.0, 0.0, 1.0);
	glTranslatef(0.5, -.05, 0.0);
	glColor3f(0.0,1.0,0.7);

	glBegin(GL_POLYGON); //gola
        glColor3f(1.0,1.0,0.7);
        glVertex2f(-.15,-.05);
        glVertex2f(-.15,.04);
        glVertex2f(.05,.04);
        glVertex2f(.05,-.05);
	glEnd();

	glBegin(GL_POLYGON); //body
        glColor3f(1.0,0.0,0.7);
        glVertex2f(-.5,-.15);
        glVertex2f(-.5,.12);
        glVertex2f(-.15,.12);
        glVertex2f(-.15,-.15);
	glEnd();

	glBegin(GL_POLYGON);//matha
	for(int i=0;i<50;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50 ;
		float r=0.1;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x-.01,y-.03 );
	}
	glEnd();

	glBegin(GL_POLYGON); //chokh
        glColor3f(0.0,1.0,1.0);
        glVertex2f(.01,.01);
        glVertex2f(.02,.00);
        glVertex2f(.03,.01);
        glVertex2f(.03,.04);
        glVertex2f(.02,.05);
        glVertex2f(.01,.04);

	glEnd();

    glPopMatrix();

	glutSwapBuffers();
	//glutTimerFunc(25, updateDemons, 0);
}



void updateDemonLeftward2(int value) { //ei method ta leftward 2 ke update korbe
    if(!isGameOver)
    {
        isShot=true;
        //rotateCount=1;
        bool isRightMost=false;
        bool isLeftMost=false;

        if (_angle1 > 120) {
            rotateCount=0;
            isLeftMost=true;
            secondDemonLeftMost=true;
            //glutTimerFunc(2500,update,0);
        }
        else if(_angle1 < 90){
            rotateCount=1;
            isRightMost=true;
            secondDemonLeftMost=false;
        }
        else
        {
            secondDemonLeftMost=false;
            isShotLeft2=false;
        }
        //else rotateCount=0;
        if(rotateCount==0 && !isLeftMost)
        {
            _angle1 -= 0.5f;
            glutTimerFunc(5, updateDemonLeftward2, 0);
        }
        else if(rotateCount==0 && isLeftMost && !isShotLeft2)
        {
            glutTimerFunc(2500, updateDemonLeftward2, 0);
            isRightMost=false;
            //_angle1 -= 0.5f;
            isShotLeft2=true;
            //glutTimerFunc(25, update, 0);
        }
        else if(rotateCount==0 && isLeftMost && isShotLeft2)
        {
            glutTimerFunc(500, updateDemonLeftward2, 0);
            isRightMost=false;
            _angle1 -= 0.5f;
            heatVisionLeft2=true;

            Sound(4);
            Sleep(200);
            Sound(2);

            //glutTimerFunc(25, update, 0);
        }
        else if(rotateCount==1 && !isRightMost){
            _angle1 += 0.75f;
            glutTimerFunc(5, updateDemonLeftward2, 0);
        }
        else if(rotateCount==1 && isRightMost){
            _angle1 += 0.75f;
            glutTimerFunc(2400, updateDemonLeftward2, 0);

            //Shot hoise ki na sheita check korbe
            if(!heatVisionLeft2) //shot hoy nai, agei maira felse
            {
                printf("safe\n");
            }
            else if(heatVisionLeft2){ //shot korte pare nai time moton, opponent maira dise
                shotCounter++;
                if(xLife!=-.8 && xDeath!=-.8)
                {
                    xLife-=xDef;
                    xDeath-=xDef;
                }
                printf("shot: %d\n",shotCounter);
            }
            heatVisionLeft2=false;
        }
        glutPostRedisplay(); //Tell GLUT that the display has changed
    }


}
//
//
//
//

void drawDemonRightward1() {

    if(!isInitiatedRight1)
    {
        initiateRight1();
    }
    //glutTimerFunc(50, updateDemons, 0);

	glPushMatrix();
	glRotatef(_angle3, 0.0, 0.0, 1.0);
	glTranslatef(0.35, .6, 0.0);
	glColor3f(0.0,1.0,0.7);

	glBegin(GL_POLYGON); //gola
        glColor3f(1.0,1.0,0.7);
        glVertex2f(-.15,-.05);
        glVertex2f(-.15,.05);
        glVertex2f(.05,.05);
        glVertex2f(.05,-.05);
	glEnd();

	glBegin(GL_POLYGON); //body
        glColor3f(1.0,0.0,0.7);
        glVertex2f(-.4,-.1);
        glVertex2f(-.4,.1);
        glVertex2f(-.15,.1);
        glVertex2f(-.15,-.1);
	glEnd();

	glBegin(GL_POLYGON);//matha
	for(int i=0;i<50;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50 ;
		float r=0.1;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();

	glBegin(GL_POLYGON); //chokh
        glColor3f(0.0,1.0,1.0);
        glVertex2f(.01,-.045);
        glVertex2f(.02,-.035);
        glVertex2f(.03,-.045);
        glVertex2f(.03,-.075);
        glVertex2f(.02,-.085);
        glVertex2f(.01,-.075);

	glEnd();

    glPopMatrix();

	glutSwapBuffers();
	//glutTimerFunc(25, updateDemons, 0);
}

void updateDemonRightward1(int value) { //ei method ta rightward 1 ke update korbe
    if(!isGameOver)
    {
        isShot=true;
    //rotateCount=1;
        bool isRightMost=false;
        bool isLeftMost=false;

        if (_angle3 < 75) {
            rotateCountRightward1=0;
            isRightMost=true;
            firstDemonRightMost=true;
            //glutTimerFunc(2500,update,0);
        }
        else if(_angle3 > 90){
            rotateCountRightward1=1;
            isLeftMost=true;
            firstDemonRightMost=false;
        }
        else
        {
            firstDemonRightMost=false;
            isShotRight1=false;
        }

        //else rotateCount=0;
        if(rotateCountRightward1==1 && !isLeftMost)
        {
            _angle3 -= 0.75f;
            glutTimerFunc(5, updateDemonRightward1, 0);
            //printf("Rotate=1,Right=0\n");
        }
        else if(rotateCountRightward1==1 && isLeftMost)
        {
            glutTimerFunc(2800, updateDemonRightward1, 0);
            //isRightMost=false;
            _angle3 -= 0.75f;
            //Shot hoise ki na sheita check korbe
            if(!heatVisionRight1) //shot hoy nai, agei maira felse
            {
                printf("safe\n");
            }
            else if(heatVisionRight1){ //shot korte pare nai time moton, opponent maira dise
                shotCounter++;
                if(xLife!=-.8 && xDeath!=-.8)
                {
                    xLife-=xDef;
                    xDeath-=xDef;
                }
                printf("shot: %d\n",shotCounter);
            }
            heatVisionRight1=false;
        }
        else if(rotateCountRightward1==0 && !isRightMost){
            _angle3 += 0.75f;
            glutTimerFunc(5, updateDemonRightward1, 0);
            //printf("Rotate=0,Left=0\n");
        }
        else if(rotateCountRightward1==0 && isRightMost && !isShotRight1){
            glutTimerFunc(2500, updateDemonRightward1, 0);
            //_angle3 += 0.75f;
            isShotRight1=true;
        }
        else if(rotateCountRightward1==0 && isRightMost && isShotRight1){
            glutTimerFunc(500, updateDemonRightward1, 0);
            _angle3 += 0.75f;
            heatVisionRight1=true;

            Sound(4);
            Sleep(200);
            Sound(2);

        }
        glutPostRedisplay(); //Tell GLUT that the display has changed
    }


}


void drawDemonRightward2() {

    if(!isInitiatedRight2)
    {
        initiateRight2();
    }
    //glutTimerFunc(50, updateDemons, 0);

	glPushMatrix();
	glRotatef(_angle4, 0.0, 0.0, 1.0);
	glTranslatef(0.5, -.05, 0.0);
	glColor3f(0.0,1.0,0.7);

	glBegin(GL_POLYGON); //gola
        glColor3f(1.0,1.0,0.7);
        glVertex2f(-.15,-.05);
        glVertex2f(-.15,.05);
        glVertex2f(.05,.05);
        glVertex2f(.05,-.05);
	glEnd();

	glBegin(GL_POLYGON); //body
        glColor3f(1.0,0.0,0.7);
        glVertex2f(-.5,-.15);
        glVertex2f(-.5,.15);
        glVertex2f(-.15,.15);
        glVertex2f(-.15,-.15);
	glEnd();

	glBegin(GL_POLYGON); //matha
	for(int i=0;i<50;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50 ;
		float r=0.1;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y-.06 );
	}
	glEnd();

	glBegin(GL_POLYGON); //chokh
        glColor3f(0.0,1.0,1.0);
        glVertex2f(.01,-.10);
        glVertex2f(.02,-.09);
        glVertex2f(.03,-.10);
        glVertex2f(.03,-.13);
        glVertex2f(.02,-.14);
        glVertex2f(.01,-.13);

	glEnd();

    glPopMatrix();

	glutSwapBuffers();
	//glutTimerFunc(25, updateDemons, 0);
}

void updateDemonRightward2(int value) { //ei method ta rightward 2 ke update korbe
    if(!isGameOver)
    {
        isShot=true;
        //rotateCount=1;
        bool isRightMost=false;
        bool isLeftMost=false;

        if (_angle4 < 75) {
            rotateCountRightward2=0;
            isRightMost=true;
            secondDemonRightMost=true;
            //glutTimerFunc(2500,update,0);
        }
        else if(_angle4 > 90){
            rotateCountRightward2=1;
            isLeftMost=true;
            secondDemonRightMost=false;
        }
        else
        {
            secondDemonRightMost=false;
            isShotRight2=false;
        }

        //else rotateCount=0;
        if(rotateCountRightward2==1 && !isLeftMost)
        {
            _angle4 -= 0.75f;
            glutTimerFunc(5, updateDemonRightward2, 0);
            //printf("Rotate=1,Right=0\n");
        }
        else if(rotateCountRightward2==1 && isLeftMost)
        {
            glutTimerFunc(2100, updateDemonRightward2, 0);
            //isRightMost=false;
            _angle4 -= 0.75f;


            if(!heatVisionRight2) //shot hoy nai, agei maira felse
            {
                printf("safe\n");
            }
            else if(heatVisionRight2){ //shot korte pare nai time moton, opponent maira dise
                shotCounter++;
                if(xLife!=-.8 && xDeath!=-.8)
                {
                    xLife-=xDef;
                    xDeath-=xDef;
                }
                printf("shot: %d\n",shotCounter);
            }
            heatVisionRight2=false;
        }
        else if(rotateCountRightward2==0 && !isRightMost){
            _angle4 += 0.75f;
            glutTimerFunc(5, updateDemonRightward2, 0);
            //printf("Rotate=0,Left=0\n");
        }
        else if(rotateCountRightward2==0 && isRightMost && !isShotRight2){
            glutTimerFunc(2500, updateDemonRightward2, 0);
            //_angle4 += 0.75f;

            isShotRight2=true;
        }
        else if(rotateCountRightward2==0 && isRightMost && isShotRight2){
            glutTimerFunc(500, updateDemonRightward2, 0);
            _angle4 += 0.75f;

            heatVisionRight2=true;

            Sound(4);
            Sleep(200);
            Sound(2);

        }
        glutPostRedisplay(); //Tell GLUT that the display has changed
    }


}



void drawDemons(void)
{
    drawDemonLeftward1();
    drawDemonLeftward2();
    drawDemonRightward1();
    drawDemonRightward2();
}

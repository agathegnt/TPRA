#include <iostream>
#include <fstream>
#include <string>
#include <opencv/cv.hpp>
#include <vector>
#include <stdio.h>     
#include <stdlib.h>
#include <aruco.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/calib3d/calib3d.hpp>

using namespace std;
using namespace cv;
using namespace aruco;

#define ESC_KEY 27

Mat image;
string imageName;
bool loaded=false;



int main(int argc, const char * argv[]) {

	VideoCapture cap;

	int num_cam;
	while(!cap.isOpened()){
		cout << "Quelle est la camera utilisee ?" << endl;
		cin >> num_cam;
		cap.open(num_cam);
	}
   
	

	/* Lecture d'une image
		while(!loaded) {
		cout <<"image name? "<<endl;

		cin >> imageName ;
		image = imread(imageName);
		loaded = true;

		 if(! image.data ) // Check for invalid input
		{
			cout <<  "Wrong Name !!" << std::endl ;
			loaded = false;
		}

	}*/

	// creation d’un detecteur de marqueurs
	MarkerDetector myDetector ;

	// liste de marqueurs : sera remplie par ArUco
	vector<Marker> markers ;



	// Creating a window to display the images
	string windowName = "Realite Augmentee";
	namedWindow(windowName, CV_WINDOW_AUTOSIZE);

	for (;;)
	{
		cap >> image;

		// detection
		myDetector.detect(image, markers ) ;

		// on affiche le resultat de la detection sur une image
		for (unsigned int i =0; i <markers.size( ) ; i ++)
		{
			cout << markers[i] ;
			markers[i].draw(image, Scalar(0 ,0 ,255) ,2) ;
		}

		imshow(windowName, image);
		if((waitKey(30) == 27)) break;
	}

	return 0;

}
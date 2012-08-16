/*
	converter.c
	Author : Soumya Mandi

	Converts 32-bit images to 8-bit images.
	Arguments : 2 1st->File containing list of source files
				  2nd->File containing list sof source files

*/

#include <stdio.h>
#include <stdlib.h>
#include <opencv/cv.h>
#include <opencv/cvaux.h>
#include <opencv/highgui.h>
#include <opencv/cxcore.h>


int main( int argc,char** argv ){
	
	printf("sys.argv[1] is : %s\n", argv[1] ) ;
	printf("sys.argv[2] is : %s\n", argv[2] ) ;
	
	FILE* src = fopen( argv[1],"r" ) ;
	FILE* tar = fopen( argv[2],"r" ) ;

	char* srcFile = ( char* )malloc( sizeof( char )*100 ) ;
	char* tarFile = ( char* )malloc( sizeof( char )*100 ) ;

	int first  = fscanf( src,"%s",srcFile ) ;
	int second = fscanf( tar,"%s",tarFile ) ;
	//printf( "srcFile is : %s\n", srcFile ) ;

	while( first != EOF ){
		//Do conversions
		IplImage* img32 = cvLoadImage( srcFile,CV_LOAD_IMAGE_UNCHANGED ) ;
		IplImage* img8 = cvCreateImage( cvGetSize( img32 ), IPL_DEPTH_8U, img32->nChannels ) ;

		//cvConvertScaleAbs( img32,img8,255.0,0.0 ) ;
		img8 = cvCloneImage( img32 ) ;
		cvSaveImage( tarFile, img8, 0 ) ;

		//printf("srcFile is : %s\n", srcFile ) ;


		first  = fscanf( src,"%s",srcFile ) ;
		second = fscanf( tar,"%s",tarFile ) ;
	}


	fclose( src ) ;
	fclose( tar ) ;

	return 0 ;
}

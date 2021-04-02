/*main function calling all other functions*/

/*importing libraries*/
#include <stdio.h>
#include <stdlib.h>
#pragma pack(1)
#include "prototype.h"
#include "structures.h"

	int arr[2];                 		 /*defining global array*/
	struct header h;             		/*defining global struct*/

int main(int argc, char* argv[])
{
    if(argc!=3){
        printf("Please enter valid input of the form - ./my_project source_image.tiff destination_image.BMP \n");
        return 0;
    }
    FILE *fp;
    FILE *fp2;
    fp=fopen(argv[1],"rb");                  	/*opening source tiff image using fopen*/
    fp2=fopen(argv[2],"wb");     		        /*opening destination bmp file using fopen*/

    /*calling of functions*/

    int cod=readTiffheader(fp);                 /*calling function to read TIFF header*/
    int *p=readIFD(fp,cod);                     /*calling function to read TIFF IFDs*/
    writeBMPHeader(fp2,p);                      /*calling function to write BMP header*/
    writeDIBHeader(fp2,p);                      /*calling function to write DIB header*/
    convert(fp,fp2,p);                          /*calling function to write grayscale data*/

    /*closing the files*/

    fclose(fp);
    fclose(fp2);
    return 0;

}





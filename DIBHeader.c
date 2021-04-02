/*function to write DIB header*/

#include <stdio.h>
#include <stdlib.h>
#pragma pack(1)
#include "prototype.h"								/*function prototypes of all functions included*/
#include "structures.h"							/*declaration of header structure included*/

void writeDIBHeader(FILE *fp2,int *p)						/*function definition*/
{
    struct DIB_header								/*declaration of DIB header structure*/
	{
		unsigned int header_size;					/*size of the dib header in bytes*/
		unsigned int width;						/*image bitmap width in pixels*/
		unsigned int heigth;						/*image bitmap height in pixels*/
		unsigned short int colorplanes;				/*number of colorplanes*/
		unsigned short int bitsperpixel;				/*number of bits per pixel or color depth*/
		unsigned int compression;					/*compression method used for image*/
		unsigned int image_size;					/*size of image*/
		unsigned int hres;						/*horizontal resolution*/
		unsigned int vres;						/*vertical resolution*/
		unsigned int color;						/*number of colors in color palette*/
		unsigned int imp_color;					/*important colors used*/

	};
	struct DIB_header dibheader;						/*struct variable declaration*/
	dibheader.header_size=40;						/*standard size=40 bytes*/
	dibheader.width=p[0]-p[0]%4;						/*p[0] corresponds to image width in array*/
	dibheader.heigth=p[1];							/*p[1] corresponds to image height in array*/
	dibheader.colorplanes=1;						/*must be 1*/
	dibheader.bitsperpixel=8;						/*8 bits per pixel*/
	dibheader.compression=0;						/*no compression*/
	dibheader.image_size=0;
	dibheader.color=256;
	fwrite(&dibheader,40,1,fp2);						/*writing DIB header values in BMP image file*/

}

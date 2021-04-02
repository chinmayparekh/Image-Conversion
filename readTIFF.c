/*function to read source tiff image*/

#include <stdio.h>
#include <stdlib.h>
#pragma pack(1)
#include "prototype.h"					/*function prototypes of all functions included*/
#include "structures.h"				/*declaration of header structure included*/

	int arr[2];					/*array of image length and width*/
	struct header h;				/*declaration of TIFF header structure*/

int readTiffheader(FILE *fp)				/*function definition*/
{
	int cod;					/*declaration of content of directories variable*/
    fread(h.byteordering,2,1,fp);			/*reading byte order as the first 2 bytes of the header*/
	if(h.byteordering[0]==0x49 && h.byteordering[1]==0x49)//checking if the image is in correct format
	{
		fread(&h.tiff,2,1,fp);				
		if(h.tiff!=42)					/*reading TIFF version number, always 42*/
		{
			printf("Incorrect image format\n");
			exit(0);
		}							
	}
	else
	{
		printf("Incorrect image format\n");
			exit(0);
	}
											/*exiting program if given image format is not TIFF*/
	fread(&h.offset,4,1,fp);			/*reading image offset of first IFD in file form at start of file*/
	fseek(fp,h.offset,SEEK_SET);			/*seeking file pointer to the offset*/
	fread(&cod,2,1,fp);				/*reading the number of content of directories*/
	return cod;					/*returning the cod from the function*/
    
}

/*function to read the image file directories from source tiff*/

/*importing libraries*/

#include <stdio.h>
#include <stdlib.h>
#pragma pack(1)
#include "prototype.h"
#include "structures.h"

	int arr[2];                  /*global variable arr*/
	struct header h;
    
int * readIFD(FILE *fp,int cod)
{
	/*a directory entry has first 2 bytes as tag, next 2 as datatype, next 4 bytes as length
	and next 4 as value*/

  struct directory
	{
		short int tag;
		short int datatype;
		int length;
		int value;
	};
	int img_wid,img_len,stripoffset,nxtoff;

    struct directory de[cod];

    /*using for loop and number of directries we got from readtiff function, we compare the tags
    in directory entries and find image length, image width and stripoffset*/

	for(int i=0;i<cod;i++)
	{
		fread(&de[i].tag,2,1,fp);
		fread(&de[i].datatype,2,1,fp);
		fread(&de[i].length,4,1,fp);
		fread(&de[i].value,4,1,fp);           	/*reading from source image*/
		if(de[i].tag==256)
			img_wid=de[i].value;              /*if tag is 256, value represents img width*/
		if(de[i].tag==257)
			img_len=de[i].value;              /*if tag is 257, value represents img length*/
		if(de[i].tag==273)
			stripoffset=de[i].value;          /*if tag is 273, value represents strip offset*/
	}

	/*now we seek to stripoffset and then to stroffset from where the image information starts*/

    (fp,h.offset+2+cod*12,SEEK_SET);
	fread(&nxtoff,4,1,fp);
	char stroffset;
	fseek(fp,stripoffset,SEEK_SET);
	fread(&stroffset,1,1,fp);
	fseek(fp,stroffset,SEEK_SET);
	 
	 arr[0]=img_wid;                           /*image length and width are stored as array in arr[]*/
	 arr[1]=img_len;
	 
	 return arr;
	
}

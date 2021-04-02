//including all header files

#include <stdio.h>
#include <stdlib.h>
#pragma pack(1)
#include "prototype.h"
#include "structures.h"

void convert(FILE *fp,FILE *fp2,int *p)
{
	int alfa=0;
	for(int ind=0;ind<256;ind++)            //filling color table
	{
		for(int in=0;in<3;in++)
			fwrite(&ind,1,1,fp2);
		fwrite(&alfa,1,1,fp2);
	}	
	
	unsigned char red,green,blue,gs;
	int sum=1,l;
	char s;
	int BIG=(54+256*4+(p[1]*(p[0]-p[0]%4)))-((p[0]-p[0]%4));
	fseek(fp2,BIG,SEEK_SET);
	for(int i=0;i<p[1];i++){                                     //filling image data and inverting the image
		for(int j=0;j<(p[0]-p[0]%4);j++){
			fread(&red,1,1,fp);
			fread(&green,1,1,fp);
			fread(&blue,1,1,fp);
			gs=0.3*red + 0.6*green + 0.1*blue;       //gs is gray scale component
			fwrite(&gs,1,1,fp2);
		}
		for(l=0;l<(p[0]%4)*3;l++)
			fread(&s,1,1,fp);
		fseek(fp2,BIG-(sum*(p[0]-p[0]%4)),SEEK_SET);
		sum++;
	}

}

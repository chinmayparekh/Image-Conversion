/*function to write BMP header*/

/*importing libraries*/

#include <stdio.h>
#include <stdlib.h>
#pragma pack(1)
#include "prototype.h"
#include "structures.h"

void writeBMPHeader(FILE *fp2,int *p)
{
    struct BMP_header                    /*defining structure*/
	{
		char name[2];
		unsigned int size;
		int garbage;
		unsigned int image_offset;
    };

    /*in BMP, the first two bytes are chars 'B' and 'M', next 4 bytes are image size,
    next 4 bytes are garbage values, and the last 4 bytes is image offset. Size of BMP header is 14 bytes*/

        struct BMP_header header;
        header.name[0]='B';
        header.name[1]='M';
        header.size=(p[0]-p[0]%4)*p[1]+54+256*4;
        header.garbage=0;
        header.image_offset=54+256*4;

        /*writing header information in destination file*/

        fwrite(header.name,2,1,fp2);
        fwrite(&header.size,4,1,fp2);
        fwrite(&header.garbage,4,1,fp2);
        fwrite(&header.image_offset,4,1,fp2);

}

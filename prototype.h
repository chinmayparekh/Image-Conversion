int readTiffheader(FILE *fp);
int * readIFD(FILE *fp,int cod);
void writeBMPHeader(FILE *fp2,int *p);
void writeDIBHeader(FILE *fp2,int *p);
void convert(FILE *fp,FILE *fp2,int *p);
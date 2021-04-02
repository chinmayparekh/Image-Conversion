CC=gcc
all_sources= main.c readTIFF.c IFD.c BMPHeader.c DIBHeader.c transform.c
my_project: $(all_sources)
		$(CC) -o my_project $(all_sources) 

clean:
	rm my_project *.bmp

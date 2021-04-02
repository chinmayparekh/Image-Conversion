# C Project-Team 16

## Source format:TIFF.Destination format :8-bit(grayscale) BMP
---

### Team members:
---

                BTV Sumanth-IMT2020072 
                Chinmay Parekh-IMT2020069
                Chaitanya Manas Cheedella-IMT2020053
                Vaibhav Thapliyal-IMT2020049
                Aamod BK-IMT2020546
                Ganga Sagar Reddy Kataru-IMT2020134
---
                

### Contribution
---

| Name                               | Contribution                                                     |
| ----                               | ------------                                                     |
| BTV Sumanth                        | research about TIFF and making IFD.c and readTIFF.c              |
| Chinmay Parekh                     | research about TIFF and making IFD.c and readTIFF.c              | 
| Chaitanya Manas                    | research about padding,image conversion and making transform.c   | 
| Vaibhav Thapliyal                  | research about BMP header,makefiles and format making BMPheader.c|
| Aamod BK                           | research about DIB headers,makefiles and making DIBHeader.c      |
| Ganga Sagar Reddy Kataru           | making main.c,prototype.h,structures.h                           |

---

### How to use?
---
    1.Insert your picture which has an extension of .tiff in the directory containing the project.

    2.Write the following commands in your terminal after reaching the directory containing the project
            - $ make
        You shall see the following output on your terminal
            -gcc -o my_project main.c readTIFF.c IFD.c BMPHeader.c DIBHeader.c transform.c
        To convert your image write the command in the following format.
            - $ ./my_project "source_image.tiff" "destination_image.bmp"
        After entering the name,you shall find an image "destination_image.bmp" which is the .tiff image converted into 8 bit(grayscale)BMP 
        to delete the converted image and the executable file use the following command
            - $ make clean

---

### Our Testcases
---
We have successfully converted four single strip TIFF images into 8 bit(grayscale)BMP and have attached the pictures along with the converted images in the zip file.

---

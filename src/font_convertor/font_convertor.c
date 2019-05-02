#include <stdio.h>
#include <stdlib.h>

#include <stdint.h>

#include <sys/stat.h>

int main(int argc, char **argv)
{
        struct stat st;
        FILE *fp;
        long int fsize, expect_fsize, raw_data_ofst;
        int width, height;
        uint32_t *converted_data, pixcol;
        uint8_t *raw_data;
        int i, j;

        if(argc != 5){
                fprintf(stderr, "Usage: $%s [inputdata] [width] [height] [prefix]\n", argv[0]);
                return -1;
        }

        width  = atoi(argv[2]);
        height = atoi(argv[3]);

        if (width == 0 || height == 0) {
                fprintf(stderr, "width and height should be correct number.\n");
                return -1;
        }

        expect_fsize = (long int)width * height * 3;

        if (stat(argv[1], &st) != 0) {
                fprintf(stderr, "Can not open %s\n", argv[1]);
                return -1;
        }
        
        if ((st.st_mode & S_IFMT) != S_IFREG) {
                fprintf(stderr, "%s is not reguler file.\n", argv[1]);
                return -1;
        }

        fsize = st.st_size;

        if ( fsize != expect_fsize ){
                fprintf(stderr, "filesize is %ld. It should be the same as %d x %d x 3 = %ld.\n", fsize, width, height, expect_fsize);
                return -1;
        }

        raw_data       = (uint8_t *)malloc(width*height*3);
        converted_data = (uint32_t *)malloc(width*height*4);

        if (raw_data == NULL || converted_data == NULL) {
                fprintf(stderr, "Could not malloc memory...\n");
                return -1;
        }

        fp = fopen(argv[1], "rb");
        if(!fp){
                fprintf(stderr, "Could not open %s\n", argv[1]);
                return -1;
        }

        if ( fread(raw_data, 1, fsize, fp) != fsize ) {
                fprintf(stderr, "Could not read data from file.\n");
                return -1;
        }

        fclose(fp);

        for(i=0; i<height; i++){
                for(j=0; j<width; j++){
                        raw_data_ofst = ((width*i) + j) * 3;
                        // raw_data order : R, G, B..
                        // neopixel color order : 00GGRRBB.
                        pixcol = (raw_data[ raw_data_ofst + 0 ] << 8) + (raw_data[ raw_data_ofst + 1 ] << 16) + raw_data[ raw_data_ofst + 2 ];
                        converted_data[ (width * (height - 1 - i)) + j ] = pixcol;
                }
        }

        printf( "const uint32_t %s_width  = %d;\n"
                "const uint32_t %s_height = %d;\n"
                "const uint32_t %s_data[] = {", argv[4], width, argv[4], height, argv[4] );

        for(i=0; i<width*height; i++){
                if (i != 0) {
                    printf(",");
                }

                if ( (i%4) == 0 ){
                        printf("\n    0x%08X", converted_data[i]);
                }else{
                        printf(" 0x%08X", converted_data[i]);
                }
        }
        printf("\n};\n");

        free(raw_data);
        free(converted_data);

        return 0;
}


#include<stdio.h>
#include<string.h>

#define STB_IMAGE_IMPLEMENTATION
#include"stb/stb_image.h"

int main(int argc,char *argv[]){
    char Chars[]=" `^\",:;Il!i~+_-?][}{1)(|\\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8B@$";
    int CharsLen =strlen(Chars);
    // printf("%d\n",CharsLen);

    int Width,Height,PixelSize;
    unsigned char *ImageData = stbi_load(argv[1],&Width,&Height,&PixelSize,0);
    if(ImageData){
        // printf("W: %d\nH:%d\nP:%d",Width,Height,PixelSize);
        unsigned char *Pixels= ImageData;
        for(int RowIndex=0;RowIndex<Height;RowIndex++){
            for(int ColIndex =0; ColIndex<Width;ColIndex++){
                unsigned char R = *Pixels++;
                unsigned char G = *Pixels++;
                unsigned char B = *Pixels++;
                if(PixelSize>=4){
                    unsigned char A = *Pixels++;

                }
                float Avg= (R+B+G)/3.0f;
                int CharIndex=(int)(CharsLen*(Avg/255.0f));
                putchar((Chars[CharIndex]));
            }
            putchar('\n');
        }
    }
    else{
        printf("failed");
    }

    return 0;
}
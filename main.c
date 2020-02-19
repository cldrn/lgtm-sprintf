//sprintf overflows

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
        char buf1[10];
        char buf2[100];
        char buf3[300];
        char buf4[3];

        if (argc < 5) {
                printf("More args!\n\n");
                return -1;
        }

        //1st error, buf1 overflows. QL: buf1>len(fmt)
        sprintf(buf1, "%s", argv[1]);

        //2nd error, buf1 overflows. QL: buf1<len(fmt)
        sprintf(buf1, "aaaaaaaa%s", argv[2]);

        //3rd case, buf3 overflows from fmt. QL: buf3>len(fmt)
        sprintf(buf2, "%s", argv[3]);
        sprintf(buf3, "%s%s%s%s", buf2, buf2, buf2, buf2);

        //4th case, fmt string expands more than len(fmt)
        sprintf(buf4, "%04x", 9);

        return 0;
}

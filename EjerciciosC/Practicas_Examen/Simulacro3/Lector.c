#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(void)
{

    char buffer[80];
    int nbytes;
    mknod("MI_FIFO", S_IFIFO | 0660, 0);
    int fp = open("MI_FIFO", O_RDONLY);

    while ((nbytes = read(fp, buffer, 80 - 1)) > 0)
    {
        buffer[nbytes] = '\0';
        printf("Cadena rebuda: %s\n", buffer);
    }

    close(fp);
    unlink("MI_FIFO");

    return 0;
}

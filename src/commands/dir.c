#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

void dir()
{
    struct dirent *de;
    DIR *dir = opendir(".");

    if (dir == NULL) { // returns if can't open directory
        printf("Directory does not exist");
    }
    else {
        while ((de = readdir(dir)) != NULL) {
            if (de->d_type == DT_DIR)
                printf("<DIR>   %s\n", de->d_name);
            else
                printf("<FILE>  %s\n", de->d_name);
        }
    
    closedir(dir);
    }
}
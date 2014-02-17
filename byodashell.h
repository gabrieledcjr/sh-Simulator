//
//  byodashell.h
//
//
//  Created by Gabriel de la Cruz on 2/13/14.
//
//

#ifndef BYODA_SHELL_H
#define BYODA_SHELL_H

#include <stdio.h>
#include <stdlib.h> // calloc(), malloc(), exit()
#include <envz.h>   // envz_get()
#include <string.h> // strtok()
#include <time.h>   // time(), localtime()
#include <fcntl.h>  // O_RDONLY, O_WRONLY, O_APPEND, O_CREAT

#define SHELL_NAME "bysh"
#define LINE_MAX   1024

typedef struct path_t
{
    char* name;
    struct path_t* next;
} Path_t;

Path_t* pathList;             /* Pointer to list of paths from PATH ENV */
char*   PATH;                 /* Pointer to PATH ENV variable */
char*   HOME;                 /* Pointer to HOME ENV variable */
char*   LOGNAME;              /* Pointer to LOGNAME ENV variable */
char    line[LINE_MAX];       /* Command user input */
char    command[64];          /* Command string */
char    head[512], tail[512]; /* Child process vars */

void  __init__        (char** env);
void  credits         (void);
int   redirectTok     (char* string, char* cmdArgs, char* file);
char* reverseString   (char* string);
char* removePreSpace  (char* string);
char* removePostSpace (char* string);
void  executeCommand  (char** env);

#endif

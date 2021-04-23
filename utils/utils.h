#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

char newline;

int signIn(char *user, char *pass, char* myFile);
int signUp(char* myFile, char *user, char *pass);
int inDB(char *user, char *myFile);
void randomPassword(char *pass, int n);
void showProducts();
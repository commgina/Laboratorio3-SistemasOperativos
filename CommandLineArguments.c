#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include "cJSON.h"
#include "lib_d.h"

/*----Variables globales----*/

cJSON *root;
cJSON *fmt;
char linea[50] = "";

/*----Metodos----*/

long retornarValor(char *linea);
char* retornarEtiqueta(char *linea);
void crearJSON(FILE *outputTxt, char *c);

int main(int argc, char **argv){

    
    root = cJSON_CreateObject();

   

	char *modoEjecucion = argv[1];
    char *modoEjecucion2 = argv[2];

	

    if(argc == 2){
        if(strcmp(modoEjecucion,"-s") == 0){

            system("./e1");

        }else if(strcmp(modoEjecucion,"-a") == 0 ){

            system("./e2");

        }if(strcmp(modoEjecucion,"-d") == 0 ){

            lib();
        }

    }else if (argc == 3){

        if(strcmp(modoEjecucion,"-s") == 0 && strcmp(modoEjecucion2,"-j") == 0){
        system("./e1 > output.txt"); 
        FILE *output = fopen("output.txt", "r");   
        cJSON_AddItemToObject(root, "Informacion de la memoria:", fmt = cJSON_CreateObject());
        crearJSON(output,argv[1]);
        printf("%s", cJSON_Print(root));

        }else if(strcmp(modoEjecucion,"-a") == 0 && strcmp(modoEjecucion2,"-j") == 0){

        system("./e2 > output.txt"); 
        FILE *output = fopen("output.txt", "r");
        cJSON_AddItemToObject(root, "Informacion de la version del sistema", fmt = cJSON_CreateArray());
        crearJSON(output,argv[1]);
        printf("%s", cJSON_Print(root));

        }

    }else{

        printf("Comandos incorrectos");
    }

    return 0;   
}


void crearJSON(FILE *outputTxt, char *c){
    
    if(strcmp(c,"-s") == 0){

        while (fgets(linea, sizeof(linea), outputTxt)){

            cJSON_AddNumberToObject(fmt, retornarEtiqueta(linea), retornarValor(linea));

        }

    }else if(strcmp(c,"-a") == 0){

        while (fgets(linea, sizeof(linea), outputTxt)){

            cJSON_AddItemToArray(fmt, cJSON_CreateString(retornarEtiqueta(linea)));

        }

    }
    
    
}

long retornarValor(char *linea)
{
    long val;
    char *p = linea;
    while(*p){

        if(isdigit(*p) && isdigit(*p+1)){
            val = strtol(p,&p,10);         
        }else{
            p++;
        }

    }

    return val;
}

char* retornarEtiqueta(char *linea){

    
    const char s[4] = ":\n";
    char *resultado = strtok(linea,s);
    if(strstr(linea, "\t")){

        const char s2[] = "\t:\n";
        resultado = strtok(linea,s2);
        
    }

    return resultado;

}
#include <stdio.h>
#include <string.h>
#include "cJSON.h"

void lib(){

    char linea[50] = "";
    FILE *f = fopen("/proc/filesystems", "r");
    cJSON *json = cJSON_CreateObject();
    cJSON *arrNoDev = cJSON_CreateArray();
    cJSON *arr = cJSON_CreateArray();
    cJSON_AddItemToObject(json,"NoDev",arrNoDev);
    cJSON_AddItemToObject(json,"     ",arr);
    while (fgets(linea, sizeof(linea), f)){

        if(strstr(linea,"nodev")){

            char *lineaFinal =linea ;
            lineaFinal += 6; //le saco el nodev\t
            if(strstr(linea, "\n")){

                
                const char s[] = "\n";
                lineaFinal = strtok(lineaFinal,s);
                
            }
            cJSON_AddItemToArray(arrNoDev,cJSON_CreateString(lineaFinal));

        }else{

            char *lineaFinal = linea ;
            lineaFinal += 1;
            
            if(strstr(linea, "\n")){

                const char s[] = "\n";
                lineaFinal = strtok(lineaFinal,s);
                
            }
            cJSON_AddItemToArray(arr,cJSON_CreateString(lineaFinal));
        }     

    }

    printf("%s", cJSON_Print(json));

}


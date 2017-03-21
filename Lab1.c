#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void filasColumnas(int Ba[48]);

int main(void)
{
   int i, M[32], E[48], k[48], B[48], Ba[48], x=0, y=0;
   unsigned semilla = (unsigned)time(NULL);
//Generación del número aleatoreo de 32 bits
//Mostramos en pantalla y guardamos la información en la matriz M.
   
   srand(semilla);

   for (i = 1; i <= 32; i++){
    if(rand()%2 ==0){
        //printf("%d", 0);
        M[i]=0;
    }
    else{
        //printf("%d", 1);
        M[i]=1;
    }
}
    //printf("\n");
//Mostramos Matriz M
    printf("Matriz de entrada: ");
    i=1;
    while(i<=32){
        printf("%d", M[i]);
    i++;
    }
    printf("\n");
    printf("\n");
    printf("\n");

//Ahora con la función de expanción E vamos a permutar los valores de la Matriz M.
    E[1]=M[32];
    E[2]=M[1];
    E[3]=M[2];
    E[4]=M[3];
    E[5]=M[4];
    E[6]=M[5];
    E[7]=M[4];
    E[8]=M[5];
    E[9]=M[6];
    E[10]=M[7];
    E[11]=M[8];
    E[12]=M[9];
    E[13]=M[8];
    E[14]=M[9];
    E[15]=M[10];
    E[16]=M[11];
    E[17]=M[12];
    E[18]=M[13];
    E[19]=M[12];
    E[20]=M[13];
    E[21]=M[14];
    E[22]=M[15];
    E[23]=M[16];
    E[24]=M[17];
    E[25]=M[16];
    E[26]=M[17];
    E[27]=M[18];
    E[28]=M[19];
    E[29]=M[20];
    E[30]=M[21];
    E[31]=M[20];
    E[32]=M[21];
    E[33]=M[22];
    E[34]=M[23];
    E[35]=M[24];
    E[36]=M[25];
    E[37]=M[24];
    E[38]=M[25];
    E[39]=M[26];
    E[40]=M[27];
    E[41]=M[28];
    E[42]=M[29];
    E[43]=M[28];
    E[44]=M[29];
    E[45]=M[30];
    E[46]=M[31];
    E[47]=M[32];
    E[48]=M[1];
//Mostramos la nueva matriz de expación E.
    i=1;
    printf("Matriz de expanción E: ");
    while(i<=48)
    {
        printf("%d", E[i]);
    i++;
    }
    printf("\n");
    printf("\n");
    printf("\n");

//Creamos la clave k, para luego aplicar la función XOR con la matriz E

 srand(semilla);
    printf("clave k: ");
   for (i = 1; i <= 48; i++){
    if(rand()%2 ==0){
        printf("%d", 0);
        k[i]=0;
    }
    else{
        printf("%d", 1);
        k[i]=1;
    }
}
    printf("\n");
    printf("\n");
    printf("\n");
       
//Función XOR, guardada en la matriz B

    for(i=1; i<=48; i++){
        if (E[i] == k[i]){
            B[i]=0;
            Ba[y]=0; //Matriz B auxiliar
        }else{
            B[i]=1;
            Ba[y]=1; //Matriz B auxiliar
        }
        y++;
        if(y==6){
            x=0;
            y=0;
            printf("Matriz Ba: ");
            while(x<6)
            {
                printf("%d", Ba[x]);
                x++;
                   
            }
            filasColumnas(Ba);
            printf("\n");
           
        }
    }

    i=1;
    printf("Matriz B: ");
    while(i<=48)
    {
        printf("%d", B[i]);
        i++;
        y++;
        if(y==6){
            printf(" ");
            y=0;
        }
       
    }
    printf("\n");
    printf("\n");
    printf("\n");



   return 0;
}


void filasColumnas(int Ba[48]){
    int r, c;   
    r= Ba[5]*1 + Ba[0]*2;    // representación de la fila (r)
    printf(" Fila = %d", r);
    c=  Ba[4]*1 + Ba[3]*2 + Ba[2]*4 + Ba[1]*8;
    printf(" Columnas = %d", c);
    printf("\n");

}

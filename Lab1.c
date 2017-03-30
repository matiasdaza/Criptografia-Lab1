#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int filasColumnas(int Ba[48], int indice);
void Permutacion(int C[32]);

int main(void)
{
   int i, M[32], E[48], k[48], B[48], Ba[48], x=0, y=0, indice=1, S=0, p=0, d=0, C[32], aux[4], resto, m, P[32];
   unsigned semilla = (unsigned)time(NULL);
   FILE *archivo=NULL;
//Generación del número aleatoreo de 32 bits
//Mostramos en pantalla y guardamos la información en la matriz M.
   
   srand(semilla);

    for (i = 1; i <= 32; i++){
        if(rand()%2 ==0){
            M[i]=0;
        }
        else{
            M[i]=1;
        }
    }
    

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

//Ahora con la función de expansión E vamos a permutar los valores de la Matriz M.

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

//Mostramos la nueva matriz de expansión E.

    i=1;
    printf("Matriz de expansión E: ");
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
    printf("Clave K: ");
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
       
//Función XOR, guardada en la matriz B, a medida que hace el función XOR, vamos separando de a 6 bits
// para crear los subvectores B e ingresarlos a las cajas S. 

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
            printf("Matriz B%d: ", indice);
            while(x<6)
            {
                printf("%d", Ba[x]);
                x++;
                   
            }
            
            S=filasColumnas(Ba, indice); //Ingresamos valores a las cajas S para completar el arreglo C
            
            //Transformamos el valor dado a binario y lo ingresamos al arreglo C

            p=0; 
            while(S >= 2){ //Mientras el dividendo sea mayor o igual que el divisor, es decir, mayor o igual que 2.
                resto = S % 2;
                if(resto == 1){
                    aux[p] = 1; //Si el resto es igual a 1 concatenamos 1 a la variable string llamada binario
                }else{
                    aux[p] = 0; // Sino concatenamos 0
                }
                S = S/2; // Actualizamos el valor del dividendo dividiendolo entre 2.
                p++;
            }
            if(S == 1){
                aux[p] = 1; // Por último si el valor final del dividendo es 1 concatenamos 1 sino concatenamos 0.
            }else{
                aux[p] = 0; 
            }           
            d=p;
            m=(4*indice)-1;
            indice=indice+1;
            p=0;
            while(p<4){
                
                if(p>d){
                    //printf("0 - ");
                    C[m]=0;
                }else{
                    //printf("%d - ", C[p]);
                    C[m]=aux[p];
            }
                p++;
                m--;
            }
        }
    printf("\n");
           
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
    i=0;
    y=1;
    printf("Matriz C: ");
    while(i<32)
    {
        printf("%d", C[i]);
        i++;
        if(y==4){
            printf(" ");
            y=0;
        }
        y++;
       
    }

    printf("\n \n");

//Se finaliza la función f, permutando C con la tabla fija P.
    printf("Arreglo final luego de la permutación P: ");
    archivo = fopen ("P.txt", "r"); //la r es solo para leer.
    if(archivo != NULL){
        for(i=0;i<32;i++){
            fscanf(archivo, "%d", &x);
            P[i]=C[x];
        }
    }
    for(i=0;i<32;i++){
        printf("%d", P[i]);
    }                
    fclose (archivo);
    printf("\n \n");
   return 0;
}


int filasColumnas(int Ba[48], int indice){
    int r, c, i, j;   
    r= Ba[5]*1 + Ba[0]*2;    // representación de la fila (r)
    printf(" Indice: %d", indice);
    printf(" Fila = %d", r);
    c=  Ba[4]*1 + Ba[3]*2 + Ba[2]*4 + Ba[1]*8;
    printf(" Columnas = %d", c);
    printf("\n");
    FILE *archivo=NULL; //Creamos la variable para leer Archivo
    

    if(indice ==1){ 
        archivo = fopen ("S1.txt", "r"); //la r es solo para leer.
        int Matriz[15][15]; 
        if(archivo != NULL)
        {
            printf("\n Caja S1: \n\n");
            for(i=0;i<4;i++){
                for(j=0;j<16;j++){
                    fscanf(archivo, "%d", &Matriz[i][j]);
                    printf("%d ", Matriz[i][j]);
                }
            printf("\n\n");
            }
            printf("C%d: %d \n", indice, Matriz[r][c]);
            return Matriz[r][c];


            
        }       
    }
    if(indice ==2){
        archivo = fopen ("S2.txt", "r"); //la r es solo para leer.
        int Matriz[15][15]; 
        if(archivo != NULL)
        {
            printf("\n Caja S2: \n\n");
            for(i=0;i<4;i++){
                for(j=0;j<16;j++){
                    fscanf(archivo, "%d", &Matriz[i][j]);
                    printf("%d ", Matriz[i][j]);
                }
            printf("\n\n");
            }
            printf("C%d: %d \n", indice, Matriz[r][c] );
            return Matriz[r][c];


            
        }      
    }

    if(indice ==3){
        archivo = fopen ("S3.txt", "r"); //la r es solo para leer.
        int Matriz[15][15]; 
        if(archivo != NULL)
        {
            printf("\n Caja S3: \n\n");
            for(i=0;i<4;i++){
                for(j=0;j<16;j++){
                    fscanf(archivo, "%d", &Matriz[i][j]);
                    printf("%d ", Matriz[i][j]);
                }
            printf("\n\n");
            }
            printf("C%d: %d \n", indice, Matriz[r][c] );
            return Matriz[r][c];

            
        }      
    }

    if(indice ==4){
        archivo = fopen ("S4.txt", "r"); //la r es solo para leer.
        int Matriz[15][15]; 
        if(archivo != NULL)
        {
            printf("\n Caja S4: \n\n");
            for(i=0;i<4;i++){
                for(j=0;j<16;j++){
                    fscanf(archivo, "%d", &Matriz[i][j]);
                    printf("%d ", Matriz[i][j]);
                }
            printf("\n\n");
            }
            printf("C%d: %d \n", indice, Matriz[r][c] );
            return Matriz[r][c];

            
        }      
    }

    if(indice ==5){
        archivo = fopen ("S5.txt", "r"); //la r es solo para leer.
        int Matriz[15][15]; 
        if(archivo != NULL)
        {
            printf("\n Caja S5: \n\n");
            for(i=0;i<4;i++){
                for(j=0;j<16;j++){
                    fscanf(archivo, "%d", &Matriz[i][j]);
                    printf("%d ", Matriz[i][j]);
                }
            printf("\n\n");
            }
            printf("C%d: %d \n", indice, Matriz[r][c] );
            return Matriz[r][c];

            
        }      
    }

    if(indice ==6){
        archivo = fopen ("S6.txt", "r"); //la r es solo para leer.
        int Matriz[15][15]; 
        if(archivo != NULL)
        {
            printf("\n Caja S6: \n\n");
            for(i=0;i<4;i++){
                for(j=0;j<16;j++){
                    fscanf(archivo, "%d", &Matriz[i][j]);
                    printf("%d ", Matriz[i][j]);
                }
            printf("\n\n");
            }
            printf("C%d: %d \n", indice, Matriz[r][c] );
            return Matriz[r][c];

            
        }      
    }

    if(indice ==7){
        archivo = fopen ("S7.txt", "r"); //la r es solo para leer.
        int Matriz[15][15]; 
        if(archivo != NULL)
        {
            printf("\n Caja S7: \n\n");
            for(i=0;i<4;i++){
                for(j=0;j<16;j++){
                    fscanf(archivo, "%d", &Matriz[i][j]);
                    printf("%d ", Matriz[i][j]);
                }
            printf("\n\n");
            }
            printf("C%d: %d \n", indice, Matriz[r][c] );
            return Matriz[r][c];

            
        }      
    }

    if(indice ==8){
        archivo = fopen ("S8.txt", "r"); //la r es solo para leer.
        int Matriz[15][15]; 
        if(archivo != NULL)
        {
            printf("\n Caja S8: \n\n");
            for(i=0;i<4;i++){
                for(j=0;j<16;j++){
                    fscanf(archivo, "%d", &Matriz[i][j]);
                    printf("%d ", Matriz[i][j]);
                }
            printf("\n\n");
            }
            printf("C%d: %d \n", indice, Matriz[r][c] );
            return Matriz[r][c];

            
        }      
    }

    fclose (archivo);

}


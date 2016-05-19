#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

#define DIM 1000
#define BLOCK_DIM 250

using namespace std;

//multiplicacion de 3 ciclos
int** matrixMult(int **m1, int **m2){
   int **m3 = new int*[DIM];
   for(int i = 0; i < DIM; i++){
   	m3[i] = new int[DIM]; 
   } 
   for(int i = 0; i < DIM; i++){ //este primer ciclo recorre filas de la 1era matriz
	for(int j = 0; j < DIM; j++){ //este recorre las columnas de la 2da matriz 
	    int s = 0;
	    for(int k = 0; k < DIM; k++){ //3er ciclo: multiplicacion y suma		
	    	s += m1[i][k]*m2[k][j]; 
	    }
	    m3[i][j] = s;		
	}
    }
    return m3;		
}

//multiplicacion de 6 ciclos por bloques
int** multByBlocks(int **m1, int **m2){
    int **m3 = new int*[DIM];
    for(int i = 0; i < DIM; i++){
   	m3[i] = new int[DIM]; 
    }
    for(int i=0; i<DIM; i+=BLOCK_DIM ){
	for(int j=0; j<DIM; j+=BLOCK_DIM){
	    for(int k=0; k<DIM; k+=BLOCK_DIM){
		for(int a=i; a<i+BLOCK_DIM; a++){
		    for(int b=j; b<j+BLOCK_DIM; b++){
		    	for (int c=k; c<k+BLOCK_DIM; c++){
			    m3[a][b] += m1[a][c]*m2[c][b];	
			}
		    }	
		}		
	    }	
	}
    }
    return m3; 
}

void printMatrix(int **m, int dim){
    for(int i = 0; i < DIM; i++){
    	for(int j = 0; j < DIM; j++){
            cout<<m[i][j]<<" ";	
        }
        cout<<endl;
    }	
    cout<<endl;	
}

int main(){
    srand(time(0));
    //matriz 1	
    int ** m1 = new int*[DIM];
    for(int i = 0; i < DIM; i++){
    	m1[i] = new int[DIM];
        for(int j = 0; j < DIM; j++){
            m1[i][j] = rand()%10;	
        }
    }
  	 	
    //printMatrix(m1, DIM);			
    
    //matriz 2
    int ** m2 = new int*[DIM];
    for(int i = 0; i < DIM; i++){
    	m2[i] = new int[DIM];
        for(int j = 0; j < DIM; j++){
            m2[i][j] = rand()%10;	
        }
    }
  	 	
    //printMatrix(m2, DIM);

    //clock_t begin = clock();
    //cout<<"Multiplicando matrices..."<<endl;	
    //int **m3 = matrixMult(m1, m2);
    //cout<<"Multiplicacion finalizada en:"<< ((double)clock() - begin)/CLOCKS_PER_SEC<<" segundos"<<endl;
    //printMatrix(m3, DIM);
  
    //begin = clock();
    int **m4 = multByBlocks(m1, m2);
    //printMatrix(m4, DIM);	
    /*
    	

   cout<<"Multiplicacion finalizada en:"<< ((double)clock() - begin)/CLOCKS_PER_SEC<<" segundos"<<endl;	
    //printMatrix(m3, DIM);		
	*/
    return 0;	
}

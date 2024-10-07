#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char bulmaca[15][15] = {
        {'A', 'Y', 'D', 'G', 'A', 'R', 'T', 'U', 'A', 'A', 'H', 'I', 'L', 'A', 'L'},
        {'R', 'E', 'I', 'A', 'A', 'M', 'N', 'K', 'L', 'T', 'E', 'M', 'H', 'E', 'M'},
        {'Y', 'R', 'R', 'L', 'A', 'R', 'T', 'B', 'I', 'S', 'D', 'S', 'G', 'A', 'S'},
        {'A', 'S', 'D', 'S', 'M', 'R', 'T', 'U', 'Y', 'U', 'A', 'S', 'O', 'A', 'I'},
        {'A', 'M', 'S', 'A', 'F', 'A', 'E', 'L', 'T', 'R', 'C', 'S', 'Z', 'Z', 'G'},
        {'R', 'R', 'E', 'E', 'S', 'D', 'Z', 'E', 'A', 'G', 'I', 'A', 'D', 'I', 'V'},
        {'A', 'S', 'U', 'U', 'C', 'A', 'N', 'N', 'F', 'T', 'N', 'R', 'E', 'R', 'E'},
        {'A', 'R', 'Y', 'E', 'Z', 'G', 'A', 'T', 'A', 'T', 'A', 'P', 'M', 'U', 'S'},
        {'U', 'T', 'S', 'A', 'R', 'M', 'E', 'S', 'E', 'A', 'R', 'R', 'A', 'G', 'A'},
        {'A', 'A', 'A', 'Z', 'A', 'Y', 'H', 'A', 'N', 'A', 'S', 'V', 'U', 'U', 'Y'},
        {'S', 'E', 'A', 'S', 'D', 'A', 'A', 'P', 'O', 'L', 'Y', 'Y', 'A', 'M', 'S'},
        {'F', 'U', 'R', 'K', 'A', 'E', 'V', 'R', 'E', 'M', 'K', 'L', 'A', 'T', 'O'},
        {'E', 'R', 'T', 'K', 'F', 'U', 'R', 'K', 'A', 'N', 'N', 'N', 'U', 'Y', 'L'},
        {'Z', 'E', 'H', 'R', 'A', 'M', 'M', 'E', 'R', 'Y', 'E', 'M', 'R', 'F', 'M'},
        {'P', 'I', 'N', 'A', 'R', 'N', 'R', 'S', 'U', 'L', 'U', 'T', 'R', 'U', 'K'}
    };
	char kelime[15];
    int i, j, k, kelimeno, a, b;
    int found=0;
    
    scanf("%s", kelime);
    kelimeno=strlen(kelime);
    
    char temp[15][15];
    for(i=0;i<15;i++){
    	for(j=0;j<15;j++){
    		temp[i][j]='*';
		}
	}
    
	for (i = 0; i < 15; i++) {
        for (j = 0; j < 15; j++) { 
            //yatay satir kontrolu SOLDAN SAGA
			if (j <= 15 - kelimeno) {
                found = 1;
                for (k = 0; k < kelimeno; k++) {
                    if (bulmaca[i][j + k] != kelime[k]) {
                        found=0;
                        break;
                    }
                }
				if(found){
					for(k=0;k<kelimeno;k++){
						temp[i][j+k]=kelime[k];
					}
				}
			}
			//SAGDAN SOLA
			if (j >= kelimeno-1) {
                found = 1;
                for (k=0; k<kelimeno; k++) {	
                    if (bulmaca[i][j-k] != kelime[k]) {
                        found=0;
                        break;
                    }
                }
				if(found){
					for(k=0;k<kelimeno;k++){
						temp[i][j-k]=kelime[k];
					}
				}
			}
			//dikey satir kontrolü- YUKARIDAN ASAGI
			if(i<=15-kelimeno){
				found=1;
				for(k=0;k<kelimeno;k++){
					if(bulmaca[i+k][j] != kelime[k]) {
						found=0;
						break;
					}
				}
				if(found){
					for(k=0;k<kelimeno;k++){
						temp[i+k][j]=kelime[k];
					}
				}
			}
			// Asagidan Yukariya kontrol
			if (i>=kelimeno-1) {
    			found = 1;
    			for (k=0; k<kelimeno; k++) {
        			if (bulmaca[i-k][j] != kelime[k]) {
            			found = 0;
            			break;
        			}
    			}
    			if (found) {
        			for(k=0;k<kelimeno;k++){
        				temp[i-k][j]=kelime[k];
					}
    			}
			}
			//capraz kontrol(sol ALTTAN sag USTE)
			if(i<=15-kelimeno && j<= 15-kelimeno){
				found=1;
				for(k=0; k<kelimeno;k++){
					if(bulmaca[i+k][j+k]!=kelime[k]){
						found=0;
						break;
					}
				}
				if(found){
					for(k=0;k<kelimeno;k++){
						temp[i+k][j+k]=kelime[k];
					}
				}
			}
			//capraz kontrol(sag alttan sol üste)
			if(i<=15-kelimeno && j>= kelimeno-1){
				found=1;
				for(k=0;k<kelimeno;k++){
					if(bulmaca[i+k][j-k] != kelime[k]){
						found=0;
						break;
					}
				}
				if(found){
					for(k=0;k<kelimeno;k++){
						temp[i+k][j-k]=kelime[k];
					}
				}
			}
			//capraz kontrol (SAG USTTEN SOL ALTA)
			if (i>=kelimeno-1 && j <= 15 - kelimeno) {
    			found = 1;
    			for (k = 0; k < kelimeno; k++) {
        			if (bulmaca[i-k][j+k] != kelime[k]) {
            			found = 0;
            			break;
        			}
    			}
    			if (found) {
        			for(k=0;k<kelimeno;k++){
        				temp[i-k][j+k]=kelime[k];
					}
    			}
			}
			//capraz kontrol(SOL USTTEN SAG ALTA)
			if (i >=kelimeno-1 && j >=kelimeno-1) {
    			found = 1;
    			for (k = 0; k < kelimeno; k++) {
        			if (bulmaca[i-k][j-k] != kelime[k]) {
            			found = 0;
            			break;
        			}
    			}
    			if (found) {
        			for(k=0;k<kelimeno;k++){
        				temp[i-k][j-k]=kelime[k];
					}
    			}
			}
		}
	}
	
	for(i=0;i<15;i++){
		for(j=0;j<15;j++){
			printf("%c ", temp[i][j]);
		}
		printf("\n");
	}
    return 0;
}

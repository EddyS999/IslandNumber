#include <stdio.h>
#include <stdlib.h>
#define ABS 5
#define ORD 4
int count_island(int tab[ORD][ABS]);
void print_grid(int grid[ORD][ABS]);
int main()
{
    int grid[ORD][ABS] = {
    {1,1,1,1,1},
    {1,1,0,0,1},
    {1,1,0,0,1},
    {0,0,0,0,1},
    };

    print_grid(grid);
    printf("Nombre d'iles : %d", count_island(grid));

    return 0;
}

void mark_current_island(int table[ORD][ABS], int i, int j){

if(i < 0 || j < 0 || table[i][j]!= 1)//limite
    return;

table[i][j] = 2;
//Appel récursif sur les 4 directions
mark_current_island(table, i+1,j);
mark_current_island(table, i-1,j);
mark_current_island(table, i,j+1);
mark_current_island(table, i,j-1);

}

int count_island(int tab[ORD][ABS]){
int count = 0;
for(int i = 0; i < ORD; i++){
        for(int j = 0; j < ABS; j++){
            if(tab[i][j] == 1){
                mark_current_island(tab, i,j);
                count+=1;
            }
        }
}return count;
}

//dessin de la grille
void print_grid(int grid[4][5]){
for(int i = 0; i<4; i++){
    for(int j = 0; j < 5; j++){
        if(grid[i][j] == 1){
            printf("%d ", grid[i][j]);
        }else {
             printf("%d ", grid[i][j]);
        }
    }printf("\n");
  }
}







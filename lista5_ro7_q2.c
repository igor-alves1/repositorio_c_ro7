#include <stdio.h>
#include <stdlib.h>

int ** mult(int m1, int n1, int **mat1, int m2, int n2, int **mat2){
    if(n1 != m2) return 0;

    int **mult_mat = (int **)malloc(sizeof(int*)*m1);

    for (int i=0; i<m1; i++){
        mult_mat[i] = (int *)malloc(sizeof(int)*n2);
    }

    for (int i=0; i<m1; i++){
        for(int j=0; j<n2; j++){
            int num = 0;
            for (int k=0; k<n1; k++){
                num += mat1[i][k]*mat2[k][j];
                printf("%d ", num);
            }

            mult_mat[i][j] = num;
            printf("%d ", mult_mat[i][j]);
            printf("\n%d ", num);
        }
    }

    return mult_mat;
}

int main(){
    int m1, n1, m2, n2;
    int **mult_mat;
    int i, j;

    scanf("%d%d%d%d", &m1, &n1, &m2, &n2);
    int mat1[m1][n1], mat2[m2][n2];
    printf("%d %d %d %d\n", m1, n1, m2, n2);

    for (i=0; i<m1; i++){
        for(j=0; j<n1; j++){
            scanf("%d", &mat1[i][j]);
        }
    }

    for (i=0; i<m2; i++){
        for(j=0; j<n2; j++){
            scanf("%d", &mat2[i][j]);
        }
    }

    int k;

    mult_mat = mult(m1, n1, mat1, m2, n2, mat2);
    for(k=0; k<m1; k++)
        printf("\n");
        for (int p=0; p<n2; p++)
            printf("%d ", mult_mat[k][p]);
        free(mult_mat[k]);

    free(mult_mat);

    return 0;
}

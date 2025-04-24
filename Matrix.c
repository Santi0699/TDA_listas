#include "Matrix.h"
#include "vector.h"
//16
typedef struct _Matrix
{
    t_elem_matrix** a;
    int col;
    int row;
}Matrix;

Matrix* matrix_new(int row, int col)
{
    Matrix* m= (Matrix*)malloc(sizeof(Matrix));

    if(m==NULL){

        puts("Error al reservar memoria para la matriz");
        return NULL;
    }

    m->a = (t_elem_matrix**)malloc(row * sizeof(t_elem_matrix*)); // Reservar punteros a filas
    for (int i = 0; i < row; i++) {
        m->a[i] = (t_elem_matrix*)malloc(col * sizeof(t_elem_matrix)); // Reservar cada fila
    }
    m->row=row;
    m->col=col;


    return m;

}

void free_matrix(Matrix* m)
{
    free(m->a);
    free(m);

}

int matrix_rows(Matrix* m)
{
    return m->row;
}

int matrix_columns(Matrix* m)
{
    return m->col;
}

t_elem_matrix matrix_get(Matrix* m, int row, int col)
{
    return m->a[row][col];
}

void matrix_set (Matrix* m, int row, int col, t_elem_matrix value)
{

    m->a[row][col]=value;
}

void matrix_print(Matrix* m, void (*print)(t_elem_matrix))
{    
    for (int i = 0; i < m->row; i++) {
        for(int j=0; j<m->col; j++)
        {
            print(m->a[i][j]);
        }   // Se imprime cada elemento usando la función pasada
        puts("");
    }
    printf("\n");

}
//17
void matrix_add_random(Matrix* m)
{
    int row=matrix_rows(m);
    int col=matrix_columns(m);


    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++)
        {
            t_elem_matrix value=rand()%10;
            matrix_set(m,i,j,value);
        }
    }

}

void print_int(t_elem_matrix x) {
    printf("|%d| ", x);
}

//18
void matrix_change_row_with_vector(Matrix* m, vector* v,int row_change)
{

    if(m==NULL && v==NULL) return;

    int size = vector_size(v);
    int row=matrix_rows(m);
    int col=matrix_columns(m);

    if(size==col)
    {
        for(int i=0; i<col; i++)
        {
            t_elem_vector value=vector_get(v,i);
            matrix_set(m,row_change,i,(t_elem_matrix)value);
        }
    }

}
//19
void matrix_change_col_with_vector(Matrix* m, vector* v,int col_change)
{

    if(m==NULL && v==NULL) return;

    int size = vector_size(v);
    int row=matrix_rows(m);
    int col=matrix_columns(m);

    if(size==col)
    {
        for(int i=0; i<row; i++)
        {
            t_elem_vector value=vector_get(v,i);
            matrix_set(m,i,col_change,(t_elem_matrix)value);
        }
    }

}
//21
Matrix* matrix_sum(Matrix* m1, Matrix* m2)
{
    int row1=matrix_rows(m1);
    int col1=matrix_columns(m1);
    int row2=matrix_rows(m2);
    int col2=matrix_columns(m2);
    Matrix* result=matrix_new(row1,col1);
    if(row1==row2 && col1==col2)
    {
        for(int i=0; i<row1; i++)
        {
            for(int j=0; j<col1; j++)
            {
                t_elem_matrix value1=matrix_get(m1,i,j);
                t_elem_matrix value2=matrix_get(m2,i,j);
                t_elem_matrix value=value1+value2;
                matrix_set(result,i,j,value);
            }
        }
    }

    return result;

}

Matrix* matrix_sum_vector(Matrix* m1, vector* v)
{
    int row1=matrix_rows(m1);
    int col1=matrix_columns(m1);
    int size=vector_size(v);
    Matrix* result=matrix_new(row1,col1);
    if(col1==size)
    {
        for(int i=0; i<row1; i++)
        {
            for(int j=0; j<col1; j++)
            {
                t_elem_matrix value1=matrix_get(m1,i,j);
                t_elem_matrix value2=(t_elem_matrix)vector_get(v,j);
                t_elem_matrix value=value1+value2;
                matrix_set(result,i,j,value);
            }
        }
    }

    return result;

}

Matrix* matrix_mult(Matrix* m1, Matrix* m2)
{
    int row1=matrix_rows(m1);
    int col1=matrix_columns(m1);
    int row2=matrix_rows(m2);
    int col2=matrix_columns(m2);
    
    if(col1 != row2)
    {
        return NULL;
    }
    
    Matrix* result=matrix_new(row1,col2);

    for (int i=0; i<row1;i++)
    {   
        t_elem_matrix value = 0;
        for (int j = 0; j < col2; j++)
        {
            for(int k=0; k<col1;k++)
            {
                t_elem_matrix v1=matrix_get(m1,i,k);
                t_elem_matrix v2=matrix_get(m2,k,i);
                value= value+ v1*v2;

            }
            matrix_set(result,i,j,value);
        }

    }

    return result;


}

t_elem_matrix matrix_determinant_recursive(Matrix* m) {
    if (matrix_rows(m) != matrix_columns(m)) {
        puts("Error: La matriz no es cuadrada");
        return 0;
    }

    int n = matrix_rows(m);
    if (n == 1) return matrix_get(m, 0, 0); // Caso base: 1x1
    if (n == 2) {
        return matrix_get(m, 0, 0) * matrix_get(m, 1, 1) - 
               matrix_get(m, 0, 1) * matrix_get(m, 1, 0); // Caso base: 2x2
    }

    t_elem_matrix det = 0;
    for (int j = 0; j < n; j++) {
        // Crear menor eliminando la fila 0 y columna j
        Matrix* minor = matrix_new(n - 1, n - 1);
        
        for (int i = 1; i < n; i++) { // Desde la fila 1 (omitir fila 0)
            int minor_col = 0;
            for (int k = 0; k < n; k++) {
                if (k == j) continue; // Omitir la columna j
                matrix_set(minor, i - 1, minor_col, matrix_get(m, i, k));
                minor_col++;
            }
        }

        // Expansión de cofactores
        t_elem_matrix cofactor = (j % 2 == 0 ? 1 : -1) * matrix_get(m, 0, j) * matrix_determinant_recursive(minor);
        det += cofactor;

        free_matrix(minor); // Liberar memoria del menor
    }

    return det;
}

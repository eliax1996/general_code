/**
 *
 * sudo gdb a.out
 *
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * @param the vector
 * @param the size of the vector
 *
 * this function print out the vector (monodimensional)
 * that you pass
 */
void stampa_vett(int v[],int dim){
    if (dim < 1)
        return;

    stampa_vett(v,dim-1);
    printf("posizione: %d    valore: %d\n",dim-1,v[dim-1]);
}

void merge(int v[],int min,int max,int med,int s[]){
    int sx=min,dx=med+1,t=0;

    while (sx <= med || dx <= max){

        if (sx > med){
            s[t++] = v[dx++];
            continue;
        }

        if (dx > max){
            s[t++] = v[sx++];
            continue;
        }

        if (v[dx] > v[sx]){
            s[t++] = v[sx++];
        } else {
            s[t++] = v[dx++];
        }

    }

    for (t = 0;t < max-min+1;t++)
        v[min+t] = s[t];

}


void merge_sort_r(int v[],int min,int max,int s[]){
    int med = (max-min)/2;

    if ((max - min)<=0)
        return;


    merge_sort_r(v,min,med+min,s);
    merge_sort_r(v,min+med+1,max,s);
    merge(v,min,max,med+min,s);
}

/**
 * @param the vector
 * @param the size of the vector
 *
 * this function is the implementation of
 * the merge sort in c
 */
void merge_sort(int v[],int size){

    int *temp = malloc(sizeof(int)*size);
    merge_sort_r(v,0,size-1,temp);
    free(temp);

}

void custom_merge(int v1[],int size1,int v2[],int size2,int *used_cells,int* res){
    int sx = 0,dx = 0;

    while (sx < size1 && dx < size2){
        if (v1[sx] < v2[dx]){
            if (res[(*used_cells)-1] != v1[sx])
                res[(*used_cells)++] = v1[sx++];
            else
                sx++;
        } else {
            if (res[(*used_cells)-1] != v2[dx])
                res[(*used_cells)++] = v2[dx++];
            else
                dx++;
        }
    }

    while (sx < size1){
        if (res[(*used_cells)-1] != v1[sx])
            res[(*used_cells)++] = v1[sx++];
        else
            sx++;
    }

    while (dx < size2){
        if (res[(*used_cells)-1] != v2[dx++])
            res[(*used_cells)++] = v2[dx++];
        else
            dx++;
    }

    res[(*used_cells)++] = -1;
}

/**
 * @param the first vector
 * @param the second vector
 * @param the size of the first vector
 * @param the size of the second vector
 * @return a new vector that represent the
 * difference between the first - the second
 * vector
 *
 * to find the next element in the return vector
 * you can check-it by finding -1 in the vector
 * value
 */
int* difference(int v1[],int v2[],int size1,int size2){
    int* temp = (int*) malloc(sizeof(int)*(size1+size2));
    int used_cells = 0;

    merge_sort(v1,size1);
    merge_sort(v2,size2);

    custom_merge(v1,size1,v2,size2,&used_cells,temp);

    temp = realloc(temp,used_cells);


    printf("risultato:\n");
    stampa_vett(temp,used_cells);

    return temp;
}

int main(int argc,char **argv){

    int v1[] = {8,1,10,11,1,3,5,7};
    int v2[] = {2,4,10,8,6};
    int v3[] = {5,6,7,8,9,10};

    int *d = difference(v2,v3,5,6);

    d++;

}

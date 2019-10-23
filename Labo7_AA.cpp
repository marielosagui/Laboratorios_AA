// A Dynamic Programming solution for Rod cutting problem 
#include<stdio.h> 
#include<limits.h> 


int max(int a, int b) { return (a > b)? a : b;}

int numBarras; //contador de trozos de barras

int cutRod(int price[], int barras[], int n)  

{
    int val[n+1];
    int ultimaBarra[n+1]; //ultimo trozo de barra que se va utilizando
    val[0] = 0;
    int i, j;

    for (i = 1; i<=n; i++)
    {
        int max_val = INT_MIN;
        int mejorPosicion = -1;   //Posicion en la que se guradará el trozo de barra
        for (j = 0; j < i; j++)
        {
            if(max_val < price[j] + val[i-j-1])
            {
                max_val = price[j] + val[i-j-1];
                mejorPosicion = j;
            }
        }

        val[i] = max_val;
        ultimaBarra[i] = mejorPosicion + 1;
    }

    for (i = n, j = 0; i>0; i -= ultimaBarra[i])
    {
        barras[j++] = ultimaBarra[i];
    }

    numBarras = j;
    return val[n];
}


int main()
{
    int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int size = sizeof(arr)/sizeof(arr[0]);
    int barras[size+1];
    int i;
    printf("Maximo obtenido es %d\n", cutRod(arr, barras, size));

    printf("\nCantidad de barras: %d\n", numBarras);

    printf("Longitud de barras: %d", barras[0]);

    for(i = 1; i < numBarras; i++)
    {
        printf(" %d", barras[i]);
    }

    printf("\n");
    getchar();
    return 0;
}
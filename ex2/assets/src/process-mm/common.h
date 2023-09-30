
#define SIZE 1000000

void 
fill_array(int *array, int size)
{
    srand(time(NULL));

    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % ( 5 + 1 );
    }
}

void 
print_array(int *array, int size)
{
    printf("[ ");

    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }

    printf("]\n");
}

struct args {
    
    int * array;
    int size;
    int start;

}; 

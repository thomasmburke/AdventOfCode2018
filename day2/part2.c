// Pythons zip function in c (transposes 2 lists)
int **zip(int *arr1, int *arr2, int length)
{
    int **ret = new int*[length];
    for(int i = 0; i<length; i++)
    {
        ret[i] = new int[2];
        ret[i][0] = arr1[i];
        ret[i][1] = arr2[i];
    }
    return ret;
}

int main(){

return 0;
}

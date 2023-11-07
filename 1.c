#include <stdio.h>
void generateNewSet(int arr[], int n){
    int new_arr[n];
    int new_size = 0;
    for (int i = 0; i < n; i += 2){
        if (i + 1 < n) {
            new_arr[new_size] = arr[i] + arr[i+1];
        } else {
            new_arr[new_size] = arr[i];
        }
        new_size++;
    }
    for (int i=0; i<new_size; i++){
        arr[i] = new_arr[i];
    }
}
int main(){
    int values[10];
    for (int i = 0; i < 10; i++){
        scanf("%d", &values[i]);
    }
    printf("%d", values[0]);
    for (int i = 1; i < 10; i++){
        printf(" %d", values[i]);
    }
    printf("\n");
    while (1){
        int count = 0;
        for (int i = 0; i < 10; i++){
            if (i < 9){
                values[i] = values[i] + values[i+1];
            }
            if (i % 2==0){
                printf("%d", values[i]);
                count++;
            } else{
                printf(" %d", values[i]);
                if (count == 5){
                    printf("\n");
                    count = 0;
                }
            }
        }
        if (count != 0){
            printf("\n");
        }
        if (values[0] == values[1]){
            break;
        }
    }
    return 0;
}

#include <stdio.h>
int get_input(); //gets user input for max
int compute_sum(); //computes the sum of multiples of 3 or 5 for the number given


int main()
{
printf("Multiples of 3 or 5!\n");
int max = get_input();
printf("Your multiples are:\n");
int sum = compute_sum(max);
printf("And your total sum is: %d\n", sum);
return 0;

}


//prompts user to enter the maximum number then sends it to main.
int get_input(){
    int inp = 0;
    printf("Enter a maximum [1,999999]: ");
    scanf("%d", &inp);
    if (inp < 1 || inp>999999){
        printf("ERROR: number not in range [1,999999]\n");
        return get_input();
    }
    return inp;

}

//calculates the multiples of 3 or 5 and then finds the sum of them
int compute_sum(int val){
    int sum = 0;
    int i;
    for (i=0; i < val; i++){
        if (i%3==0 || i%5==0){
            printf("%d\n",i);
            sum += i;
        }
        
    }
    return sum;
}
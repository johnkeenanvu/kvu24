// Program indicates whether an integer is postive, negative, or zero and if it is a multiple of 3 or not 


#include <stdio.h>
int main()
{
int number;
printf("Enter an integer: "); 
scanf("%d", &number);




// Is number positve negative or zero? 
if (number == 0)
{
    printf("%d is zero.\n", number);

}

else if (number < 0)
{
    printf("%d is not postive.\n", number);
    printf("%d is negative.\n", number); 
}
else 
{
    printf("%d is positive\n", number);
    printf("%d is not negative\n", number); 
}


//Is the number a multiple of 3?
if ((number%3)==0)
{
    printf("%d is a multiple of 3.\n", number);
}
else
{
    printf("%d is not a multiple of 3\n.", number);
}

return 0; 
}


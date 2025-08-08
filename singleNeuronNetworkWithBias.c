#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>


//we are adding the bias to make the model train with the function 
//f(x) = 2x+5 , where 5 is the y intercept . 
// hence absence of bias will be a total failure to calculate as it forces the model to pass through
// the orign . we have to make the y = mx + c , y intercept to calibrate to 5 .thus the purpose of adding the bias to the model
// we will caliberate the bias and the initial weight using a small value to tweak
float train_data[][2]={
    {0,0},
    {1}
};


float random_weight(void){
    return (float)rand()/(float) RAND_MAX;
}

int main()
{
    srand(5000);
    float weight;
    weight = 1.0f + random_weight()*9.0f;
    printf("Generated weight : %f ",weight);
    



}

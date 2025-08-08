#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// we are adding the bias to make the model train with the function
// f(x) = 2x+5 , where 5 is the y intercept .
//  hence absence of bias will be a total failure to calculate as it forces the model to pass through
//  the orign . we have to make the y = mx + c , y intercept to calibrate to 5 .thus the purpose of adding the bias to the model
//  we will caliberate the bias and the initial weight using a small value to tweak
float train_data[][2] = {
    {0, 0},
    {1, 7},
    {2, 9},
    {3, 11},
    {4, 13},
    {5, 15},
    {6, 17},
    {7, 19},
    {8, 21},
    {9, 23},
    {10, 25}};

#define train_count sizeof(train_data) / sizeof(train_data[0])

float random_weight(void)
{
    return (float)rand() / (float)RAND_MAX;
}

float cost(float weight, float bias)
{
    float prediction, result = 0.0f,difference;
    for (size_t i = 0; i < train_count; i++)
    {
        prediction = train_data[i][0]*weight+bias;
        difference = train_data[i][1]-prediction;
        difference*=difference;
        result+=difference;
    }
    return (float)result/train_count;
}

int main()
{
    srand(5000);
    float weight;
    float rate,bias,output;
    rate=1e-3;
    bias=1e-3;
    weight = 1.0f + random_weight() * 9.0f;
    printf("Generated weight : %f ", weight);

    printf("\nPredicted values before the training\n");
    for (size_t i = 0; i < train_count; i++)
    {
        output = train_data[i][0]*weight+bias;
        printf("input value : %f , expected output : %f , predicted output : %f \n",train_data[i][0],train_data[i][1],output);
    }
    printf("Initial cost function : %f\n",cost(weight,bias));
    


}

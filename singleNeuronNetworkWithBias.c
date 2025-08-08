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
    {0, 5},
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
    float learning_rate,bias,output;
    bias = 0.1f;
    learning_rate=0.01f;
    weight = 1.0f + random_weight() * 9.0f;
    printf("Generated weight : %f , initial bias : %f ", weight,bias);

    printf("\nPredicted values before the training\n");
    for (size_t i = 0; i < train_count; i++)
    {
        output = (train_data[i][0]*weight)+bias;
        printf("input value : %f , expected output : %f , predicted output : %f \n",train_data[i][0],train_data[i][1],output);
    }
    printf("\n\n\nInitial cost function : %f\n\n\n",cost(weight,bias));
    float dw,db;
    float x,y,predicted,error;

    for (size_t i = 0; i < 10000; i++)
    {
        dw=0.0f;
        db=0.0f;
        for (size_t j = 0; j < train_count; j++)
        {
            x=train_data[j][0];
            y=train_data[j][1];
            predicted=x*weight+bias;
            error=y-predicted;

            dw+= -2.0f*error*x;
            db+= -2.0f*error;
        }

        dw/=train_count;
        db/=train_count;
        weight-=learning_rate*dw;
        bias-=learning_rate*db;
        
        if((i+1)%1000==0){
            printf("cost function after %d iteration : %f \n",i+1,cost(weight,bias));
            printf("dw : %f db :%f weight : %f bias : %f \n",dw,db,weight,bias);
        }
        
    }
    
    



    printf("\nPredicted values after the training\n");
    float actual_total=0.0f,predicted_total=0.0f;
    for (size_t i = 0; i < train_count; i++)
    {
        output = (train_data[i][0]*weight)+bias;
        printf("input value : %f , expected output : %f , predicted output : %f \n",train_data[i][0],train_data[i][1],output);
        actual_total+=train_data[i][1];
        predicted_total+=output;
    }
    float percent;
    // percent = (float)(fabs((float)predicted_total- (float)actual_total)/(float)actual_total)*100.0f;



    percent = (float)fabs((float)(actual_total>predicted_total?predicted_total:actual_total)/(float)(actual_total>predicted_total?actual_total:predicted_total))*100.0f;
    printf("\n\n accuracy of the model : %f %% \n\n",percent);

    printf("\nweight after training : %f , bias after training  %f \n", weight,bias);

    float input;
    while(1){
        printf("\nEnter the input : ");
        scanf("%f",&input);
        printf("Input : %f \n Actual expected output : %f \n Predicted input using the model : %f ",input,(float)((2*input)+5),(float)((weight*input)+bias));
    }

}

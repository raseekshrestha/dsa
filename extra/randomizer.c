#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int main(){
    srand(time(0));
    char arr[26];
    int random,temp;

    char names[47][40] = {"Rashik Shrestha","Reebhu Adhikari","Usha Suwal","Alok Khadka","Amshu Man Maharjan","Binisha Naga","Shisant ","Rachana Shrestha","Sayal Karki","Sailesh Achhami","Sarad Kathayat","Samyog Dhital","Manish Karki","Prashant Bista","Praveen Shrestha","Milan Gyawali","Amish Chaudhary","Aabhash Basnet","Nayan Shrestha","Kamal Soud","Nulok Rai","Perisa Koirala","Shriya Shrestha","Ivaan Prajapati","Lasta Pudasaini","Smarika Shrestha","Nirdesika Chuhan","Suzana Pyakhurel","Shirish Shrestha","Pranjal Neupane","Salil Shrestha","Suchak Niraula","Sulav Karki","Rohan Taujale","Saransh Sharma","Saurav Kathayat","Aastha Shrestha","Anmol Shrestha","Sisam Ghaju","Rachana Ghaju","Reya Awal","Krima Madhi","Sareena Shrestha","Rubeen Shrestha","Rohan Karanjit","Chirag Ds","Deepika Sainju"};
    char tempName[40];

    for (int i=0;i<47;i++){
        for (int j=0;j<46-i;j++){
            if (strcmp(names[j] , names[j+1]) > 0){
                strcpy(tempName, names[j+1]);
                strcpy(names[j+1] , names[j]);
                strcpy(names[j] , tempName);
            }
        }
    }

    for (int i=0;i<26;i++){
        arr[i] = 65 + i;
    }

    //randomly shuffle letters
    for (int i=0;i<26;i++){
        random = rand() % 26;
        temp = arr[i];
        arr[i] = arr[random];
        arr[random] = temp;
    }

    for (int i=0;i<26;i++){
        for (int j=0;j<47;j++){
            // printf("hey %d\n",i);
            if(arr[i] == names[j][0]){
                printf("%s\n",names[j]);
            }
        }
    }
}
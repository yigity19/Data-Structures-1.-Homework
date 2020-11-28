/* @Author
Student Name: <YUNUS EMRE YİĞİT>
Student ID : <150190107>
Date: <11.11.2020> */

#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "counter.h"

using namespace std;

	
int Counter::findindex(Token *arr,char elem[]){
	//THIS FUNCTION WILL BE CODED BY YOU
    for (int i = 0;i <100;i++){
        if (strcmp(arr[i].token,elem) == 0)
            return i;
    }

    return -1;

} 

bool Counter::contains(char *token, char target){
	//THIS FUNCTION WILL BE CODED BY YOU
    return true;
}

void Counter::read_and_count(){
	//THIS FUNCTION WILL BE CODED BY YOU
 
  char filename[] = "pi_approximate";
  FILE* file;
  file= fopen( filename, "r+" );
  if (!file){
    cout<< "file couldn't be loaded";
  }
else{

    char ch;
    int digit_num = 0;
    while ((ch = fgetc(file)) != EOF){
        digit_num++;
    }

    fseek(file,0,SEEK_SET);
    char pi[digit_num+5];
    fgets(pi,digit_num+1,file);
    //std::cout<<pi;
    long long int len = strlen(pi)-2;
    char nums[len][3];
    int j = 2;
    //int counter = 0;

    //GETTING ALL THE 2 DIGITS NUMS FROM PI DECIMAL
    for (int i = 0; i < len-1; i++){
      nums[i][0] = pi[j];
      nums[i][1] = pi[j+1];
      nums[i][2] = '\0';
      j+=1;
      token_count++;
      }

    //FILLING TOKEN_ARRAY.TOKEN WITH NUMS 00 TO 99
    for (int i =0;i<10;i++){
        for (int j = 0; j< 10;j++)
        {   
            token_array[i*10+j].token[0] = '0' + i;
            token_array[i*10+j].token[1] = '0' + j;
            token_array[i*10+j].token[2] = '\0';
        }
        
    }

    //MAKING ALL THE COUNT VALUES 0
    for (int i=0;i<100;i++) token_array[i].count =0;
    //for (int i=0;i<counter;i++) cout<<nums[i]<<endl;

    //COUNTING PROCESS
    for (int i =0;i<len-2;i++){
        int tens = ((nums[i][0])-'0') * 10;
        int ones = (nums[i][1])-'0';
        int place = ones + tens;
        int counter = 0;
        for (int j=i;j<len;j++){
            if (strcmp(nums[i],nums[j]) == 0){
                counter++;
            }
        } 
        //cout<<place<<" "<<counter<<endl;
        if (token_array[place].count == 0)
            token_array[place].count=counter;
     
      }

    }
    
}


Token *Counter::get_most_common_three(){
	//THIS FUNCTION WILL BE CODED BY YOU
    //Token* common = new Token[3];
    static Token common[3];
    //for (int i =0; i< 100;i++) printf("%d %d \n",i,counts[i]);
    /*int big = token_array[1].count;
    int med = token_array[1].count;
    int small = token_array[1].count;*/
    int big,med;
    int curr = token_array[1].count;
    for (int i =2;i<100;i++){
        if (token_array[i].count>=curr){
            curr = token_array[i].count;
            common[0].token[0] = '0' + (i / 10);
            common[0].token[1] = '0' + (i % 10);
            common[0].token[2] = '\0';
            big = i;
            common[0].count = curr;
        }
    }
    curr = 0;
    for (int i =2;i<100;i++){
        if (token_array[i].count>curr && i != big){
            curr = token_array[i].count;
            common[1].token[0] = '0' + (i / 10);
            common[1].token[1] = '0' + (i % 10);
            common[1].token[2] = '\0';
            common[1].count = curr;
            med = i;
        }
    }
    curr = 0;
    
    for (int i =2;i<100;i++){
        if (token_array[i].count>curr && i!= big && i!= med ){
            curr = token_array[i].count;
            common[2].token[0] = '0' + int(i / 10);
            common[2].token[1] = '0' + int(i % 10);
            common[2].token[2] = '\0';
            common[2].count = curr;
        }
    }
    //for (int i =0;i<3;i++) cout<<common[i].token<<"  "<<common[i].count<<endl;
    //Token* adress = common;
    
    return common;
    
}

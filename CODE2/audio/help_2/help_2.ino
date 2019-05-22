
#include <uspeech.h>
#define led 13

#define MIN3(a, b, c) ((a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c)))
signal voice(A0);
const int BUFFER_MAX_PHONEMES=32;
char inputString[BUFFER_MAX_PHONEMES]; // Allocate some space for the string
byte index = 0; // Index into array; where to store the character
//
const int DICT_MAX_ELEMNTS=3;
char dict[DICT_MAX_ELEMNTS][BUFFER_MAX_PHONEMES]={"eeeooovvvooovvooo","hhhvooofffffffeee"};  //,"eeeooofffffffoovvvoo"
int LOWEST_COST_MAX_THREASHOLD=13;
void setup(){
  
  voice.f_enabled = true;
  voice.minVolume = 1500;
  voice.fconstant = 680;
  voice.econstant = 2;
  voice.aconstant = 3;
  voice.vconstant = 6;
  voice.shconstant = 13;
  voice.calibrate();
  Serial.begin(9600);
  pinMode(led, OUTPUT); 
  
}
 
void loop(){
   voice.sample();
 
    char p = voice.getPhoneme();
    if(p==' ' || index >= BUFFER_MAX_PHONEMES){
      if(strLength(inputString)>0){
         /*Serial.println("received:"+String(inputString));*/
         parseCommand(inputString);
         inputString[0]=0;//clear string char array
         index=0;
      }
    }else{
      //printArray(voice.arr);
      inputString[index] = p; // Store it
      index++;
      inputString[index] = '\0'; // Null terminate the string
    }
    
}
 
char* guessWord(char* target){
  int len = strlen(target);//held target length
   
  for(int i=0;i<DICT_MAX_ELEMNTS;i++){
    //simple validation
    if(dict[i]==target){
      return dict[i];
    }
  }
   
  unsigned int cost[DICT_MAX_ELEMNTS];//held minimum distance cost
 
  //calculating each words cost and hits
  for(int j=0;j<DICT_MAX_ELEMNTS;j++){//loop through the dictionary
      cost[j]=levenshtein(dict[j],target);
      /*Serial.println("dict[j]="+String(dict[j])+" target="+String(target)+" cost="+String(cost[j]));*/
  }    
   
  //Determining lowest cost but still all letters in the pattern hitting word
  int lowestCostIndex=-1;
  int lowestCost=LOWEST_COST_MAX_THREASHOLD;
  for(int j=0;j<DICT_MAX_ELEMNTS;j++){//loop through the dictionary
    //Serial.println("dict[j]="+dict[j]+" dict[j].length()="+String(strlen(dict[j]))+" cost="+String(cost[j])+" hits="+String(hits[j])+" j="+String(j));
    if(cost[j]<lowestCost){
      lowestCost = cost[j];
      lowestCostIndex=j;
    }
  }
   
  //Serial.println("lowestCostIndex="+String(lowestCostIndex)+" lowestCost="+String(lowestCost));
   
  if(lowestCostIndex>-1){
    //Serial.println("lowestCost="+String(lowestCost)+" lowestCostIndex="+String(lowestCostIndex));
    return dict[lowestCostIndex];
  }else{
    return "";
  }
}
 
void parseCommand(char* str){
  char *gWord = guessWord(str);
  /*Serial.println("guessed :"+String(gWord));*/
  if(gWord==""){
    digitalWrite(led, LOW);
    return;
  }else if(gWord==dict[0] || gWord==dict[1] ){
    digitalWrite(led, HIGH);
    Serial.println("help");
  }
  else{
    
    digitalWrite(led, LOW);
  }
}
 
unsigned int levenshtein(char *s1, char *s2) {
    unsigned int s1len, s2len, x, y, lastdiag, olddiag;
    s1len = strlen(s1);
    s2len = strlen(s2);
    unsigned int column[s1len+1];
    for (y = 1; y <= s1len; y++)
        column[y] = y;
    for (x = 1; x <= s2len; x++) {
        column[0] = x;
        for (y = 1, lastdiag = x-1; y <= s1len; y++) {
            olddiag = column[y];
            column[y] = MIN3(column[y] + 1, column[y-1] + 1, lastdiag + (s1[y-1] == s2[x-1] ? 0 : 1));
            lastdiag = olddiag;
        }
    }
    return(column[s1len]);
}
 
int strLength(char const* s) {
    int i = 0;
    while (s[i] != '\0' && s[i] != ' ')
        ++i;
 
    return i;
}

    

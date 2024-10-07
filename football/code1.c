#include <stdio.h>
int orders[10000][5];
 
void resetorders(){
	// initalize orders
	for (int i = 0; i <= 9999; i++) {
		for (int j = 0; j <= 4; j++) {
			orders[i][j] = 0;
		}
	}	
}
int checkorders(int toCheck[5]){
	
	for (int i = 0; i < 10000; i++) {
	if (toCheck[0]==0 && toCheck[1]==0 && toCheck[2]==0 && toCheck[3]==0 && toCheck[4]==0){
		return 0;
	}
	if(toCheck[0]==orders[i][0] && toCheck[1]==orders[i][1] && toCheck[2]==orders[i][2] && toCheck[3]==orders[i][3] && toCheck[4]==orders[i][4]){
		return 1;
	}
	}
	return 0;
}
void recuse(int score, int eight, int seven, int six, int three, int two, int realscore){
int cool [5] = {0,0,0,0,0};

	for (int plays = 4; plays >= 0; plays--) {
		
	   if(plays==4){
		  for (; eight>0; eight--) {
			
		      score-=8;
		      cool[0]+=1;
		  }
	   }
	   else if(plays==3){
	       for(; seven>0; seven--){
			
		   score-=7;
		   cool[1]+=1;
	       }
	   }
	   else if(plays==2){
	       for(; six>0; six--){
			
		   score-=6;
		   cool[2]+=1;
	       }
	   }
	   else if(plays==1){
	       for(; three>0;three--){
			
		   score-=3;
		   cool[3]+=1;
	       }
	   }
	   else if(plays==0){
	       for(; two>0;two--){
			
		   score-=2;
		   cool[4]+=1;
	       }
	   }
	    
	
	}
	if(score>=0){
	if(checkorders(cool)==0){
	for (int i = 0; ; i++){
		if(orders[i][0]==0 && orders[i][1]==0 && orders[i][2] == 0  && orders[i][3]==0 && orders[i][4]==0){
			for(int j = 0; j <5; j++){
				orders[i][j]=cool[j];
			}
			break;
		}
	}
	if(score==0){
	    printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",cool[0],cool[1],cool[2],cool[3],cool[4]);
	}
	else{
	   if(score-8>=0 ){
	       recuse(realscore,cool[0]+1,cool[1],cool[2],cool[3],cool[4], realscore);
	   }
	   if(score-7>=0){
	       recuse(realscore,cool[0],cool[1]+1,cool[2],cool[3],cool[4], realscore);
			
	   }
	  if(score-6>=0){
		recuse(realscore,cool[0],cool[1],cool[2]+1,cool[3],cool[4], realscore);
		
	   }
	  if(score-3>=0){
	       recuse(realscore,cool[0],cool[1],cool[2],cool[3]+1,cool[4], realscore);
			
	   }
	  if(score-2>=0 ){
	       recuse(realscore,cool[0],cool[1],cool[2],cool[3],cool[4]+1, realscore);
			
		   
	   }
	   
	}
	
	}}

}
int main(int argc, char *argv[])
{	

	printf("Enter 0 or 1 to STOP\nEnter the nfl score: ");
	int score;
	scanf("%d",&score);
	while(score>1){
		resetorders();
	    recuse(score,0,0,0,0,0, score);
	    scanf("%d",&score);
	}
	return 1;
}



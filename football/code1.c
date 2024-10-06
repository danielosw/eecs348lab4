#include <stdio.h>
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
	if(score==0){
	    printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",cool[0],cool[1],cool[2],cool[3],cool[4]);
	}
	else{
	   if(score-8>=0){
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
	    if(score-2>=0){
	       recuse(realscore,cool[0],cool[1],cool[2],cool[3],cool[4]+1, realscore);
			
		   
	   }
	   
	}}

}
int main(int argc, char *argv[])
{
	int score;
	
	scanf("%d",&score);
	while(score>1){
	    recuse(score,0,0,0,0,0, score);
	    scanf("%d",&score);
	}
	return 1;
}



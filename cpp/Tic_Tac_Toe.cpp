#include<bits/stdc++.h>

using namespace std;





int main(){
        

        int t;
        cin>>t;

        
        
        
   while(t--){
        char a[3][3];
   int x=0,y=0,count=0;
   for(int i=0;i<3;i++){
       for(int j=0;j<3;j++){
           cin>>a[i][j];
            if(a[i][j]=='X'){
                x++;
            }
            if(a[i][j]=='O'){
                y++;
            }
            if(a[i][j]=='_'){
                count++;
            }
       }
   }

   
        
            
            int jaihind=0,jaihindmerebhai=0;
    if(a[0][0]==a[0][1]&&a[0][1]==a[0][2]&&a[0][1]=='X'){
        jaihind=1;
        
    }
    if(a[1][0]==a[1][1]&&a[1][1]==a[1][2]&&a[1][1]=='X'){
        jaihind=1;
        
    }
    if(a[2][0]==a[2][1]&&a[2][1]==a[2][2]&&a[2][1]=='X'){
        jaihind=1;
        
    }
    if(a[1][0]==a[0][0]&&a[0][0]==a[2][0]&&a[0][0]=='X'){
        jaihind=1;
        
    }
    if(a[1][1]==a[0][1]&&a[0][1]==a[2][1]&&a[0][1]=='X'){
        jaihind=1;
        
    }
    if(a[1][2]==a[0][2]&&a[0][2]==a[2][2]&&a[0][2]=='X'){
        jaihind=1;
        
    }
    if(a[1][1]==a[0][0]&&a[1][1]==a[2][2]&&a[0][0]=='X'){
        jaihind=1;
        
    }
    if(a[0][2]==a[1][1]&&a[1][1]==a[2][0]&&a[1][1]=='X'){
        jaihind=1;
        
    }

     if(a[0][0]==a[0][1]&&a[0][1]==a[0][2]&&a[0][1]=='O'){
        jaihindmerebhai=1;
        
    }
    if(a[1][0]==a[1][1]&&a[1][1]==a[1][2]&&a[1][1]=='O'){
        jaihindmerebhai=1;
        
    }
    if(a[2][0]==a[2][1]&&a[2][1]==a[2][2]&&a[2][1]=='O'){
        jaihindmerebhai=1;

    }
    if(a[1][0]==a[0][0]&&a[0][0]==a[2][0]&&a[0][0]=='O'){
        jaihindmerebhai=1;
        
    }
    if(a[1][1]==a[0][1]&&a[0][1]==a[2][1]&&a[0][1]=='O'){
        jaihindmerebhai=1;
        
    }
    if(a[1][2]==a[0][2]&&a[0][2]==a[2][2]&&a[0][2]=='O'){
        jaihindmerebhai=1;
    
    }
    if(a[1][1]==a[0][0]&&a[1][1]==a[2][2]&&a[0][0]=='O'){
        jaihindmerebhai=1;
        
    }
    if(a[0][2]==a[1][1]&&a[1][1]==a[2][0]&&a[1][1]=='O'){
        jaihindmerebhai=1;
    
    }
    
    if((jaihind==1&&jaihindmerebhai==1)||x-y<0||x-y>1){         
         cout<<3<<"\n";                      
        
    }
    else if(x==0&&y==0&&count==9){
        cout<<2<<"\n";
    }
    else if(jaihind==1&&x>y){
        cout<<1<<"\n";
    }
    else if(jaihindmerebhai==1&&x==y){
        cout<<1<<"\n";
    }
    else if(jaihind==0&&jaihindmerebhai==0&&count==0){
        cout<<1<<"\n";
    }
    else if(jaihind==0&&jaihindmerebhai==0&&count>0){
        cout<<2<<"\n";
    }else{
        cout<<3<<"\n";
    }
        
  }
    
 return 0;
}
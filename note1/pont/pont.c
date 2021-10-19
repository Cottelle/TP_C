#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc,char **argv){
    if (argc !=3 && argc !=4){
        return 42;
    }
    if (argc ==3){
    int D,H;
    D=atoi(argv[1]);
    H=atoi(argv[2]);
    if(D<0 || H< 0){
        return 42;
    }
    int res=D*21534;
    res+=(D/72)*H*9047;
    printf("%i\n",res);
    }
    else{
        int D,H1,H2;
        long double res=0;
        D=atoi(argv[1]);
        H1=atoi(argv[2]);
        H2=atoi(argv[3]);
        //printf("H1=%i  ,H2=%i  ,D=%i\n",H1,H2,D);
        if(D<0 || H1<0 || H2<0){
            return 42;
        }
        if(D<0 || H1< 0 || H2<0){
            return 42;
        }
        if(D==0){
            printf("0\n");
        }
        else{
        long double alpha= (H2-H1);
        alpha=alpha/D; //D!=0
        //printf("alpha=%Lf\n",alpha);
        int nbpillier=D/72;
        //printf("nbpillier= %i\n",nbpillier);
        res+=sqrt(pow(H1-H2,2)+pow(D,2))*21534;
        if(H2<H1){
        for(int i=1;i<nbpillier+1;i++){
            printf("ok\n");
            res+=(H2-(alpha*i*72))*9047;
        }
        }
        if (H1<=H2){
            for(int i=1;i<nbpillier+1;i++){
                //printf("res avant= %Lf\n",res);
                res+=(H1+(alpha*(D-i*72)))*9047;
            }
        }
        

        }
        int resultat= res;
        //printf("resultat= %i\n",resultat);
        //printf("res= %Lf\n",res);
        double test= res -resultat;
        if (test>=0.5){
            resultat+=1;
        }
        //printf("test=%f\n",test);
        printf("%i\n",resultat);


    }
    return 0;
}
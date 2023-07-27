/* KNN */

# include <stdio.h>
#include <math.h>

int main(){
  float a, b, c, d, distM, w, x, y, z, dist;
  int classeR, classe, classeP, acerto = 0;

  FILE *arquivoTeste = fopen("IrisTeste.txt","r");
  FILE *arquivoTreino = fopen("IrisTreino.txt","r");
  while(!feof(arquivoTeste)){
    distM = 1;
  fscanf(arquivoTeste,"%f,%f,%f,%f,%d",&a,&b,&c,&d,&classeR);
  //printf("%f,%f,%f,%f,%d",a,b,c,d,classeR);
  arquivoTreino = fopen("IrisTreino.txt","r");
  while(!feof(arquivoTreino)){
    fscanf(arquivoTreino,"%f,%f,%f,%f,%d",&w,&x,&y,&z,&classe);
    //printf("%f,%f,%f,%f,%d",w,x,y,z,classe);
    dist = sqrt(pow(w-a, 2)+ pow(x-b, 2) + pow(y-c, 2) + pow(z-d,2));
    if(dist < distM){
      distM = dist;
      classeP = classe;
    }
  }
     if(classeP == classeR){
    acerto++;
  fclose(arquivoTreino);
  }
   }
   fclose(arquivoTeste);
   printf("\nQuantidae de Acertos: %d", acerto);
   printf("\nPorcentagem de Acertos: %d", (acerto/45)*100);
  return 0;
}
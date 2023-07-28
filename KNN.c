/* KNN */

# include <stdio.h>
#include <math.h>

int main(){
  float a, b, c, d, k, w, x, y, z, dist; 
  int classeR, classe, classeP, acerto = 0;

  /*Abrindo arquivos*/
  FILE *arquivoTeste = fopen("IrisTeste.txt","r");
  FILE *arquivoTreino = fopen("IrisTreino.txt","r");
  while(!feof(arquivoTeste)){
    k = 1; // instanciando k sendo igual a 1
  fscanf(arquivoTeste,"%f,%f,%f,%f,%d",&a,&b,&c,&d,&classeR); // leitura de arquivo
  arquivoTreino = fopen("IrisTreino.txt","r"); // abrindo arquivo
  while(!feof(arquivoTreino)){
    fscanf(arquivoTreino,"%f,%f,%f,%f,%d",&w,&x,&y,&z,&classe); // leitura de arquivo
    dist = sqrt(pow(w-a, 2)+ pow(x-b, 2) + pow(y-c, 2) + pow(z-d,2)); // calculando a distancia
    /*Com o if se instancia as classes*/
    if(dist < k){
      k = dist;
      classeP = classe;
    }
  }
    /*Conta quantidade de acertos*/
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
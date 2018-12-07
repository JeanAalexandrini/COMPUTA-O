#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int i=0;
    double a[1000], fx[1000],fs[1000],fc[1000],Qs[1000],Qc[1000];
    double SOMA=0, MEDIAseno=0, MEDIAcos=0, MEDIA=0;

    FILE *arq=NULL;
    arq=fopen("C:\\Users\\jeana\\Desktop\\ENTRADA.txt","r"); //LEITURA DOS PONTOS
    if (arq==NULL){
        printf("ERRO AO ABRIR O ARQUIVO! \n");
        exit(1);
    }

    i=0;
    while(fscanf(arq,"%lf",&a[i])!=EOF){
          i++;
    }

    for (i=0;i<1000;i++){ //UTILIZANDO OS PONTOS RECEBIDOS E MULTIPLICANDO ELES POR SENO E COSSENO
        fx[i]=sin(a[i]);
        fs[i]=sin(a[i]);
        fc[i]=cos(a[i]);
        Qs[i]=fs[i]*fx[i];
        Qc[i]=fc[i]*fx[i];
    }

    arq=fopen("C:\\Users\\jeana\\Desktop\\SAIDA.txt","w"); //GRAVANDO OS NOVOS PONTOS EM UM NOVO ARQUIVO
    if (arq==NULL){
        printf("ERRO AO ABRIR O ARQUIVO! \n");
        exit(1);
    }

    for (i=0;i<1000;i++){
        fprintf(arq,"%lf\n",Qs[i]);
    }

    SOMA=0;
    for (i=0;i<1000;i++){
        SOMA= SOMA + Qs[i];
    }

    MEDIAseno=SOMA/1000*2;

    SOMA=0;
    for (i=0;i<1000;i++){
        SOMA= SOMA + Qc[i];
    }

    MEDIAcos=SOMA/1000*2;

    atan(MEDIAseno/MEDIAcos);

    printf("ANGULO DE FASE: %lf\n",atan(MEDIAseno/MEDIAcos));

    sqrt(pow(MEDIAseno,2)+pow(MEDIAcos,2));

    printf("AMPLITUDE: %lf\n",sqrt(pow(MEDIAseno,2)+pow(MEDIAcos,2)));

    MEDIA= sqrt(pow(MEDIAseno,2)+pow(MEDIAcos,2))/2;
    printf("R MEDIA: %lf\n", MEDIA);

    fclose(arq);

    if (arq==NULL){
        printf("ERRO AO ABRIR O ARQUIVO! \n");
        exit(1);
    }

    for (i=0;i<1000;i++){
        fprintf(arq,"%lf %lf\n", a[i],fx[i]);
    }

    fclose(arq);

    system("C:\\Users\\jeana\\Downloads\\gnuplot\\gnuplot\\bin\\gnuplot -p C:\\Users\\jeana\\Desktop\\SCRIPT2.txt");
    system("C:\\Users\\jeana\\Downloads\\gnuplot\\gnuplot\\bin\\gnuplot -p C:\\Users\\jeana\\Desktop\\SCRIPT3.txt");

    return 0;
}

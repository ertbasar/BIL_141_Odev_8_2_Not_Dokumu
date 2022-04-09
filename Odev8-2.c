#include <stdio.h>
#include <conio.h>
#include <string.h>
double ortfonk(int i);
int main()
{
	printf("\tNot dokumu uygulamasina hos geldiniz\n\n");
	FILE* notdosya=fopen("ogrenci_notlari.txt","r");
	FILE* bilgidosya=fopen("ogrenci_bilgileri.txt","r");
	if(notdosya==NULL){
		printf("\tBu programin bulundugu klasorde ogrenci_notlari.txt isimli dosya\n\tolmadan bu kod calismaz.");
		getch();
		return 1;
	}
	if(bilgidosya==NULL){
		printf("\tBu programin bulundugu klasorde ogrenci_bilgileri.txt isimli dosya\n\tolmadan bu kod calismaz.");
		getch();
		return 1;
	}
	char xxx[75][75]={},xxxfake[75][75]={};
	double yyy[75]={},ortalama,yyyfake;
	int i=0,j,a,n;
	while((feof(bilgidosya))==0){
		fscanf(bilgidosya, " %[^\n]s",xxx[i]);
		i++;
		}
		i=0;
	while((feof(notdosya))==0){
		fscanf(notdosya, " %lf", &yyy[i]);
		i++;
	}
	ortalama=ortfonk(i);
	j=i-1;
	i=0;
	printf("\tOkunan veri girisi su sekilde\n\n");
	for(i;i<j;i++){
		printf("\t%s\t%.2lf\n",xxx[i],yyy[i]);
	}	
	printf("\n\tBu verilere gore not ortalamasi %.1lf'dir.\n\t*****************************************\n\n",ortalama);
	for(a=0;a<i-1;a++){
		for(n=0;n<i-1;n++){
			if(yyy[n]>yyy[n+1]){
			yyyfake=yyy[n];
			yyy[n]=yyy[n+1];
			yyy[n+1]=yyyfake;

			strcpy(xxxfake[n],xxx[n]);
			strcpy(xxx[n],xxx[n+1]);
			strcpy(xxx[n+1],xxxfake[n]);
			}
		}
	}
	j=i-1;
	i=0;
		for(i;i<j+1;i++){
		printf("\t%s\t%.2lf\n",xxx[i],yyy[i]);}
	printf("\n\tBu verilere gore en dusuk not:\n\t%s->%.1lf",xxx[0], yyy[0]);
	printf("\t\n	Bu verilere gore en yuksek not:\n\t%s->%.1lf",xxx[j], yyy[j]);
	printf("\n\n\t\tGule Gule :)");
	getch();
	return 0;
	}
double ortfonk(int i){
	i=0;
	int b;
	double gecici=0.0;
	FILE* notdosya=fopen("ogrenci_notlari.txt","r");
	double yyy[75]={};
	while((feof(notdosya))==0){
		fscanf(notdosya, " %lf", &yyy[i]);
		i++;
	}
	b=i-1;
	i=0;
	for(i;i<b;i++){
	gecici=gecici+yyy[i];
	}
	gecici=gecici/(b);
	return gecici;
		}	

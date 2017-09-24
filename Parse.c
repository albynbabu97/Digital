#include<stdio.h>
#include<string.h>
void main()
{
	char put[200];
	int input=0,output=0,and=0,or=0,not=0,nand=0,nor=0,xor=0;
	FILE *fp1,*fp2;
	fp1=fopen("Bench.bench","r");
	fp2=fopen("Out.txt","w");
	while(!feof(fp1))
	{
		while(fgets(put,sizeof(put),fp1))
		{
			if(put[0]=='#')
				continue;
			else
				if(strstr(put,"INPUT")!=NULL)
					input++;
				else if(strstr(put,"OUTPUT")!=NULL)
					output++;
				if(strstr(put,"and")!=NULL)
				{
					if(strcmp(put,"nand")==0)
						and++;
				}
				if(strstr(put,"or")!=NULL)
				{
					if((strcmp(put,"xor")==0)&&(strcmp(put,"nor")==0))
						or++;
				}
				if(strstr(put,"not")!=NULL)
					not++;
				if(strstr(put,"nand")!=NULL)
					nand++;
				if(strstr(put,"nor")!=NULL)
					nor++;
				if(strstr(put,"xor")!=NULL)
					xor++;
				fprintf(fp2,"%s",put);
		}
		fprintf(fp2,"\nTotal No. of inputs : %d\nTotal No. of outputs : %d\n",input,output);
		fprintf(fp2,"\nTotal No. of AND gates : %d",and);
		fprintf(fp2,"\nTotal No. of OR gates : %d",or);
		fprintf(fp2,"\nTotal No. of NOT gates : %d",not);
		fprintf(fp2,"\nTotal No. of NAND gates : %d",nand);
		fprintf(fp2,"\nTotal No. of NOR gates : %d",nor);
		fprintf(fp2,"\nTotal No. of XOR gates : %d",xor);
	}
	fclose(fp1);
	fclose(fp2);
}

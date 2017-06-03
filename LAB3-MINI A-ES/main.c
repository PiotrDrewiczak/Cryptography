#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int i=0,j;
int policz1;
int policz2;
int k[2][8]={{1,1,1,1,0,0,1,1},{0,1,1,1,0,0,1,1}};
int sbox1[4];
int sbox2[4];
int k1[2][8];
int k_pomoc[4]={0,0,0,1};
int k2[2][8];
int k_pomoc2[4]={0,0,1,0};
int t[2][8]={{0,0,1,1,1,1,1,1},{0,0,0,0,1,0,0,1}};
int k0w[2][8];
// OBLICZANIE DO 3 PKT // 
int przelicz1=0; int przelicz2=0; int przelicz3=0; int przelicz4=0;
int w1[4];int w4[4];int w2[4];int w3[4];
// ZK
int w5[4];
// MNOZENIE
int m_a[7]; int m_b[7]; int m_c[7]; int m_d[7];
// MACIERZ
int s_m1[4]={0,0,1,1}; int s_m2[4]={0,0,1,0}; int s_m3[4]={0,0,1,0}; int s_m4[4]={0,0,1,1};
//WYNIK
int wynik1[7],wynik2[7],wynik3[7],wynik4[7],wynik5[7],wynik6[7],wynik7[7],wynik8[7];
int w_wynik1[7],w_wynik2[7],w_wynik3[7],w_wynik4[7];
int mod[5]={1,0,0,1,1};
int d_wynik1[7],d_wynik2[7],d_wynik3[7],d_wynik4[7],d_wynik5[7],d_wynik6[7],d_wynik7[7],d_wynik8[7];
int dzielenie1[6],dzielenie2[6],dzielenie3[6],dzielenie4[6];
int przesuniecie[4]={1,2,3,4};
// DODAWANIE KLUCZA 1 DO MMA
int dod1[4],dod2[4],dod3[4],dod4[4];
// DOD klucz 2
int dkl1[4],dkl2[4],dkl3[4],dkl4[4];
void dklucz2(void)
{
printf("PO DODANIU KLUCZA 2:");
for(i=0;i<4;i++)
{
dkl3[i]=(dod3[i]+k2[1][i])%2;
dkl1[i]=(dod1[i]+k2[0][i])%2;	
}

for(i=4;i<8;i++)
{ 
	dkl2[i-4]=(dod2[i-4]+k2[0][i])%2;
	dkl4[i-4]=(dod4[i-4]+k2[1][i])%2;
}

for(i=0;i<4;i++)
printf("%i",dkl1[i]);
for(i=0;i<4;i++)
printf("%i",dkl2[i]);
for(i=0;i<4;i++)
printf("%i",dkl3[i]);
for(i=0;i<4;i++)
printf("%i",dkl4[i]);
printf("\n");

}
void zk2(void)
{
	printf("TWOJ KLUCZ PO ZASTOSOWANIU ZK(A):");
	for(i=0;i<4;i++)
	{
	w5[i]=dod4[i];
	dod4[i]=dod3[i];
	dod3[i]=w5[i];
	}
	for(i=0;i<4;i++)
	printf("%i",dod1[i]);
	for(i=0;i<4;i++)
	printf("%i",dod2[i]);
	for(i=0;i<4;i++)
	printf("%i",dod3[i]);
	for(i=0;i<4;i++)
	printf("%i",dod4[i]);
	printf("\n");
	dklucz2();
}
void fsboxo(int w[],int a)
{
if (a==0)
		{
		w[0]=1; w[1]=1; w[2]=1; w[3]=0;
		}
		else if (a==8)
		{
		w[0]=0; w[1]=1; w[2]=0; w[3]=0;
		}
		else if (a==4)
		{
		w[0]=1; w[1]=1; w[2]=0; w[3]=1;
		}
		else if (a==12)
		{
		w[0]=0; w[1]=0; w[2]=0; w[3]=1;
		}
		else if (a==2)
		{
		w[0]=0; w[1]=0; w[2]=1; w[3]=0;
		}
		else if (a==10)
		{
		w[0]=1; w[1]=1; w[2]=1; w[3]=1;
		}
		else if (a==6)
		{
		w[0]=1; w[1]=0; w[2]=1; w[3]=1;
		}
		else if (a==14)
		{
		w[0]=1; w[1]=0; w[2]=0; w[3]=0;
		}
		else if (a==1)
		{
		w[0]=0; w[1]=0; w[2]=1; w[3]=1;
		}
		else if (a==9)
		{
		w[0]=1; w[1]=0; w[2]=1; w[3]=0;
		}
		else if (a==5)
		{
		w[0]=0; w[1]=1; w[2]=1; w[3]=0;
		}
		else if (a==13)
		{
		w[0]=1; w[1]=1; w[2]=0; w[3]=0;
		}
		else if (a==3)
		{
		w[0]=0; w[1]=1; w[2]=0; w[3]=1;
		}
		else if (a==11)
		{
		w[0]=1; w[1]=0; w[2]=0; w[3]=1;
		}
		else if (a==7)
		{
		w[0]=0; w[1]=0; w[2]=0; w[3]=0;
		}
		else
		{
		w[0]=0; w[1]=1; w[2]=1; w[3]=1;	
		}
			
}

void policzmy(void)
{
	przelicz1=0;
	przelicz2=0;
	przelicz3=0;
	przelicz4=0;
	for(i=0;i<4;i++)
					{
						if(dod1[i]==1)
						{
							przelicz1=przelicz1+pow(2,i);
						}
					}
			for(i=0;i<4;i++)
					{
					if(dod3[i]==1)
						{
							przelicz3=przelicz3 + pow(2,i);	
						}
					}
			for(i=0;i<4;i++)
					{
					if(dod2[i]==1)
							{
								przelicz2=przelicz2+pow(2,i);	
							}
					}
			for(i=0;i<4;i++)
					{
					if(dod4[i]==1)
							{
								przelicz4=przelicz4+pow(2,i);	
							}
					}

			fsboxo(dod1,przelicz1);
			fsboxo(dod2,przelicz2);
			fsboxo(dod3,przelicz3);
			fsboxo(dod4,przelicz4);		
				printf("TWOJA WIADOMOSC PO ZASTOSOWANIU FSBOX(A,E):");
	for(i=0;i<4;i++)
	printf("%i",dod1[i]);
	for(i=0;i<4;i++)
	printf("%i",dod2[i]);
	for(i=0;i<4;i++)
	printf("%i",dod3[i]);
	for(i=0;i<4;i++)
	printf("%i",dod4[i]);
	printf("\n");
	zk2();

}


void dodanie_klucz1(void)
{
	printf("MM(A) + KLUCZ 1 RUNDY:");
		for(i=0;i<4;i++)
			{
				dod1[i]=(k1[0][i]+dzielenie1[i])%2;
				dod3[i]=(k1[1][i]+dzielenie3[i])%2;
			}
		for(i=4;i<8;i++)	
			{
				dod2[i-4]=(k1[0][i]+dzielenie2[i-4])%2;
				dod4[i-4]=(k1[1][i]+dzielenie4[i-4])%2;	
			}
		for(i=0;i<4;i++)
		printf("%i",dod1[i]);
		for(i=0;i<4;i++)
		printf("%i",dod2[i]);
		for(i=0;i<4;i++)
		printf("%i",dod3[i]);
		for(i=0;i<4;i++)
		printf("%i",dod4[i]);
		printf("\n");
		policzmy();
}



void dzielenie(int a[],int b[])
{
	do
	{
	
		if(a[0]==0 && a[1]==0 && a[2]==0)
			{
					//printf("TWOJ CIAG TO:");
						for(i=3;i<7;i++)
						{
							b[i-3]=a[i];
							//printf("%i",b[i-3]);
						}
							
						
			}	
		else if(a[0]==1)
			{
			for(i=0;i<7;i++)
			b[i]=(a[i]+mod[i])%2;
				if(b[1]==1)
					{
							for(i=1;i<7;i++)
								{		
								b[i-1]=(b[i]+mod[i-1])%2;		
								}	
								if(b[1]==1)
									{
										for(i=1;i<6;i++)
										{
										b[i-1]=(b[i]+mod[i-1])%2;	
										}
										for(i=0;i<4;i++)
										b[i]=b[przesuniecie[i]];
									}
					}	
			}	
		else if(a[1]==1)
		{
		for(i=0;i<6;i++)	
			{
			b[i]=(a[i+1]+mod[i])%2;
			}
				if(b[1]==1)
						{
							for(i=0;i<5;i++)
									{
									b[i]=(b[i+1]+mod[i])%2;	
									}
									for(i=0;i<4;i++)
										b[i]=b[przesuniecie[i]];	
						}
		}
		else if(a[2]==1)
			{
				for(i=0;i<5;i++)
					{
						b[i]=(a[i+2]+mod[i])%2;
					}
					for(i=0;i<4;i++)
							b[i]=b[przesuniecie[i]];
			}
			i++;
			}while(i<5);

}
void mnozenie(int a[],int b[],int c[],int d[],int e[],int f[],int g[])
{	
for(i=0;i<7;i++)
{
b[i]=0;c[i]=0;d[i]=0;e[i]=0;// WYPELNIANIE TABLIC ZERAMI
}
			for(j=6;j>2;j--)
					{          // g=sm_1{1,0,1,1} 
					b[j]=g[j-3]*a[3]; //b=m_a[7]	
					
					}
			for(j=5;j>1;j--)
					{
					c[j]=g[j-2]*a[2];		
					}
							
			for(j=4;j>0;j--)
					{
					d[j]=g[j-1]*a[1];
					}
			for(j=3;j>-1;j--)
					{
					e[j]=g[j]*a[0];
					}
					// DODAWANIE
					for(i=6;i>-1;i--)
					{
					f[i]=(b[i]+c[i]+d[i]+e[i])%2;
					}		
}
void ZK(void)
{
	printf("TWOJ KLUCZ PO ZASTOSOWANIU ZK(A):");
	for(i=0;i<4;i++)
	{
	w5[i]=w4[i];
	w4[i]=w3[i];
	w3[i]=w5[i];
	}
	for(i=0;i<4;i++)
	printf("%i",w1[i]);
	for(i=0;i<4;i++)
	printf("%i",w2[i]);
	for(i=0;i<4;i++)
	printf("%i",w3[i]);
	for(i=0;i<4;i++)
	printf("%i",w4[i]);
	printf("\n");

mnozenie(w1,m_a,m_b,m_c,m_d,wynik1,s_m1);
dzielenie(wynik1,d_wynik1);
mnozenie(w3,m_a,m_b,m_c,m_d,wynik2,s_m2);
dzielenie(wynik2,d_wynik2);
mnozenie(w2,m_a,m_b,m_c,m_d,wynik3,s_m1);
dzielenie(wynik3,d_wynik3);
mnozenie(w4,m_a,m_b,m_c,m_d,wynik4,s_m2);
dzielenie(wynik4,d_wynik4);
mnozenie(w1,m_a,m_b,m_c,m_d,wynik5,s_m3);
dzielenie(wynik5,d_wynik5);
mnozenie(w3,m_a,m_b,m_c,m_d,wynik6,s_m4);
dzielenie(wynik6,d_wynik6);
mnozenie(w2,m_a,m_b,m_c,m_d,wynik7,s_m3);
dzielenie(wynik7,d_wynik7);
mnozenie(w4,m_a,m_b,m_c,m_d,wynik8,s_m4);
dzielenie(wynik8,d_wynik8);
printf("TWOJA MACIERZ PO MM(A):");
for(i=0;i<4;i++)
{
dzielenie1[i]=(d_wynik1[i]+d_wynik2[i])%2;
dzielenie2[i]=(d_wynik3[i]+d_wynik4[i])%2;
dzielenie3[i]=(d_wynik5[i]+d_wynik6[i])%2;
dzielenie4[i]=(d_wynik7[i]+d_wynik8[i])%2;	
}
for(i=0;i<16;i++)
{
if(i<4)
printf("%i",dzielenie1[i]);
else if(i<8)
printf("%i",dzielenie2[i-4]);
else if(i<12)
printf("%i",dzielenie3[i-8]);
else
printf("%i",dzielenie4[i-12]);
}
printf("\n");
}
void wyswietlenie(void)
{
	printf("TWOJA WIADOMOSC PO ZASTOSOWANIU FSBOX(A,E):");
	for(i=0;i<4;i++)
	printf("%i",w1[i]);
	for(i=0;i<4;i++)
	printf("%i",w2[i]);
	for(i=0;i<4;i++)
	printf("%i",w3[i]);
	for(i=0;i<4;i++)
	printf("%i",w4[i]);
	printf("\n");
	ZK();
}
void fsbox(int w[],int a)
{
if (a==0)
		{
		w[0]=1; w[1]=1; w[2]=1; w[3]=0;
		}
		else if (a==8)
		{
		w[0]=0; w[1]=1; w[2]=0; w[3]=0;
		}
		else if (a==4)
		{
		w[0]=1; w[1]=1; w[2]=0; w[3]=1;
		}
		else if (a==12)
		{
		w[0]=0; w[1]=0; w[2]=0; w[3]=1;
		}
		else if (a==2)
		{
		w[0]=0; w[1]=0; w[2]=1; w[3]=0;
		}
		else if (a==10)
		{
		w[0]=1; w[1]=1; w[2]=1; w[3]=1;
		}
		else if (a==6)
		{
		w[0]=1; w[1]=0; w[2]=1; w[3]=1;
		}
		else if (a==14)
		{
		w[0]=1; w[1]=0; w[2]=0; w[3]=0;
		}
		else if (a==1)
		{
		w[0]=0; w[1]=0; w[2]=1; w[3]=1;
		}
		else if (a==9)
		{
		w[0]=1; w[1]=0; w[2]=1; w[3]=0;
		}
		else if (a==5)
		{
		w[0]=0; w[1]=1; w[2]=1; w[3]=0;
		}
		else if (a==13)
		{
		w[0]=1; w[1]=1; w[2]=0; w[3]=0;
		}
		else if (a==3)
		{
		w[0]=0; w[1]=1; w[2]=0; w[3]=1;
		}
		else if (a==11)
		{
		w[0]=1; w[1]=0; w[2]=0; w[3]=1;
		}
		else if (a==7)
		{
		w[0]=0; w[1]=0; w[2]=0; w[3]=0;
		}
		else
		{
		w[0]=0; w[1]=1; w[2]=1; w[3]=1;	
		}
			
}
void k0_wiadomosc(void)
{
	for(j=0;j<2;j++)
		{
			for(i=0;i<8;i++)
				{
				k0w[j][i]=(t[j][i]+k[j][i])%2;	
				}
		}
		printf("KLUCZ 0 + WIADOMOSC T:");
		for(j=0;j<2;j++)
		{
			for(i=0;i<8;i++)
				{
				printf("%i",k0w[j][i]);	// MOJE A:
				}
		}	
		printf("\n");
		for(i=0;i<4;i++)
					{
						if(k0w[0][i]==1)
						{
							przelicz1=przelicz1+pow(2,i);
						}
					}
			for(i=0;i<4;i++)
					{
					if(k0w[1][i]==1)
						{
							przelicz3=przelicz3 + pow(2,i);	
						}
					}
			for(i=4;i<8;i++)
					{
					if(k0w[0][i]==1)
							{
								przelicz2=przelicz2+pow(2,i-4);	
							}
					}
			for(i=4;i<8;i++)
					{
					if(k0w[1][i]==1)
							{
								przelicz4=przelicz4+pow(2,i-4);	
							}
					}

			fsbox(w1,przelicz1);
			fsbox(w2,przelicz2);
			fsbox(w3,przelicz3);
			fsbox(w4,przelicz4);
	}

				


void klucz_2(void)
{
for(i=0;i<4;i++)
	{
		k2[0][i]=(k1[0][i]+sbox2[i]+k_pomoc2[i])%2;
	}
	for(i=0;i<4;i++)
	{
		k2[1][i]=(k1[1][i]+k2[0][i])%2;
	}
	for(i=4;i<8;i++)
	{
		k2[0][i]=(k1[0][i]+k2[1][i-4])%2;
	}
	for(i=4;i<8;i++)
	{
	k2[1][i]=(k1[1][i]+k2[0][i])%2;	
	}
	printf("KLUCZ 2 RUNDY TO:");
	for(j=0;j<2;j++)
	{
		for(i=0;i<8;i++)
			{
				printf("%i",k2[j][i]);
			}
	}
	printf("\n");
}
void sboxy2(void)
{
		if (policz2==0)
		{
		sbox2[0]=1; sbox2[1]=1; sbox2[2]=1; sbox2[3]=0;
		}
		else if (policz2==8)
		{
		sbox2[0]=0; sbox2[1]=1; sbox2[2]=0; sbox2[3]=0;
		}
		else if (policz2==4)
		{
		sbox2[0]=1; sbox2[1]=1; sbox2[2]=0; sbox2[3]=1;
		}
		else if (policz2==12)
		{
		sbox2[0]=0; sbox2[1]=0; sbox2[2]=0; sbox2[3]=1;
		}
		else if (policz2==2)
		{
		sbox2[0]=0; sbox2[1]=0; sbox2[2]=1; sbox2[3]=0;
		}
		else if (policz2==10)
		{
		sbox2[0]=1; sbox2[1]=1; sbox2[2]=1; sbox2[3]=1;
		}
		else if (policz2==6)
		{
		sbox2[0]=1; sbox2[1]=0; sbox2[2]=1; sbox2[3]=1;
		}
		else if (policz2==14)
		{
		sbox2[0]=1; sbox2[1]=0; sbox2[2]=0; sbox2[3]=0;
		}
		else if (policz2==1)
		{
		sbox2[0]=0; sbox2[1]=0; sbox2[2]=1; sbox2[3]=1;
		}
		else if (policz2==9)
		{
		sbox2[0]=1; sbox2[1]=0; sbox2[2]=1; sbox2[3]=0;
		}
		else if (policz2==5)
		{
		sbox2[0]=0; sbox2[1]=1; sbox2[2]=1; sbox2[3]=0;
		}
		else if (policz2==13)
		{
		sbox2[0]=1; sbox2[1]=1; sbox2[2]=0; sbox2[3]=0;
		}
		else if (policz2==3)
		{
		sbox2[0]=0; sbox2[1]=1; sbox2[2]=0; sbox2[3]=1;
		}
		else if (policz2==11)
		{
		sbox2[0]=1; sbox2[1]=0; sbox2[2]=0; sbox2[3]=1;
		}
		else if (policz2==7)
		{
		sbox2[0]=0; sbox2[1]=0; sbox2[2]=0; sbox2[3]=0;
		}
		else
		{
		sbox2[0]=0; sbox2[1]=1; sbox2[2]=1; sbox2[3]=1;	
		}
		
		klucz_2();	
}

void liczenie_binarne2(void)
{
	for(i=4;i<8;i++)	
		{
			if(k1[1][i]==1)
				{
				policz2=policz2+pow(2,i-4);
				}
					
		}	
		sboxy2();
}
void klucz_1(void)
{
	for(i=0;i<4;i++)
			{
			k1[0][i]=(k[0][i]+sbox1[i]+k_pomoc[i])%2;
		
			}	
	for(i=0;i<4;i++)
			{
			k1[1][i]=(k[1][i]+k1[0][i])%2;		
			}
	for(i=4;i<8;i++)
			{
			k1[0][i]=(k[0][i]+k1[1][i-4])%2;
			}
	for(i=4;i<8;i++)
			{
			k1[1][i]=(k[1][i]+k1[0][i])%2;
			}
	printf("KLUCZ 1 RUNDY TO:");
	for(j=0;j<2;j++)
	{
		for(i=0;i<8;i++)
			{
				printf("%i",k1[j][i]);
			}
	}

	printf("\n");
	liczenie_binarne2();
			
}
void sboxy(void)
{
		if (policz1==0)
		{
		sbox1[0]=1; sbox1[1]=1; sbox1[2]=1; sbox1[3]=0;
		}
		else if (policz1==8)
		{
		sbox1[0]=0; sbox1[1]=1; sbox1[2]=0; sbox1[3]=0;
		}
		else if (policz1==4)
		{
		sbox1[0]=1; sbox1[1]=1; sbox1[2]=0; sbox1[3]=1;
		}
		else if (policz1==12)
		{
		sbox1[0]=0; sbox1[1]=0; sbox1[2]=0; sbox1[3]=1;
		}
		else if (policz1==2)
		{
		sbox1[0]=0; sbox1[1]=0; sbox1[2]=1; sbox1[3]=0;
		}
		else if (policz1==10)
		{
		sbox1[0]=1; sbox1[1]=1; sbox1[2]=1; sbox1[3]=1;
		}
		else if (policz1==6)
		{
		sbox1[0]=1; sbox1[1]=0; sbox1[2]=1; sbox1[3]=1;
		}
		else if (policz1==14)
		{
		sbox1[0]=1; sbox1[1]=0; sbox1[2]=0; sbox1[3]=0;
		}
		else if (policz1==1)
		{
		sbox1[0]=0; sbox1[1]=0; sbox1[2]=1; sbox1[3]=1;
		}
		else if (policz1==9)
		{
		sbox1[0]=1; sbox1[1]=0; sbox1[2]=1; sbox1[3]=0;
		}
		else if (policz1==5)
		{
		sbox1[0]=0; sbox1[1]=1; sbox1[2]=1; sbox1[3]=0;
		}
		else if (policz1==13)
		{
		sbox1[0]=1; sbox1[1]=1; sbox1[2]=0; sbox1[3]=0;
		}
		else if (policz1==3)
		{
		sbox1[0]=0; sbox1[1]=1; sbox1[2]=0; sbox1[3]=1;
		}
		else if (policz1==11)
		{
		sbox1[0]=1; sbox1[1]=0; sbox1[2]=0; sbox1[3]=1;
		}
		else if (policz1==7)
		{
		sbox1[0]=0; sbox1[1]=0; sbox1[2]=0; sbox1[3]=0;
		}
		else
		{
		sbox1[0]=0; sbox1[1]=1; sbox1[2]=1; sbox1[3]=1;	
		}
		klucz_1();
}

void liczenie_binarne(void)
{
for(i=4;i<8;i++)	
{
		if(k[1][i]==1)
		{
			policz1=policz1+pow(2,i-4);
		}	
}
sboxy();
}


int main() 
{
	printf("KLUCZ 0 RUNDY TO:");
	for(j=0;j<2;j++)
	{
		for(i=0;i<8;i++)
		{
			printf("%i",k[j][i]);
		}
	}
	printf("\n");
	liczenie_binarne();
	k0_wiadomosc();
	wyswietlenie();
	dodanie_klucz1();
	system("PAUSE");
	return 0;
}

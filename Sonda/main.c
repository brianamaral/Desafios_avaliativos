#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Sonda
{
	int linha;
	int coluna;
};

void preencher_plato(int ** plato);
void print_plato(int **plato,struct Sonda sonda);

void mover_sonda(int ** plato,struct Sonda * sonda,char direcao,int espacos,int ** obstaculos);
int ** gerar_obstaculos();


int main(void)
{
	srand(time(0));
	
	struct Sonda sonda;
	sonda.linha = 0;
	sonda.coluna = 0;
	
	int ** obstaculos = gerar_obstaculos();
	
	int **plato = malloc(sizeof(int*) * 10);
	int i;
	for(i = 0; i < 10;i++)
		plato[i] = (int * )malloc(sizeof(int) * 20);
	
	preencher_plato(plato);
	
	char direcao;
	int espacos;
	
	while(true)
	{
		printf("\nDigite seu comando:");
		scanf(" [%c %d]",&direcao,&espacos);
		fflush(stdin);
		if(direcao == '0' && espacos == 0)
		{	
			print_plato(plato,sonda);
		}
		else if(direcao != '0')
		{
			mover_sonda(plato,&sonda,direcao,espacos,obstaculos);	
		}
		else
		{
			printf("Digite o comando corretamente");
		}
				
	}
			
}

void mover_sonda(int ** plato,struct Sonda * sonda,char direcao,int espacos,int ** obstaculos)
{
	int i,dirx,diry,tempx,tempy;
	dirx = 0;
	diry = 0;
	
	tempx = sonda->linha;
	tempy = sonda->coluna;
	
	switch(direcao)
	{
		case 'N':
			dirx = -1;
			break;
		case 'S':
			dirx = 1;
			break;
		case 'L':
			diry = 1;
			break;
		case 'O':
			diry = -1;
			break;
					
	}
		
	for(i = 1; i <= espacos; i++)
	{	
		
		sonda->linha += dirx;
	
		sonda->coluna += diry;
		
		if(sonda->linha > 9 || sonda->linha  < 0 || sonda->coluna > 19 || sonda->coluna < 0 )
		{
			sonda->linha = tempx;
			sonda->coluna = tempy;
			
			printf("FAILED");
			break;		
		}
		
		else if(plato[sonda->linha][sonda->coluna] == 2 || obstaculos[sonda->linha][sonda->coluna] == 2)
		{
			
			plato[sonda->linha][sonda->coluna] = 2;
			sonda->linha = tempx;
			sonda->coluna = tempy;
			
			printf("FAILED");
			break;	
		}
			
		plato[sonda->linha][sonda->coluna] = 1;
	
		tempx = sonda->linha;
	
		tempy = sonda->coluna;
		
		if(i == espacos)
		{
			printf("SUCESS");		
		}	
	} 
}


int ** gerar_obstaculos()
{
	
		
	int i;
	
	int ** obstaculos = malloc(sizeof(int*)*10);
	for(i = 0; i < 10; i++)
		obstaculos[i] = malloc(sizeof(int)*20);
	
	
	for(i = 0; i < 50; i++)
	{
		int x = rand() % 9;
		int y = rand() % 19;
		if(obstaculos[x][y] == 2 || x == 0 && y == 0)
		{
			i--;
			continue;
		}
		
		obstaculos[x][y] = 2;
		
	}
	return obstaculos;
}


void preencher_plato(int ** plato)
{
	int i,j,t;
	for(i = 0; i < 10;i++)
	{
		for(j = 0; j < 20; j++)
		{
			t++;
			plato[i][j] = 0;	
		}
				
	}
	
		
}

void print_plato(int **plato,struct Sonda sonda)
{
	int i,j;
	for(i = 0; i < 10;i++)
	{
		printf("\n");
		
		for(j = 0; j < 20; j++)
		{	
			if(sonda.linha == i && sonda.coluna == j)
			{
				printf("X ");
			}
			else if(plato[i][j] == 0)
			{
				printf("0 ");	
			}
			else if(plato[i][j] == 1)
			{
				printf("1 ");
			}
			else
			{
				printf("# ");
			}			
		}	
	}					
}



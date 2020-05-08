#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Item
{
	int quantidade;
	float preco;
	char nome[20];
};

void printar_menu(struct Item item1,struct Item item2,struct Item item3,struct Item item4,struct Item item5,struct Item item6,
				  struct Item item7,struct Item item8,struct Item item9,struct Item item10,struct Item item11,struct Item item12,
				  struct Item item13,struct Item item14,struct Item item15,struct Item item16,struct Item item17,struct Item item18,
				  struct Item item19,struct Item item20,struct Item item21,struct Item item22,struct Item item23,struct Item item24)
{
	printf("1 Frutas:\n	a. Banana %.2f (%d itens)\n	b. Maca %.2f (%d itens)\n	c. Abacaxi %.2f (%d itens)\n", item1.preco, item1.quantidade, item2.preco, item2.quantidade, item3.preco, item3.quantidade);
	printf("2 Verduras:\n	a. Cheiro-verde %.2f (%d itens)\n	b. Cebolinha %.2f (%d itens)\n	c. Alface %.2f (%d itens)\n",item4.preco, item4.quantidade, item5.preco, item5.quantidade, item6.preco, item6.quantidade);
	printf("3 Legumes:\n	a. Tomate %.2f (%d itens)\n	b. Pimentao %.2f (%d itens)\n	c. Brocolis %.2f (%d itens)\n",item7.preco, item7.quantidade, item8.preco, item8.quantidade,item9.preco,item9.quantidade);
	printf("4 Proteinas:\n	a. Carne bovina %.2f (%d itens)\n	b. Carne de frango %.2f (%d itens)\n	c. Carne de peixe %.2f (%d itens)\n",item10.preco,item10.quantidade,item11.preco,item11.quantidade,item12.preco,item12.quantidade);
	printf("5 Congelados:\n	a. Batata frita %.2f (%d itens)\n	b. Pizza congelada %.2f (%d itens)\n	c. Ervilhas congeladas %.2f (%d itens)\n",item13.preco,item13.quantidade,item14.preco,item14.quantidade,item15.preco,item15.quantidade);
	printf("6 Bebidas:\n	a. Coca-cola %.2f (%d itens)\n	b. Suquinho %.2f (%d itens)\n	c. Agua %.2f (%d itens)\n",item16.preco,item16.quantidade,item17.preco,item17.quantidade,item18.preco,item18.quantidade);
	printf("7 Bebidas alcoolicas:\n	a. Whisky %.2f (%d itens)\n	b. Buchudinha %.2f (%d itens)\n	c. Cerveja %.2f (%d itens)\n",item19.preco,item19.quantidade,item20.preco,item20.quantidade,item21.preco,item21.quantidade);
	printf("8 Panificadora:\n	a. pao %.2f (%d itens)\n	b. Sonho %.2f (%d itens)\n	c. Salgado %.2f (%d itens)\n",item22.preco,item22.quantidade,item23.preco,item23.quantidade,item24.preco,item24.quantidade);
}

void printar_carrinho(char**carrinho,float**matriz,int tamanho_carrinho,int n_produtos)
{	
	int i;
	printf("|-----Carrinho-----|\n");
	
	
	for(i = 0; i < tamanho_carrinho; i++)
	{
		printf("%s %.0f\n",carrinho[i],matriz[0][i]);	
	}
		
	printf("|-----Total:%d-----|\n",n_produtos);
}

int adicionar_carrinho(struct Item item,float **matriz,int quantidade,int tamanho)
{

	matriz[0][tamanho] = (float)quantidade;
	matriz[1][tamanho] = item.preco;
	item.quantidade -= quantidade;		
	
	return item.quantidade;	
}

float desconto_frutas(int tamanho_carrinho,char **carrinho,float **matriz,float total)
{	
	int i;	
	float total_reais = 0;
	int total_frutas = 0;
	for(i = 0; i < tamanho_carrinho; i++)
	{
		if(strcmp(carrinho[i],"banana") == 0 || strcmp(carrinho[i],"maca") == 0 || strcmp(carrinho[i],"abacaxi") == 0)
		{
			total_frutas += matriz[0][i];
			total_reais += matriz[0][i] * matriz[1][i];
		}
	}
	
	if(total_frutas > 10)
	{	
		total_reais = (total_reais * 5) / 100;
		printf("%.2f Descontados do extrato pelas frutas\n",total_reais);
		return total - total_reais;
	}
	
	else{
		return total;
	}
}

float desconto_vegetais_legumes(int tamanho_carrinho,char ** carrinho, float ** matriz,float total)
{
	int i;
	float total_reais = 0;
	float total_coisas = 0;
	
	for(i = 0; i < tamanho_carrinho; i ++)
	{
		if(strcmp(carrinho[i],"cheiro-verde") == 0 || strcmp(carrinho[i],"cebolinha") == 0 || strcmp(carrinho[i],"alface") == 0
		|| strcmp(carrinho[i],"tomate") == 0 || strcmp(carrinho[i],"pimentao") == 0 || strcmp(carrinho[i],"brocolis") == 0)
		{
			total_coisas += matriz[0][i];
			total_reais += matriz[0][i] * matriz[1][i];	
		}
			
	}
	
	if(total_coisas > 8)
	{
		total_reais = (total_reais * 7) / 100;
		printf("%.2f Descontados do extrato pelos vegetais e legumes\n",total_reais);
		return total - total_reais;
	}
	else
	{
		return total;
	}
}

float desconto_alcool(int tamanho_carrinho,char ** carrinho, float ** matriz,float total)
{
	int i,j;
	int total_bebidas = 0;
	float desconto = 0;
	for(i = 0; i < tamanho_carrinho; i++)
	{
		if(strcmp(carrinho[i],"whisky") == 0 || strcmp(carrinho[i],"buchudinha") == 0 || strcmp(carrinho[i],"cerveja") == 0)
		{
			
			for(j = 0; j < matriz[0][i]; j++)
			{	
				total_bebidas += 1;
				if(total_bebidas == 6)
				{
					desconto += matriz[1][i];
					total_bebidas = 0; 
				}
			}
			
		}
		
	} 
	printf("%.2f Descontados do extrato pelas bebidas\n",desconto);
	return total - desconto;
}

float desconto_peixe(int tamanho_carrinho,char ** carrinho, float ** matriz,float total)
{
	int i;
	float desconto = 0;
	for( i = 0; i < tamanho_carrinho;i++)
	{
		if(strcmp(carrinho[i],"carne de peixe") == 0)
		{	
			desconto = ( ( matriz[1][i] * matriz[0][i]) * 10 ) / 100;
			printf("%.2f Descontados do extrato pelo peixe\n",desconto);
			return total - desconto;
		}
	} return total;
}


int main(void)
{	
	struct Item item1 = {10,2.50,"banana"};struct Item item2 = {2,2.0,"maca"};struct Item item3 = {5,4.0,"abacaxi"};
	struct Item item4 = {7,1.40,"cheiro-verde"};struct Item item5 = {14,1.0,"cebolinha"}; struct Item item6 = {8,2.0,"alface"};
	struct Item item7 = {12,3.50,"tomate"};struct Item item8 = {7,2.0,"pimentao"};struct Item item9 = {15,2.35,"brocolis"};
	struct Item item10 = {11,10.50,"carne bovina"};struct Item item11 = {12,9.50,"carne de frango"};struct Item item12 = {7,15.0,"carne de peixe"};
	struct Item item13 = {10,7.50,"batata frita"};struct Item item14 = {6,10.15,"pizza congelada"};struct Item item15 = {5,4.0,"ervilhas congeladas"};
	struct Item item16 = {13,2.50,"coca-cola"};struct Item item17 = {10,5.0,"suquinho"};struct Item item18 = {15,1.0,"agua"};
	struct Item item19 = {3,30.50,"whisky"};struct Item item20 = {20,2.0,"buchudinha"};struct Item item21 = {7,4.0,"cerveja"};
	struct Item item22 = {23,0.75,"pao"};struct Item item23 = {9,2.0,"sonho"};struct Item item24 = {9,3.50,"salagado"};
	
	float **matriz = malloc(sizeof(float)*2);
	int i;
	int tamanho = 0;
	int n_produtos = 0;
	for(i = 0; i < 2; i++)
		matriz[i] = (float*) malloc(sizeof(float)*24);
	
	int tamanho_carrinho = 0;
	char **carrinho = malloc(sizeof(char)*10);
	for(i = 0; i < 10; i++)
		carrinho[i] = malloc(sizeof(char)*20);
	
	while(true)
	{
		printar_menu(item1,item2,item3,item4,item5,item6,
			item7,item8, item9,item10,item11,item12,
			item13,item14, item15,item16,item17, item18,
			item19,item20,item21,item22,item23,item24);
		printar_carrinho(carrinho,matriz,tamanho_carrinho,n_produtos);
		int escolha;
		printf("Escolha para qual setor você deseja ir ou digite 0 para finalizar:");
		scanf("%d",&escolha);
		if(escolha == 0){break;}

		switch(escolha)
		{
			case 1:
				while(true)
				{	
					printar_menu(item1,item2,item3,item4,item5,item6,
					item7,item8, item9,item10,item11,item12,
					item13,item14, item15,item16,item17, item18,
					item19,item20,item21,item22,item23,item24);
					
					char produto;
					int quantidade;
					printf("\nVocê está no setor de Frutas\n");
					printar_carrinho(carrinho,matriz,tamanho_carrinho,n_produtos);
					printf("Qual produto?(para sair do setor digite 'e'):");
					scanf(" %c",&produto);
					if(produto == 'e'){break;}
					printf("Quantos?:");
					scanf("%d",&quantidade);
					
					if(quantidade + n_produtos > 45){
						printf("Você não pode adicionar essa quantidade de produtos!");
						continue;
					}
					
					switch(produto)
					{
						case 'a':
							if(quantidade <= item1.quantidade)
							{
								item1.quantidade = adicionar_carrinho(item1,matriz,quantidade,tamanho);
								tamanho++;
								carrinho[tamanho_carrinho] = item1.nome;
								tamanho_carrinho++;	
								n_produtos += quantidade;
							}
							else
							{
								printf("Não temos esse tanto em estoque!");	
							}
							
							break;
						case 'b':
							if(quantidade <= item2.quantidade)
							{
								item2.quantidade = adicionar_carrinho(item2,matriz,quantidade,tamanho);
								tamanho++;
								carrinho[tamanho_carrinho] = item2.nome;
								tamanho_carrinho++;	
								n_produtos += quantidade;
							}
							else
							{
								printf("Não temos esse tanto em estoque!");	
							}
							break;
						case 'c':
							if(quantidade <= item3.quantidade)
							{
								item3.quantidade = adicionar_carrinho(item3,matriz,quantidade,tamanho);
								tamanho++;
								carrinho[tamanho_carrinho] = item3.nome;
								tamanho_carrinho++;
								n_produtos += quantidade;	
							}
							else
							{
								printf("Não temos esse tanto em estoque!");	
							}
							break;
							
					}
					
				}break;
			case 2:
				while(true)
					{	
						printar_menu(item1,item2,item3,item4,item5,item6,
						item7,item8, item9,item10,item11,item12,
						item13,item14, item15,item16,item17, item18,
						item19,item20,item21,item22,item23,item24);
	
						char produto;
						int quantidade;
						printf("\nVocê está no setor de Verduras\n");
						printar_carrinho(carrinho,matriz,tamanho_carrinho,n_produtos);
						printf("Qual produto?(para sair do setor digite 'e'):");
						scanf(" %c",&produto);
						if(produto == 'e'){break;}
						printf("Quantos?:");
						scanf("%d",&quantidade);
						if(quantidade + n_produtos > 45)
						{
						printf("Você não pode adicionar essa quantidade de produtos!");
						continue;
						}
						
						switch(produto)
						{
							case 'a':
							if(quantidade <= item4.quantidade)
							{
								item4.quantidade = adicionar_carrinho(item4,matriz,quantidade,tamanho);
								tamanho++;
								carrinho[tamanho_carrinho] = item4.nome;
								tamanho_carrinho++;
								n_produtos += quantidade;	
							}
							else
							{
								printf("Não temos esse tanto em estoque!");	
							}
							break;
							case 'b':
							if(quantidade <= item5.quantidade)
							{
								item5.quantidade = adicionar_carrinho(item5,matriz,quantidade,tamanho);
								tamanho++;
								carrinho[tamanho_carrinho] = item5.nome;
								tamanho_carrinho++;	
								n_produtos += quantidade;
							}
							else
							{
								printf("Não temos esse tanto em estoque!");	
							}
							break;
							case 'c':
							if(quantidade <= item6.quantidade)
							{
								item6.quantidade = adicionar_carrinho(item6,matriz,quantidade,tamanho);
								tamanho++;
								carrinho[tamanho_carrinho] = item6.nome;
								tamanho_carrinho++;
								n_produtos += quantidade;	
							}
							else
							{
								printf("Não temos esse tanto em estoque!");	
							}
							break;
								
						}	
		}break;
			case 3:
				while(true)
				{	
					printar_menu(item1,item2,item3,item4,item5,item6,
					item7,item8, item9,item10,item11,item12,
					item13,item14, item15,item16,item17, item18,
					item19,item20,item21,item22,item23,item24);

					char produto;
					int quantidade;
					printf("\nVocê está no setor de Legumes\n");
					printar_carrinho(carrinho,matriz,tamanho_carrinho,n_produtos);
					printf("Qual produto?(para sair do setor digite 'e'):");
					scanf(" %c",&produto);
					if(produto == 'e'){break;}
					printf("Quantos?:");
					scanf("%d",&quantidade);
					if(quantidade + n_produtos > 45)
						{
						printf("Você não pode adicionar essa quantidade de produtos!");
						continue;
						}
					
						
					switch(produto)
					{
						case 'a':
							if(quantidade <= item7.quantidade)
							{
								item7.quantidade = adicionar_carrinho(item7,matriz,quantidade,tamanho);
								tamanho++;
								carrinho[tamanho_carrinho] = item7.nome;
								tamanho_carrinho++;
								n_produtos += quantidade;	
							}
							else
							{
								printf("Não temos esse tanto em estoque!");	
							}
							break;
						case 'b':
							if(quantidade <= item8.quantidade)
							{
								item8.quantidade = adicionar_carrinho(item8,matriz,quantidade,tamanho);
								tamanho++;
								carrinho[tamanho_carrinho] = item8.nome;
								tamanho_carrinho++;
								n_produtos += quantidade;	
							}
							else
							{
								printf("Não temos esse tanto em estoque!");	
							}
							break;
						case 'c':
							if(quantidade <= item9.quantidade)
							{
								item9.quantidade = adicionar_carrinho(item9,matriz,quantidade,tamanho);
								tamanho++;
								carrinho[tamanho_carrinho] = item9.nome;
								tamanho_carrinho++;
								n_produtos += quantidade;	
							}
							else
							{
								printf("Não temos esse tanto em estoque!");	
							}
							break;
							
					}
					
				}break;
			case 4:
				while(true)
				{	
					printar_menu(item1,item2,item3,item4,item5,item6,
					item7,item8, item9,item10,item11,item12,
					item13,item14, item15,item16,item17, item18,
					item19,item20,item21,item22,item23,item24);

					char produto;
					int quantidade;
					printf("\nVocê está no setor de Proteinas\n");
					printar_carrinho(carrinho,matriz,tamanho_carrinho,n_produtos);
					printf("Qual produto?(para sair do setor digite 'e'):");
					scanf(" %c",&produto);
					if(produto == 'e'){break;}
					printf("Quantos?:");
					scanf("%d",&quantidade);
					if(quantidade + n_produtos > 45)
						{
						printf("Você não pode adicionar essa quantidade de produtos!");
						continue;
						}
						
						
					switch(produto)
					{
						case 'a':
							if(quantidade <= item10.quantidade)
							{
								item10.quantidade = adicionar_carrinho(item10,matriz,quantidade,tamanho);
								tamanho++;
								carrinho[tamanho_carrinho] = item10.nome;
								tamanho_carrinho++;
								n_produtos += quantidade;	
							}
							else
							{
								printf("Não temos esse tanto em estoque!");	
							}
							break;
						case 'b':
							if(quantidade <= item11.quantidade)
							{
								item11.quantidade = adicionar_carrinho(item11,matriz,quantidade,tamanho);
								tamanho++;
								carrinho[tamanho_carrinho] = item11.nome;
								tamanho_carrinho++;
								n_produtos += quantidade;	
							}
							else
							{
								printf("Não temos esse tanto em estoque!");	
							}
							break;
							break;
						case 'c':
							if(quantidade <= item12.quantidade)
							{
								item12.quantidade = adicionar_carrinho(item12,matriz,quantidade,tamanho);
								tamanho++;
								carrinho[tamanho_carrinho] = item12.nome;
								tamanho_carrinho++;
								n_produtos += quantidade;	
							}
							else
							{
								printf("Não temos esse tanto em estoque!");	
							}
							break;
							
					}
	
				}break;
			case 5:
				while(true)
				{	
					printar_menu(item1,item2,item3,item4,item5,item6,
					item7,item8, item9,item10,item11,item12,
					item13,item14, item15,item16,item17, item18,
					item19,item20,item21,item22,item23,item24);

					char produto;
					int quantidade;
					printf("\nVocê está no setor de Congelados\n");
					printar_carrinho(carrinho,matriz,tamanho_carrinho,n_produtos);
					printf("Qual produto?(para sair do setor digite 'e'):");
					scanf(" %c",&produto);
					if(produto == 'e'){break;}
					printf("Quantos?:");
					scanf("%d",&quantidade);
					if(quantidade + n_produtos > 45)
						{
						printf("Você não pode adicionar essa quantidade de produtos!");
						continue;
						}
						
						
					switch(produto)
					{
						case 'a':
							if(quantidade <= item13.quantidade)
							{
								item13.quantidade = adicionar_carrinho(item13,matriz,quantidade,tamanho);
								tamanho++;
								carrinho[tamanho_carrinho] = item13.nome;
								tamanho_carrinho++;
								n_produtos += quantidade;	
							}
							else
							{
								printf("Não temos esse tanto em estoque!");	
							}
							break;
						case 'b':
							if(quantidade <= item14.quantidade)
							{
								item14.quantidade = adicionar_carrinho(item14,matriz,quantidade,tamanho);
								tamanho++;
								carrinho[tamanho_carrinho] = item14.nome;
								tamanho_carrinho++;
								n_produtos += quantidade;	
							}
							else
							{
								printf("Não temos esse tanto em estoque!");	
							}
							break;
							break;
						case 'c':
							if(quantidade <= item15.quantidade)
							{
								item15.quantidade = adicionar_carrinho(item15,matriz,quantidade,tamanho);
								tamanho++;
								carrinho[tamanho_carrinho] = item15.nome;
								tamanho_carrinho++;
								n_produtos += quantidade;	
							}
							else
							{
								printf("Não temos esse tanto em estoque!");	
							}
							break;
							
					}
	
				}break;
			case 6:
				while(true)
				{	
					printar_menu(item1,item2,item3,item4,item5,item6,
					item7,item8, item9,item10,item11,item12,
					item13,item14, item15,item16,item17, item18,
					item19,item20,item21,item22,item23,item24);

					char produto;
					int quantidade;
					printf("\nVocê está no setor de Bebidas\n");
					printar_carrinho(carrinho,matriz,tamanho_carrinho,n_produtos);
					printf("Qual produto?(para sair do setor digite 'e'):");
					scanf(" %c",&produto);
					if(produto == 'e'){break;}
					printf("Quantos?:");
					scanf("%d",&quantidade);
					if(quantidade + n_produtos > 45)
						{
						printf("Você não pode adicionar essa quantidade de produtos!");
						continue;
						}
						
					
					switch(produto)
					{
						case 'a':
							if(quantidade <= item16.quantidade)
							{
								item16.quantidade = adicionar_carrinho(item16,matriz,quantidade,tamanho);
								tamanho++;
								carrinho[tamanho_carrinho] = item16.nome;
								tamanho_carrinho++;
								n_produtos += quantidade;	
							}
							else
							{
								printf("Não temos esse tanto em estoque!");	
							}
							break;
						case 'b':
							if(quantidade <= item17.quantidade)
							{
								item17.quantidade = adicionar_carrinho(item17,matriz,quantidade,tamanho);
								tamanho++;
								carrinho[tamanho_carrinho] = item17.nome;
								tamanho_carrinho++;
								n_produtos += quantidade;	
							}
							else
							{
								printf("Não temos esse tanto em estoque!");	
							}
							break;
						case 'c':
							if(quantidade <= item18.quantidade)
							{
								item18.quantidade = adicionar_carrinho(item18,matriz,quantidade,tamanho);
								tamanho++;
								carrinho[tamanho_carrinho] = item18.nome;
								tamanho_carrinho++;
								n_produtos += quantidade;	
							}
							else
							{
								printf("Não temos esse tanto em estoque!");	
							}
							break;
							
					}
	
				}break;
			case 7:
				while(true)
				{	
					printar_menu(item1,item2,item3,item4,item5,item6,
					item7,item8, item9,item10,item11,item12,
					item13,item14, item15,item16,item17, item18,
					item19,item20,item21,item22,item23,item24);

					char produto;
					int quantidade;
					printf("\nVocê está no setor de Bebidas alcoolicas\n");
					printar_carrinho(carrinho,matriz,tamanho_carrinho,n_produtos);
					printf("Qual produto?(para sair do setor digite 'e'):");
					scanf(" %c",&produto);
					if(produto == 'e'){break;}
					printf("Quantos?:");
					scanf("%d",&quantidade);
					if(quantidade + n_produtos > 45)
						{
						printf("Você não pode adicionar essa quantidade de produtos!");
						continue;
						}
						
					
					switch(produto)
					{
						case 'a':
							if(quantidade <= item19.quantidade)
							{
								item19.quantidade = adicionar_carrinho(item19,matriz,quantidade,tamanho);
								tamanho++;
								carrinho[tamanho_carrinho] = item19.nome;
								tamanho_carrinho++;
								n_produtos += quantidade;	
							}
							else
							{
								printf("Não temos esse tanto em estoque!");	
							}
							break;
						case 'b':
							if(quantidade <= item20.quantidade)
							{
								item20.quantidade = adicionar_carrinho(item20,matriz,quantidade,tamanho);
								tamanho++;
								carrinho[tamanho_carrinho] = item20.nome;
								tamanho_carrinho++;
								n_produtos += quantidade;	
							}
							else
							{
								printf("Não temos esse tanto em estoque!");	
							}
							break;
						case 'c':
							if(quantidade <= item21.quantidade)
							{
								item21.quantidade = adicionar_carrinho(item21,matriz,quantidade,tamanho);
								tamanho++;
								carrinho[tamanho_carrinho] = item21.nome;
								tamanho_carrinho++;
								n_produtos += quantidade;	
							}
							else
							{
								printf("Não temos esse tanto em estoque!");	
							}
							break;
							
					}
	
				}break;
			case 8:
				while(true)
				{	
					printar_menu(item1,item2,item3,item4,item5,item6,
					item7,item8, item9,item10,item11,item12,
					item13,item14, item15,item16,item17, item18,
					item19,item20,item21,item22,item23,item24);

					char produto;
					int quantidade;
					printf("\nVocê está no setor de Panificadora\n");
					printar_carrinho(carrinho,matriz,tamanho_carrinho,n_produtos);
					printf("Qual produto?(para sair do setor digite 'e'):");
					scanf(" %c",&produto);
					if(produto == 'e'){break;}
					printf("Quantos?:");
					scanf("%d",&quantidade);
					if(quantidade + n_produtos > 45)
						{
						printf("Você não pode adicionar essa quantidade de produtos!");
						continue;
						}
					
						
					switch(produto)
					{
						case 'a':
							if(quantidade <= item22.quantidade)
							{
								item22.quantidade = adicionar_carrinho(item22,matriz,quantidade,tamanho);
								tamanho++;
								carrinho[tamanho_carrinho] = item22.nome;
								tamanho_carrinho++;
								n_produtos += quantidade;	
							}
							else
							{
								printf("Não temos esse tanto em estoque!");	
							}
							break;
						case 'b':
							if(quantidade <= item23.quantidade)
							{
								item23.quantidade = adicionar_carrinho(item23,matriz,quantidade,tamanho);
								tamanho++;
								carrinho[tamanho_carrinho] = item23.nome;
								tamanho_carrinho++;
								n_produtos += quantidade;	
							}
							else
							{
								printf("Não temos esse tanto em estoque!");	
							}
							break;
						case 'c':
							if(quantidade <= item24.quantidade)
							{
								item24.quantidade = adicionar_carrinho(item24,matriz,quantidade,tamanho);
								tamanho++;
								carrinho[tamanho_carrinho] = item24.nome;
								tamanho_carrinho++;
								n_produtos += quantidade;	
							}
							else
							{
								printf("Não temos esse tanto em estoque!");	
							}
							break;
							
					}
	
				}break;
}
}	
	system("cls");
	int total_frutas,verduras_legumes,bebidas;
	float extrato = 0;
	for(i = 0; i < tamanho_carrinho; i++)
	{	
		float total = matriz[0][i] * matriz[1][i];
		extrato += total;	
		printf("Item: %s | Valor: %.2f | Quantidade: %0.f | Total: %.2f\n",carrinho[i],matriz[1][i],matriz[0][i],total);
	}
	
	extrato = desconto_frutas(tamanho_carrinho,carrinho,matriz,extrato);
	
	printf("Extrato atual de: %.2f\n",extrato);
	
	extrato = desconto_vegetais_legumes(tamanho_carrinho,carrinho,matriz,extrato);
	
	printf("Extrato atual de: %.2f\n",extrato);
	
	extrato = desconto_alcool(tamanho_carrinho,carrinho,matriz,extrato);
	
	printf("Extrato atual de: %.2f\n",extrato);
	
	extrato = desconto_peixe(tamanho_carrinho,carrinho,matriz,extrato);
	
	printf("Extrato atual de: %.2f\n",extrato);
	
	if(extrato < 75)
	{
		extrato += 7;
		printf("7 adicionado pelo frete\n");
		printf("Extrato atual de: %.2f\n",extrato);
	}
	
	printf("Seu extrato final eh: %.2f",extrato);
		
}


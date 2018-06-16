#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu() {
	
	system ("cls");
	printf ("|----------------------------------------|\n");
	printf ("|                * MENU *                |\n");
	printf ("|                                        |\n");
	printf ("|      * OMEGA *                         |\n");
	printf ("|           * LOCADORA *                 |\n");
	printf ("|                   * DE *               |\n");
	printf ("|                     * VEICULOS *       |\n");
	printf ("|                                        |\n");
	printf ("|1- Cadastrar                            |\n");
	printf ("|2- Edicao                               |\n");
	printf ("|3- Exclusao                             |\n");
	printf ("|4- Consulta                             |\n");
	printf ("|5- Relatorio                            |\n");
	printf ("|0- Sair                                 |\n");
	printf ("|                                        |\n");
	printf ("| VIAJE COM QUALIDADE, VIAJE COM A OMEGA!|\n");
	printf ("|----------------------------------------|\n\n");
	
}

int main (){
	
		struct cliente {
		char nome[50],cnh[50], veiculo[50], placa[7];
		char tel[50];
		int dias, ativo;
		float valor;
	};
	
	FILE *pont_arq;
	char texto [250];
	char* token;
	
	struct cliente A[10];
	int i = 0, x = 0, men, j, ind; 
	float total = 0;
	
	pont_arq = fopen ("Cadastro.txt", "r");
	
	while (fgets(texto, 250, pont_arq) != NULL){
		
		token = strtok(texto, "@");
		
		while (token != NULL){
			
			if (x == 0){
				strcpy(A[i].nome,token);
				x++;
			}
			else if (x == 1){
				strcpy(A[i].cnh,token);
				x++;
			}
			else if (x == 2){
				strcpy(A[i].tel,token);
				x++;
			}
			else if (x == 3){
				A[i].dias = atoi(token);
				x++;
			}
			else if (x == 4){
				sscanf(token, "%f", &A[i].valor);
				x++;
			}
			else if (x == 5){
				strcpy(A[i].veiculo,token);
        		x++;
			}
			else if (x == 6){
				strcpy(A[i].placa,token);
        		x++;
			}
			else if (x == 7){
				A[i].ativo = atoi(token);
        		x++;
			}
			else if (x == 8){
				sscanf (token, "%f", &total);
				x++;
			}
			
			token = strtok(NULL, "@");
		}
		x=0;
     	i++;
	}
	
	fclose(pont_arq);
	
	menu();
	scanf ("%d", &men);
	
	while (men != 0){
		
		switch (men){
			
			case 1:
			printf ("|----------------------------------------|\n");	
			printf ("|        * CADASTRO DE CLIENTES *        |\n");
			printf ("|                                        |\n");
			printf ("|      * OMEGA *                         |\n");
			printf ("|           * LOCADORA *                 |\n");
			printf ("|                   * DE *               |\n");
			printf ("|                     * VEICULOS *       |\n");
			printf ("|----------------------------------------|\n\n"); 
			 
		 	printf ("Nome Cliente:");
			scanf ("%s", &A[i].nome);
				
			printf ("Numero da CNH:");
			scanf ("%s", &A[i].cnh);
				
			printf ("Telefone:");
			scanf ("%s", &A[i].tel);
			
			printf ("Dias alugados:");
			scanf ("%d", &A[i].dias);
				
			printf ("Valor do aluguel:");
			scanf ("%f", &A[i].valor);
				
			printf ("|----------------------------------------|\n");	
			printf ("|           * VEICULOS OMEGA *           |\n");
			printf ("|                                        |\n");
			printf ("|      * OMEGA *                         |\n");
			printf ("|           * LOCADORA *                 |\n");
			printf ("|                   * DE *               |\n");
			printf ("|                     * VEICULOS *       |\n");
			printf ("|----------------------------------------|\n\n");
				
			printf ("Veiculo:");
			scanf ("%s", &A[i].veiculo);
				
			printf ("Placa:");
			scanf ("%s", &A[i].placa);
				
			total = total + A[i].valor;
				
			A[i].ativo=1;	
			i++;
				
			break;
			
			case 2:
			printf ("|----------------------------------------|\n");	
			printf ("|         * EDICAO DE CADASTRO *         |\n");
			printf ("|                                        |\n");
			printf ("|      * OMEGA *                         |\n");
			printf ("|           * LOCADORA *                 |\n");
			printf ("|                   * DE *               |\n");
			printf ("|                     * VEICULOS *       |\n");
			printf ("|----------------------------------------|\n\n");
			
			printf ("Digite o codigo do cadastro para edicao:");
			scanf ("%d", &ind);
			
			printf ("Nome Cliente:%s\n", A[ind].nome);
			
			printf ("Numero da CNH:%s\n", A[ind].cnh);
				
			printf ("Telefone:%s\n", A[ind].tel);
			
			printf ("Dias alugados:%d\n", A[ind].dias);
				
			printf ("Valor do aluguel:%.2f\n", A[ind].valor);
				
			printf ("Veiculo:%s\n", A[ind].veiculo);
			
			printf ("Placa:%s\n", A[ind].placa);

			printf ("status:%d\n", A[ind].ativo);
			
			printf ("EDITAR DADOS DO CLIENTE.\n\n");
			 
			printf ("Nome Cliente:");
			scanf ("%s", &A[ind].nome);
				
			printf ("Numero da CNH:");
			scanf ("%s", &A[ind].cnh);
				
			printf ("Telefone:");
			scanf ("%s", &A[ind].tel);
			
			printf ("Dias alugados:");
			scanf ("%d", &A[ind].dias);
				
			printf ("Valor do aluguel:");
			scanf ("%f", &A[ind].valor);
				
			printf ("EDITAR DADOS DO VEICULO.\n\n");
				
			printf ("Veiculo:");
			scanf ("%s", &A[ind].veiculo);
				
			printf ("Placa:");
			scanf ("%s", &A[ind].placa);
			
			total = total - A[ind].valor + A[ind].valor;
				
			break;
			
			case 3:
			
			printf ("|----------------------------------------|\n");	
			printf ("|          * EXCLUIR CADASTRO *          |\n");
			printf ("|                                        |\n");
			printf ("|      * OMEGA *                         |\n");
			printf ("|           * LOCADORA *                 |\n");
			printf ("|                   * DE *               |\n");
			printf ("|                     * VEICULOS *       |\n");
			printf ("|----------------------------------------|\n\n");
			
			printf ("Digite o codigo do cadastro para excluir:");
			scanf ("%d", &ind);
			
			total = total - A[ind].valor;
			A[ind].ativo=0;
  			
  			printf("CADASTRO EXCLUIDO COM SUCESSO!\n\n");
  			system("pause");
			  
			break;
			
			case 4:
			
			printf ("|----------------------------------------|\n");	
			printf ("|        * CONSULTA DE CADASTRO *        |\n");
			printf ("|                                        |\n");
			printf ("|      * OMEGA *                         |\n");
			printf ("|           * LOCADORA *                 |\n");
			printf ("|                   * DE *               |\n");
			printf ("|                     * VEICULOS *       |\n");
			printf ("|----------------------------------------|\n\n");
				
			printf ("Digite o codigo do cadastro para a consulta:");
			scanf ("%d", &ind);
			
			printf ("Nome Cliente:%s\n", A[ind].nome);
			
			printf ("Numero da CNH:%s\n", A[ind].cnh);
				
			printf ("Telefone:%s\n", A[ind].tel);
			
			printf ("Dias alugados:%d\n", A[ind].dias);
				
			printf ("Valor do aluguel:%.2f\n", A[ind].valor);
				
			printf ("Veiculo:%s\n", A[ind].veiculo);
			
			printf ("Placa:%s\n", A[ind].placa);

			printf ("status:%d\n", A[ind].ativo);
			
			system ("pause");
			
			break;
			
			case 5:
			
			printf ("|----------------------------------------|\n");	
			printf ("|              * RELATORIO *             |\n");
			printf ("|                                        |\n");
			printf ("|      * OMEGA *                         |\n");
			printf ("|           * LOCADORA *                 |\n");
			printf ("|                   * DE *               |\n");
			printf ("|                     * VEICULOS *       |\n");
			printf ("|----------------------------------------|\n\n");
			
			printf ("Valor arrecadado:%.2f\n", total);
			system ("pause");
			
			break;	
			
			default:
				
  			printf("ERROR Opcao invalida!\n");
  			
			break;	
		}
			menu();
  			scanf("%d",&men);
	}
	
			pont_arq = fopen("Cadastro.txt", "w");
  
  			for(j=0; j < i; j++) {
  	
    		if (A[j].ativo == 1){
    			
	  		fprintf(pont_arq,"%s@%s@%s@%d@%.2f@%s@%s@%d@%.2f\n", A[j].nome, A[j].cnh, A[j].tel, A[j].dias, A[j].valor, A[j].veiculo, A[j].placa, A[j].ativo, total);
	  		
    		}
  }
  
  fclose(pont_arq);
}

#include <iostream>
#include <string>
using namespace std;
string entrada_2(){
    string b;
    cin>> b;
    return  b;
}
void comparacion_or(int &a ,int &b,int &c){
    if (a+b==0){
        c=0;
    }else{
		c=1;
		}
}
void comparacion_and(int &a ,int &b,int &c){
    if (a+b==2){
        c=1;
    }else{
		c=0;
		}
}
void comparacion_xor(int &a ,int &b,int &c){
    if (a==b){
        c=0;
    }else{
		c=1;
		}
}
void comparacion_negacion(int &a,int &b ){
    if (a==0){
        b=1;
    }else{
		b=0;
	}
}
int potencia(int a,int b){
	int pot=1;
    for (int i=0;i<b;i++){
        pot=pot*a;
    }
    return pot;
}
void busca_indices(int &a,int &b,int &c ,int &d,int &e,int &f){
	if(a<d){
		b=a;
	}			
	if(a>d){
		c=a;
	}
}
void verificar_1(int &a,bool c ){
	if (a==40 or a==41 or a==38 or a==124 or a==94 or a==126){
		c=false;
	}
	
}
void verificar_2(int &a,bool c ){
	if(a==41 or a==38 or a==124 or a==94){
		c=false;
	}
}

void verificar_3(int &a,bool c ){
	if (a<=90 and a>=65){
		c=false;
	}
	if (a==40 or a==126){
		c=false;
	}
	
}
	
int main()
{   string operacion=entrada_2();//el ejercicio
	string copia="";
	//parte de operadores
	int operador_5[15]={};//( )
	int op_5=0;
	int array_posiciones_operadores[25]={};
	int cont_op=0;
	//parte de variables
	int array_posiciones_variables[25]={};
	int indices[25]={};
	int cont_va=0;
	//Procede o no procede
	bool continuar=true;
    //obtener posiciones de variables
    int poner=0;
    //Cuenta negaciones
    int especial=0;
    const int  numero_datos_1=operacion.size();
    for(int j=0;j<numero_datos_1;j++){
		if (int(operacion[j])==126){
			especial++;
			
		}else{
			if(especial%2==1){
				copia=copia+"~"+operacion[j];	
			}else{ 
				copia=copia+operacion[j];
			}
			especial=0;
		}
	}
	
	copia="("+copia+")";
	const int  numero_datos=copia.size();
	//cout<<"Numero de datos_1:"<<numero_datos<<"\n";
	int aux_1=0;
    //****************************************************************
    for( poner=0;poner<numero_datos;poner++){
		aux_1=(int)copia[poner+1];
		if ((int)copia[poner]<=90 and (int)copia[poner]>=65){
			verificar_3(aux_1,continuar);
			array_posiciones_variables[cont_va]=poner;
			indices[cont_va]=poner;
			cont_va++;
		}else{
			switch((int)copia[poner])
			{
				case 126://~
					verificar_2(aux_1,continuar);
					break;
				case 38://&
					verificar_1(aux_1,continuar);
					array_posiciones_operadores[cont_op]=poner;
					cont_op++;
					break;
				case 94://
					verificar_1(aux_1,continuar);
					array_posiciones_operadores[cont_op]=poner;
					cont_op++;
					break;
				case 124://
					verificar_1(aux_1,continuar);
					array_posiciones_operadores[cont_op]=poner;
					cont_op++;
					break;
				case 40://(
					verificar_2(aux_1,continuar);
					operador_5[op_5]=poner;
					op_5++;
					break;
				case 41://(
					verificar_3(aux_1,continuar);
					operador_5[op_5]=poner;
					op_5++;
					break;
				default:
					continuar=false;
				
				}
		} 		
	}
	const int pot=potencia(2,cont_va);
	int matriz_tabla[pot][numero_datos]={};
	//llenado de matriz
	int reduccion=pot;
	int bit=0;
	int casilla=0;
	int columna=0;
	for(int i=0;i<cont_va;i++){
		bit=0;
		reduccion=reduccion/2;
		columna=array_posiciones_variables[i];
		for(int j=0;j<pot;j++){
			if (j%reduccion==0){
				bit++;
				if (bit%2==0){
					casilla=0;
					}
				else{
					casilla=1;
					}	
			}
			matriz_tabla[j][columna]=casilla;
		}
	}
	cout<<"Procesando expresion...\n";
	//Operando las ~
	int posi_negacion_1=0;
	int posi_negacion_2=0;
	for(int i=0;i<cont_va;i++){
		posi_negacion_1=array_posiciones_variables[i]-1;
		posi_negacion_2=array_posiciones_variables[i];
		indices[i]=posi_negacion_2;
		if((int)(copia[posi_negacion_1])==126){
			indices[i]=posi_negacion_1;
			for(int j=0;j<pot;j++){
			comparacion_negacion(matriz_tabla[j][posi_negacion_2],matriz_tabla[j][posi_negacion_1]);
			}
		}	
	}
	//LLAMADO DE VARIABLES PARA EL PROCESO DE OPERACION DE LOS OPERADORES LOGICOS
	int dato_x=0;	
	int part_1=0;
	int part_2=0;
	int cont_n=op_5;
	int inicio_1=0;
	int primero=0;
	int segundo=0;
	int tercero=0;
	bool neg=false;
	int posi_neg=0;
	//INICIO DEL PROCESO DE OPERACIONES
	while (op_5>1 and continuar){
		for(int i=0;i<op_5-1;i++){
			cont_n=0;
			part_1=operador_5[i];
			part_2=operador_5[i+1];
			if ((int)copia[part_1]-(int)copia[part_2]==-1){
				for(int m=0;m<op_5-1;m++){
					if (operador_5[m]==part_1 and operador_5[m+1]==part_2){
						cont_n+=2;
					}
					operador_5[m]=operador_5[cont_n];
					cont_n++;
					}
				if ((int)copia[part_1-1]==126){
					neg=true;
					posi_neg=part_1-1;
					tercero=part_1+1;
					}
				i=op_5;
				op_5=op_5-2; 
					for(int se=0;se<cont_op;se++){
						//UBICACION Y RESOLUCION DE LOS OPERADORES,SEGUN CORRRESPONDE
						inicio_1=array_posiciones_operadores[se];
						if (inicio_1>part_1 and inicio_1<part_2){
							array_posiciones_operadores[se]=0;
							tercero=inicio_1;
							switch ((int)copia[inicio_1])
							{
								case 38:
									for(int a=0;a<cont_va;a++){
										if(indices[a]<tercero and indices[a]!=-1){
											primero=indices[a];
										}
										if(indices[a]>tercero){
											segundo=indices[a];
											a=cont_va;
										}
									}
										
									for(int j=0;j<pot;j++){
										comparacion_and(matriz_tabla[j][primero],matriz_tabla[j][segundo],matriz_tabla[j][tercero]);
									}
									for(int a=0;a<cont_va;a++){
										if(indices[a]==primero){
											indices[a]=tercero;
										}
										if(indices[a]==segundo){
											indices[a]=-1;
											a=cont_va;
										}
									}
									break;
								case 94:
									for(int a=0;a<cont_va;a++){
										if(indices[a]<tercero and indices[a]!=-1){
											primero=indices[a];
										}
										if(indices[a]>tercero){
											segundo=indices[a];
											a=cont_va;
										}
									}
									
									for(int j=0;j<pot;j++){
										comparacion_xor(matriz_tabla[j][primero],matriz_tabla[j][segundo],matriz_tabla[j][tercero]);
									}
									for(int a=0;a<cont_va;a++){
										if(indices[a]==primero){
											indices[a]=tercero;
										}
										if(indices[a]==segundo){
											indices[a]=-1;
											a=cont_va;
										}
									}
									break;
								case 124:
									for(int a=0;a<cont_va;a++){
										if(indices[a]<tercero and indices[a]!=-1){
											primero=indices[a];
										}
										if(indices[a]>tercero){
											segundo=indices[a];
											a=cont_va;
										}
									}
									
									for(int j=0;j<pot;j++){
										comparacion_or(matriz_tabla[j][primero],matriz_tabla[j][segundo],matriz_tabla[j][tercero]);
									}
									for(int a=0;a<cont_va;a++){
										if(indices[a]==primero){
											indices[a]=tercero;
										}
										if(indices[a]==segundo){
											indices[a]=-1;
											a=cont_va;
										}
									}
									break;	
								}
							}
								
						}
						if (neg){
							for(int j=0;j<pot;j++){
								comparacion_negacion(matriz_tabla[j][tercero],matriz_tabla[j][posi_neg]);
							}
							for(int a=0;a<cont_va;a++){
								if(indices[a]==tercero){
									indices[a]=posi_neg;
									a=cont_va;
									neg=false;
								}
						    }
						}
					}		
				}
			}
	if(continuar){		
		for(int i=0;i<numero_datos;i++){
					cout<<" "<<copia[i]<<" ";
			}			
		cout<<"respuesta\n";
		for(int i=0;i<numero_datos;i++){
					cout<<"___";
			}
		for(int a=0;a<cont_va;a++){
			if(indices[a]>0){
				dato_x=indices[a];
				a=cont_va;
				}
			}					
		cout<<"\n";
		for(int i=0;i<pot;i++){
			for(int j=0;j<numero_datos;j++){
			cout<<" "<<matriz_tabla[i][j]<<" ";
			}
			cout<<"    "<<matriz_tabla[i][dato_x];
			cout<<"\n";
		}
		cout<<"Los datos abajo de cada variables son sus posibles 0 y 1;";
		cout<<"las respuestas de cada operacion se encuentran por debajo de los operadores";	
		cout<<"los 0 en los() no considerar , se imprimen por defecto, la respuesta total es la ultima columna"; 
		cout<<"abajo de donde dice respuesta\n";			
	}else{
		cout<<"Los datos entrados son invalidos \n";
		}		

    return 0;
}

#include <iostream>
using namespace std;
void imi_for_1(int a,int b=0){
	if (a==b){
		return ;
	}else{
		cout<<b<<"\n";
		b++;
		return imi_for_1(a,b);
	}
	
	}
void imi_for(int a){
	if (a==0){
		return ;
	}else{
		cout<<a<<"\n";
		return imi_for(a-1);
		}
	}
void ascendente(int n,int i=0){
	if (n==i-1){
		return;
	}else{
		cout<<i<<"\n";
		i++;
		return ascendente(n,i);	
	}
}	
void descendente(int n){
	if (n==0){
		return;
	}else{
		cout<<n<<"\n";
		n--;
		descendente(n);
		}
	}
void primo(int n,int i=2){
	if (n==i){
		cout<<"si\n";
	}
	else if(n%i==0){
		cout<<"no\n";
	}else{
		i++;
		return primo(n,i);
	}
}
		
int main()
{	
	cout<<"----------------primos---------------------------\n";
	primo(7);
	cout<<"----------------descendente--------------------------\n";
	descendente(7);
	cout<<"----------------ascendente-------------------------\n";
	ascendente(8);
	cout<<"----------------for------------------------\n";
	imi_for_1(9);
	cout<<"------------------------------------------\n";
	return 0;
}
	

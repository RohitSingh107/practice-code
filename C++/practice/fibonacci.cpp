// fibonacci Number

# include <iostream>
using namespace std;


int fibonacci(int x){
	int fn;
	if (x == 0){
		return 0;
	}
	else if (x == 1){
		return 1;
	}

	else {
		fn = fibonacci(x-1) + fibonacci(x-2);
	}
	return fn;
}


int main(){
	int a;

	cout<<"Enter the number: "<<endl;

	cin>>a;

	// fibonacci(a);

	cout<<a<<"th fibonacci no is "<<fibonacci(a);

	
	return 0;
} 

#include <stdio.h>
#include <math.h>

//Hanoi function declared
void hanoi(int n, char from_rod, char to_rod, char aux_rod);

//int moves(int n);

int main()
{

	//print the opening setence and get the number of hanois
	int n, rt;
	printf("Enter the number of disks you want to have: ");
	scanf("%d", &n);
	
	//rt = 
	//Assign A,B and C as the rods of hanoi
	hanoi(n, 'A', 'B', 'C');
	
	
	//prints the number of moves using pow(2,n)-1
	printf("\nThe number of Moves is :%.f",pow(2,n)-1);
	//rt-1 / moves(n)
	
	return 0;
}

//def of the hanoi function
void hanoi(int n, char from_rod, char to_rod, char aux_rod)
{
	//int rt1, rt2;
	

	//printf("n  = %d x = %c y = %c z = %c \n",n, x,y,z);
	
	
	if(n > 0)
	{
		//rt1 = 
		hanoi(n-1, from_rod, aux_rod, to_rod);
		
		printf("Move %d from col %c to col %c\n", n, from_rod, to_rod);
		
		//rt2 = 
		hanoi(n-1, aux_rod, to_rod, from_rod);
		//printf("x = %c y = %c z = %c %d \n", x,y,z, rt1 + rt2);
		//return rt1 + rt2;
		
	}
	
	else if (n == 0)
	{
		return 1;
		
	}
	//printf("x = %c y = %c z = %c\n", x,y,z);

}

/*int moves(int n)
{
	int i = 0, val = 1;
	
	for(i = 0; i < n; i++)
	{
		val = val*2;
	}
	
	return val -1;
	
}*/

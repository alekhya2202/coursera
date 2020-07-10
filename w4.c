#include <stdio.h>

void read_data(FILE *ptr, int d[], int *size) //function that reads file
{
	*size = 0;
	while(fscanf(ptr,"%d", &d[*size]==1))
		(*size)++ ;
}

double average(int d[], int size) //function that computes average of an array
{

	int i;
	double avg = 0.0;
	for( i = 0 ; i < size ; i++)
	{
		avg += d[i];
	}
	return (avg/size);
}

int max_of_array(int d[], int size) //function that computes max of an array
{
	int i, a = 0, b = a+1 , max = 0;
	for(i=0 ; i < size ; i++)
	{
		if(d[a] > d[b])
		{
			max = d[a];
		}
		a +=1
	}
	return(max);
}

int main()
{
	int i , j , sz = 10;
	int all_data[10];
	FILE *ifp;
	FILE *ofp;
	ifp = fopen("Ints.txt" , "r");
	ofp = fopen("answers-hw3.txt","w+");
	read_data(ifp , all_data , &sz);
	j = all_data[0]; //first input number
	int data[j];
	int k = 1;
	for(i = 0; i < j ; i++) //creating array of numbers of whose average is to be calculated
	{
		data[i] = all_data[k];
		k += 1;
	}
	printf("Average of numbers is %lf\n\n", average(data , j));
	printf("Max of given nos. is %d\n\n" , max_of_array(data.j));
	fprintf(ofp,"average of nos. is %lf and max is %d",average(data,j) , max_of_array(data,j));
	fclose(ifp);
	fclose(ofp);
	return 0;
}

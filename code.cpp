#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>
#include<string.h>
#include<malloc.h>

int partition(int arr[], int low, int high, int x_gap)
{
	char* str;
	int pivot = arr[high];
	int i = (low-1);
	int j, temp;
	setcolor(RED);
	rectangle(x_gap*high +1, 400 -(arr[high]*10), x_gap*high +21, 400);
	sprintf(str, "%d", arr[high]);
	outtextxy(x_gap*high + 1, 400 - arr[high]*10 - 10, str);
	for(j = low; j<=high -1;j++){
		if(arr[j]<pivot){
			i++;
			setcolor(GREEN);
			rectangle(x_gap*i +1, 400 - (arr[i]*10), x_gap*i + 21, 400);
			sprintf(str, "%d", arr[i]);
			outtextxy(x_gap*i+1, 400-(arr[i]*10) -10, str);
			delay(700);
			setcolor(BLACK);
			rectangle(x_gap*i +1, 400 - (arr[i]*10), x_gap*i + 21, 400);
			sprintf(str, "%d", arr[i]);
			outtextxy(x_gap*i+1, 400-(arr[i]*10) -10, str);
			rectangle(x_gap*j +1, 400 - (arr[j]*10), x_gap*j + 21, 400);
			sprintf(str, "%d", arr[j]);
			outtextxy(x_gap*j+1, 400-(arr[j]*10) -10, str);
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			delay(200);
			setcolor(WHITE);
			rectangle(x_gap*i +1, 400 - (arr[i]*10), x_gap*i + 21, 400);
			sprintf(str, "%d", arr[i]);
			outtextxy(x_gap*i+1, 400-(arr[i]*10) -10, str);
			rectangle(x_gap*j +1, 400 - (arr[j]*10), x_gap*j + 21, 400);
			sprintf(str, "%d", arr[j]);
			outtextxy(x_gap*j+1, 400-(arr[j]*10) -10, str);
		}
		setcolor(BLACK);
		rectangle(x_gap*i +1, 400 - (arr[i]*10), x_gap*i + 21, 400);
		sprintf(str, "%d", arr[i]);
		outtextxy(x_gap*i+1, 400-(arr[i]*10) -10, str);
		setcolor(WHITE);
		rectangle(x_gap*i +1, 400 - (arr[i]*10), x_gap*i + 21, 400);
		sprintf(str, "%d", arr[i]);
		outtextxy(x_gap*i+1, 400-(arr[i]*10) -10, str);
	}
	delay(700);
	setcolor(BLACK);
	rectangle(x_gap*(i+1) +1, 400 - (arr[i+1]*10), x_gap*(i+1) + 21, 400);
	sprintf(str, "%d", arr[i+1]);
	outtextxy(x_gap*(i+1)+1, 400-(arr[i+1]*10) -10, str);
	rectangle(x_gap*high +1, 400 - (arr[high]*10), x_gap*high + 21, 400);
	sprintf(str, "%d", arr[high]);
	outtextxy(x_gap*high+1, 400-(arr[high]*10) -10, str);
	temp = arr[i+1];
	arr[i+1] = arr[high];
	arr[high] = temp;
	delay(200);
	setcolor(WHITE);
	rectangle(x_gap*(i+1) +1, 400 - (arr[i+1]*10), x_gap*(i+1) + 21, 400);
	sprintf(str, "%d", arr[i+1]);
	outtextxy(x_gap*(i+1)+1, 400-(arr[i+1]*10) -10, str);
	rectangle(x_gap*high +1, 400 - (arr[high]*10), x_gap*high + 21, 400);
	sprintf(str, "%d", arr[high]);
	outtextxy(x_gap*high+1, 400-(arr[high]*10) -10, str);

	return (i+1);
}

void quickSort(int arr[], int low, int high, int x_gap)
{
	if(low<high){
		int pivot = partition(arr, low, high, x_gap);
		quickSort(arr, low, pivot-1, x_gap);
		quickSort(arr, pivot+1, high, x_gap);
	}
}

void selectionSort(int arr[], int n, int x_gap)
{
	char *str;
	int i, j;
	int min;
	int temp;
	for(i = 0; i<n-1; i++){
		min = i;
		setcolor(RED);
		rectangle(x_gap*min +1, 400 - arr[min]*10, x_gap*min + 21, 400);
		sprintf(str, "%d", arr[min]);
		outtextxy(x_gap*min+1, 400-(arr[min]*10) -10, str);
		for(j = i+1; j<n; j++)
		{
			setcolor(BLUE);
			rectangle(x_gap *(j) +1, 400 - (arr[j]*10), x_gap*j + 21, 400);
			sprintf(str, "%d", arr[j]);
			outtextxy(x_gap*j+1, 400-(arr[j]*10) -10, str);
			if(arr[j]<arr[min]){
				min = j;
			}
			delay(200);
			setcolor(WHITE);
			rectangle(x_gap *(j) +1, 400 - (arr[j]*10), x_gap*j + 21, 400);
			sprintf(str, "%d", arr[j]);
			outtextxy(x_gap*j+1, 400-(arr[j]*10) -10, str);
		}
		delay(500);
		setcolor(BLACK);
		rectangle(x_gap*min +1, 400 - arr[min]*10, x_gap*min + 21, 400);
		sprintf(str, "%d", arr[min]);
		outtextxy(x_gap*min+1, 400-(arr[min]*10) -10, str);
		rectangle(x_gap*i +1, 400 - arr[i]*10, x_gap*i + 21, 400);
		sprintf(str,"%d",arr[i]);
		outtextxy(x_gap*i+1, 400-(arr[i]*10) -10, str);
		temp = arr[min];
		arr[min] = arr[i];
		arr[i] = temp;
		setcolor(WHITE);
		rectangle(x_gap*min +1, 400 - arr[min]*10, x_gap*min + 21, 400);
		sprintf(str, "%d", arr[min]);
		outtextxy(x_gap*min+1, 400-(arr[min]*10) -10, str);
		rectangle(x_gap*i +1, 400 - arr[i]*10, x_gap*i + 21, 400);
		sprintf(str, "%d", arr[i]);
		outtextxy(x_gap*i+1, 400-(arr[i]*10) -10, str);
		delay(500);
	}
}

void insertionSort(int arr[], int n, int x_gap)
{
	char *str;
	int i, j, key;
	for(i = 1; i<n; i++){
		j = i-1;
		key = arr[i];
		while (j >= 0 && arr[j] > key)
        {
        	setcolor(BLACK);
        	rectangle(x_gap*(j+1)+1, 400-(arr[j+1])*10, x_gap*(j+1)+21, 400);
        	sprintf(str, "%d", arr[j+1]);
        	outtextxy(x_gap*(j+1)+1, 400-(arr[j+1]*10) -10, str);
            arr[j + 1] = arr[j];
            delay(500);
            setcolor(WHITE);
            rectangle(x_gap*(j+1)+1, 400-(arr[j+1])*10, x_gap*(j+1)+21, 400);
            sprintf(str, "%d", arr[j+1]);
        	outtextxy(x_gap*(j+1)+1, 400-(arr[j+1]*10) -10, str);
            j = j - 1;
        }
        setcolor(BLACK);
        rectangle(x_gap*(j+1)+1, 400-(arr[j+1])*10, x_gap*(j+1)+21, 400);
        sprintf(str, "%d", arr[j+1]);
        outtextxy(x_gap*(j+1)+1, 400-(arr[j+1]*10) -10, str);
        arr[j + 1] = key;
        delay(500);
        setcolor(WHITE);
        rectangle(x_gap*(j+1)+1, 400-(arr[j+1])*10, x_gap*(j+1)+21, 400);
        sprintf(str, "%d", arr[j+1]);
        outtextxy(x_gap*(j+1)+1, 400-(arr[j+1]*10) -10, str);
       	delay(500);
	}
}

void bubbleSort(int arr[], int n, int x_gap)
{
	char *str;
	int i, j, temp;
	for(i = 0; i<n-1; i++){
		for(j = 0; j<n-i-1; j++){
			setcolor(RED);
			rectangle(x_gap*(j+1)+1, 400 - (arr[j+1])*10, x_gap*(j+1)+21, 400);
			sprintf(str, "%d", arr[j+1]);
        	outtextxy(x_gap*(j+1)+1, 400-(arr[j+1]*10) -10, str);
			rectangle(x_gap*j + 1, 400 - (arr[j]*10), x_gap*j +21, 400);
			sprintf(str, "%d", arr[j]);
        	outtextxy(x_gap*(j)+1, 400-(arr[j]*10) -10, str);
			delay(500);
			if(arr[j]>arr[j+1]){
				setcolor(BLACK);
				rectangle(x_gap*(j+1)+1, 400 - (arr[j+1])*10, x_gap*(j+1)+21, 400);
				sprintf(str, "%d", arr[j+1]);
        		outtextxy(x_gap*(j+1)+1, 400-(arr[j+1]*10) -10, str);
				rectangle(x_gap*j + 1, 400 - (arr[j]*10), x_gap*j +21, 400);
				sprintf(str, "%d", arr[j]);
        		outtextxy(x_gap*(j)+1, 400-(arr[j]*10) -10, str);

				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;

				setcolor(WHITE);
				rectangle(x_gap*(j+1)+1, 400 - (arr[j+1])*10, x_gap*(j+1)+21, 400);
				sprintf(str, "%d", arr[j+1]);
        		outtextxy(x_gap*(j+1)+1, 400-(arr[j+1]*10) -10, str);
				delay(500);
				rectangle(x_gap*j + 1, 400 - (arr[j]*10), x_gap*j +21, 400);
				sprintf(str, "%d", arr[j]);
        		outtextxy(x_gap*(j)+1, 400-(arr[j]*10) -10, str);
				delay(500);
			}
			setcolor(BLACK);
			rectangle(x_gap*(j+1)+1, 400 - (arr[j+1])*10, x_gap*(j+1)+21, 400);
			sprintf(str, "%d", arr[j+1]);
        	outtextxy(x_gap*(j+1)+1, 400-(arr[j+1]*10) -10, str);
			rectangle(x_gap*j + 1, 400 - (arr[j]*10), x_gap*j +21, 400);
			sprintf(str, "%d", arr[j]);
        	outtextxy(x_gap*(j)+1, 400-(arr[j]*10) -10, str);

        	setcolor(WHITE);
			rectangle(x_gap*(j+1)+1, 400 - (arr[j+1])*10, x_gap*(j+1)+21, 400);
			sprintf(str, "%d", arr[j+1]);
        	outtextxy(x_gap*(j+1)+1, 400-(arr[j+1]*10) -10, str);
			rectangle(x_gap*j + 1, 400 - (arr[j]*10), x_gap*j +21, 400);
			sprintf(str, "%d", arr[j]);
        	outtextxy(x_gap*(j)+1, 400-(arr[j]*10) -10, str);
		}
	}
}

int main()
{
	int gd = DETECT, gm;
	int array[100];
	int n = 10;
	int i, choice = 1;
	int x_gap = 24;
	char *str;
	printf("Enter the number of elements in the array (max 40)\n");
	scanf("%d", &n);
	printf("Enter the elements in the array\n");
	for(i = 0; i<n; i++){
		scanf("%d", &array[i]);
	}
	printf("Enter\n 1. To sort using Bubble Sort\n 2. To sort using Selection Sort\n 3. To sort using Insertion Sort\n 4. To sort using Quick Sort\n 5. To exit\n");
	scanf("%d", &choice);
	switch(choice){
		case 1:
			initgraph(&gd,&gm,"");
			for(i = 1; i<=n*x_gap; i+=x_gap){
				rectangle(i, 400-(array[i/x_gap]*10), i+20, 400);
				sprintf(str, "%d", array[i/x_gap]);
				outtextxy(x_gap*(i/x_gap)+1, 400-(array[i]*10) -10, str);
			}
			delay(1000);
			bubbleSort(array, n, x_gap);
			delay(1000);
			break;
		case 2:
			initgraph(&gd,&gm,"");
			for(i = 1; i<=n*x_gap; i+=x_gap){
				rectangle(i, 400-(array[i/x_gap]*10), i+20, 400);
				sprintf(str, "%d", array[i/x_gap]);
				outtextxy(x_gap*(i/x_gap)+1, 400-(array[i]*10) -10, str);
			}
			delay(1000);
			selectionSort(array, n, x_gap);
			delay(1000);
			break;
		case 3:
			initgraph(&gd,&gm,"");
			for(i = 1; i<=n*x_gap; i+=x_gap){
				rectangle(i, 400-(array[i/x_gap]*10), i+20, 400);
				sprintf(str, "%d", array[i/x_gap]);
				outtextxy(x_gap*(i/x_gap)+1, 400-(array[i]*10) -10, str);
			}
			delay(1000);
			insertionSort(array, n, x_gap);
			delay(1000);
			break;

		case 4:
			initgraph(&gd,&gm,"");
			for(i = 1; i<=n*x_gap; i+=x_gap){
				rectangle(i, 400-(array[i/x_gap]*10), i+20, 400);
				sprintf(str, "%d", array[i/x_gap]);
				outtextxy(x_gap*(i/x_gap)+1, 400-(array[i]*10) -10, str);
			}
			delay(1000);
			quickSort(array, 0, n-1, x_gap);
			delay(1000);
			break;
	}
	getch();
	closegraph();
	return 0;
}

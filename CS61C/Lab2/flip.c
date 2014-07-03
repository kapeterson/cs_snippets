#include <stdio.h>

void swap(unsigned char *x, unsigned char *y) {
  int tmp = *x;
  *x = *y;
  *y = tmp;
  //printf("X is %3c",*x);
  //printf("Y is %3c",*y);
}

void flip_horizontal(unsigned char *arr, int dim) {
  int x, y;
  int remainder = dim % 2;
  //printf("Modulo is %3d\n",remainder);
  int  swapspace = dim / 2;
  //printf("swap space is %3d\n",swapspace);
  for (y = 0; y < dim; y += 1) {
	//printf("--------\n");
	//char p = *arr;
	//int val = *(arr+y);

	//*(arr+y) = 5;
	//printf("Value is %3d \n",val);
	//printf("C is %3c \n",p);
	//printf("Value is %15s\n",p);
	for (x = 0; x < swapspace; x += 1) {
			int val = *(arr+x+(y*5));
			int val2 = *(arr+(y*5)+dim-x-1);
			//printf("VAl is %5d for y=%3d x=%3d item=%10d \n", val, y, x, (x+y*5));
			//printf("Val2 is %5d for y=%3d x=%3d item=%10d \n", 1,1, 1, (y*5+dim-x-1) );
		//  printf("X value: %5s\n",(arr+x+y));
			swap(arr+(x+y*5), arr + (y*5+dim-x-1)); // Changed from &arr[___] syntax to arr + ___
	}
  }
}

void print_2D(unsigned char *arr, int dim) {
  char *format = "%02x ";
  char *format_nl = "%02x\n";
  int i = 0;
  for (i = 0; i < dim*dim; i++) {
    printf( ((i + 1) % dim) ? format : format_nl, arr[i]);
  }
  printf("\n");
}

int main() {
  int dim = 5, i;
//unsigned char arr[] = {0x00, 0xff, 0xff, 0xff, 0x00,
//                       0x00, 0x00, 0x00, 0xff, 0x00,
//                       0x00, 0xff, 0xff, 0xff, 0x00,
//                       0x00, 0x00, 0x00, 0xff, 0x00,
//                       0x00, 0xff, 0xff, 0xff, 0x00};
//					 
//  unsigned char arr[] = {0xff, 0xff, 0xff, 0xff, 0x00,
//                         0xff, 0xff, 0xff, 0xff, 0x00,
//                         0xff, 0xff, 0xff, 0xff, 0x00,
//                         0xff, 0xff, 0xff, 0xff, 0x00,
//                         0xff, 0xff, 0xff, 0xff, 0x00};
//
unsigned char arr[] = {0xff, 0x00, 0x00, 0x00, 0x00,
                       0x00, 0xff, 0x00, 0x00, 0x00,
                       0x00, 0x00, 0xff, 0x00, 0x00,
                       0x00, 0x00, 0x00, 0xff, 0x00,
                       0x00, 0x00, 0x00, 0x00, 0xff};
					 
  printf("Before flip:\n");
  print_2D(arr, dim);

  flip_horizontal(arr, dim);

  printf("After flip:\n");
  print_2D(arr, dim);

  return 0;
}

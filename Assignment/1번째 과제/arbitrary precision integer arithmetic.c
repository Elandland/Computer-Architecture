#include<stdio.h>
#include<stdlib.h>

void rev(char *arr1, int cnt);
void plus_1(char *arr1, char *arr2, char *arr3, int cnt1, int cnt2, int max);
void min_1(char *arr1, char *arr2, char *arr3, int cnt1, int cnt2, int max);
void multi_1(char *arr1, char *arr2, char *arr3, int cnt1, int cnt2);
void div_1(char *arr1, char *arr2, char *arr3, char *temp, char *temp_res, int cnt1, int cnt2);

int comp(char *arr1, char *arr2);

int main() {

	int cnt1, cnt2;

	int tmp = 0;
	
	printf("연산할 첫번째 수의 자릿수를 입력하세요\n");
	scanf_s("%d", &cnt1);
	printf("연산할 두번째 수의 자릿수를 입력하세요\n");
	scanf_s("%d", &cnt2);

	int max = cnt1;

	if (cnt1 < cnt2) {
		max = cnt2;
	}

	char *arr1, *arr2, *plus_res,*plus1,*plus2;
	char *min1, *min2, *min_res;
	char *porg1,*porg2;
	char *mul1,*mul2,*mul_res;
	char *div1, *div2, *div_res, *temp,*temp_res;


	arr1 = (char*)calloc(max+1,sizeof(char));
	arr2 = (char*)calloc(max+1,sizeof(char));
	plus1 = (char*)calloc(max + 1, sizeof(char));
	plus2 = (char*)calloc(max + 1, sizeof(char));
	min1 = (char*)calloc(max + 1, sizeof(char));
	min2 = (char*)calloc(max + 1, sizeof(char));
	mul1 = (char*)calloc(max + 1, sizeof(char));
	mul2 = (char*)calloc(max + 1, sizeof(char));
	div1 = (char*)calloc(max + 1, sizeof(char));
	div2 = (char*)calloc(max + 1, sizeof(char));
	porg1 = (char*)calloc(max + 1, sizeof(char));
	porg2 = (char*)calloc(max + 1, sizeof(char));
	


	if(arr1 == NULL||arr2 ==NULL) {
		printf("할당실패");
	}

	printf("연산할 첫번째 수를 입력하세요\n");
	scanf_s("%s",arr1,max+1);

	printf("연산할 두번째 수를 입력하세요\n");
	scanf_s("%s",arr2,max+1);

	strcpy(plus1, arr1);
	strcpy(plus2, arr2);
	strcpy(min1, arr1);
	strcpy(min2, arr2);
	strcpy(mul1, arr1);
	strcpy(mul2, arr2);
	strcpy(div1, arr1);
	strcpy(div2, arr2);

	int cnt3 = max + 2;

	plus_res = (char*)calloc(cnt3 + 1, sizeof(char));
	min_res = (char*)calloc(cnt3 + 1, sizeof(char));
	mul_res = (char*)calloc(cnt1 + cnt2 + 1, sizeof(char));
	div_res = (char*)calloc(cnt3, sizeof(char));
	temp = (char*)calloc(cnt2+2, sizeof(char));
	temp_res = (char*)calloc(cnt3, sizeof(char));


	//음수,음수


	if (arr1[0] == '-'&&arr2[0] == '-')				
	{
		rev(plus1, cnt1);
		rev(plus2, cnt2);
		rev(min1, cnt1);
		rev(min2, cnt2);

		plus1[strlen(arr1) - 1] = 0;
		plus2[strlen(arr2) - 1] = 0;

		plus_1(plus1, plus2, plus_res, strlen(plus1), strlen(plus2), max-1);			//음수 + 음수
		if (plus_res[strlen(plus_res) - 1] == 0)
			plus_res[strlen(plus_res) - 1] = '-';
		else
			plus_res[strlen(plus_res)] = '-';
	
		//음수 - 음수
		
		if (cnt2  > cnt1) {
			min_1(min2, min1, min_res, strlen(min2), strlen(min1), max-1);			//양수 - 양수 ( 앞의 자릿수가 더 클 때 )
		}
		else if (cnt2 <cnt1)											//양수 - 양수 ( 뒤의 자릿수가 더 클 때)
		{
			min_1(min1, min2, min_res, strlen(min1), strlen(min2), max-1);

		}
		else	//cnt2 == cnt1 (연산 자리수 같을때)
		{
			strcpy(porg1, min1);
			strcpy(porg2, min2);

			rev(porg1, cnt1);
			rev(porg2, cnt2);

			int comp_num = comp(porg2, porg1);

			if (comp_num == 1) {
				min_1(min2, min1, min_res, strlen(min2), strlen(min1), max-1);
				min_res[strlen(min_res)] = '-';
			}
			else if (comp_num == 0) {
				min_1(min1, min2, min_res, strlen(min1), strlen(min2), max-1);
			}
			else if (comp_num == -1)
			{
				min_1(min1, min2, min_res, strlen(min1), strlen(min2), max - 1);
			}
		}

		//음수 * 음수


		//음수 / 음수
	
		cnt3 = strlen(plus_res);
		rev(plus_res, cnt3);
		cnt3 = strlen(min_res);
		rev(min_res, cnt3);
		cnt3 = strlen(mul_res);
		rev(mul_res, cnt3);
		cnt3 = strlen(div_res);
		rev(div_res, cnt3);
	
	}

	//음수, 양수
	else if (arr1[0] == '-' || arr2[0] == '-') {
		rev(plus1, cnt1);
		rev(plus2, cnt2);
		rev(min1, cnt1);
		rev(min2, cnt2);
		rev(mul1, cnt1);
		rev(mul2, cnt2);


		if (arr1[0] == '-') {			//음수  양수

			//음수 + 양수
			
			plus1[strlen(plus1) - 1] = 0;
			

			if (cnt1-1 > cnt2) {
				min_1(plus1, plus2, plus_res, strlen(plus1), strlen(plus2), max);			//양수 - 양수 ( 앞의 자릿수가 더 클 때 )
				plus_res[strlen(plus_res)] = '-';
			}
			else if (cnt1-1<cnt2)											//양수 - 양수 ( 뒤의 자릿수가 더 클 때)
			{
				min_1(plus2, plus1, plus_res, strlen(plus2), strlen(plus1), max);
				
			}
			else	//cnt1-1 == cnt2 (연산 자리수 같을때)
			{
				strcpy(porg1, plus1);
				strcpy(porg2, plus2);

				rev(porg1, cnt1 - 1);
				rev(porg2, cnt2);

				int comp_num = comp(porg1, porg2);

				if (comp_num == 1) {
					min_1(plus1, plus2, plus_res, strlen(plus1), strlen(plus2), max);
					plus_res[strlen(plus_res)] = '-';
				}
				else if (comp_num == 0) {
					min_1(plus1, plus2, plus_res, strlen(plus1), strlen(plus2), max);
				}
				else if (comp_num == -1)
				{
					min_1(plus2, plus1, plus_res, strlen(plus2), strlen(plus1), max);
				}
			}


			// 음수 - 양수
			min1[strlen(min1) - 1] = 0;
			plus_1(min1, min2, min_res, strlen(min1), strlen(min2), max);
			for (int i = max - 1; i > 0 && min_res[i] == '0'; i--)
			{
				min_res[i] = 0;
			}
			min_res[strlen(min_res)] = '-';

			//음수 * 양수
			mul1[strlen(mul1) - 1] = 0;

			multi_1(mul1, mul2, mul_res, cnt1, cnt2);

			mul_res[strlen(mul_res)] = '-';

			//음수 / 양수
			rev(div1, cnt1);
			div1[strlen(div1) - 1] = 0;
			rev(div1, strlen(div1));

			div_1(div1, div2, div_res, temp, temp_res, strlen(div1), strlen(div2));

			div_res[strlen(div_res)] = '-';

		}

		else {							//양수 , 음수
			
			//양수 + 음수

			plus2[strlen(plus2) - 1] = 0;

			if (cnt2 - 1 > cnt1) {
				min_1(plus2, plus1, plus_res, strlen(plus2), strlen(plus1), max);			//양수 - 양수 ( 앞의 자릿수가 더 클 때 )
				plus_res[strlen(plus_res)] = '-';
			}
			else if (cnt2 - 1<cnt1)											//양수 - 양수 ( 뒤의 자릿수가 더 클 때)
			{
				min_1(plus1, plus2, plus_res, strlen(plus1), strlen(plus2), max);

			}
			else	//cnt2-1 == cnt1 (연산 자리수 같을때)
			{
				strcpy(porg1, plus1);
				strcpy(porg2, plus2);

				rev(porg1, cnt1);
				rev(porg2, cnt2-1);

				int comp_num = comp(porg2, porg1);

				if (comp_num == 1) {
					min_1(plus2, plus1, plus_res, strlen(plus2), strlen(plus1), max);
					plus_res[strlen(plus_res)] = '-';
				}
				else if (comp_num == 0) {
					min_1(plus1, plus2, plus_res, strlen(plus1), strlen(plus2), max);
				}
				else if (comp_num == -1)
				{
					min_1(plus1, plus2, plus_res, strlen(plus1), strlen(plus2), max-1);
				}
			}

			//양수 - 음수
			min2[strlen(min2) - 1] = 0;

			plus_1(min1, min2, min_res, strlen(min1), strlen(min2), max);
			for (int i = max - 1; i > 0 && min_res[i] == '0'; i--)
			{
				min_res[i] = 0;
			}

			//양수 * 음수
			mul2[strlen(mul2) - 1] = 0;

			multi_1(mul1, mul2, mul_res, cnt1, cnt2);

			mul_res[strlen(mul_res)] = '-';

			//양수 / 음수
			rev(div2, cnt2);
			div2[strlen(div2) - 1] = 0;
			rev(div2, strlen(div2));

			div_1(div1, div2, div_res, temp, temp_res, strlen(div1), strlen(div2));

			div_res[strlen(div_res)] = '-';
		}
		cnt3 = strlen(plus_res);
		rev(plus_res, cnt3);
		cnt3 = strlen(min_res);
		rev(min_res, cnt3);
		cnt3 = strlen(mul_res);
		rev(mul_res, cnt3);
		cnt3 = strlen(div_res);
		rev(div_res, cnt3);

	}



	else {							//양수 , 양수
		
		rev(plus1, cnt1);
		rev(plus2, cnt2);
		rev(min1, cnt1);
		rev(min2, cnt2);
		rev(mul1, cnt1);
		rev(mul2, cnt2);

		//양수 + 양수
		plus_1(plus1, plus2, plus_res, strlen(plus1), strlen(plus2), max);		
		
		
		if (cnt1 > cnt2)
			min_1(min1, min2, min_res, strlen(min1), strlen(min2), max);			//양수 - 양수 ( 앞의 자릿수가 더 클 때 )
		else if (cnt1<cnt2)											//양수 - 양수 ( 뒤의 자릿수가 더 클 때)
		{
			min_1(min2, min1, min_res, strlen(min2), strlen(min1), max);
			min_res[strlen(min_res)] = '-';
		}
		else	//cnt1 == cnt2
		{
			strcpy(porg1, plus1);
			strcpy(porg2, plus2);

			rev(porg1, cnt1);
			rev(porg2, cnt2);
			int comp_num = comp(porg1, porg2);
			if (comp_num == 1) {
				min_1(min1, min2, min_res, strlen(min1), strlen(min2), max);
			}
			else if (comp_num == 0) {
				min_1(min1, min2, min_res, strlen(min1), strlen(min2), max);
			}
			else if (comp_num == -1)
			{
				min_1(min2, min1, min_res, strlen(min2), strlen(min1), max);
				min_res[strlen(min_res)] = '-';
			}

		}

		//양수 * 양수
		multi_1(mul1, mul2, mul_res, cnt1, cnt2);


		//양수 / 양수
		div_1(div1, div2, div_res, temp, temp_res, cnt1, cnt2);


		cnt3 = strlen(plus_res);
		rev(plus_res, cnt3);
		cnt3 = strlen(min_res);
		rev(min_res, cnt3);
		cnt3 = strlen(mul_res);
		rev(mul_res, cnt3);
		cnt3 = strlen(div_res);
		rev(div_res, cnt3);

	}
	printf("더하기 결과 = %s\n",plus_res);

	printf("빼기 결과 = %s\n", min_res);

	printf("곱셈 결과 = %s\n", mul_res);

	printf("나눗셈 결과 = %s\n", div_res);
	printf("%d\n", cnt1);
	printf("%d\n", cnt2);
	printf("%d\n", cnt3);
	printf("%s\n", arr1);
	printf("%s\n", arr2);
	printf("\n");


	free(arr1);
	free(arr2);
	free(plus1);
	free(plus2);
	free(min1);
	free(min2);
	free(plus_res);
	free(min_res);
	free(porg1);
	free(porg2);
	free(mul1);
	free(mul2);
	free(mul_res);
	free(div1);
	free(div2);
	free(div_res);
	free(temp);
	free(temp_res);


	return 0;
}

//입력 값 뒤집기
void rev(char *arr1,int cnt) {
	for (int i = 0; i < cnt / 2; i++)
	{
		int tmp;
		tmp = arr1[i];
		arr1[i] = arr1[cnt - i - 1];
		arr1[cnt - i - 1] = tmp;
	}
}

//더하기 연산 (양수 +양수)
void plus_1(char *arr1, char *arr2, char *arr3,int cnt1,int cnt2,int max) {
	for (int i = 0; i < max; i++)
	{
		int a1 = 0, a2 = 0;

		if (i < cnt1&&arr1[i] != 0) {
			a1 = arr1[i] - '0';
		}
		if (i < cnt2&&arr2[i] != 0) {
			a2 = arr2[i] - '0';
		}
		arr3[i] += (a1 + a2);
		if (arr3[i] >= 10)
		{
			arr3[i] %= 10;
			arr3[i + 1]++;
		}
		arr3[i] += '0';
	}
	if (arr3[max] != 0)
		arr3[max] += '0'; 
}

//빼기 연산 (양수-양수)
void min_1(char *arr1, char *arr2, char *arr3, int cnt1, int cnt2, int max) {
	for (int i = 0; i < max; i++)
	{
		int a1 = 0, a2 = 0;

		if (i < cnt1&&arr1[i] != 0) {
			a1 = arr1[i] - '0';
		}
		if (i < cnt2&&arr2[i] != 0) {
			a2 = arr2[i] - '0';
		}
		arr3[i] = a1 - a2;

		if (arr3[i] < 0)
		{
			arr3[i] += 10;
			arr1[i + 1] -= 1;

		}
		arr3[i] += '0';

		for (int i = max - 1; i > 0 && arr3[i] == '0'; i--)
		{
			arr3[i] = 0;
		}
	}
}


//곱하기 연산
void multi_1(char *arr1, char *arr2, char *arr3, int cnt1, int cnt2) {
	for (int i = 0; i < cnt1; i++) {
		for (int j = 0; j < cnt2; j++)
		{
			int a1 = 0, a2 = 0;

			if (i < cnt1&&arr1[i] != 0) {
				a1 = arr1[i] - '0';
			}
			if (j < cnt2&&arr2[j] != 0) {
				a2 = arr2[j] - '0';
			}

			arr3[i+j] += a1 * a2;
			if (arr3[i+j] >= 10)
			{
				arr3[i+j + 1] += arr3[i+j] / 10;
				arr3[i+j] %= 10;

			}
		}
	}
	for(int i =0; i< cnt1+cnt2; i++)
		arr3[i] += '0';

	for (int i = cnt1 + cnt2 - 1; i > 0 && arr3[i] == '0'; i--)
	{
		arr3[i] = 0;
	}
}

//나누기 연산
void div_1(char *arr1, char *arr2, char *arr3,char *temp,char *temp_res, int cnt1, int cnt2)
{
	int cnt;
	char *rev_arr2;
	rev_arr2 = (char*)calloc(strlen(arr2) + 1, sizeof(char));

	strcpy(rev_arr2, arr2);
	rev(rev_arr2, strlen(rev_arr2));

	for (int i = 0; i < cnt1; i++)
	{
		cnt = 0;
		temp[strlen(temp)] = arr1[i];
		while (comp(temp, arr2)>=0) {
			rev(temp, strlen(temp));
			min_1(temp,rev_arr2,temp_res,strlen(temp),cnt2,strlen(temp));
			rev(temp_res, strlen(temp_res));
			strcpy(temp, temp_res);
			cnt++;
		}
		arr3[i] += cnt+ '0';
	}
	rev(arr3, strlen(arr3));
	for (int i = strlen(arr3)-1 ; i > 0 && arr3[i] == '0'; i--)
	{
		arr3[i] = 0;
	}
	
}



int comp(char *arr1, char *arr2)		//안 뒤집은 양수끼리만 비교 , 문자열 비교
{
	if (strlen(arr1) > strlen(arr2))
		return 1;
	else if (strlen(arr1) < strlen(arr2))
		return -1;
	else {
		for (int i = 0; i < strlen(arr1); i++)
		{
			if (arr1[i] > arr2[i])
				return 1;
			else if (arr1[i] < arr2[i])
				return -1;
		}
		return 0;
	}
}


// 양수 양수 일때 덧셈, 뺄셈, 곱셈 ,나눗셈
// 양수 음수 일때 덧셈, 뺄셈, 곱셈 , 나눗셈
// 음수 음수 일때 덧셈, 

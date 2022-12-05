#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX(a, b) (a>b ? a : b)

// Val �ؼ����� Weight ���ǹ���, Value���ǰ�ġ 
int Val[101][100001];
int Weight[101];
int Value[101];
void dp(int n, int k){
	int i, j;
	for (i=1; i<=n; i++){
		for (j=0; j<=k; j++){
			Val[i][j] = Val[i-1][j];
			if (j - Weight[i] >= 0){
				Val[i][j] = MAX(Val[i][j], Val[i-1][j-Weight[i]]+Value[i]);
			}
		}
	}
	printf("%d", Val[n][k]);
}

int main(void){
	// n: ���ǰ��� k :�� ���� ���� 
	int i, n, k, temp;
	scanf("%d %d", &n, &k);
	
	for (i=1; i<=n; i++){
		scanf("%d %d", &Weight[i], &Value[i]);
	}
	
	dp(n, k);
	
	return 0;
}

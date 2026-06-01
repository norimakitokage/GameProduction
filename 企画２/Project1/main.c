#include <stdio.h>

#define NUM 5

int main(void)
{
	char c = 'x';
	int num[NUM] = { 0 };

	for (int i = 0; i < NUM; i++) {
		printf("%dつ目の数字を入力してください：", i + 1);
		scanf_s("%d", &num[i]);
		rewind(stdin);
	}

	

	while (c != 'z') {
		printf("\n■入力された数字■\n");
		printf("入力：");
		for (int i = 0; i < NUM; i++) {
			printf("[ %d]", num[i]);
		}
		printf("\n添字：");
		for (int i = 0; i < NUM; i++) {
			printf("[ %d]", i + 1);
		}
		printf("\n");
		
		printf("a：入れ替えモード\n");
		printf("b：連番チェック\n");
		printf("z：終了\n");
		printf("入力してください：");
		scanf_s("%c", &c,1);
		rewind(stdin);

		if (c == 'a') {
			int n1, n2, mem;
			printf("入れ替えたい添字を2つ入力してください(空白区切り)：");
			scanf_s("%d %d", &n1, &n2);
			rewind(stdin);
			printf("\n");

			n1 -= 1;
			n2 -= 1;

			mem = num[n1];
			num[n1] = num[n2];
			num[n2] = mem;
		}
		else if (c == 'b') {
			printf("入力された数字が連番かチェックします。\n");
			
			int res = 0;
			for (int i = 0; i < NUM - 1; i++) {
				int mem = abs(num[i] - num[i + 1]);
				if (mem != 1) {
					res = -1;
				}
			}

			if (res == -1) {
				printf("連番ではありません。\n");
			}
			else {
				printf("連番です。\n");
			}

		}
	}
}
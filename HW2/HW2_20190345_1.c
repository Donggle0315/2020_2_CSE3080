#include <stdio.h>
#include <string.h>

int main() {
	//�Է��� ����ܾ�, �ּ� 2���� �ִ� 30����
	//�ߺ��� ������ ���ڸ� ���
	char a[100];
	char b[31];
	int i, j=0;

	gets(a, 100);
	if (strlen(a) < 2 || strlen(a) > 30) {
		fprintf(stderr, "size error");
		return 1;
	}

	for (i = 0; i < strlen(a); i++) {
		if (a[i] == a[i + 1]) {
			continue;
		}
		b[j++] = a[i];
	}
	b[j] = '\0';

	printf("%s\n", b);


	return 0;
}

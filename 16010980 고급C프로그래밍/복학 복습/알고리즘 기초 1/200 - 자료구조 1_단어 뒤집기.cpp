#include <iostream>

int main(){
	char **stc, wrd[20];
	int T;

	std::cin >> T;	// ���� 'T' �� �Է�

	// 2�� �迭 �����Ҵ�
	try {
		stc = new char *[T];
		for (int i = 0 ; i < T ; i++)
			stc[i] = new char [1000];
	}
	catch (std::bad_alloc & ba){
		std::cerr << "bad_alloc�� �߻��߽��ϴ�: " << ba.what() << '\n';
	}
	//

	// ������ �Է�
	for (int i = 0 ; i < T ; i++)
		std::cin.getline(stc[i], 1000);
	//

	// 2�� �迭 �޸�����
	for (int i = 0 ; i < T ; i++)
		delete [] stc[i];
	delete [] stc;
	//

	return 0;
}
#include <iostream>

int main(){
	char **stc, wrd[20];
	int T;

	std::cin >> T;	// 정수 'T' 를 입력

	// 2차 배열 동적할당
	try {
		stc = new char *[T];
		for (int i = 0 ; i < T ; i++)
			stc[i] = new char [1000];
	}
	catch (std::bad_alloc & ba){
		std::cerr << "bad_alloc이 발생했습니다: " << ba.what() << '\n';
	}
	//

	// 문장을 입력
	for (int i = 0 ; i < T ; i++)
		std::cin.getline(stc[i], 1000);
	//

	// 2차 배열 메모리해제
	for (int i = 0 ; i < T ; i++)
		delete [] stc[i];
	delete [] stc;
	//

	return 0;
}
#include <iostream>

using namespace std;

int main(){
	char ch, peekCh;
	cout << "Enter a string: ";
	
	cin.get(ch);
	cout << "After first cin.get(ch): ";
	cout << "ch = " << ch << '\n';

	cin.get(ch);
	cout << "After second cin.get(ch): ";
	cout << "ch = " << ch << '\n';

	// put the character back in the stream
	cin.putback(ch);
	cin.get(ch);
	cout << "After putback, the third cin.get(ch): ";
	cout << "ch = " << ch << '\n';

	// get next character in stream
	// without removing it
	peekCh = cin.peek();
	while (cin.peek() != '5')
			cin.ignore();

	cin.get(ch);

	cout << "After peek, the fourth cin.get(ch): ";
	cout << "ch = " << ch << '\n';
	cout << "And peekCh: " << peekCh << '\n';

	return 0;
}

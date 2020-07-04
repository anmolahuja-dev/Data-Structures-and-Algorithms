#include <iostream>
#include "Array.h";
using namespace std;

struct Choice {
	int mainCh{ 0 };
	int subCh{ 0 };
};
Choice SetMenu(Choice c);
int subMenu();
void MainMenu() {
	int n;
	cout << " ##### Data Structure - Array #### "<<endl<<endl;
	cout << "Enter the size of the array : ";
	cin >> n;
	Array arr(n);
	arr.create();
	
	int ch;
	do {
		cout << "\nEnter the Operation, You want to perform on the Array" << endl;
		cout << " [1] - Display the Array" << endl;
		cout << " [2] - Add Element" << endl;
		cout << " [3] - Insert Element" << endl;
		cout << " [4] - Delete Element" << endl;
		cout << " [5] - Linear Search" << endl;
		cout << " [6] - Binary Search" << endl;
		cout << " [7] - Binary Search (Recursive version)" << endl;
		cout << " [8] - Get, Set, Max, Min, Add and Average" << endl;
		cout << " [9] - Reverse, Left Rotate and Right rotate" << endl;
		cout << " [10] - Check for Sorted Array,Insert Element in Sorted order and arranging elements" << endl;
		cout << " [11] - Merge a new array to the existing array" << endl;
		cout << " [12] - Set Operations" << endl;
		cout << " [0]- Quit the program" << endl;
		cout << " \nYour option : ";
		cin >> ch;

		if (ch == 1) {
			arr.display();
		}
		if (ch == 2) {
			arr.add();
		}
		if (ch == 3) {
			arr.insert();
		}
		if (ch == 4) {
			arr.Delete();
		}
		if (ch == 5) {
			arr.Lsearch();
		}
		if (ch == 6) {
			arr.BinarySearch();
		}
		if (ch == 7) {
			int l{ 0 }, h = arr.getLength() - 1, key{ 0 };
			cout << "Enter the element you want to search : ";
			cin >> key;
			int pos{ 0 };
			pos = arr.RBinarySearch(l, h, key);
			if (pos >= 0)
				cout << "\nElement found at position " << pos<<endl;
			else
				cout << "\nElement Not found !!" << endl;
		}
		if (ch == 8) {
			int opt{ 0 };
			opt = subMenu();

			if (opt == 1) {
				int index{ 0 };
				cout << "Enter the index of the element, You want to get : ";
				cin >> index;
				if (arr.getElement(index) == -1) {
					cout << "\nElement not found" << endl;
				}
				else {
					cout << "\nElement at "<<index<< " is : " << arr.getElement(index);

				}
			}
			else if (opt == 2) {
				int index{ 0 }, x{ 0 };
				cout << "Enter the index of the element, You want to set : ";
				cin >> index;
				cout << "Enter the element : ";
				cin >> x;
				arr.setElement(index,x);
			}
			else if (opt == 3) {
				arr.maxElement();
			}
			else if (opt == 4) {
				arr.minElement();
			}
			else if (opt == 5) {
				arr.sumElement();
			}
			else if (opt == 6) {
				int sum=arr.RsumElement(arr.getLength()-1);
				cout << "\nSum of Elements is : " << sum << endl;
			}
			else if (opt == 7) {
				arr.avgElement();
			}
			else {
				cout << "\n Enter valid choice!" << endl;
			}
		}
		if (ch == 9) {
			int opt{ 0 };
			cout << "\nEnter the operation you want to perform" << endl;
			cout << " [1] - Reverse the Array" << endl;
			cout << " [2] - Left rotate the Array" << endl;
			cout << " [3] - Right rotate the Array" << endl;
			cout << "\n Your Choice : ";
			cin >> opt;

			if (opt == 1) {
				arr.reverse();
			}
			if (opt == 2) {
				arr.Lrotate();
			}
			if (opt == 3) {
				arr.Rrotate();
			}
		}
		if (ch == 10) {
			int opt{ 0 };
			cout << "\nEnter the operation you want to perform" << endl;
			cout << " [1] - Insert Element in a Sorted Array" << endl;
			cout << " [2] - Check if Array is Sorted" << endl;
			cout << " [3] - Arrange the Array (negatives on the left and positives on the right)" << endl;
			cout << "\n Your Choice : ";
			cin >> opt;

			if (opt == 1) {
				arr.sInsert();
			}
			if (opt == 2) {
				arr.isSorted();
			}
			if (opt == 3) {
				arr.arrange();
			}
		}
		if (ch == 11) {
			int n;
			cout << "Enter the size of the array : ";
			cin >> n;
			Array arrB(n);
			arrB.create();
			Array C=arr.Merge(arrB);
			C.display();
		}
		if (ch == 12) {

			int n;
			cout << "\nEnter the size of the Array B : ";
			cin >> n;
			Array arrB(n);
			arrB.create();

			Choice ch;
			ch=SetMenu(ch);

			if (ch.mainCh == 1) {
				if (ch.subCh == 1) {
					Array C = arr.Union(arrB);
					C.display();
				}
				else if (ch.subCh == 2) {
					Array C = arr.Intersection(arrB);
					C.display();
				}
				else if (ch.subCh == 3) {
					Array C = arr.Deletion(arrB);
					C.display();
				}
			}
			if (ch.mainCh == 2) {
				if (ch.subCh == 1) {
					Array C = arr.usUnion(arrB);
					C.display();
				}
				else if (ch.subCh == 2) {
					Array C = arr.usIntersection(arrB);
					C.display();
				}
				else if (ch.subCh == 3) {
					Array C = arr.usDeletion(arrB);
					C.display();
				}
			}
		}
	} while (ch != 0);
}
Choice SetMenu(Choice c) {
	cout << "\nEnter Your Array Type : "<<endl;
	cout << "[1] Sorted Array" << endl;
	cout << "[2] Unsorted Array" << endl;
	cout << "\nEnter your choice : " ;
	cin >> c.mainCh;

	cout << "\nEnter the Set operation, you want to perform on this array" << endl;
	cout << " [1]- Union Operation" << endl;
	cout << " [2]- Intersection Operation" << endl;
	cout << " [3]- Difference Operation" << endl;
	cout << "\nEnter your choice : ";
	cin >> c.subCh;
	return (c);

}
int subMenu() {
	cout << "\n Select the operation, You want to perform" << endl;
	cout << " [1] - Get an Element" << endl;
	cout << " [2] - Set an Element" << endl;
	cout << " [3] - Get Max Element" << endl;
	cout << " [4] - Get Min Element" << endl;
	cout << " [5] - Get Total Sum of Elements" << endl;
	cout << " [6] - Get Total Sum of Elements [using Recursion]" << endl;
	cout << " [7] - Get Average of all Elements" << endl;
	int opt{ 0 };
	cout << "Enter Your Choice : ";
	cin >> opt;
	return opt;
}

int main() {
	MainMenu();
	
	return 0;
}
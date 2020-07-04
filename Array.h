#pragma once
#include<math.h>
using namespace std;
class Array
{
private:
	int* A;
	int size;
	int length;
public:
	Array(int size) {
		this->size = size;
		A = new int[size];
	}
	void create() {
		cout << "Enter the number of elements, you want to enter : ";
		cin >> length;
		if (length <= size) {
			cout << "Enter " << length << " element : " << endl;
			for (int i = 0; i < length; i++) {
				cout << "Enter Element [" << i + 1 << "] : ";
				cin >> A[i];
			}
		}
		else {
			cout << "\nLength Entered is greater than the size of the Array!" << endl;
		}
	}
	void display() {
		cout << "\nThe Array is : ";
		for (int i = 0; i < length; i++) {
			cout << A[i] << " ";
		}
		cout << endl;
	}
	int getLength() {
		return length;
	}
	void add() {
		if (length < size) {
			cout << "Enter " << length + 1<< " element : ";
			cin >> A[length];
			length++;
			cout << "Element Added!!" << endl;
		}
		else {
			cout << "Array is full!"<<endl ;
		}
	}
	void insert() {
		int index, element;
		
		cout << "Enter the index at which you want to add the element : ";
		cin >> index;
		cout << "Enter the element : ";
		cin >> element;

		if (index <= length && index>=0 && length < size) {
			for (int i = length; i > index; i--) {
				A[i] = A[i - 1];
			}
			A[index] = element;
			length++;
			cout << "\nElement Inserted!!" << endl;
		}
		else {
			cout << "Element cannot be inserted as the index exceeds the array size " << endl;
		}
	}

	void Delete() {
		int index;
		cout << "Enter the index of the element, you want to delete : ";
		cin >> index;
		if (index >= 0 && index < length) {
			int x = A[index];
			for (int i = index; i < length - 1; i++) {
				A[i] = A[i + 1];
			}
			length--;
			cout << "\nElement " << x << " Deleted Succesfully! " << endl;
		}
		else {
			cout << "\nCannot delete the element as the index is not valid!"<<endl;
		}
	}

	void swap(int i1, int i2) {
		int temp{ 0 };
		temp = A[i1];
		A[i1] = A[i2];
		A[i2] = temp;
	}
	void Lsearch() {
		int key{ 0 }, i, flag = 1, pos{ 0 };
		cout << "\nEnter the element you want to search : ";
		cin >> key;
		for (i = 0; i < length; i++) {
			if (A[i] == key) {
				flag = 0;
				pos = i;
			}
		}
		if (flag == 0) {
			swap(0, pos);
			cout << "\nElement found at position : " << pos << endl;
		}
		else
			cout << "\nElement not found!" << endl;
	}

	void BinarySearch() {
		int l{ 0 }, h = length - 1, key{ 0 }, pos{ 0 }, mid{ 0 },flag=1;
		cout << "Enter the element you want to search : ";
		cin >> key;
		while (l <= h) {
			mid = floor((l + h) / 2);
			if (A[mid] == key) {
				pos = mid;
				flag = 0;
				break;
			}
			else if (key < A[mid]) {
				h = mid - 1;
			}
			else {
				l = mid + 1;
			}
		}
		if (flag == 0)
			cout << "\nElement Found at position " << pos << endl;
		else
			cout << "\nElement Not found!"<<endl;
	}

	int RBinarySearch(int l,int h,int key) {
		int mid;
		mid = floor((l + h) / 2);
		if (l <= h) {
			if (A[mid] == key) {
				return mid;
			}
			else if (key < A[mid]) {
				RBinarySearch(l,mid - 1,key);
			}
			else {
				RBinarySearch(mid + 1,h,key);
				
			}
		}
		else
		{
			return -1;
		}
		
	}

	int getElement(int index) {
		
		if (index >= 0 && index < length)
			return A[index];
		else
			return -1;
	}
	void setElement(int index, int x) {
		if (index >= 0 && index < length) {
			A[index] = x;
			cout << "\nElement at " << index << " is set to : " << x << endl;
		}
		else {
			cout << "\nInvalid Index" << endl;
		}
		
	}

	void maxElement() {
		int max = A[0];
		for (int i = 1; i < length; i++) {
			if (A[i] > max)
				max = A[i];
		}
		cout << "\nMax Element is : " << max << endl;
	}

	void minElement() {
		int min = A[0];
		for (int i = 1; i < length; i++) {
			if (A[i] < min)
				min = A[i];
		}
		cout << "\nMax Element is : " << min << endl;
	}
	void sumElement() {
		int sum=0;
		for (int i = 0; i < length; i++) {
			sum += A[i];
		}
		cout << "\nSum of Elements is : " << sum << endl;
	}

	int RsumElement(int n) {
		if (n < 0)
			return 0;
		else
			return RsumElement(n - 1) + A[n];
	}
	void avgElement() {
		int sum = 0;
		for (int i = 0; i < length; i++) {
			sum += A[i];
		}
		cout << "\nAverage of Elements is : " << float(sum)/length << endl;
	}

	void Lrotate() {
		int temp = A[0];
		for (int i = 0; i < length; i++)
			A[i] = A[i + 1];
		A[length - 1] = temp;
		cout << "\nArray Rotated Succesfully!" << endl;
		display();
	}
	void Rrotate() {
		int temp = A[length-1];
		for (int i = length-1; i >= 0; i--)
			A[i] = A[i - 1];
		A[0] = temp;
		cout << "\nArray Rotated Succesfully!" << endl;
		display();
	}

	void reverse() {
		int i, j;
		for (i = 0, j = length - 1; i < j; i++, j--)
			swap(i, j);
		cout << "\nArray Reversed Succesfully!" << endl;
		display();
	}

	void isSorted() {
		int flag{ 1 };
		for (int i = 0; i < length-1; i++) {
			if (A[i] > A[i + 1])
				flag = 0;
		}
		if (flag == 0)
			cout << "\nArray is not Sorted!" << endl;
		else
			cout << "\nArray is Sorted!!" << endl;
	}
	void sInsert() {
		int j,x;
		cout << "Enter the element, you want to insert : ";
		cin >> x;
		j = length - 1;
		if (length < size) {
			while (A[j] > x) {
				A[j + 1] = A[j];
				j--;
			}
			A[j + 1] = x;
			cout << "\nElement Inserted Successfully" << endl;
			display();
		}
		else
			cout << "\nArray is full!"<<endl;
	}

	void arrange() {
		int i, j;
		i = 0;
		j = length - 1;

		while (i < j) {
			while (A[i] < 0) { i++; }
			while (A[j] >= 0) { j--; }

			if (i < j)
				swap(i, j);
		}

		cout << "\nArranged the Elements" << endl;
		display();
	}

	Array Merge(Array& B) {
		Array *C= new Array(length + B.length);
		int i{ 0 }, j{ 0 }, k{0};

		while (i < length && j < B.length)
		{
			if (A[i] < B.getElement(j)) {
				C->A[k++]=A[i++];
			}
			else {
				C->A[k++]= B.A[j++];
			}
		}
		for (; i < length; i++) {
				C->A[k++]= A[i];
		}
		for (; j < B.length; j++) {
				C->A[k++]= B.A[j];
		}
		C->length = length + B.length;
		return *C;

	}

	Array Union(Array& B) {
		Array* C = new Array(length + B.length);
		int i{ 0 }, j{ 0 }, k{ 0 };

		while (i < length && j < B.length)
		{
			if (A[i] < B.getElement(j)) {
				C->A[k++] = A[i++];
			}
			else if (A[i] > B.getElement(j)) {
				C->A[k++] = B.A[j++];
			}
			else {
				C->A[k++] = A[i++];
				j++;
			}
		}
		for (; i < length; i++) {
			C->A[k++] = A[i];
		}
		for (; j < B.length; j++) {
			C->A[k++] = B.A[j];
		}
		C->length = k;
		return *C;

	}
	Array Intersection(Array& B) {
		Array* C = new Array(length + B.length);
		int i{ 0 }, j{ 0 }, k{ 0 };

		while (i < length && j < B.length)
		{
			if (A[i] < B.getElement(j)) {
				i++;
			}
			else if (A[i] > B.getElement(j)) {
				j++;
			}
			else {
				C->A[k++] = A[i++];
				j++;
			}
		}
		
		C->length = k;
		return *C;

	}

	Array Deletion(Array& B) {
		Array* C = new Array(length + B.length);
		int i{ 0 }, j{ 0 }, k{ 0 };

		while (i < length && j < B.length)
		{
			if (A[i] < B.getElement(j)) {
				C->A[k++]=A[i++];
				
			}
			else if (A[i] > B.getElement(j)) {
				j++;
			}
			else {
				i++;
				j++;
			}
		}
		for (; i < length; i++) {
			C->A[k++] = A[i];
		}
		C->length = k;
		return *C;

	}

	Array usUnion(Array &B) {
		Array* C = new Array(length + B.length);
		int i, j, k{ 0 },flag=1;
		
		for (i = 0; i < length; i++) {
			C->A[k++] = A[i];
		}
		
		for (j = 0; j < B.length; j++) {
			flag = 1;
			for (int i = 0; i < length; i++) {
				if (C->A[i] == B.A[j]) {
					flag = 0;
				}
			}
				if (flag == 1) {
					C->A[k++] = B.A[j];
				}
			}
		C->length = k;
		return *C;
	}
	Array usIntersection(Array& B) {
		Array* C = new Array(length + B.length);
		int i, j, k{ 0 }, flag = 1;

		for (i = 0; i < length; i++) {
			for (int j = 0; j < B.length; j++) {
				if (A[i] == B.A[j]) {
					C->A[k++] = A[i];
				}
			}
		}
		C->length = k;
		return *C;
	}

	Array usDeletion(Array& B) {
		Array* C = new Array(length + B.length);
		int i, j, k{ 0 }, flag = 1;


		for (i = 0; i < length; i++) {
			flag = 1;
			for (int j = 0; j < B.length; j++) {
				if (A[i] == B.A[j]) {
					flag = 0;
				}
			}
			if (flag == 1) {
				C->A[k++] = A[i];
			}
		}
		C->length = k;
		return *C;
	}

	~Array() {
		delete[] A;
		cout << "\nThanks for using Array DS"<<endl;
	}
};


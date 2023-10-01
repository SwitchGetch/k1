#include <iostream>
#include <cmath>
using namespace std;

template <typename T>
class Arr
{
	T* array;
	size_t size = 0;
public:
	Arr(T size) {
		array = new T[size];

		this->size = size;

		for (size_t i = 0; i < this->size; i++) array[i] = 0;
	}

	Arr() = default;

	~Arr() { delete array; }

	void append(int a)
	{
		T* TempArray = array;
		array = new T[this->size + 1];

		for (size_t i = 0; i < this->size; i++) array[i] = TempArray[i];

		array[this->size] = a;
		this->size++;
	}

	void destroy(size_t index)
	{
		T* TempArray = new T[this->size];

		for (size_t i = 0; i < size; i++) TempArray[i] = array[i];

		delete array;
		array = new T[this->size - 1];

		for (size_t i = 0; i < size; i++)
		{
			if (i > index) array[i - 1] = TempArray[i];
			else if (i < index) array[i] = TempArray[i];
		}

		size--;
	}

	void destroy(size_t index, size_t count)
	{
		T* TempArray = new T[this->size];

		for (size_t i = 0; i < size; i++) TempArray[i] = array[i];

		delete array;
		array = new T[size - count];

		for (size_t i = 0; i < size; i++)
		{
			if (i >= index + count) array[i - count] = TempArray[i];
			else if (i < index) array[i] = TempArray[i];
		}

		size -= count;
	}

	void set_element(size_t index, T value) { array[index] = value; }

	//T operator[](size_t index) { return array[index]; }

	void output()
	{
		for (size_t i = 0; i < this->size; i++) cout << array[i] << " ";

		cout << endl;
	}

	T at(size_t index) { return array[abs(index) % this->size]; }

	size_t length() { return this->size; }

};

int main()
{
	setlocale(LC_ALL, "ru");
	Arr<int> arr(7);

	cout << "после конструктора от 7:" << endl;
	arr.output();
	cout << endl;

	arr.append(8);
	cout << "после append(8):" << endl;
	arr.output();
	cout << endl;

	for (size_t i = 0; i < arr.length(); i++) arr.set_element(i, i + 1);
	cout << "после set_element(i, i + 1):" << endl;
	arr.output();
	cout << endl;

	arr.destroy(2);
	cout << "после destroy(2):" << endl;
	arr.output();
	cout << endl;

	arr.append(0);
	arr.output();

	for (size_t i = 0; i < arr.length(); i++) arr.set_element(i, i + 1);
	arr.output();
	cout << endl;

	int index, count;

	cout << "index: ";
	cin >> index;
	cout << "count: ";
	cin >> count;

	cout << "после destroy(" << index << ", " << count << "):" << endl;
	arr.destroy(index, count);
	arr.output();
	cout << endl;
}

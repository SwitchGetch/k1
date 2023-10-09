#include <iostream>
#include <cmath>
using namespace std;

template <typename T>
class Array
{

	T* array;
	size_t size = 0;

public:

	Array(T size) {
		array = new T[size];

		this->size = size;

		for (size_t i = 0; i < this->size; i++) array[i] = 0;
	}

	Array() = default;


	void append(int a)
	{
		T* TempArray = new T[this->size];

		for (size_t i = 0; i < this->size; i++) TempArray[i] = this->array[i];

		delete array;
		this->array = new T[this->size + 1];

		for (size_t i = 0; i < this->size; i++) array[i] = TempArray[i];

		array[this->size] = a;
		this->size++;
	}


	void insert(size_t index, T value)
	{
		T* TempArray = new T[this->size + 1];

		for (size_t i = 0; i <= this->size; i++)
		{
			if (i < index) TempArray[i] = array[i];
			else if (i == index) TempArray[i] = value;
			else if (i > index) TempArray[i] = array[i - 1];
		}

		delete array;
		this->size++;

		array = new T[this->size];

		for (size_t i = 0; i < this->size; i++) array[i] = TempArray[i];
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


	void destroy(Array<T> arr)
	{
		size_t count = 0;

		T* TempArray = new T[this->size];


		for (size_t i = 0; i < this->size; i++)
		{
			bool include = true;

			for (size_t j = 0; j < arr.length(); j++)
			{
				if (this->array[i] == arr[j])
				{
					include = false;
					break;
				}
			}

			if (include)
			{
				TempArray[count] = this->array[i];
				count++;
			}
		}


		delete this->array;
		this->size = count;

		this->array = new T[this->size];

		for (size_t i = 0; i < this->size; i++) this->array[i] = TempArray[i];
	}


	size_t length()
	{
		return this->size;
	}


	T& operator[](size_t index)
	{
		return this->array[index];
	}

};

int main()
{
	Array<int> arr;
	int size, count, temp;

	cout << "array size: ";
	cin >> size;

	for (size_t i = 0; i < size; i++)
	{
		cout << i + 1 << ") ";
		cin >> temp;

		arr.append(temp);
	}

	cout << endl;

	for (size_t i = 0; i < arr.length(); i++) cout << arr[i] << " ";

	cout << "\n" << endl;


	cout << "destroy(index): " << endl;
	
	cout << "index: ";
	cin >> temp;

	arr.destroy(temp);

	for (size_t i = 0; i < arr.length(); i++) cout << arr[i] << " ";

	cout << "\n" << endl;


	cout << "destroy(index, count): " << endl;
	cout << "index: ";
	cin >> temp;

	cout << "count: ";
	cin >> count;

	arr.destroy(temp, count);

	for (size_t i = 0; i < arr.length(); i++) cout << arr[i] << " ";

	cout << "\n" << endl;


	cout << "destroy(array):" << endl;

	cout << "array size: ";
	cin >> size;

	Array<int> temp_arr(size);

	for (size_t i = 0; i < size; i++)
	{
		cout << i + 1 << ") ";
		cin >> temp_arr[i];
	}

	for (size_t i = 0; i < temp_arr.length(); i++) cout << temp_arr[i] << " ";

	cout << "\n" << endl;

	arr.destroy(temp_arr);


	for (size_t i = 0; i < arr.length(); i++) cout << arr[i] << " ";

	cout << endl;
}

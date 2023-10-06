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

	~Arr() { delete[] array; }


	void append(int a)
	{
		T* TempArray = new T[this->size];

		for (size_t i = 0; i < this->size; i++) TempArray[i] = this->array[i];

		delete array;
		this->array = new T[this->size + 1];

		for (size_t i = 0; i < this->size; i++) array[i] = TempArray[i];

		array[this->size] = a;
		this->size++;

		delete TempArray;
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

		delete TempArray;
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

		delete TempArray;
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

		delete TempArray;
	}


	void destroy(Arr<T> arr)
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

		delete TempArray;
	}


	T at(size_t index) { return array[index]; }


	size_t length() { return this->size; }

	T& operator[](size_t index) { return this->array[index]; }


};

int main()
{
	setlocale(0, "");

	Arr<int> array(5);
	Arr<int> temp(3);

	for (size_t i = 0; i < 5; i++) array[i] = i;

	for (size_t i = 0; i < 3; i++) temp[i] = i;


	for (size_t i = 0; i < array.length(); i++) cout << array[i] << " ";
	cout << endl;

	for (size_t i = 0; i < temp.length(); i++) cout << temp[i] << " ";
	cout << endl;


	array.destroy(temp);

	for (size_t i = 0; i < array.length(); i++) cout << array[i] << " ";
	cout << endl;

	cout << "whjegbfjh" << endl;
	cout << "whjegbfjh" << endl;
	cout << "whjegbfjh" << endl;
	cout << "whjegbfjh" << endl;
	cout << "whjegbfjh" << endl;
	cout << "whjegbfjh" << endl;
	cout << "whjegbfjh" << endl;

	/*Arr<int> array(5);
	int index, value;

	array.output();

	cout << "index: ";
	cin >> index;
	cout << "value: ";
	cin >> value;

	array.insert(index, value);

	array.output();

	array[index + 1] = 5;
	array.output();

	cout << array[index];*/

	/*size_t temp;

	cout << "размер массива: ";
	cin >> temp;

	Arr<int> array(temp);
	array.output();

	cout << "добавить: ";
	cin >> temp;

	array.append(temp);
	array.output();

	cout << "удалить: ";
	cin >> temp;

	array.destroy(temp);
	array.output();*/

	/*setlocale(LC_ALL, "ru");
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
	cout << endl;*/
}

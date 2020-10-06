#include <iostream>
#include <variant>

class AnyType
{
private:
	std::variant<bool, char, double, int, float, long> data;
	std::string dataType;
public:

	/// <summary>
	/// Constructor to initialize data and dataType by standard values
	/// </summary>
	AnyType():data(0), dataType(typeid(int).name()) {}

	/// <summary>
	/// Constructor to initialize data and dataType by custom values
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="data_"></param>
	template<typename T>
	AnyType(const T data_) : data(data_),
		dataType(typeid(data_).name()) {}

	/// <summary>
	/// Copy costructor
	/// </summary>
	/// <param name="object"></param>
	AnyType(const AnyType& object)
	{
		data = object.data;
		dataType = object.dataType;
	}

	/// <summary>
	/// Assignment operator
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="data_"></param>
	/// <returns></returns>
	template<typename T>
	AnyType& operator= (T data_)
	{
		data = data_;
		dataType = typeid(data_).name();
		return *this;
	}

	/// <summary>
	/// Copy operator
	/// </summary>
	/// <param name="object"></param>
	/// <returns></returns>
	AnyType& operator= (const AnyType& object)
	{
		data = object.data;
		dataType = object.dataType;
	}

	/// <summary>
	/// Function to swap two objects
	/// </summary>
	/// <param name="obj"></param>
	void swap(AnyType& obj)
	{
		AnyType temp = *this;
		this->data = obj.data;
		this->dataType = obj.dataType;

		obj.data = temp.data;
		obj.dataType = temp.dataType;
	}

	/// <summary>
	/// Function to get data type
	/// </summary>
	/// <returns></returns>
	std::string getType()
	{
		return dataType;
	}

	/// <summary>
	/// Function to cast data to char
	/// </summary>
	/// <returns></returns>
	char toChar()
	{
		if (dataType == typeid(char).name()) return *std::get_if<char>(&data); else
			throw std::bad_cast();
	}

	/// <summary>
	/// Function to cast data to bool
	/// </summary>
	/// <returns></returns>
	bool toBool()
	{
		if (dataType == typeid(bool).name()) return *std::get_if<bool>(&data); else
			throw std::bad_cast();
	}

	/// <summary>
	/// Function to cast data to double
	/// </summary>
	/// <returns></returns>
	double toDouble()
	{
		if (dataType == typeid(double).name()) return *std::get_if<double>(&data); else
			throw std::bad_cast();
	}

	/// <summary>
	/// Function to cast data to int
	/// </summary>
	/// <returns></returns>
	int toInt()
	{
		if (dataType == typeid(int).name()) return *std::get_if<int>(&data); else
			throw std::bad_cast();
	}

	/// <summary>
	/// Function to cast data to float
	/// </summary>
	/// <returns></returns>
	float toFloat()
	{
		if (dataType == typeid(float).name()) return *std::get_if<float>(&data); else
			throw std::bad_cast();
	}

	/// <summary>
	/// Function to cast data to long
	/// </summary>
	/// <returns></returns>
	long toLong()
	{
		if (dataType == typeid(long).name()) return *std::get_if<long>(&data); else
			throw std::bad_cast();
	}
};

int main()
{
	try
	{
		AnyType obj = 1;
		AnyType obj2 = 'c';
		obj.swap(obj2);
		int storedValue = obj.toDouble();
	}
	catch (const std::bad_cast& ex)
	{
		std::cerr <<"Error: "<< ex.what() <<"!"<< std::endl;
	}
	return 0;
}
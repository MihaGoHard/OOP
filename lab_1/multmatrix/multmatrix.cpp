#include <array>
#include <fstream>
#include <iostream>
#include <optional>
#include <sstream>
#include <string>
#include <iomanip>  

const unsigned int MATRIX_SIZE = 3;
using Matrix = std::array<std::array<double, MATRIX_SIZE>, MATRIX_SIZE>;

struct Matrices
{
	Matrix matrixA = {0};
	Matrix matrixB = {0};
};

struct InputStreams
{
	std::ifstream firstInput;
	std::ifstream secondInput;
};

struct Args
{
	std::string firstFileName;
	std::string secondFileName;
};

std::optional<Args> ParseArgs(int argc, char* argv[])
{
	if (argc != 3)
	{
		std::cout << "Invalid arguments number: " << argc << "\n";
		std::cout << "Usage: multmatrix.exe <first file name> <second file name>";
		return std::nullopt;
	}
	Args args;
	args.firstFileName = argv[1];
	args.secondFileName = argv[2];
	return args;
}

bool OpenStreams(InputStreams& streams, Args& args)
{
	streams.firstInput.open(args.firstFileName);
	if (!streams.firstInput.is_open())
	{
		std::cout << "Failed to open '" << args.firstFileName << "' for reading\n";
		return false;
	}

	streams.secondInput.open(args.secondFileName);
	if (!streams.secondInput.is_open())
	{
		std::cout << "Failed to open '" << args.secondFileName << "' for reading\n";
		return false;
	}
	return true;
}

bool GetMatrixFromFile(std::ifstream& input, Matrix& matrix)
{
	std::string line = "";
	int rows = 0;
	int columns;

	while (getline(input, line))
	{
		columns = 0;
		if (rows < MATRIX_SIZE)
		{
			std::stringstream stringCounter(line);
			while (!stringCounter.eof())
			{
				if (columns == MATRIX_SIZE)
				{
					return false;
				}
				
				stringCounter >> matrix[rows][columns];
				++columns;
			}
			if (columns != MATRIX_SIZE)
			{
				return false;
			}
		}
		++rows;
	}

	if (line == "" && rows != MATRIX_SIZE)
	{
		std::cout << "Empty file or empty row\n";
		return false;
	}

	if (rows != MATRIX_SIZE)
	{
		return false;
	}

	return true;
}


bool GetMatrices(InputStreams& streams, Matrices& matrices, Args& args)
{
	if (!GetMatrixFromFile(streams.firstInput, matrices.matrixA))
	{
		std::cout << "Invalid content in first file\n";
		std::cout << "Usage: input file includes matrix 3x3 \n";
		return false;
	}
	if (!GetMatrixFromFile(streams.secondInput, matrices.matrixB))
	{
		std::cout << "Invalid content in second file\n";
		std::cout << "Usage: input file includes matrix 3x3 \n";
		return false;
	}
	return true;
}

Matrix MultiplyMatrices(const Matrices &matrices)
{
	Matrix resultMatrix = {0};

	for (int rows = 0; rows < MATRIX_SIZE; ++rows)
	{
		for (int columns = 0; columns < MATRIX_SIZE; ++columns)
		{
			for (int inner = 0; inner < MATRIX_SIZE; ++inner)
			{
				resultMatrix[rows][columns] += matrices.matrixA[rows][inner] * matrices.matrixB[inner][columns];
			}
		}
	}
	return resultMatrix;
}


int GetMaxNumLength(const Matrix& matrix)
{
	int maxNumLength = 0;
	int offsetIndex = 3;
	for (int i = 0; i < MATRIX_SIZE; ++i)
	{
		for (int j = 0; j < MATRIX_SIZE; ++j)
		{
			int currNumLength = std::to_string(matrix[i][j]).length() - offsetIndex; 
			if (currNumLength > maxNumLength)
			{
				maxNumLength = currNumLength;
			}
		}
	}
	return maxNumLength;
}


void PrintMatrix(const Matrix &matrix)
{
	int accuracy = 3;
	int maxNumLength = GetMaxNumLength(matrix);
	for (int i = 0; i < MATRIX_SIZE; i++)
	{
		for (int j = 0; j < MATRIX_SIZE; j++)
		{
			std::cout << std::setw(maxNumLength) << std::setprecision(accuracy) << std::fixed << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int main(int argc, char* argv[])
{
	auto args = ParseArgs(argc, argv);
	if (!argc)
	{
		return 1;
	}

	InputStreams streams;

	if (!OpenStreams(streams, *args))
	{
		return 1;
	}

	Matrices matrices;

	if (!GetMatrices(streams, matrices, *args))
	{
		return 1;
	}

	Matrix matrixC = MultiplyMatrices(matrices);

	PrintMatrix(matrixC);

	return 0;
}


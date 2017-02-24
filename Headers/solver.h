/**
 * Created by colin on 15/02/17.
 * This class will contain methods for solving s-even magic squares
**/
#define MIDTERM_ALT_SINGLYEVEN_H

using namespace std;

void printStep(vector<vector<int>> &square, int n)  //Method to do the final pint out of the vector, with the addition listed on the side
{
	//Printing out the magic square and its summations, fancy formatting and all
	for (int row = 0; row < n; row++) //print out the matrix
	{
		for (int col = 0; col < n; col++)
		{
			cout << "[" << square[row][col] << "] \t";
		}
		cout << "\n\n";
	}
}

void odd(vector<vector<int>> &square, int n)
{
	//TODO: visualization.  print the square at each step
	int i = n / 2;
	int j = n - 1;

	for (int num = 1; num <= n * n;) {
		if (i == -1 && j == n) //3rd condition
		{
			j = n - 2;
			i = 0;
		}
		else
		{
			if (j == n) //1st condition helper if next number goes to out of square's right side
				j = 0;
			if (i < 0)  //1st condition helper if next number is goes to out of square's upper side
				i = n - 1;
		}
		if (square[i][j]) //2nd condition
		{
			j -= 2;
			i++;
			continue;
		} else
		{
			cout << "-----------------------------------" << endl;
			cout << "Step " << num << endl << endl;
			square[i][j] = num++; //set number
			printStep(square, n);
		}
		//TODO print should probably be here, where we actually make changes

		j++;
		i--; //1st condition

	}
}

void dEven(vector<vector<int>> &square, int n)
{
	int i, j;
	vector<vector<int>> I(n, vector<int>(n, 0));
	vector<vector<int>> J(n, vector<int>(n, 0));
	int index = 1;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			I[i][j] = ((i + 1) % 4) / 2;
			J[j][i] = ((i + 1) % 4) / 2;
			square[i][j] = index;
			index++;
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (I[i][j] == J[i][j])
			{
				square[i][j] = n * n + 1 - square[i][j];
			}
		}
	}
}

void sEven(vector<vector<int>> &square, int n)
{
	//TODO sudden realization about singly even numbers.
	/* Essentially all singly even numbers can be broken down into an odd times 2.
	 * Which means that all we need to do is divide the singly even square into 4
	 * odd squares (one for each quadrant) and solve each in the right order.
	 * Then put them all back together.
	 */

	/* Better idea:  Each quadrant will be the same pattern, just with proportionally larger numbers.
	 * I will solve only one odd size square, then I will add the largest number in the former quadrant
	 * to it to as I fold it back into the original square, in the correct order.  This should be much
	 * easier to understand for people who already know how to solve odd magic squares.
	 * Thankfully this software already does, so we will make use of that instead of writing another
	 * algorithm all together.
	 */

	//There will be an extra step at the end where we switch some numbers around, but that is it past solving an odd.
	//TODO make this step

	int p = n / 2;
	vector<vector<int>> quadrant(p, vector<int>(p, 0));
	int max = 


	//I think I may have a clever way of solving this.
	odd(quadrant, p);
}
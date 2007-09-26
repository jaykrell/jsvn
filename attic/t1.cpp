#include <stdio.h>

int main()
{
	try
	{
		try
		{
			throw 1;
		}
		catch (...)
		{
			try
			{
				throw 2;
			}
			catch (...)
			{
			}
			throw;
		}
	}
	catch (int i)
	{
		printf("%d\n", i);
	}
	return 0;
}

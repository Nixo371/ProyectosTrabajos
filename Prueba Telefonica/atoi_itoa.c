#include "MVP.h"


// ATOI
static int	ft_calculate(char n)
{
	char	*base;
	int		i;

	base = "0123456789";
	i = 0;
	while (n != base[i])
	{
		i++;
	}
	return (i);
}

int	ft_atoi(const char *ptr)
{
	int	i;
	int	num;
	int	neg;

	i = 0;
	num = 0;
	neg = 1;
	while (ptr[i] == ' ' || (ptr[i] >= 9 && ptr[i] <= 13))
		i++;
	if (ptr[i] == '+')
		i++;
	else if (ptr[i] == '-')
	{
		neg *= -1;
		i++;
	}
	while (ptr[i] != '\0')
	{
		if (ptr[i] < '0' || ptr[i] > '9')
			return (num * neg);
		num = (num * 10) + ft_calculate(ptr[i]);
		i++;
	}
	return (num * neg);
}

//ITOA
static char	get_number(int n, int m, int deg, int neg)
{
	int		i;
	int		pos;

	if (neg == 1 && m == 0)
		return ('-');
	i = 0;
	pos = m - neg;
	while (pos++ < deg)
		n = n / 10;
	n = n % 10;
	if (neg == 1)
		n *= -1;
	return (n + 48);
}

static int	set_a(int m)
{
	int	a;

	a = 1;
	while (m / 10)
	{
		m = m / 10;
		a++;
	}
	return (a);
}

char	*ft_itoa(int n)
{
	char	*number;
	int		a;
	int		m;
	int		neg;

	m = n;
	neg = 0;
	if (n < 0)
		neg = 1;
	a = set_a(m);
	number = (char *)malloc(sizeof(char) * (a + neg + 1));
	if (number == NULL)
		return (NULL);
	m = 0;
	while (m < (a + neg))
	{
		number[m] = get_number(n, m, (a - 1), neg);
		m++;
	}
	number[m] = '\0';
	return (number);
}

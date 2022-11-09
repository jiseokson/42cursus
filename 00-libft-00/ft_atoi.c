#include "libft.h"

static int	ft_isspace(char c)
{
	char	*spaces;

	spaces = "\t\n\v\f\r ";
	while (*spaces)
	{
		if (*spaces == c)
			return (1);
		++spaces;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int	ret;
	int	sign;

	ret = 0;
	sign = 1;
	while (*str && ft_isspace(*str))
		++str;
	if (*str == '+')
	{
		++str;
	}
	else if (*str == '-')
	{
		++str;
		sign = -1;
	}
	while (*str && ft_isdigit(*str))
	{
		ret = ret * 10 + sign * (*str - '0');
		++str;
	}
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:53:34 by jison             #+#    #+#             */
/*   Updated: 2022/10/15 15:16:20 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *str);
int		get_operator_id(char *str);
void	ft_putstr(char *str);
void	ft_putnbr(long long n);
int		eval(int n1, int n2, int operator_id);

int	main(int argc, char **argv)
{
	int	n1;
	int	n2;
	int	operator_id;

	if (argc != 4)
		return (1);
	n1 = ft_atoi(argv[1]);
	n2 = ft_atoi(argv[3]);
	operator_id = get_operator_id(argv[2]);
	if (operator_id == get_operator_id("/") && n2 == 0)
	{
		ft_putstr("Stop : division by zero\n");
		return (1);
	}
	if (operator_id == get_operator_id("%") && n2 == 0)
	{
		ft_putstr("Stop : modulo by zero\n");
		return (1);
	}
	ft_putnbr((long long)eval(n1, n2, operator_id));
	ft_putstr("\n");
	return (0);
}

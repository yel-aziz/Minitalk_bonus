/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 17:52:55 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/01/13 15:20:39 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	message_end(int sig)
{
	if (sig == SIGUSR1)
	{
		ft_printf(" \n %s \n", "Message recu😍");
	}
}

int	ft_atoi(const char *str)
{
	int	i;
	int	c;
	int	res;

	i = 0;
	c = 1;
	res = 0;
	while (str[i] == '\t' || str[i] == ' ' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == '\n')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			c *= -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * c);
}

void	send_binary(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		kill(pid, SIGUSR1 + ((c >> i) & 1));
		i--;
		usleep(500);
	}
}

int	main(int ac, char **av)
{
	char	*str;
	int		pid;

	signal(SIGUSR1, message_end);
	if (ac != 3)
	{
		ft_printf(" \n %s \n", "invalide argument(PID AND MESSAGE)");
	}
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		str = av[2];
		while (*str)
		{
			send_binary(pid, *str++);
		}
		if (*str == '\0')
		{
			return (0);
		}
	}
	while (1)
	{
		pause();
	}
}

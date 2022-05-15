/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 17:53:01 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/01/13 15:20:53 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	handler(int sig, siginfo_t *info, void *usless)
{
	static int	i;
	static char	c;
	int			pid;

	(void)usless;
	pid = info->si_pid;
	c = (c << 1) | (sig & 1);
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		c = 0;
		i = 0;
		kill(pid, SIGUSR1);
	}
}

int	main(void)
{
	struct sigaction	s;

	s.sa_sigaction = handler;
	s.sa_flags = SA_SIGINFO;
	ft_printf("pid = %d \n", getpid());
	sigaction(SIGUSR1, &s, NULL);
	sigaction(SIGUSR2, &s, NULL);
	while (1)
	{
		pause();
	}
}

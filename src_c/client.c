/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 12:16:13 by kvebers           #+#    #+#             */
/*   Updated: 2023/01/09 12:38:27 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	ft_test1(int pid, char c)
{
	if (c / 2 > 0)
		ft_test1(pid, c / 2);
	if (c % 2 == 1)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	usleep (50);
}

void	ft_test(int pid, char c)
{
	int	base;

	base = 128;
	while (base > c)
	{
		kill(pid, SIGUSR2);
		base = base / 2;
		usleep (50);
	}
	ft_test1(pid, c);
}

int	ft_check_arg(char *arg)
{
	int	cnt;

	cnt = 0;
	while (*(arg + cnt) != '\0')
	{
		if (ft_isprint(*(arg + cnt)) == 0)
		{
			ft_printf("Error: The char is not printable");
			return (0);
		}
		cnt++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	pid;
	int	cnt;

	if (argc != 3)
	{
		ft_printf("Error: Call should be ./client PID + TXT");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	cnt = 0;
	if (ft_check_arg(argv[2]) == 0)
		return (0);
	while (*(argv[2] + cnt) != '\0')
	{
		ft_test(pid, *(argv[2] + cnt));
		cnt++;
	}
	return (0);
}

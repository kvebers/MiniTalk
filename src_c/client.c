/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 12:16:13 by kvebers           #+#    #+#             */
/*   Updated: 2023/01/08 19:54:11 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	test1(int pid, char c)
{
	if (c / 2 > 0)
		test1(pid, c / 2);
	if (c % 2 == 1)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	sleep (1);
	
}

void	test(int pid, char c)
{
	int base;

	base = 128;
	while (base > c)
	{
		kill(pid, SIGUSR2);
		base = base / 2;
		sleep (1);
	}
	test1(pid, c);
}

int	main(int argc, char **argv)
{
	int pid;
	int cnt;
	
	if (argc != 3)
	{
		ft_printf("call should be ./client PID + TXT");
		return 0;
	}
	pid = ft_atoi(argv[1]);
	cnt = 0;
	while (*(argv[2] + cnt) != '\0')
	{
		test(pid, *(argv[2] + cnt));
		cnt++;
	}
}

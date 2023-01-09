/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 12:15:40 by kvebers           #+#    #+#             */
/*   Updated: 2023/01/09 12:27:56 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	ft_printer(int sig)
{
	static int	result;
	static int	pow;

	if (pow == 0 || pow == 1)
		pow = 256;
	pow = pow / 2;
	if (sig == SIGUSR1)
		result = result + pow;
	if (pow == 1)
	{
		ft_putchar(result);
		result = 0;
	}
}

int	main(void)
{
	ft_printf("Server PID: %d\n", getpid());
	signal(SIGUSR1, ft_printer);
	signal(SIGUSR2, ft_printer);
	while (1)
		pause();
	return (0);
}

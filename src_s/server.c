/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 12:15:40 by kvebers           #+#    #+#             */
/*   Updated: 2023/01/08 19:32:55 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void printer(int sig)
{
    static int  result;
    static int  pow;

    if (pow == 0 || pow == 1)
        pow = 256;
    pow = pow / 2;
    if (sig == SIGUSR1)
        result = result + pow;
    ft_printf("\nPow: %i Result %i", pow, result);
    if (pow == 1)
    {
        ft_putchar(result);
        result = 0;
        ft_printf("\n");
    }
}


int main(void) 
{
    ft_printf("Server PID: %d\n", getpid());
    signal(SIGUSR1, printer);
    signal(SIGUSR2, printer);
    while (1) 
        pause();
    return 0;
}

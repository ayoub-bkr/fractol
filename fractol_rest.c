/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_rest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 23:09:36 by aboukent          #+#    #+#             */
/*   Updated: 2025/04/16 23:09:40 by aboukent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	erroring(void)
{
	write(1, "Invalid input! Try this:\n", 26);
	write(1, "./fractol mandelbort\n", 22);
	write(1, "./fractol julia <real> <imaginer> [-2, 2]", 42);
	exit(1);
}
